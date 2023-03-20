import datetime
import os
import re
from typing import List
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
import requests
from bs4 import BeautifulSoup
from collections import Counter
import multiprocessing as mp
import threading
import concurrent.futures

MAX_VOCAB_SIZE = 10000
EMBEDDING_SIZE, HIDDEN_SIZE, NUM_HIDDEN_LAYERS = 256, 1024, 3
TRAIN_BATCH_SIZE, LEARNING_RATE = 32768, 0.0001
DEVICE = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
MODEL_SAVE_PATH = './hughbot_model.pth'


class NewsTitleDataset(Dataset):
    def __init__(self, id_data):
        self.id_data = id_data

    def __len__(self):
        return len(self.id_data)

    def __getitem__(self, idx):
        inputs, targets = self.id_data[idx][:-1], self.id_data[idx][1:]
        return inputs, targets


class LanguageModel(nn.Module):
    def __init__(self):
        super(LanguageModel, self).__init__()
        self.embedding = nn.Embedding(MAX_VOCAB_SIZE, EMBEDDING_SIZE)
        self.lstm = nn.LSTM(EMBEDDING_SIZE, HIDDEN_SIZE, NUM_HIDDEN_LAYERS, batch_first=True, dropout=0.5)
        self.attention = nn.Linear(HIDDEN_SIZE, HIDDEN_SIZE)
        self.linear = nn.Linear(HIDDEN_SIZE, MAX_VOCAB_SIZE, bias=True)
        self.weight_decay = 0.001

    def forward(self, x):
        x = self.embedding(x)
        if x.shape[1] <= 0:
            return torch.zeros_like(x)
        lstm_output, _ = self.lstm(x)
        attention_scores = self.attention(lstm_output)
        attention_weights = torch.softmax(attention_scores, dim=1)
        context_vector = torch.bmm(attention_weights.transpose(1, 2), lstm_output)
        output = self.linear(context_vector.squeeze(1))
        l2_reg = self.weight_decay * torch.sum(torch.stack([torch.sum(param ** 2) for param in self.parameters()]))
        output = output + l2_reg
        return output


def preprocess_title(title, token_to_id, max_len):
    title = title[:-1]
    title = title[:max_len]
    # title이 2차원 리스트인 경우 처리
    title = [token for tokens in title for token in tokens if isinstance(token, str)]
    title = ' '.join(title)
    title = [token_to_id.get(token, token_to_id['<unk>']) if token in token_to_id else token_to_id['<unk>'] for token in title.split()]
    return title if title else [token_to_id['<pad>']]


def collate_fn(batch, token_to_id):
    inputs = []
    targets = []
    for input_title, target_title in batch:
        input_title = [token_to_id.get(token, token_to_id['<unk>']) for token in input_title]
        target_title = [token_to_id.get(token, token_to_id['<unk>']) for token in target_title]
        if any(torch.isnan(torch.tensor(input_title + target_title).float())):
            continue
        inputs.append(input_title)
        targets.append(target_title)

    if len(inputs) == 0 or len(targets) == 0:  # 배치에 유효한 데이터가 없는 경우 None을 반환합니다.
        return None, None

    padded_inputs = nn.utils.rnn.pad_sequence([torch.tensor(title, dtype=torch.long) for title in inputs], batch_first=True).to(DEVICE)
    padded_targets = nn.utils.rnn.pad_sequence([torch.tensor(title, dtype=torch.long) for title in targets], batch_first=True).to(DEVICE)

    return padded_inputs, padded_targets  # tuple -> tensor로 변경


def preprocess_data_lm(data):
    token_to_id = {'<pad>': 0, '<unk>': 1, '<sos>': 2, '<eos>': 3}

    tokenized_data = [[token for token in text.split()[:100]] for text in data if text.split()]
    if not tokenized_data:
        return [], token_to_id

    # 2차원 리스트인 경우 처리
    if not all(isinstance(elem, list) for elem in tokenized_data):
        tokenized_data = [tokenized_data]

    tokenized_data = [[token for tokens in title for token in tokens if isinstance(token, str)] for title in tokenized_data if len(title) > 1]
    if not tokenized_data:
        return [], token_to_id

    tokenized_data = [title for title in tokenized_data if len(title) > 1]

    word_count = Counter(word for title in tokenized_data for word in title)

    for word, count in word_count.items():
        if count >= 1 and len(token_to_id) < MAX_VOCAB_SIZE:
            token_to_id[word] = len(token_to_id)

    id_data = [([token_to_id.get(token, token_to_id['<unk>']) for token in title[:-1]] + [token_to_id['<eos>']],
                [token_to_id.get(token, token_to_id['<unk>']) for token in title[1:]] + [token_to_id['<eos>']])
               for title in tokenized_data]

    max_title_len = max(len(title[0]) for title in id_data)
    padded_data = [(title[0] + [token_to_id['<pad>']] * (max_title_len - len(title[0])),
                    title[1] + [token_to_id['<pad>']] * (max_title_len - len(title[1])))
                   for title in id_data]

    padded_data = [(tuple(title[0]), tuple(title[1])) for title in padded_data]

    padded_data = [(torch.zeros_like(title[0]) if torch.isnan(torch.tensor(title[0]).float()).any() else title[0],
                    torch.zeros_like(title[1]) if torch.isnan(torch.tensor(title[1]).float()).any() else title[1])
                   for title in padded_data]

    if len(padded_data) == 0:
        return [], token_to_id

    return padded_data, token_to_id


def train_and_update_lm(data):
    if len(data) == 0:
        return

    # 데이터 전처리 및 데이터셋 생성
    padded_data, token_to_id = preprocess_data_lm(data)
    title_dataset = NewsTitleDataset(padded_data)
    title_loader = DataLoader(title_dataset, batch_size=TRAIN_BATCH_SIZE, shuffle=True, collate_fn=lambda batch: collate_fn(batch, token_to_id), drop_last=True)

    # 모델 생성
    try:
        # 저장된 모델 불러오기
        lm = LanguageModel()
        lm.load_state_dict(torch.load(MODEL_SAVE_PATH, map_location=DEVICE))
        optimizer = optim.Adam(lm.parameters(), lr=LEARNING_RATE)
        lm.to(DEVICE)

    except FileNotFoundError:
        # 새로운 모델 생성
        lm = LanguageModel()
        optimizer = optim.Adam(lm.parameters(), lr=LEARNING_RATE)
        lm.to(DEVICE)

    # 학습
    best_loss = float('inf')
    epoch = 0
    while True:
        running_loss = 0.0
        for batch in title_loader:
            inputs, targets = batch
            if inputs is None and targets is None:  # 빈 텐서를 건너뛰기
                continue
            inputs, targets = inputs.to(DEVICE), targets.to(DEVICE)
            optimizer.zero_grad()
            outputs = lm(inputs)
            outputs = outputs.view(-1, MAX_VOCAB_SIZE)
            targets = targets.view(-1)
            loss = nn.CrossEntropyLoss()(outputs, targets)
            loss.backward()
            nn.utils.clip_grad_norm_(lm.parameters(), max_norm=1.0)  # gradient clipping 적용
            optimizer.step()
            optimizer.zero_grad()  # gradient 초기화
            running_loss += loss.item() * inputs.shape[0] * inputs.shape[1]
        epoch += 1
        cur_loss = running_loss / len(title_dataset)
        if cur_loss != cur_loss:  # nan 값이 발생하는 경우
            save_train_logs(f"    Epoch {epoch}, Loss: NaN")
            break
        save_train_logs(f"    Epoch {epoch}, Loss: {cur_loss}")
        if cur_loss < best_loss:
            best_loss = cur_loss
        else:
            break

    # 모델 저장
    torch.save(lm.state_dict(), MODEL_SAVE_PATH)


def crawl_news_articles(url: str) -> List[str]:
    try:
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3",
            "Referer": url,
            "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7",
            "Content-Type": "text/html; charset=utf-8",
        }
        response = requests.get(url, headers=headers)
        response.encoding = 'utf-8'
        soup = BeautifulSoup(response.text, "html.parser")
        news_sites = {
            'naver': '.cjs_d',
            'chosun': '.story-card-component span',
            'donga': '.desc a',
            'hani': '.article-prologue a',
            'mk': '.news_desc',
            'bbc': '.gs-c-promo-summary',
            'nytimes': '.summary-class',
            'cnn': '.container__headline',
            'theguardian': '.u-faux-block-link__overlay',
            'reuters': '.text__text__1FZLe'
        }
        if any(site in url for site in news_sites):
            articles = [title.text.strip() for title in soup.select(news_sites[url.split('.')[1]])]
        else:
            save_error_logs(f"[{datetime.datetime.now()}] Unsupported url: {url}")
            return []
    except Exception as exc:
        save_error_logs(f"[{datetime.datetime.now()}] {url} generated an exception: {exc}")
        return []
    return articles


def crawl_news_articles_multi(urls: List[str]) -> List[str]:
    with mp.Pool(mp.cpu_count()) as pool:
        return sum(pool.map(crawl_news_articles, urls), [])


def clean_text(text):
    # 영어, 한국어, 숫자, 공백을 제외한 문자 제거
    cleaned_text = re.sub('[^A-Za-z가-힣0-9\s]+', '', text)
    return cleaned_text


def update_news_articles():
    save_train_logs(f"[{datetime.datetime.now()}] Updating news articles...")

    urls = ["https://news.naver.com",
            "https://www.chosun.com",
            "https://www.donga.com",
            "http://www.hani.co.kr",
            "https://www.mk.co.kr/news/economy",
            "https://www.bbc.com/news",
            "https://www.nytimes.com",
            "https://edition.cnn.com/business",
            "https://www.theguardian.com/international",
            "https://www.reuters.com"]
    news_articles = []

    with concurrent.futures.ProcessPoolExecutor(max_workers=len(urls)) as executor:
        future_to_url = {executor.submit(crawl_news_articles, url): url for url in urls}
        for future in concurrent.futures.as_completed(future_to_url):
            url = future_to_url[future]
            try:
                data = future.result()
                news_articles.extend(data)
            except Exception as exc:
                save_error_logs(f"[{datetime.datetime.now()}] {url} generated an exception: {exc}")

    data = []
    for article in news_articles:
        for sent in re.split('(?<=[.?!])\s+', article):
            if len(sent.split()) >= 2:
                cleaned_sent = clean_text(sent.strip())
                if cleaned_sent:
                    data.append(cleaned_sent)

    train_and_update_lm(data)

    save_train_logs(f"[{datetime.datetime.now()}] Done updating news articles...")

    # 60초마다 뉴스 타이틀 갱신
    threading.Timer(60, update_news_articles).start()


def update_chat_logs(chat_logs):
    save_train_logs(f"[{datetime.datetime.now()}] Updating chat logs...")

    if len(chat_logs) == 0:
        return None, None, None, None

    train_and_update_lm(chat_logs)

    save_train_logs(f"[{datetime.datetime.now()}] Done updating chat logs.")


def generate_response_lm(input_text, token_to_id, lm):
    if lm is None or token_to_id is None:
        _, token_to_id = preprocess_data_lm([])
        lm = LanguageModel()
        try:
            lm.load_state_dict(torch.load(MODEL_SAVE_PATH))
        except FileNotFoundError:
            save_error_logs(f"[{datetime.datetime.now()}] Language model not found. Generating new model...")
            lm.load_state_dict(torch.load(MODEL_SAVE_PATH))
        lm.to(DEVICE)

    lm.eval()  # Inference 모드로 변경

    # 단어 시퀀스를 ID로 변환
    input_ids = [token_to_id.get(token, token_to_id['<unk>']) for token in input_text.split() + ['<eos>']]
    if len(input_ids) > EMBEDDING_SIZE:
        input_ids = input_ids[:EMBEDDING_SIZE]
    else:
        input_ids = input_ids + [token_to_id['<pad>']] * (EMBEDDING_SIZE - len(input_ids))
    input_tensor = torch.LongTensor(input_ids).unsqueeze(0)

    # Generate response
    output_ids = lm(input_tensor.to(DEVICE)).squeeze(0).argmax(dim=-1).tolist()
    output_text = ' '.join([list(token_to_id.keys())[list(token_to_id.values()).index(id)] if id in token_to_id else '<unk>' for id in output_ids])

    return output_text


def save_train_logs(train_logs):
    if not os.path.isfile("./train_logs.txt"):
        with open("./train_logs.txt", "w") as f:
            pass  # 파일을 새로 생성합니다.
    with open("./train_logs.txt", "a") as f:
        f.write(train_logs + "\n")


def load_chat_logs():
    if not os.path.isfile("./chat_logs.txt"):
        with open("./chat_logs.txt", "w") as f:
            pass  # 파일을 새로 생성합니다.
    with open("./chat_logs.txt", "r") as f:
        chat_logs = f.read().splitlines()
    return chat_logs


def save_chat_logs(chat_logs):
    with open("./chat_logs.txt", "w") as f:
        f.write("\n".join(chat_logs))


def save_error_logs(error_log):
    if not os.path.isfile("./error_logs.txt"):
        with open("./error_logs.txt", "w") as f:
            pass  # 파일을 새로 생성합니다.
    with open("./error_logs.txt", "a") as f:
        f.write(error_log + "\n")


def main():
    chat_logs = load_chat_logs()

    token_to_id = None
    lm = None  # lm 변수 초기화

    update_news_articles()

    while True:
        # 사용자 입력 받기
        input_text = input("User: ")
        if input_text.strip() == "":
            continue
        chat_logs.append(input_text)

        # 채팅 로그 파일에 저장
        save_chat_logs(chat_logs)

        # 봇 응답 생성
        output_text = generate_response_lm(input_text, token_to_id, lm)  # lm 변수 전달

        print("Bot:", output_text)

        # 채팅 로그 업데이트
        if len(chat_logs) >= 1000:
            update_chat_logs(chat_logs)
            chat_logs = []


if __name__ == "__main__":
    main()
