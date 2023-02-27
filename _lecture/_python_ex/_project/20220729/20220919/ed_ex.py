import json
import urllib.request
import datetime
import pandas as pd
import time

def getRequestUrl(url):
    req = urllib.request.Request(url)  # Request 객체
    try:
        response = urllib.request.urlopen(req)  # html 요청
        if response.getcode() == 200:
            print(f"[{datetime.datetime.now()}] URL Request Success")
            return response.read().decode("utf-8")  # json str 반환
    except Exception as e:
        print(e)
        print(f"[{datetime.datetime.now()}] Error for URL : {url}")
        return None


def getTourismStatsItem(yyyymm, nat_cd, ed_cd):
    url = "http://openapi.tour.go.kr/openapi/service/EdrcntTourismStatsService/getEdrcntTourismStatsList?"
    url += "_type=json"
    url += "&YM=" + yyyymm
    url += "&NAT_CD=" + nat_cd
    url += "&ED_CD=" + ed_cd
    url += "&serviceKey=" + "PIVwmt8aN6GBHVgPvAsjE%2Fr8puRxdxf8V%2Bg68L5pNTPcREoI4aiP68%2FiZy2AS4ei9YufV2GDH1BAgNyYEsEfhQ%3D%3D"

    reqData = getRequestUrl(url)  # json str

    if reqData == None:
        return None
    else:
        return json.loads(reqData)  # python dict 반환


def getTourismStatsService(nat_cd, ed_cd, nStartYear, nEndYear):
    jsonResult = []
    result = []
    natName = ""
    dataEnd = f"{nEndYear}{12}"
    isDataEnd = 0

    for year in range(nStartYear, nEndYear + 1):
        for month in range(1, 13):
            if isDataEnd == 1:
                break
            yyyymm = f"{year}{('0' + str(month)) if (month < 10) else str(month)}"
            jsonData = getTourismStatsItem(yyyymm, nat_cd, ed_cd)  # python dict
            if jsonData["response"]["header"]["resultMsg"] == "OK":
                if jsonData["response"]["body"]["items"] == "":
                    isDataEnd = 1
                    dataEnd = f"{year}{('0' + str(month - 1)) if ((month - 1) < 10) else (month - 1)}"
                    print(f"{year}년 {month}월 데이터 없음. 마지막 데이터 : {year}년 {month - 1}월")
                    break
                print(json.dumps(jsonData, indent=4, sort_keys=True, ensure_ascii=False))  # json str 확인 출력, indent= 들여쓰기, sort_key= 키로 정렬, ensure_ascii= 아스키인코딩 여부
                natName = jsonData["response"]["body"]["items"]["item"]["natKorNm"].replace(" ", "")
                num = jsonData["response"]["body"]["items"]["item"]["num"]
                ed = jsonData["response"]["body"]["items"]["item"]["ed"]
                print(f"[{natName}_{yyyymm} : {num}]")
                print("-------------------------------------------------------------------")
                jsonResult.append({"natName" : natName, "nat_cd" : nat_cd, "yyyymm" : yyyymm, "visit_cnt" : num})
                result.append([natName, nat_cd, yyyymm, num])

    return jsonResult, result, natName, ed, dataEnd



def main():
    jsonResult = []
    result = []
    natName = ""
    print("--- 외국인 통계 ---")
    nat_cd = input("국가 코드 : ")
    nStartYear = int(input("시작 연도 : "))
    nEndYear = int(input("종료 연도 : "))
    ed_cd = "E"
    jsonResult, result, natName, ed, dataEnd = getTourismStatsService(nat_cd, ed_cd, nStartYear, nEndYear)

    if natName == "":
        print("데이터 오류. 공공데이터포털 서비스 상태 확인")
    else:
        with open(f"./{natName}_{ed}_{nStartYear}_{dataEnd}.json", "w", encoding="utf8") as outfile:
            jsonFile = json.dumps(jsonResult, indent=4, sort_keys=True, ensure_ascii=False)
            outfile.write(jsonFile)
        result_df = pd.DataFrame(result, columns=["국가명", "국가코드", "입국연월", "입국자 수"])
        result_df.to_csv(f"./{natName}_{ed}_{nStartYear}_{dataEnd}.csv", index=False, encoding="cp949")

if __name__=="__main__":
    main()
