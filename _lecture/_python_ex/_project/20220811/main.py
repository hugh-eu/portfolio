from bs4 import BeautifulSoup  # 분석
import urllib.request  # 웹페이지 들어가기
from openpyxl import Workbook  # 엑셀
from utils import getTime

def getStoreInfos(storeInfos):
    PAGE_START_NO = 1  # 상수값, 대체로 대문자
    PAGE_END_NO = 53
    BASE_URL = 'https://www.hollys.co.kr/store/korea/korStore2.do?pageNo='

    for pageNo in range(PAGE_START_NO, PAGE_END_NO + 1):
        url = BASE_URL + str(pageNo)
        responseObj = urllib.request.urlopen(url)  # url 데이터 요청, Obj리턴
        parsingData = BeautifulSoup(responseObj, 'html.parser')  # Obj는 html, 파싱해줘
        tag_tbody = parsingData.find('tbody')  # find_all 많을경우 리스트 인덱스로 찾기
        for store in tag_tbody.find_all('tr'):
            tds = store.find_all('td')
            store_sido = tds[0].text  # 태그빼고 텍스트만
            store_name = tds[1].text
            store_status = tds[2].text
            store_address = tds[3].text
            imgs = tds[4].find_all('img')
            alts = []
            for img in imgs:
                alts.append(img['alt'])
            store_services = ','.join(alts)  # ['흡연시설', '주차'] -> '흡연시설,주차'
            store_phone = tds[5].text

            storeInfos.append({'store_sido':store_sido,
                               'store_name':store_name,
                               'store_status':store_status,
                               'store_address':store_address,
                               'store_services':store_services,
                               'store_phone':store_phone})

def app():
    storeInfos = []
    getStoreInfos(storeInfos)
    print(f'storeInfors: {storeInfos}')

    write_wb = Workbook()
    write_ws = write_wb.create_sheet('store_infos')
    write_ws.append(['번호', '지역', '매장명', '현황', '주소', '매장서비스', '전화번호'])

    for idx, info in enumerate(storeInfos):
        write_ws.append([idx+1, info['store_sido'], info['store_name'], info['store_status'], info['store_address'], info['store_services'], info['store_phone']])

    write_wb.save(f'./output/{getTime.getCurrentTime()}_store_infos.xlsx')

if __name__ == '__main__':
    app()
