from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
import urllib.request as req  # 클라이언트가 서버에 데이터 요청, response 받음
import time

def app():
    # 브라우저 드라이버 얻기
    driver = set_chrome_driver()
    driver.implicitly_wait(5)  # 관례적으로 로딩 최대 5초 기다림, 불안정

    # google.com 접속
    driver.get('https://www.google.com')

    # 이미지 검색 이동
    imgBtnEle = driver.find_element(By.CSS_SELECTOR, '#gb > div > div:nth-child(1) > div > div:nth-child(2) > a')  # css selector 방식으로 찾음, 경로
    imgBtnEle.click()  # 클릭

    # 검색
    inputEle = driver.find_element(By.CSS_SELECTOR, 'body form div.a4bIc > input')
    inputEle.send_keys('rothy')
    inputEle.send_keys(Keys.ENTER)

    # 스크롤 끝까지 내리기
    cur_browser_height = driver.execute_script('return document.body.scrollHeight')  # 브라우저의 높이 찾기
    while True:
        driver.execute_script('window.scrollTo(0, document.body.scrollHeight);')
        time.sleep(1)

        temp_browser_height = driver.execute_script('return document.body.scrollHeight')

        if temp_browser_height == cur_browser_height:
            break
        else:
            cur_browser_height = temp_browser_height

    driver.execute_script('window.scrollTo(0, 0);')
    time.sleep(1)

    # 썸네일 이미지 클릭
    imgThumbs = driver.find_elements(By.CLASS_NAME, 'rg_i')  # 클래스명으로 이미지 리스트 찾기
    for idx, imgThumb in enumerate(imgThumbs):
        try:
            imgThumb.click()
            time.sleep(1)

            # 디테일뷰 요소
            imgLarge = driver.find_element(By.CSS_SELECTOR, '#Sva75c > div > div > div.pxAole > div.tvh9oe.BIB1wf > c-wiz > div > div.OUZ5W > div.zjoqD > div.qdnLaf.isv-id.b0vFpe > div > a > img')
            imgAttSrc = imgLarge.get_attribute('src')  # src 속성값 얻기

            # 디테일 이미지 다운로드
            req.urlretrieve(imgAttSrc, f'./imgs/rothy_img_{idx+1}.jpg')  # 이미지 다운로드
        except Exception as e:
            print(f'ERROR: {e}')
            continue


    time.sleep(5)

def set_chrome_driver():  # webdriver 모듈에서 자동으로 크롬 드라이버 가져오기
    chrome_options = webdriver.ChromeOptions()  # 크롬의 여러가지 설정
    driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)

    return driver

if __name__ == '__main__':
    app()
