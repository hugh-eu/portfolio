import json
import requests

url = "https://kapi.kakao.com/v2/api/talk/memo/default/send"

headers = {
    "Content_type":"application/x-www-form-urlencoded",
    "Authorization":"Bearer " + "rxASn7JhQvJ7YCcAk8j0A0HrMbu5PjMJ_SWGOlm3CisMpgAAAYSIvkS_"

}

data = {
    "template_object":json.dumps({
        "object_type":"text", 
        "text":"침입 감지",
        "link": {
            "web_url":"http://www.hugh.co.kr"
        },
    })
}

response = requests.post(url, headers=headers, data=data)
print(response.status_code)
if response.json().get("result_code") == 0:
    print("MSG sended.")
else:
    print("failed : " + str(response.json()))