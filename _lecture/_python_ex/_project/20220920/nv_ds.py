import json
import pandas
import urllib.request
import time
import datetime


client_id = "KNRIZ2ox9W2azGKpMxo7"
client_secret = "fdnvdipsT5"


def getRequestUrl(url):
    req = urllib.request.Request(url)
    req.add_header("X-Naver-Client-Id", client_id)
    req.add_header("X-Naver-Client-Secret", client_secret)

    try:
        response = urllib.request.urlopen(req)
        print(f"[{datetime.datetime.now()}] rescode : {response.getcode()}")
        if response.getcode() == 200:
            return response.read().decode("utf-8")
    except Exception as e:
        print(f"[{datetime.datetime.now()}] {e}")
        return None


def getNaverSearch(node, srcText, start, display):
    url = f"https://openapi.naver.com/v1/search/{node}?query={urllib.parse.quote(srcText)}&start={start}&display={display}"
    responseDecode = getRequestUrl(url)
    if responseDecode == None:
        return None
    else:
        return json.loads(responseDecode)


def getPostData(post, jsonResult, cnt):
    title = post["title"]
    description = post["description"]
    oriLink = post["originallink"]
    link = post["link"]
    pubDate = datetime.datetime.strptime(post["pubDate"], "%a, %d %b %Y %H:%M:%S +0900").strftime("%Y-%m-%d %H:%M:%S")

    jsonResult.append({"cnt" : cnt, "title" : title, "description" : description, "oriLink" : oriLink, "link" : link, "pubDate" : pubDate})


def main():
    node = "news"  # 데이터 수집 서비스 대상 카테고리
    srcText = input("검색어 입력 : ")
    cnt = 0
    jsonResult = []

    jsonResponse = getNaverSearch(node, srcText, 1, 100)
    total = jsonResponse["total"]
    while (jsonResponse != None) and (jsonResponse["display"] != 0):
        for post in jsonResponse["items"]:
            cnt += 1
            getPostData(post, jsonResult, cnt)

        start = jsonResponse["start"] + jsonResponse["display"]
        jsonResponse = getNaverSearch(node, srcText, start, "100")

    print(f"total : {total}")

    fileName = f"./{node}_{srcText}_naver.json"
    with open(fileName, "w", encoding="utf-8") as f:
        jsonFile = json.dumps(jsonResult, indent=4, sort_keys=True, ensure_ascii=False)
        f.write(jsonFile)


if __name__ == "__main__":
    main()
