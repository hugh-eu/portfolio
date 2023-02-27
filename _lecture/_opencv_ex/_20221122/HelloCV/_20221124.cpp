#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

// int lower_hue = 40, upper_hue = 80;
// Mat src, src_hsv, mask;
// void on_hue_changed(int, void*);

// void on_threshold(int pos, void* userdata);

// void on_trackbar(int pos, void* userdata);

// void setLabel(Mat& img, const vector<Point>& pts, const String& label) {
//     Rect rc = boundingRect(pts);
//     rectangle(img, rc, Scalar(0, 0, 255), 1);
//     putText(img, label, rc.tl(), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, 255));
// }

int main(/*int argc, char* argv[]*/){

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat dx, dy;
    // Sobel(src, dx, CV_32FC1, 1, 0);
    // Sobel(src, dy, CV_32FC1, 0, 1);
    // Mat fmag, mag;
    // magnitude(dx, dy, fmag);
    // fmag.convertTo(mag, CV_8UC1);
    // Mat edge = mag > 150;
    // imshow("src", src);
    // imshow("mag", mag);
    // imshow("edge", edge);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat dst1, dst2;
    // Canny(src, dst1, 50, 100);
    // Canny(src, dst2, 50, 150);
    // imshow("src", src);
    // imshow("dst1", dst1);
    // imshow("dst2", dst2);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat edge;
    // Canny(src, edge, 50, 150);
    // vector<Vec2f> lines;
    // HoughLines(edge, lines, 1, CV_PI / 180, 150);
    // Mat dst;
    // cvtColor(edge, dst, COLOR_GRAY2BGR);
    // for (size_t i = 0; i < lines.size(); i++) {
    //     float r = lines[i][0], t = lines[i][1];
    //     double cos_t = cos(t), sin_t = sin(t);
    //     double x0 = r * cos_t, y0 = r * sin_t;
    //     double alpha = 1000;
    //     Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
    //     Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
    //     line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat edge;
    // Canny(src, edge, 50, 150);
    // vector<Vec4i> lines;
    // HoughLinesP(edge, lines, 1, CV_PI / 180, 160, 50, 5);
    // Mat dst;
    // cvtColor(edge, dst, COLOR_GRAY2BGR);
    // for (Vec4i l : lines) {
    //     line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 2, LINE_AA);
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat blurred;
    // blur(src, blurred, Size(3, 3));
    // vector<Vec3f> circles;
    // HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);
    // Mat dst;
    // cvtColor(src, dst, COLOR_GRAY2BGR);
    // for (Vec3f c : circles) {
    //     Point center(cvRound(c[0]), cvRound(c[1]));
    //     int radius = cvRound(c[2]);
    //     circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat dst(src.rows, src.cols, src.type());
    // for (int j = 0; j < src.rows; j++) {
    //     for (int i = 0; i < src.cols; i++) {
    //         // Vec3b& p1 = src.at<Vec3b>(j, i);
    //         // Vec3b& p2 = dst.at<Vec3b>(j, i);
    //         // p2[0] = 255 - p1[0];
    //         // p2[1] = 255 - p1[1];
    //         // p2[2] = 255 - p1[2];
    //         dst.at<Vec3b>(j, i) = Vec3b(255, 255, 255) - src.at<Vec3b>(j, i);
    //     }
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat dst;
    // vector<Mat> bgr_planes;
    // split(src, bgr_planes);
    // merge(bgr_planes, dst);
    // imshow("src", src);
    // imshow("b", bgr_planes[0]);
    // imshow("g", bgr_planes[1]);
    // imshow("r", bgr_planes[2]);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat src_ycrcb;
    // cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);
    // vector<Mat> ycrcb_planes;
    // split(src_ycrcb, ycrcb_planes);
    // equalizeHist(ycrcb_planes[0], ycrcb_planes[0]);
    // Mat dst_ycrcb;
    // merge(ycrcb_planes, dst_ycrcb);
    // Mat dst;
    // cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR);
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // cvtColor(src, src_hsv, COLOR_BGR2HSV);
    // imshow("src", src);
    // namedWindow("mask");
    // createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
    // createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
    // on_hue_changed(0, 0);
    // waitKey();

    // Mat ref, ref_ycrcb, mask;
    // ref = imread("ref.png", IMREAD_COLOR);
    // mask = imread("mask.bmp", IMREAD_GRAYSCALE);
    // cvtColor(ref, ref_ycrcb, COLOR_BGR2YCrCb);
    // Mat hist;
    // int channels[] = {1, 2};
    // int cr_bins = 128; int cb_bins = 128;
    // int histSize[] = {cr_bins, cb_bins};
    // float cr_range[] = {0, 256};
    // float cb_range[] = {0, 256};
    // const float* ranges[] = {cr_range, cb_range};
    // calcHist(&ref_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);
    // Mat src, src_ycrcb;
    // src = imread("kids.png", IMREAD_COLOR);
    // cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);
    // Mat backproj;
    // calcBackProject(&src_ycrcb, 1, channels, hist, backproj, ranges, 1, true);
    // imshow("src", src);
    // imshow("backproj", backproj);
    // waitKey();

    // Mat src;
    // if(argc < 2){
    //     src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // } else {
    //     src = imread(argv[1], IMREAD_GRAYSCALE);
    // }
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // namedWindow("dst");
    // createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
    // setTrackbarPos("Threshold", "dst", 128);
    // waitKey();

    // Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()){
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // imshow("src", src);
    // namedWindow("dst");
    // createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
    // setTrackbarPos("Block Size", "dst", 11);
    // waitKey();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat bin;
    // threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // Mat dst1, dst2;
    // erode(bin, dst1, Mat());
    // dilate(bin, dst2, Mat());
    // imshow("src", src);
    // imshow("bin", bin);
    // imshow("erode", dst1);
    // imshow("dilate", dst2);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat bin;
    // threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // Mat dst1, dst2;
    // morphologyEx(bin, dst1, MORPH_OPEN, Mat());
    // morphologyEx(bin, dst2, MORPH_CLOSE, Mat());
    // imshow("src", src);
    // imshow("bin", bin);
    // imshow("opening", dst1);
    // imshow("closing", dst2);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("keyboard.bmp", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat bin;
    // threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // Mat labels, stats, centroids;
    // int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
    // Mat dst;
    // cvtColor(src, dst, COLOR_GRAY2BGR);
    // for (int i = 0; i < cnt; i++) {
    //     int* p = stats.ptr<int>(i);
    //     if(p[4] < 20) continue;
    //     rectangle(dst, Rect(p[0], p[1], p[2], p[3]), Scalar(0, 255, 255), 2);
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if(src.empty()){
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // threshold(src, src, 0, 255, THRESH_BINARY | THRESH_OTSU);
    // vector<vector<Point>> contours;
    // findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);
    // Mat dst;
    // cvtColor(src, dst, COLOR_GRAY2BGR);
    // for (int i = 0; i < contours.size(); i++) {
    //     Scalar c(rand() & 255, rand() & 255, rand() & 255);
    //     drawContours(dst, contours, i, c, 1);
    // }
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat img = imread("polygon.bmp", IMREAD_COLOR);
    // if(img.empty()){
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Mat gray;
    // cvtColor(img, gray, COLOR_BGR2GRAY);
    // Mat bin;
    // threshold(gray, bin, 200, 255, THRESH_BINARY_INV | THRESH_OTSU);
    // vector<vector<Point>> contours;
    // findContours(bin, contours, RETR_EXTERNAL, CHAIN_APPROX_NONE);
    // for(vector<Point>& pts : contours){
    //     if (contourArea(pts) < 400){
    //         continue;
    //     }
    //     vector<Point> approx;
    //     approxPolyDP(pts, approx, arcLength(pts, true)*0.02, true);
    //     int vtc = (int)approx.size();
    //     if(vtc == 3){
    //         setLabel(img, pts, "TRI");
    //     } else if (vtc == 4) {
    //         setLabel(img, pts, "RECT");
    //     } else if (vtc > 4) {
    //         double len = arcLength(pts, true);
    //         double area = contourArea(pts);
    //         double ratio = 4. * CV_PI * area / (len * len);
    //         if (ratio > 0.8){
    //             setLabel(img, pts, "CIR");
    //         }
    //     }
    // }
    // imshow("img", img);
    // waitKey();

    // Mat src = imread("rothy.jpg", IMREAD_COLOR);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // CascadeClassifier face_classifier("haarcascade_frontalface_default.xml");
    // CascadeClassifier eye_classifier("haarcascade_eye.xml");
    // if (face_classifier.empty() || eye_classifier.empty()) {
    //     cerr << "XML load failed!" << endl;
    //     return -1;
    // }
    // vector<Rect> faces;
    // face_classifier.detectMultiScale(src, faces);
    // for (Rect face : faces) {
    //     rectangle(src, face, Scalar(255, 0, 255), 2);
    //     Mat faceROI = src(face);
    //     vector<Rect> eyes;
    //     eye_classifier.detectMultiScale(faceROI, eyes);
    //     for (Rect eye : eyes){
    //         Point center(eye.x + eye.width / 2, eye.y + eye.height / 2);
    //         circle(faceROI, center, eye.width / 2, Scalar(255, 0, 0), 2, LINE_AA);
    //     }
    // }
    // imshow("src", src);
    // waitKey();
    // destroyAllWindows();

    // VideoCapture cap("vtest.avi");
    // if (!cap.isOpened()){
    //     cerr << "Video open failed!" << endl;
    //     return -1;
    // }
    // HOGDescriptor hog;
    // hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    // Mat frame;
    // while(true){
    //     cap >> frame;
    //     if (frame.empty()){
    //         break;
    //     }
    //     vector<Rect> detected;
    //     hog.detectMultiScale(frame, detected);
    //     for (Rect r : detected) {
    //         Scalar c = Scalar(rand() % 256, rand() % 256, rand() % 256);
    //         rectangle(frame, r, c, 1);
    //     }
    //     imshow("frame", frame);
    //     if (waitKey(10) == 27) {
    //         break;
    //     }
    // }

    // Mat src = imread("rothy.jpg", IMREAD_GRAYSCALE);
    // if (src.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Ptr<Feature2D> feature = ORB::create();
    // vector<KeyPoint> keypoints;
    // feature->detect(src, keypoints);
    // Mat desc;
    // feature->compute(src, keypoints, desc);
    // cout << "keypoints.size() : " << keypoints.size() << endl;
    // cout << "desc.size() : " << desc.size() << endl;
    // Mat dst;
    // drawKeypoints(src, keypoints, dst, Scalar::all(-1), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    // imshow("src", src);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
    // Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);
    // if(src1.empty() || src2.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Ptr<Feature2D> feature = ORB::create();
    // vector<KeyPoint> keypoints1, keypoints2;
    // Mat desc1, desc2;
    // feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
    // feature->detectAndCompute(src2, Mat(), keypoints2, desc2);
    // Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
    // vector<DMatch> matches;
    // matcher->match(desc1, desc2, matches);
    // std::sort(matches.begin(), matches.end());
    // vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);
    // Mat dst;
    // drawMatches(src1, keypoints1, src2, keypoints2, good_matches, dst, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();

    // Mat src1 = imread("box.png", IMREAD_GRAYSCALE);
    // Mat src2 = imread("box_in_scene.png", IMREAD_GRAYSCALE);
    // if(src1.empty() || src2.empty()) {
    //     cerr << "Image load failed!" << endl;
    //     return -1;
    // }
    // Ptr<Feature2D> feature = ORB::create();
    // vector<KeyPoint> keypoints1, keypoints2;
    // Mat desc1, desc2;
    // feature->detectAndCompute(src1, Mat(), keypoints1, desc1);
    // feature->detectAndCompute(src2, Mat(), keypoints2, desc2);
    // Ptr<DescriptorMatcher> matcher = BFMatcher::create(NORM_HAMMING);
    // vector<DMatch> matches;
    // matcher->match(desc1, desc2, matches);
    // std::sort(matches.begin(), matches.end());
    // vector<DMatch> good_matches(matches.begin(), matches.begin() + 50);
    // Mat dst;
    // drawMatches(src1, keypoints1, src2, keypoints2, good_matches, dst, Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    // vector<Point2f> pts1, pts2;
    // for (size_t i = 0; i < good_matches.size(); i++){
    //     pts1.push_back(keypoints1[good_matches[i].queryIdx].pt);
    //     pts2.push_back(keypoints2[good_matches[i].trainIdx].pt);
    // }
    // Mat H = findHomography(pts1, pts2, RANSAC);
    // vector<Point2f> corners1, corners2;
    // corners1.push_back(Point2f(0, 0));
    // corners1.push_back(Point2f(src1.cols - 1.f, 0));
    // corners1.push_back(Point2f(src1.cols - 1.f, src1.rows - 1.f));
    // corners1.push_back(Point2f(0, src1.rows - 1.f));
    // perspectiveTransform(corners1, corners2, H);
    // vector<Point> corners_dst;
    // for (Point2f pt : corners2){
    //     corners_dst.push_back(Point(cvRound(pt.x + src1.cols), cvRound(pt.y)));
    // }
    // polylines(dst, corners_dst, true, Scalar(0, 255, 0), 2, LINE_AA);
    // imshow("dst", dst);
    // waitKey();
    // destroyAllWindows();


    return 0;
}

// void on_hue_changed(int, void*){
//     Scalar lowerb(lower_hue, 100, 0);
//     Scalar upperb(upper_hue, 255, 255);
//     inRange(src_hsv, lowerb, upperb, mask);
//     imshow("mask", mask);
// }

// void on_threshold(int pos, void* userdata){
//     Mat src = *(Mat*)userdata;
//     Mat dst;
//     threshold(src, dst, pos, 255, THRESH_BINARY);
//     imshow("dst", dst);
// }

// void on_trackbar(int pos, void* userdata) {
//     Mat src = *(Mat*)userdata;
//     int bsize = pos;
//     if (bsize % 2 == 0) bsize--;
//     if (bsize < 3) bsize = 3;
//     Mat dst;
//     adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, bsize, 5);
//     imshow("dst", dst);
// }