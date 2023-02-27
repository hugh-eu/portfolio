### 데이터 구조, 전송, text, xml, html, json
#["홍", "hong@gmail.com", "70kg", "175cm"]
# text:
# 홍//hong@gmail.com//70//175
#
# html5:
# <p>name</p>
# <p>홍</p>
# <p>mail</p>
# <p>hong@gmail.com</p>
# <p>weight</p>
# <p>70</p>
# <p>height</p>
# <p>175</p>
#
# xml:
# <name>홍</name>
# <mail>hong@gmail.com</mail>
# <weight>70</weight>
# <height>175</height
#
# json:  # 좋지만, 용량이 커지면 속도가 느려짐, 쪼개받기
# {
#     "school" : "mirae",
#     "students" : [{
#                   "no" : 1,
#                   "name" : "홍",
#                   "mail" : "hong@gmail.com",
#                   "weight" : 70,
#                   "height" : 175,
#                   },
#                   {
#                   "no" : 2,
#                   "name" : "김",
#                   "mail" : "kim@gmail.com",
#                   "weight" : 55,
#                   "height" : 158,
#                   }
#                  ]
# }

### json ex,
# import json
#
# def printLog(data_name, data):
#     print(f"# {data_name} :\n{data}\n")

## json to python
# json_string =\
# '''{
#     "students": [
#         {
#         "no" : "0001",
#         "name" : "길동",
#         "email" : "gildong@gmail.com",
#         "address" :
#             {
#             "시" : "서울",
#             "구" : "서초",
#             "동" : "개포"
#             },
#         "admin" : false,
#         "hobbies" : ["축구", "야구", "골프"]
#         },
#         {
#         "no" : "0002",
#         "name" : "길서",
#         "email" : "gilseo@gmail.com",
#         "address" :
#             {
#             "시" : "서울",
#             "구" : "노원",
#             "동" : "동문"
#             },
#         "admin" : true,
#         "hobbies" : ["테니스"]
#         }
#     ]
# }'''
#
# json_obj = json.loads(json_string)
# printLog("json_obj", json_obj)
# printLog("type(json_obj)", type(json_obj))
# printLog('json_obj["students"][0]["name"]', json_obj["students"][0]["name"])
# printLog('json_obj["students"][0]["email"]', json_obj["students"][0]["email"])
# printLog('json_obj["students"][0]["hobbies"]', json_obj["students"][0]["hobbies"])

## python to json
# python_dic =\
# {"students": [
#         {
#         "no" : "0001",
#         "name" : "길동",
#         "email" : "gildong@gmail.com",
#         "address" :
#             {
#             "시" : "서울",
#             "구" : "서초",
#             "동" : "개포"
#             },
#         "admin" : False,
#         "hobbies" : ["축구", "야구", "골프"]
#         },
#         {
#         "no" : "0002",
#         "name" : "길서",
#         "email" : "gilseo@gmail.com",
#         "address" :
#             {
#             "시" : "서울",
#             "구" : "노원",
#             "동" : "동문"
#             },
#         "admin" : True,
#         "hobbies" : None
#         }
#     ]
# }
# json_str = json.dumps(python_dic, ensure_ascii=False)
# printLog("json_str", json_str)
# printLog("type(json_str)", type(json_str))

