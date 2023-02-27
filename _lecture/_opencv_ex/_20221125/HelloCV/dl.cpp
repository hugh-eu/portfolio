#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>

using namespace cv;
using namespace cv::dnn;
using namespace std;

//void on_mouse(int event, int x, int y, int flags, void* userdata);

const String model = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
const String config = "deploy.prototxt";
//const String model = "opencv_face_detector_uint8.pb";
//const String config = "opencv_face_detector.pbtxt";

int main(int argc, char* argv[])
{
	//Net net = readNet("mnist_cnn.pb");
	//if (net.empty()) {
	//	cerr << "Network load failed!" << endl;
	//	return -1;
	//}
	//Mat img = Mat::zeros(400, 400, CV_8UC1);
	//imshow("img", img);
	//setMouseCallback("img", on_mouse, (void*)&img);
	//while (true) {
	//	int c = waitKey(0);
	//	if (c == 27) {
	//		break;
	//	} else if (c == ' ') {
	//		Mat blob = blobFromImage(img, 1/255.f, Size(28, 28));
	//		net.setInput(blob);
	//		Mat prob = net.forward();
	//		double maxVal;
	//		Point maxLoc;
	//		minMaxLoc(prob, NULL, &maxVal, NULL, &maxLoc);
	//		int digit = maxLoc.x;
	//		cout << digit << " (" << maxVal * 100 << "%)" <<endl;
	//		img.setTo(0);
	//		imshow("img", img);
	//	}
	//}

	//Mat img;
	//if (argc < 2)
	//	img = imread("rothy.png", IMREAD_COLOR);
	//else
	//	img = imread(argv[1], IMREAD_COLOR);
	//if (img.empty()) {
	//	cerr << "Image load failed!" << endl;
	//	return -1;
	//}
	//Net net = readNet("bvlc_googlenet.caffemodel", "deploy.prototxt");
	//if (net.empty()) {
	//	cerr << "Network load failed!" << endl;
	//	return -1;
	//}
	//ifstream fp("classification_classes_ILSVRC2012.txt");
	//if (!fp.is_open()) {
	//	cerr << "Class file load failed!" << endl;
	//	return -1;
	//}
	//vector<String> classNames;
	//string name;
	//while (!fp.eof()) {
	//	getline(fp, name);
	//	if (name.length())
	//		classNames.push_back(name);
	//}
	//fp.close();
	//Mat inputBlob = blobFromImage(img, 1, Size(224, 224), Scalar(104, 117, 123));
	//net.setInput(inputBlob, "data");
	//Mat prob = net.forward();
	//double maxVal;
	//Point maxLoc;
	//minMaxLoc(prob, NULL, &maxVal, NULL, &maxLoc);
	//String str = format("%s (%4.2lf%%)", classNames[maxLoc.x].c_str(), maxVal * 100);
	//putText(img, str, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255));
	//imshow("img", img);
	//waitKey();

	VideoCapture cap("http://192.168.0.100:8090/?action=stream");
	if (!cap.isOpened()) {
		cerr << "Camera open failed!" << endl;
		return -1;
	}
	Net net = readNet(model, config);
	if (net.empty()) {
		cerr << "Net open failed!" << endl;
		return -1;
	}
	Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;
		Mat blob = blobFromImage(frame, 1, Size(300, 300), Scalar(104, 177, 123));
		net.setInput(blob);
		Mat res = net.forward();
		Mat detect(res.size[2], res.size[3], CV_32FC1, res.ptr<float>());
		for (int i = 0; i < detect.rows; i++) {
			float confidence = detect.at<float>(i, 2);
			if (confidence < 0.5)
				break;
			int x1 = cvRound(detect.at<float>(i, 3) * frame.cols);
			int y1 = cvRound(detect.at<float>(i, 4) * frame.rows);
			int x2 = cvRound(detect.at<float>(i, 5) * frame.cols);
			int y2 = cvRound(detect.at<float>(i, 6) * frame.rows);
			rectangle(frame, Rect(Point(x1, y1), Point(x2, y2)), Scalar(0, 255, 0));
			String label = format("Face: %4.3f", confidence);
			putText(frame, label, Point(x1, y1 - 1), FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 255, 0));
		}
		imshow("frame", frame);
		if (waitKey(1) == 27)
			break;
	}

	return 0;
}

//Point ptPrev(-1, -1);
//void on_mouse(int event, int x, int y, int flags, void* userdata)
//{
//	Mat img = *(Mat*)userdata;
//	if (event == EVENT_LBUTTONDOWN) {
//		ptPrev = Point(x, y);
//	} else if (event == EVENT_LBUTTONUP) {
//		ptPrev = Point(-1, -1);
//	} else if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) {
//		line(img, ptPrev, Point(x, y), Scalar::all(255), 40, LINE_AA, 0);
//		ptPrev = Point(x, y);
//		imshow("img", img);
//	}
//}

