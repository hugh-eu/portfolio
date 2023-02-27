//#include "opencv2/opencv.hpp"
//#include <iostream>
//
//using namespace cv;
//using namespace cv::ml;
//using namespace std;
//
////Mat img;
////Mat train, label;
////Ptr<KNearest> knn;
////int k_value = 1;
////void on_k_changed(int, void*);
////void addPoint(const Point& pt, int cls);
////void trainAndDisplay();
//
////Ptr<KNearest> train_knn();
////void on_mouse(int event, int x, int y, int flags, void* userdata);
//
////Ptr<SVM> train_hog_svm(const HOGDescriptor& hog);
////void on_mouse(int event, int x, int y, int flags, void* userdata);
//
//int main() {
//    //img = Mat::zeros(Size(500, 500), CV_8UC3);
//    //knn = KNearest::create();
//    //namedWindow("knn");
//    //createTrackbar("k", "knn", &k_value, 5, on_k_changed);
//    //const int NUM = 30;
//    //Mat rn(NUM, 2, CV_32SC1);
//    //randn(rn, 0, 50);
//    //for (int i = 0; i < NUM; i++) {
//    //    addPoint(Point(rn.at<int>(i, 0) + 150, rn.at<int>(i, 1) + 150), 0);
//    //}
//    //randn(rn, 0, 50);
//    //for (int i = 0; i < NUM; i++) {
//    //    addPoint(Point(rn.at<int>(i, 0) + 350, rn.at<int>(i, 1) + 150), 1);
//    //}
//    //randn(rn, 0, 70);
//    //for (int i = 0; i < NUM; i++) {
//    //    addPoint(Point(rn.at<int>(i, 0) + 250, rn.at<int>(i, 1) + 400), 2);
//    //}
//    //trainAndDisplay();
//    //waitKey();
//
//    //Ptr<KNearest> knn = train_knn();
//    //if (knn.empty()) {
//    //    cerr << "Training failed!" << endl;
//    //    return -1;
//    //}
//    //Mat img = Mat::zeros(400, 400, CV_8U);
//    //imshow("img", img);
//    //setMouseCallback("img", on_mouse, (void*)&img);
//    //while (true) {
//    //    int c = waitKey();
//    //    if (c == 27) {
//    //        break;
//    //    }
//    //    else if (c == ' ') {
//    //        Mat img_resize, img_float, img_flatten, res;
//    //        resize(img, img_resize, Size(20, 20), 0, 0, INTER_AREA);
//    //        img_resize.convertTo(img_float, CV_32F);
//    //        img_flatten = img_float.reshape(1, 1);
//    //        knn->findNearest(img_flatten, 3, res);
//    //        cout << cvRound(res.at<float>(0, 0)) << endl;
//    //        img.setTo(0);
//    //        imshow("img", img);
//    //    }
//    //}
//
//    //Mat train = Mat_<float>({ 8, 2 }, { 150, 200, 200, 250, 100, 250, 150, 300, 350, 100, 400, 200, 400, 300, 350, 400 });
//    //Mat label = Mat_<int>({ 8, 1 }, { 0, 0, 0, 0, 1, 1, 1, 1 });
//    //Ptr<SVM> svm = SVM::create();
//    //svm->setType(SVM::Types::C_SVC);
//    //svm->setKernel(SVM::KernelTypes::RBF);
//    //svm->trainAuto(train, ROW_SAMPLE, label);
//    //Mat img = Mat::zeros(Size(500, 500), CV_8UC3);
//    //for (int j = 0; j < img.rows; j++) {
//    //    for (int i = 0; i < img.cols; i++) {
//    //        Mat test = Mat_<float>({ 1, 2 }, { (float)i, (float)j });
//    //        int res = cvRound(svm->predict(test));
//    //        if (res == 0) {
//    //            img.at<Vec3b>(j, i) = Vec3b(128, 128, 255);
//    //        }
//    //        else {
//    //            img.at<Vec3b>(j, i) = Vec3b(128, 255, 128);
//    //        }
//    //    }
//    //    for (int i = 0; i < train.rows; i++) {
//    //        int x = cvRound(train.at<float>(i, 0));
//    //        int y = cvRound(train.at<float>(i, 1));
//    //        int l = label.at<int>(i, 0);
//    //        if (l == 0) {
//    //            circle(img, Point(x, y), 5, Scalar(0, 0, 128), -1, LINE_AA);
//    //        }
//    //        else {
//    //            circle(img, Point(x, y), 5, Scalar(0, 128, 0), -1, LINE_AA);
//    //        }
//    //    }
//    //}
//    //imshow("svm", img);
//    //waitKey();
//
////#if _DEBUG
////    cout << "svmdigits.exe should be built as Release mode!" << endl;
////#endif
////    HOGDescriptor hog(Size(20, 20), Size(10, 10), Size(5, 5), Size(5, 5), 9);
////    Ptr<SVM> svm = train_hog_svm(hog);
////    if (svm.empty()) {
////        cerr << "Training failed!" << endl;
////        return -1;
////    }
////    Mat img = Mat::zeros(400, 400, CV_8U);
////    imshow("img", img);
////    setMouseCallback("img", on_mouse, (void*)&img);
////    while (true) {
////        int c = waitKey();
////        if (c == 27) {
////            break;
////        }
////        else if (c == ' ') {
////            Mat img_resize;
////            resize(img, img_resize, Size(20, 20), 0, 0, INTER_AREA);
////            vector<float> desc;
////            hog.compute(img_resize, desc);
////            Mat desc_mat(desc);
////            int res = cvRound(svm->predict(desc_mat.t()));
////            cout << res << endl;
////            img.setTo(0);
////            imshow("img", img);
////        }
////    }
//
//    return 0;
//}
//
////void on_k_changed(int, void*){
////    if (k_value < 1) k_value = 1;
////    trainAndDisplay();
////}
////
////void addPoint(const Point& pt, int cls){
////    Mat new_sample = (Mat_<float>(1, 2) << pt.x, pt.y);
////    train.push_back(new_sample);
////    Mat new_label = (Mat_<int>(1, 1) << cls);
////    label.push_back(new_label);
////}
////
////void trainAndDisplay() {
////    knn->train(train, ROW_SAMPLE, label);
////    for(int i = 0; i < img.rows; ++i){
////        for(int j = 0; j < img.cols; ++j){
////            Mat sample = (Mat_<float>(1, 2) << j, i);
////            Mat res;
////            knn->findNearest(sample, k_value, res);
////            int response = cvRound(res.at<float>(0, 0));
////            if (response == 0) {
////                img.at<Vec3b>(i, j) = Vec3b(128, 128, 255);
////            } else if (response == 1) {
////                img.at<Vec3b>(i, j) = Vec3b(128, 255, 128);
////            } else if (response == 2) {
////                img.at<Vec3b>(i, j) = Vec3b(255, 128, 128);
////            }
////        }
////    }
////    for (int i = 0; i < train.rows; i++) {
////        int x = cvRound(train.at<float>(i, 0));
////        int y = cvRound(train.at<float>(i, 1));
////        int l = label.at<int>(i, 0);
////        if (l == 0) {
////            circle(img, Point(x, y), 5, Scalar(0, 0, 128), -1, LINE_AA);
////        } else if (l == 1) {
////            circle(img, Point(x, y), 5, Scalar(0, 128, 0), -1, LINE_AA);
////        } else if (l == 2) {
////            circle(img, Point(x, y), 5, Scalar(128, 0, 0), -1, LINE_AA);
////        }
////    }
////    imshow("knn", img);
////}
//
////Ptr<KNearest> train_knn() {
////    Mat digits = imread("digits.png", IMREAD_GRAYSCALE);
////    if (digits.empty()) {
////        cerr << "Image load failed!" << endl;
////        return 0;
////    }
////    Mat train_images, train_labels;
////    for (int j = 0; j < 50; j++) {
////        for (int i = 0; i < 100; i++) {
////            Mat roi, roi_float, roi_flatten;
////            roi = digits(Rect(i * 20, j * 20, 20, 20));
////            roi.convertTo(roi_float, CV_32F);
////            roi_flatten = roi_float.reshape(1, 1);
////            train_images.push_back(roi_flatten);
////            train_labels.push_back(j / 5);
////        }
////    }
////    Ptr<KNearest> knn = KNearest::create();
////    knn->train(train_images, ROW_SAMPLE, train_labels);
////    return knn;
////}
////
////Point ptPrev(-1, -1);
////
////void on_mouse(int event, int x, int y, int flags, void* userdata) {
////    Mat img = *(Mat*)userdata;
////    if (event == EVENT_LBUTTONDOWN) {
////        ptPrev = Point(x, y);
////    }
////    else if (event == EVENT_LBUTTONUP) {
////        ptPrev = Point(-1, -1);
////    }
////    else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) {
////        line(img, ptPrev, Point(x, y), Scalar::all(255), 30, LINE_AA, 0);
////        ptPrev = Point(x, y);
////        imshow("img", img);
////    }
////}
//
////Ptr<SVM> train_hog_svm(const HOGDescriptor& hog) {
////    Mat digits = imread("digits.png", IMREAD_GRAYSCALE);
////    if (digits.empty()) {
////        cerr << "Image load failed!" << endl;
////        return 0;
////    }
////    Mat train_hog, train_labels;
////    for (int j = 0; j < 50; j++) {
////        for (int i = 0; i < 100; i++) {
////            Mat roi = digits(Rect(i * 20, j * 20, 20, 20));
////            vector<float> desc;
////            hog.compute(roi, desc);
////            Mat desc_mat(desc);
////            train_hog.push_back(desc_mat.t());
////            train_labels.push_back(j / 5);
////        }
////    }
////    Ptr<SVM> svm = SVM::create();
////    svm->setType(SVM::Types::C_SVC);
////    svm->setKernel(SVM::KernelTypes::RBF);
////    svm->setC(2.5);
////    svm->setGamma(0.50625);
////    svm->train(train_hog, ROW_SAMPLE, train_labels);
////
////    return svm;
////}
////
////Point ptPrev(-1, -1);
////
////void on_mouse(int event, int x, int y, int flags, void* userdata) {
////    Mat img = *(Mat*)userdata;
////    if (event == EVENT_LBUTTONDOWN) {
////        ptPrev = Point(x, y);
////    }
////    else if (event == EVENT_LBUTTONUP) {
////        ptPrev = Point(-1, -1);
////    }
////    else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) {
////        line(img, ptPrev, Point(x, y), Scalar::all(255), 40, LINE_AA, 0);
////        ptPrev = Point(x, y);
////        imshow("img", img);
////    }
////}