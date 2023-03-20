
import torch
import os
import re
import cv2
import jieba
import konlpy
import asyncio
import aiohttp
import requests
import sudachipy
import unicodedata
from bs4 import BeautifulSoup
from langdetect import detect
from transformers import AutoTokenizer, BertForSequenceClassification
# import RPi.GPIO as GPIO

os.environ['CUDA_VISIBLE_DEVICES'] = '-1'


class Chatbot:
    def __init__(self, model_path):
        self.model_path = model_path
        if os.path.exists(model_path):
            self.model = torch.load(model_path, map_location=torch.device('cpu'))
        else:
            self.model = BertForSequenceClassification.from_pretrained("bert-base-uncased", num_labels=2).to('cpu')
        self.tokenizer = AutoTokenizer.from_pretrained("bert-base-uncased")
        self.tokenizer.max_length = 512  # 추가한 코드

    async def train_news(self):
        while True:
            # 뉴스 크롤링 및 전처리
            news = await self.crawl_news()
            data, label = self.preprocess_news(news)
            if len(data) == 0:
                await asyncio.sleep(600)  # 뉴스가 없을 경우 10분 대기
                continue

            # 모델 학습
            self.train_model(data, label)

            # 10분마다 train_news 메서드 실행
            await asyncio.sleep(600)

    async def crawl_news(self):
        async with aiohttp.ClientSession() as session:
            urls = [
                ("https://www.nytimes.com/", "en"),
                ("https://www.lemonde.fr/international/", "fr"),
                ("https://www.elpais.com/internacional/", "es"),
                ("https://www.asahi.com/international/", "ja"),
                ("https://www.joongang.co.kr/", "ko"),
                ("https://www.folha.uol.com.br/mundo/", "pt"),
                ("https://www.zaobao.com.sg/realtime/world", "zh"),
            ]
            tasks = []
            for url, language in urls:
                tasks.append(asyncio.ensure_future(self.crawl_url(session, url, language)))
            results = await asyncio.gather(*tasks)

            return results

    async def crawl_url(self, session, url, language):
        headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3",
            "Referer": url,
            "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7",
            "Content-Type": "text/html; charset=utf-8",
        }
        async with session.get(url, headers=headers) as resp:
            html = await resp.text()
            soup = BeautifulSoup(html, "html.parser")

            # 사이트에 맞게 분기하여 기사 본문 추출
            if "nytimes" in url:
                text = [article.text.strip() for article in soup.select('.summary-class')]
            elif "lemonde" in url:
                text = [article.text.strip() for article in soup.select('.teaser__desc')]
            elif "elpais" in url:
                text = [article.text.strip() for article in soup.select('.c_d')]
            elif "asahi" in url:
                text = [article.text.strip() for article in soup.select('p')]
            elif "joongang" in url:
                text = [article.text.strip() for article in soup.select('.description')]
            elif "folha" in url:
                text = [article.text.strip() for article in soup.select('.c-headline__title')]
            elif "zaobao" in url:
                text = [article.text.strip() for article in soup.select('h2')]
            else:
                return []  # 해당 사이트에서는 기사 추출 불가능한 경우

            # 기사 본문 추출 및 언어 정보 추가
            text = [(t, language) for t in text if t is not None]
            return text

    def preprocess_news(self, news):
        data = []
        label = []
        for n in news:
            for text, language in n:
                if len(text) > 512:
                    text = text[:512]

                # 언어별 전처리
                if language == "en":
                    # 영어 전처리 코드
                    text = text.lower()
                    text = re.sub(r"[^a-zA-Z0-9\s]", "", text)
                elif language == "fr":
                    # 프랑스어 전처리 코드
                    text = unicodedata.normalize("NFKD", text)
                    text = "".join([c for c in text if not unicodedata.combining(c)])
                elif language == "es":
                    # 스페인어 전처리 코드
                    text = unicodedata.normalize("NFKD", text)
                    text = "".join([c for c in text if not unicodedata.combining(c)])
                elif language == "ja":
                    # 일본어 전처리 코드
                    tokenizer_obj = sudachipy.Dictionary().create()
                    nouns = []
                    for m in tokenizer_obj.tokenize(text):
                        if m.part_of_speech()[0] == "名詞":
                            nouns.append(m.surface())
                    text = " ".join(nouns)
                elif language == "ko":
                    # 한국어 전처리 코드
                    nouns = konlpy.tag.Komoran().nouns(text)
                    text = " ".join(nouns)
                elif language == "pt":
                    # 포르투갈어 전처리 코드
                    text = re.sub(r"[^\w\s]", "", text)
                elif language == "zh":
                    # 중국어 전처리 코드
                    words = jieba.cut(text)
                    nouns = []
                    for word in words:
                        if len(word) > 1:
                            nouns.append(word)
                    text = " ".join(nouns)

                data.append(text)
                label.append(1)

        return data, label

    def train_model(self, data, label):
        # 뉴스 데이터에 대한 모델 학습 코드 작성
        inputs = self.tokenizer(data, padding=True, truncation=True, max_length=512, return_tensors="pt").to('cpu')
        labels = torch.tensor(label).to('cpu')
        optimizer = torch.optim.AdamW(self.model.parameters(), lr=5e-5)
        loss_fn = torch.nn.CrossEntropyLoss()

        self.model.train()
        for epoch in range(3):
            loss = 0
            for i in range(len(inputs["input_ids"])):
                optimizer.zero_grad()
                output = self.model(**inputs, labels=labels)
                loss += output[0].item()
                output[0].backward()
                optimizer.step()
            loss = loss / len(inputs["input_ids"])
            print(f"Epoch {epoch + 1}, Loss : {loss:.3f}")

        # 모델 저장
        torch.save(self.model, self.model_path)

    def generate_response(self, input_text):
        # 입력된 언어 감지
        language = detect(input_text)

        # 언어별 전처리 함수 적용
        if language == "en":
            # 영어 전처리 코드
            input_text = input_text.lower()
            input_text = re.sub(r"[^a-zA-Z0-9\s]", "", input_text)
        elif language == "fr":
            # 프랑스어 전처리 코드
            input_text = unicodedata.normalize("NFKD", input_text)
            input_text = "".join([c for c in input_text if not unicodedata.combining(c)])
        elif language == "es":
            # 스페인어 전처리 코드
            input_text = unicodedata.normalize("NFKD", input_text)
            input_text = "".join([c for c in input_text if not unicodedata.combining(c)])
        elif language == "ja":
            # 일본어 전처리 코드
            tokenizer_obj = sudachipy.Dictionary().create()
            nouns = []
            for m in tokenizer_obj.tokenize(input_text):
                if m.part_of_speech()[0] == "名詞":
                    nouns.append(m.surface())
            input_text = " ".join(nouns)
        elif language == "ko":
            # 한국어 전처리 코드
            nouns = konlpy.tag.Komoran().nouns(input_text)
            input_text = " ".join(nouns)
        elif language == "pt":
            # 포르투갈어 전처리 코드
            input_text = re.sub(r"[^\w\s]", "", input_text)
        elif language == "zh":
            # 중국어 전처리 코드
            words = jieba.cut(input_text)
            nouns = []
            for word in words:
                if len(word) > 1:
                    nouns.append(word)
            input_text = " ".join(nouns)

        # 모델 입력 데이터로 변환
        inputs = self.tokenizer([input_text], padding=True, truncation=True, max_length=512, return_tensors="pt").to("cpu")

        # 모델에 입력하여 대답 생성
        model_output = self.model(**inputs)
        predicted_label = torch.argmax(model_output.logits.to('cpu'), dim=1)
        response_text = " ".join(self.tokenizer.convert_ids_to_tokens(inputs['input_ids'][0][1:-1][predicted_label]))

        print(response_text)

        return response_text


# class ImageAnalyzer:
#     def __init__(self, model_path):
#         self.camera = cv2.VideoCapture(0)
#         self.model_path = model_path
#         if os.path.exists(model_path):
#             self.model = torch.load(model_path, map_location=torch.device('cpu'))
#         else:
#             self.model = None
#         self.tokenizer = AutoTokenizer.from_pretrained("bert-base-uncased")
#         self.tokenizer.max_length = 512  # 추가한 코드

#     def analyze(self):
#         # 카메라 데이터 취득
#         ret, frame = self.camera.read()
#         # 여기서 딥러닝을 사용한 이미지 분석 코드 작성
#
#         return result


# class SensorAnalyzer:
#     def __init__(self, model_path):
#         self.light_api = 'http://example.com/api/light'
#         self.temperature_api = 'http://example.com/api/temperature'
#         self.humidity_api = 'http://example.com/api/humidity'
#         self.touch_api = 'http://example.com/api/touch'
#         self.smell_api = 'http://example.com/api/smell'
#         self.pressure_api = 'http://example.com/api/pressure'
#         self.model_path = model_path
#         if os.path.exists(model_path):
#             self.model = torch.load(model_path, map_location=torch.device('cpu'))
#         else:
#             self.model = None
#         self.tokenizer = AutoTokenizer.from_pretrained("bert-base-uncased")
#         self.tokenizer.max_length = 512  # 추가한 코드
#
#     def analyze(self):
#         # 빛, 온도, 습도, 촉각, 후각, 압력센서 데이터 취득
#         light = requests.get(self.light_api).text
#         temperature = requests.get(self.temperature_api).text
#         humidity = requests.get(self.humidity_api).text
#         touch = requests.get(self.touch_api).text
#         smell = requests.get(self.smell_api).text
#         pressure = requests.get(self.pressure_api).text
#
#         # 여기서 딥러닝을 사용한 센서 데이터 분석 코드 작성
#
#         return result


# class Controller:
#     def __init__(self):
#         GPIO.setmode(GPIO.BCM)
#         GPIO.setup(18, GPIO.OUT)
#
#     def control(self):
#         # 여기서 구동부 제어 코드 작성
#         GPIO.output(18, GPIO.HIGH)


class IntentClassifier:
    def __init__(self, model_path):
        if os.path.exists(model_path):
            self.model = torch.load(model_path, map_location=torch.device('cpu'))
        else:
            self.model = BertForSequenceClassification.from_pretrained("bert-base-uncased", num_labels=4).to("cpu")
        self.model_path = model_path
        self.tokenizer = AutoTokenizer.from_pretrained("bert-base-uncased")
        self.tokenizer.max_length = 512  # 추가한 코드

    def classify_intent(self, input_text):
        # 토큰화
        input_ids = self.tokenizer.encode(input_text, add_special_tokens=True)
        # 패딩
        input_ids = input_ids + [0] * (self.tokenizer.max_length - len(input_ids))
        # 텐서로 변환
        input_tensor = torch.tensor([input_ids])
        # 추론 실행
        model_input = {
            "input_ids": input_tensor,
        }
        outputs = self.model(**model_input)[0]
        # 결과 반환
        _, predicted = torch.max(outputs, dim=1)
        return predicted.item()


class MyAI:
    def __init__(self, chatbot_model_path, image_model_path, sensor_model_path, decision_model_path):
        self.chatbot = Chatbot(chatbot_model_path)
        # self.image_analyzer = ImageAnalyzer(image_model_path)
        # self.sensor_analyzer = SensorAnalyzer(sensor_model_path)
        # self.controller = Controller()
        self.intent_classifier = IntentClassifier(decision_model_path)

    def run(self):
        task = self.chatbot.train_news()
        loop = asyncio.get_event_loop()
        loop.run_until_complete(task)
        while True:
            input_text = input('사용자: ')
            # 입력값에 대한 판단
            intent = self.intent_classifier.classify_intent(input_text)
            print("intent: " + str(intent))

            if intent <= 10:
                response_text = self.chatbot.generate_response(input_text)
                print(response_text)
            # elif intent == 2:
            #     image_result = self.image_analyzer.analyze()
            #     print(image_result)
            # elif intent == 3:
            #     sensor_result = self.sensor_analyzer.analyze()
            #     print(sensor_result)
            # elif intent == 4:
            #     self.controller.control()


if __name__ == '__main__':
    my_ai = MyAI('./chatbot_model.pth', './image_model.pth', './sensor_model.pth', './decision_model.pth')
    my_ai.run()
