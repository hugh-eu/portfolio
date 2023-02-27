import cv2

img_file = "./img/rothy.jpg"
img = cv2.imread(img_file)

if img is not None:
    img_resize = cv2.resize(img, (800, 600))
    cv2.imshow("IMG", img_resize)
    cv2.waitKey()
    cv2.destroyAllWindows()
else:
    print("Img not found.")