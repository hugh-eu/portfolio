import pandas as pd
import folium
import webbrowser
import urllib.request
from bs4 import BeautifulSoup
from selenium import webdriver
import time
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager


def main():
    CB = pd.read_csv("./res/CoffeeBean.csv", encoding="cp949", index_col=0, header=0, engine="python")
    # print(CB.head())

    addr = []
    for address in CB.address:
        addr.append(str(address).split())
    # print(addr)

    addr2 = []
    for i in range(len(addr)):
        if "서울" in addr[i][0]: addr[i][0] = "서울특별시"
        elif "부산" in addr[i][0]: addr[i][0] = "부산광역시"
        elif "대구" in addr[i][0]: addr[i][0] = "대구광역시"
        elif "인천" in addr[i][0]: addr[i][0] = "인천광역시"
        elif "광주" in addr[i][0]: addr[i][0] = "광주광역시"
        elif "대전" in addr[i][0]: addr[i][0] = "대전광역시"
        elif "울산" in addr[i][0]: addr[i][0] = "울산광역시"
        elif "세종" in addr[i][0]: addr[i][0] = "세종특별자치시"
        elif "경기" in addr[i][0]: addr[i][0] = "경기도"
        elif "강원" in addr[i][0]: addr[i][0] = "강원도"
        elif "충북" in addr[i][0]: addr[i][0] = "충청북도"
        elif "충남" in addr[i][0]: addr[i][0] = "충청남도"
        elif "전북" in addr[i][0]: addr[i][0] = "전라북도"
        elif "전남" in addr[i][0]: addr[i][0] = "전라남도"
        elif "경북" in addr[i][0]: addr[i][0] = "경상북도"
        elif "경남" in addr[i][0]: addr[i][0] = "경상남도"
        elif "제주" in addr[i][0]: addr[i][0] = "제주특별자치도"

        addr2.append(" ".join(addr[i]))
    # print(addr2)

    addr2 = pd.DataFrame(addr2, columns=["address2"])

    CB2 = pd.concat([CB, addr2], axis=1)
    # print(CB.head())
    # print(CB2.head())



######################################################################################################################
    # map_osm = folium.Map(location=[37.559984, 126.9753071], zoom_start=16)
    # map_osm.save("./output/map.html")
    # CB2.to_csv("./res/CoffeeBean_2.csv", encoding="cp949", index=False)
    #
    # chrome_options = webdriver.ChromeOptions()
    # driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()), options=chrome_options)
    # driver.implicitly_wait(5)
    # url = f"https://www.google.com/maps/place/{CB2.copy().loc[0, 'address2'].replace(' ', '+')}"
    # driver.get(url)


    CB_geoData = pd.read_csv("./res/CB_geo.shp_2.csv", encoding="cp949", engine="python")
    map_CB = folium.Map(location=[37.560284, 126.975334], zoom_start=16)
    for i, store in CB_geoData.iterrows():
        folium.Marker(location=[store["위도"], store["경도"]], popup=store["store"], icon=folium.Icon(color="red", icon="star")).add_to(map_CB)
    map_CB.save("./output/map_CB.html")
    webbrowser.open("D:/hugh/_python_ex/_project/20220920/output/map_CB.html")



if __name__ == "__main__":
    main()
