from flask import Flask, render_template, Response
import cv2
import numpy as np
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

app = Flask(__name__)

threshold_move = 50
diff_compare = 10
img_first = None
img_second = None
img_third = None


cap = cv2.VideoCapture(-1, cv2.CAP_V4L)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)

ret, img_first = cap.read()
ret, img_second = cap.read()

def gen_frames():
    while True:
        global img_first
        global img_second
        global img_third
        global threshold_move
        global diff_compare

        ret, img_third = cap.read()
        scr = img_third.copy()

        img_first_gray = cv2.cvtColor(img_first, cv2.COLOR_BGR2GRAY)
        img_second_gray = cv2.cvtColor(img_second, cv2.COLOR_BGR2GRAY)
        img_third_gray = cv2.cvtColor(img_third, cv2.COLOR_BGR2GRAY)

        diff_1 = cv2.absdiff(img_first_gray, img_second_gray)
        diff_2 = cv2.absdiff(img_second_gray, img_third_gray)

        ret, diff_1_thres = cv2.threshold(diff_1, threshold_move, 255, cv2.THRESH_BINARY)
        ret, diff_2_thres = cv2.threshold(diff_2, threshold_move, 255, cv2.THRESH_BINARY)

        diff = cv2.bitwise_and(diff_1_thres, diff_2_thres)

        diff_cnt = cv2.countNonZero(diff)
        if diff_cnt > diff_compare:
            nzero = np.nonzero(diff)
            cv2.rectangle(scr, (min(nzero[1]), min(nzero[0])), (max(nzero[1]), max(nzero[0])), (0, 255, 0), 1)
            cv2.putText(scr, "Motion Detected", (10, 10), cv2.FONT_HERSHEY_DUPLEX, 0.3, (0, 255, 0))
            response = requests.post(url, headers=headers, data=data)

        img_first = img_second
        img_second = img_third

        ret, buffer = cv2.imencode(".jpg", scr)
        frame = buffer.tobytes()

        yield (b"--frame\r\n"
               b"Content-Type : image/jpeg\r\n\r\n" + frame + b"\r\n")

@app.route("/cv_motion")
def cv_motion():
    return render_template("cv_motion.html")

@app.route("/video_feed")
def video_feed():
    return Response(gen_frames(), mimetype="multipart/x-mixed-replace; boundary=frame")

if __name__ == "__main__":
    app.run(debug=False, port=80, host="0.0.0.0")
