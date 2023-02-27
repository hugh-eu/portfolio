#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// Mat img;
// Point pt0ld;
// void on_mouse(int event, int x, int y, int flags, void*);

// void on_level_change(int pos, void* userdata);

// String filename = "mydata.json";

// void on_brightness(int pos, void* userdata);

// Mat calcGrayHist(const Mat& img);
// Mat getGrayHistImage(const Mat& hist);

Mat src;
Point2f srcQuad[4], dstQuad[4];
void on_mouse(int event, int x, int y, int flags, void* userdata);

int main(void) {
    
    // Mat img(200, 600, CV_8UC3, Scalar(255, 255, 255));

    // line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
    // line(img, Point(50, 100), Point(200, 100), Scalar(255, 0, 255), 3);
    // line(img, Point(50, 150), Point(200, 150), Scalar(255, 0, 0), 10);

    // line(img, Point(250, 50), Point(350, 100), Scalar(0, 0, 255), 1, LINE_4);
    // line(img, Point(250, 70), Point(350, 120), Scalar(255, 0, 255), 1, LINE_8);
    // line(img, Point(250, 90), Point(350, 140), Scalar(255, 0, 0), 1, LINE_AA);

    // arrowedLine(img, Point(50, 200), Point(150, 200), Scalar(0, 0, 255), 1);
    // arrowedLine(img, Point(50, 250), Point(350, 250), Scalar(255, 0, 255), 1);
    // arrowedLine(img, Point(50, 300), Point(350, 300), Scalar(255, 0, 0), 1, LINE_8, 0, 0.05);

    // drawMarker(img, Point(50, 350), Scalar(0, 0, 255), MARKER_CROSS);
    // drawMarker(img, Point(100, 350), Scalar(0, 0, 255), MARKER_TILTED_CROSS);
    // drawMarker(img, Point(150, 350), Scalar(0, 0, 255), MARKER_STAR);
    // drawMarker(img, Point(200, 350), Scalar(0, 0, 255), MARKER_DIAMOND);
    // drawMarker(img, Point(250, 350), Scalar(0, 0, 255), MARKER_SQUARE);
    // drawMarker(img, Point(300, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_UP);
    // drawMarker(img, Point(350, 350), Scalar(0, 0, 255), MARKER_TRIANGLE_DOWN);

    // rectangle(img, Rect(50, 50, 100, 50), Scalar(0,255,0), 2);

    // vector<Point> pts;
    // pts.push_back(Point(250, 250));
    // pts.push_back(Point(250, 260));
    // pts.push_back(Point(260, 270));
    // pts.push_back(Point(230, 210));
    // pts.push_back(Point(200, 190));

    // polylines(img, pts, true, Scalar(255, 255, 255), 2);

    // putText(img, "FONT_HERSHEY_SIMPLEX", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 0));

    // const String text = "Hello, OpenCV";
    // int fontFace = FONT_HERSHEY_TRIPLEX;
    // double fontScale = 2.0;
    // int thickness = 1;

    // Size sizeText = getTextSize(text, fontFace, fontScale, thickness, 0);
    // Size sizeImg = img.size();

    // Point org((sizeImg.width - sizeText.width) / 2, (sizeImg.height - sizeText.height) / 2);
    // putText(img, text, org, fontFace, fontScale, Scalar(0, 0, 0 , thickness));
    // rectangle(img, org, org + Point(sizeText.width, -sizeText.height), Scalar(255, 0, 0), 1);

    // imshow("img", img);
    // waitKey();

    // destroyAllWindows();

    // Mat img = imread("rothy.jpg");
    // if (img.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }

    // imshow("img", img);

    // while (true) {
    //     int keycode = waitKey();
    //     if (keycode == 'i' || keycode == 'I') {
    //         img = ~img;
    //         imshow("img", img);
    //     }
    //     else if (keycode == 27 || keycode == 'q' || keycode == 'Q') {
    //         break;
    //     }
    // }

    // img = imread("rothy.jpg");
    // if (img.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }

    // namedWindow("img");
    // setMouseCallback("img", on_mouse);
    // imshow("img", img);
    // waitKey();

    // Mat img = Mat::zeros(400, 400, CV_8UC1);

    // namedWindow("image");
    // createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);

    // imshow("image", img);
    // waitKey();

    // String name = "Jane";
    // int age = 10;
    // Point pt1(100, 200);
    // vector<int> scores = {80, 90, 50};
    // Mat mat1 = (Mat_<float>(2, 2) << 1.0f, 1.5f, 2.0f, 3.2f);

    // FileStorage fs(filename, FileStorage::WRITE);

    // if (!fs.isOpened()) {
    //     cerr << "File open failed!" << endl;
    //     return -1;
    // }

    // fs << "name" << name;
    // fs << "age" << age;
    // fs << "point" << pt1;
    // fs << "scores" << scores;
    // fs << "data" << mat1;

    // fs.release();

    // String name;
    // int age;
    // Point pt1;
    // vector<int> scores;
    // Mat mat1;

    // FileStorage fs(filename, FileStorage::READ);

    // if (!fs.isOpened()) {
    //     cerr << "File open failed!" << endl;
    //     return -1;
    // }

    // fs["name"] >> name;
    // fs["age"] >> age;
    // fs["point"] >> pt1;
    // fs["scores"] >> scores;
    // fs["data"] >> mat1;

    // fs.release();

    // cout << name << endl;
    // cout << age << endl;
    // cout << pt1 << endl;
    // cout << Mat(scores).t() << endl;
    // cout << mat1 << endl;

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // Mat mask = imread("rothy.jpg", IMREAD_GRAYSCALE);

    // if (src.empty() || mask.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }

    // src.setTo(Scalar(0, 255, 255), mask);

    // imshow("src", src);
    // imshow("mask", mask);

    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()){
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }

    // Mat dst(src.rows, src.cols, src.type());

    // TickMeter tm;
    // tm.start();

    // for (int j = 0; j< src.rows; j++) {
    //     for (int i = 0; i < src.cols; i++) {
    //         dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
    //     }
    // }

    // tm.stop();
    // cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;

    // Mat img = imread("rothy.jpg", IMREAD_GRAYSCALE);

    // cout << (int)sum(img)[0] << endl;
    // cout << (int)mean(img)[0] << endl;

    // double minVal, maxVal;
    // Point minPos, maxPos;
    // minMaxLoc(img, &minVal, &maxVal, &minPos, &maxPos);

    // cout << minVal << minPos << endl;
    // cout << maxVal << maxPos << endl;

    // Mat src = Mat_<float>({1, 5}, {-1.f, -0.5f, 0.f, 0.5f, 1.f});
    // Mat dst;
    // normalize(src, dst, 0, 255, NORM_MINMAX, CV_8UC1);
    // cout << src << endl;
    // cout << dst << endl;
    // cout << cvRound(2.5)<< endl;

    // Mat img3 = imread("rothy.jpg", IMREAD_COLOR);
    // Mat img4;
    // cvtColor(img3, img4, COLOR_BGR2GRAY);

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()){
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Mat dst = src - 100;
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Mat dst(src.rows, src.cols, src.type());
    // for (int j = 0; j < src.rows; j++) {
    //     for (int i = 0; i < src.cols; i++) {
    //         // int v = src.at<uchar>(j, i) + 100;
    //         // dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
    //         dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100);
    //     }
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // namedWindow("dst");
    // createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
    // on_brightness(0, (void*)&src);
    // waitKey();
    // destroyAllWindows();
    // return 0;

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // float s = 2.f;
    // Mat dst = s * src;

    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // float alpha = 0.1f;
    // Mat dst = src + (src - 128) * alpha;
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat img = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (img.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Mat imgHist = getGrayHistImage(calcGrayHist(img));
    // imshow("img", img);
    // imshow("imgHist", imgHist);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // src = src + 100;
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // double gmin, gmax;
    // minMaxLoc(src, &gmin, &gmax);
    // Mat dst = (src - gmin) * 255 / (gmax - gmin);

    // imshow("src", src);
    // imshow("srcHist", getGrayHistImage(calcGrayHist(src)));
    // imshow("dst", dst);
    // imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    // waitKey();
    // destroyAllWindows();

    // return 0;

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // src = src + 50;

    // Mat dst;
    // equalizeHist(src, dst);
    // imshow("src", src);
    // imshow("srcHist", getGrayHistImage(calcGrayHist(src)));

    // imshow("dst", dst);
    // imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));

    // waitKey();
    // destroyAllWindows();

    // Mat src1 = imread("rothy.jpg", IMREAD_COLOR);
    // Mat src2 = imread("background.jpg", IMREAD_COLOR);

    // Mat dst;
    // dst = src1 - src2;
    // addWeighted(src1, 0.5, src2, 0.5, 0, dst);
    // subtract(src1, src2, dst);
    // absdiff(src1, src2, dst);
    // bitwise_and(src1, src2, dst);
    // bitwise_or(src1, src2, dst);
    // bitwise_xor(src1, src2, dst);
    // bitwise_not(src1, dst);

    // imshow("src1", src1);
    // imshow("src2", src2);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }

    // float data1[] = {-1, -1, 0, -1, 0, 1, 0, 1, 1};
    // float data2[] = {1, 1, 0, 1, 0, -1, 0, -1, -1};
    // Mat emboss1(3, 3, CV_32FC1, data1);
    // Mat emboss2(3, 3, CV_32FC1, data2);
    // Mat dst1, dst2, dst3;
    // filter2D(src, dst1, -1, emboss1, Point(-1, -1), 128);
    // filter2D(src, dst2, -1, emboss2, Point(-1, -1), 128);
    // absdiff(dst1, dst2, dst3);
    // imshow("src", src);
    // imshow("dst1", dst1);
    // imshow("dst2", dst2);
    // imshow("dst3", dst3);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // imshow("src", src);

    // Mat dst;
    // for (int ksize = 3; ksize <= 7; ksize +=2){
    //     blur(src, dst, Size(ksize, ksize));
    //     String desc = format("Mean : %dx%d", ksize, ksize);
    //     putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    //     imshow("dst", dst);
    //     waitKey();
    // }
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // Mat dst;
    // for (int sigma = 1; sigma <=5; sigma++){
    //     GaussianBlur(src, dst, Size(), (double)sigma);
    //     String text = format("sigma = %d", sigma);
    //     putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    //     imshow("dst", dst);
    //     waitKey();
    // }
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // for (int sigma = 1; sigma <= 5; sigma++){
    //     Mat blurred;
    //     GaussianBlur(src, blurred, Size(), sigma);
    //     float alpha = 1.f;
    //     Mat dst = (1 + alpha) * src - alpha * blurred;

    //     String desc = format("sigma : %d", sigma);
    //     putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    //     imshow("dst", dst);
    //     waitKey();
    // }
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // for (int stddev = 10; stddev <= 30; stddev += 10) {
    //     Mat noise(src.size(), CV_32SC1);
    //     randn(noise, 0, stddev);

    //     Mat dst;
    //     add(src, noise, dst, Mat(), CV_8U);

    //     String desc = format("stddev = %d", stddev);
    //     putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
    //     imshow("dst", dst);
    //     waitKey();
    // }
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }

    // Mat noise(src.size(), CV_32SC1);
    // randn(noise, 0, 5);
    // add(src, noise, src, Mat(), CV_8U);

    // Mat dst1;
    // GaussianBlur(src, dst1, Size(), 5);

    // Mat dst2;
    // bilateralFilter(src, dst2, -1, 10, 5);

    // imshow("src", src);
    // imshow("dst1", dst1);
    // imshow("dst2", dst2);

    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // int num = (int)(src.total() * 0.1);
    // for(int i = 0; i < num; i++){
    //     int x = rand() % src.cols;
    //     int y = rand() % src.rows;
    //     src.at<uchar>(y, x) = (i % 2) * 255;
    // }
    // Mat dst1;
    // GaussianBlur(src, dst1, Size(), 1);
    // Mat dst2;
    // medianBlur(src, dst2, 3);
    // imshow("src", src);
    // imshow("dst1", dst1);
    // imshow("dst2", dst2);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Point2f srcPts[3], dstPts[3];
    // srcPts[0] = Point2f(0, 0);
    // srcPts[1] = Point2f(src.cols - 1, 0);
    // srcPts[2] = Point2f(src.cols - 1, src.rows - 1);
    // dstPts[0] = Point2f(50, 50);
    // dstPts[1] = Point2f(src.cols - 100, 100);
    // dstPts[2] = Point2f(src.cols - 50, src.rows - 50);
    // Mat M = getAffineTransform(srcPts, dstPts);
    // Mat dst;
    // warpAffine(src, dst, M, Size());
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Mat M = Mat_<double>({2, 3}, {1, 0, 150, 0, 1, 100});

    // Mat dst;
    // warpAffine(src, dst, M, Size());
    // imshow("src", src);
    // imshow("dst", dst);
    
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // double mx = 0.3;
    // Mat M = Mat_<double>({2, 3}, {1, mx, 0, 0, 1, 0});
    // Mat dst;
    // warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Mat dst1, dst2, dst3, dst4;
    // resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
    // resize(src, dst2, Size(1920, 1280));
    // resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
    // resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

    // imshow("src", src);
    // imshow("dst1", dst1(Rect(400, 500, 400, 400)));
    // imshow("dst2", dst2(Rect(400, 500, 400, 400)));
    // imshow("dst3", dst3(Rect(400, 500, 400, 400)));
    // imshow("dst4", dst4(Rect(400, 500, 400, 400)));

    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // Point2f cp(src.cols / 2.f, src.rows / 2.f);
    // Mat M = getRotationMatrix2D(cp, -20, 1);
    // Mat dst;
    // warpAffine(src, dst, M, Size());
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed." << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // Mat dst;
    // int flipCode[] = {1, 0, -1};
    // for (int i = 0; i < 3; i++){
    //     flip(src, dst, flipCode[i]);
    //     String desc = format("flipCode: %d", flipCode[i]);
    //     putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0), 1, LINE_AA);
    //     imshow("dst", dst);
    //     waitKey(0);
    // }
    // destroyAllWindows();

    src = imread("rothy.jpg");
    if (src.empty()) {
        cerr << "Image load failed." << endl;
        return -1;
    }
    namedWindow("src");
    setMouseCallback("src", on_mouse);
    imshow("src", src);
    waitKey();
    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*){
    static int cnt = 0;
    if (event == EVENT_LBUTTONDOWN) {
        if (cnt < 4){
            srcQuad[cnt++] = Point2f(x, y);
            circle(src, Point(x, y), 1, Scalar(0, 0, 255), -1);
            imshow("src", src);
            if (cnt == 4){
                int w = 200, h = 300;
                dstQuad[0] = Point2f(0, 0);
                dstQuad[1] = Point2f(w - 1, 0);
                dstQuad[2] = Point2f(w - 1, h - 1);
                dstQuad[3] = Point2f(0, h - 1);
                Mat pers = getPerspectiveTransform(srcQuad, dstQuad);
                Mat dst;
                warpPerspective(src, dst, pers, Size(w, h));
                imshow("dst", dst);
            }
        }
    }


}


// Mat calcGrayHist(const Mat& img){
//     CV_Assert(img.type() == CV_8UC1);
//     Mat hist;
//     int channels[] = {0};
//     int dims = 1;
//     const int histSize[] = {256};
//     float graylevel[] = {0, 256};
//     const float* ranges[] = {graylevel};
//     calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);
//     return hist;

// }

// Mat getGrayHistImage(const Mat& hist){
//     CV_Assert(hist.type() == CV_32FC1);
//     CV_Assert(hist.size() == Size(1, 256));

//     double histMax;
//     minMaxLoc(hist, 0, &histMax);

//     Mat imgHist(100, 256, CV_8UC1, Scalar(255));
//     for (int i = 0; i < 256; i++) {
//         line(imgHist, Point(i, 100), Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100/histMax)), Scalar(0));
//     }
//     return imgHist;

// }



// void on_brightness(int pos, void* userdata) {
//     Mat src = *(Mat*)userdata;
//     Mat dst = src + pos;
//     imshow("dst", dst);
// }


// void on_mouse(int event, int x, int y, int flags, void*){
//     switch(event){
//     case EVENT_LBUTTONDOWN:
//         pt0ld = Point(x, y);
//         cout << "EVENT_LBUTTONDOWN : " << x << ", " << y << endl;
//         break;
//     case EVENT_LBUTTONUP:
//         cout << "EVENT_LBUTTONUP : " << x << ", " << y << endl;
//         break;
//     case EVENT_MOUSEMOVE:
//         if (flags & EVENT_FLAG_LBUTTON) {
//             line(img, pt0ld, Point(x, y), Scalar(0, 0, 0), 2);
//             imshow("img", img);
//             pt0ld = Point(x, y);
//         }
//         break;
//     default:
//         break;
//     }
// }

// void on_level_change(int pos, void* userdata){
//     Mat img = *(Mat*)userdata;
//     img.setTo(pos * 16);
//     imshow("image", img);
// }