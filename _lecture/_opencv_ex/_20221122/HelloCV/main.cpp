#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// int main() {
//     cout << "Hello OpenCV" << CV_VERSION << endl;

//     // Mat img1 = imread("rothy.png");
//     // if (img1.empty()/*|| img2.empty() || img3.empty()*/) {
//     //     cerr << "Image load failed!" << endl;
//     //     return -1;
//     // }

//     // Mat img(Size(640, 480), CV_8UC1, Scalar(128));
//     // Mat img(Size(640, 480), CV_8UC3, Scalar(0, 255, 0));
//     // Mat img2 = img1;
//     // Mat img3 = img1.clone();
//     // img1.setTo(Scalar(0, 255, 255));
//     // Mat img4 = img1(Rect(200, 150, 200, 200));
//     // Mat img4 = img1(Rect(200, 200, 200, 200)).clone();
//     // img4 = ~img4;
//     // Mat img5 = img1.clone();
//     // for (int j = 0; j < img1.rows; j++) {
//     //     Vec3b* p1 = img1.ptr<Vec3b>(j);
//     //     Vec3b* p5 = img5.ptr<Vec3b>(j);
//     //     for (int i = 0; i < img1.cols; i++) {
//     //         for (int k = 0; k < 3; k++){
//     //             p5[i][k] = p1[i][k]-100;
//     //         }
//     //     }
//     // }

//     // cout << "Width : " << img1.cols << endl;
//     // cout << "Height : " << img1.rows << endl;
//     // cout << "channels : "  << img1.channels() << endl;
//     // cout << "type : "  << img1.type() << endl;
//     // img1.convertTo(img1, CV_32FC1);
//     // cout << "type : "  << img1.type() << endl;

//     // Mat img6 = img1.clone().t();

//     // Mat img7 = img1.reshape(0, 100);

//     // imshow("image1", img1);
//     // imshow("image2", img2);
//     // imshow("image3", img3);
//     // imshow("image4", img4);
//     // imshow("image5", img5);
//     // imshow("image6", img6);
//     // imshow("image7", img7);


//     // VideoCapture cap(0);
//     // if (!cap.isOpened()) {
//     //     cerr << "Camera open failed!" << endl;
//     //     return -1;
//     // }

//     // Mat frame, inversed;
//     // while (true){
//     //     cap >> frame;
//     //     if (frame.empty()) break;
//     //     inversed = ~frame;
//     //     imshow("frame", frame);
//     //     imshow("inversed", inversed);
//     //     if (waitKey(10) == 27)
//     //         break;
//     // }

//     // VideoCapture cap("wolf.mp4");

//     // if (!cap.isOpened()) {
//     //     cerr << "Video open failed!" << endl;
//     //     return -1;
//     // }

//     // cout << "width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
//     // cout << "height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
//     // cout << "count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

//     // double fps = cap.get(CAP_PROP_FPS);
//     // cout << "FPS : " << fps << endl;
    
//     // int delay = cvRound(1000 / fps);

//     // Mat frame, inversed;
//     // while (true){
//     //     cap >> frame;
//     //     if (frame.empty()) break;
//     //     inversed = ~frame;
//     //     imshow("frame", frame);
//     //     imshow("inversed", inversed);
//     //     if (waitKey(delay) == 27) {
//     //         break;
//     //     }
//     // }

//     VideoCapture cap(0);

//     if (!cap.isOpened()) {
//         cerr << "Camera open failed!" << endl;
//         return -1;
//     }

//     int width = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
//     int height = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
//     double fps = cap.get(CAP_PROP_FPS);
    
//     int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
//     int delay = cvRound(1000 / fps);

//     VideoWriter outputVideo("output.avi", fourcc, fps, Size(width, height));

//     if (!outputVideo.isOpened()) {
//         cout << "File open failed!" << endl;
//         return -1;
//     }

//     Mat frame, inversed;
//     while (true){
//         cap >> frame;
//         if (frame.empty()) break;
//         inversed = ~frame;
//         outputVideo << inversed;
//         imshow("frame", frame);
//         imshow("inversed", inversed);
//         if (waitKey(delay) == 27) {
//             break;
//         }
//     }


//     destroyAllWindows();
//     return 0;

// }