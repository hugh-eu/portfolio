import cv2

cap = cv2.VideoCapture(0, cv2.CAP_V4L)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)

while True:
    ret, video = cap.read()
    cv2.imshow("video", video)

    key = cv2.waitKey(30) & 0xff
    if key == 27:
        break

cap.release()
cv2.destroyAllWindows()