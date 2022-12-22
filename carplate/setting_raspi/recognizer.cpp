#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <time.h>

// 관련 라이브러리 설치하기
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

//DB, mariadb 및 라이브러리 설치
#include <mysql.h>
#pragma comment(lib, "libmySQL.lib")

using namespace cv;
using namespace std;

string DEVICE = "1";

const char* DB_HOST = "192.168.31.135";
int DB_PORT = 3306;
const char* DB_NAME = "db_license_plate_trace";
const char* DB_USER = "group1";
const char* DB_PW = "group1";

string IMG_HOST = "192.168.31.135";
string IMG_PATH = "/img";
string IMG_USER = "jae";
string IMG_PW = "jae";

int main() {
    Mat imgOg, cp1_imgOg, cp2_imgOg, imgGray, imgGaussian, imgCanny, cp1_imgCanny, imgContours, imgRotation, imgFinal;

    Rect tempRect;

    vector<Rect> carNum;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    int widthOg, heightOg, sel, cnt, cntFriend, cntRefinery, xPlateCenter, yPlateCenter, sumHeight, widthPlate, heightPlate, cntTextPlate, chkChar, cntNumsPlate, stat;
    string outText, text, nameImg, now, cmd, strSql;
    double ratio, deltaX, deltaY, gradient, angleDegree;

    time_t curTime;
    struct tm *t;

    VideoCapture cap(0, cv::CAP_V4L);
    if (!cap.isOpened()) {
        cerr << "VideoCapture Failed." << endl;
        return -1;

    }

    while (true) {
        cap >> imgOg;
        
        widthOg = imgOg.cols;
        heightOg = imgOg.rows;

        imgOg.copyTo(cp1_imgOg);
        imgOg.copyTo(cp2_imgOg);
        imgOg.copyTo(imgFinal);

        // 그레이스케일
        cvtColor(imgOg, imgGray, COLOR_BGR2GRAY);

        // 가우시안블러, 테스트 후 sigma 조절, 0
        GaussianBlur(imgGray, imgGaussian, Size(5, 5), 0);

        // 캐니 에지 검출, 임계값 조절, 낮은 임계, 높은 임계, 낮추면 많이 검출
        Canny(imgGaussian, imgCanny, 90, 200);

        // 적당한 비율 찾아 사각형 그리기
        findContours(imgCanny, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
        if (contours.size() > 0) {
            vector<vector<Point>> contours_poly(contours.size());
            vector<Rect> boundRect(contours.size());
            vector<Rect> boundRect2(contours.size());

            for (int i = 0; i < contours.size(); i++) {
                approxPolyDP(Mat(contours[i]), contours_poly[i], 1, true);
                boundRect[i] = boundingRect(Mat(contours_poly[i]));

            }

            imgContours = Mat::zeros(imgCanny.size(), CV_8UC3);
            cntRefinery = 0;
            for (int i = 0; i < contours.size(); i++) {
                ratio = (double)boundRect[i].height / boundRect[i].width;
                if (0.5 <= ratio && ratio <= 2.5) {
                    drawContours(imgContours, contours, i, Scalar(0, 255, 255), 1, 8, hierarchy, 0, Point());
                    rectangle(imgContours, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 1, 8, 0);
                    boundRect2[cntRefinery] = boundRect[i];
                    cntRefinery++;

                }
            }
            boundRect2.resize(cntRefinery);

            // 번호판위 사각형 분별
            if (boundRect2.size() > 0) {
                for (int i = 0; i < boundRect2.size(); i++) {
                    for (int j = 0; j < (boundRect2.size() - i - 1); j++) {
                        if (boundRect2[j].tl().x > boundRect2[j + 1].tl().x) {
                            tempRect = boundRect2[j];
                            boundRect2[j] = boundRect2[j + 1];
                            boundRect2[j + 1] = tempRect;

                        }

                    }

                }

                cntFriend = 0;
                sel = -1;
                for (int i = 0; i < boundRect2.size(); i++) {
                    rectangle(cp1_imgOg, boundRect2[i].tl(), boundRect2[i].br(), Scalar(0, 255, 0), 1, 8, 0);

                    cnt = 0;
                    for (int j = i + 1; j < boundRect2.size(); j++) {
                        deltaX = abs(boundRect2[j].tl().x - boundRect2[i].tl().x);
                        // 델타값 조절, 떨어진거리에따른 무언가
                        if (deltaX > 150) {
                            break;

                        }
                        deltaY = abs(boundRect2[j].tl().y - boundRect2[i].tl().y);
                        if (deltaX == 0) {
                            deltaX = 1;

                        }
                        if (deltaY == 0) {
                            deltaY = 1;

                        }
                        gradient = deltaY / deltaX;
                        if (gradient < 0.25) {
                            cnt++;

                        }
                    }

                    if (cnt > cntFriend) {
                        sel = i;
                        cntFriend = cnt;
                        rectangle(cp1_imgOg, boundRect2[sel].tl(), boundRect2[sel].br(), Scalar(255, 0, 255), 1, 8, 0);

                    }

                }
                if (0 <= sel) {
                    carNum.clear();
                    cnt = 1;
                    carNum.push_back(boundRect2[sel]);
                    rectangle(cp2_imgOg, boundRect2[sel].tl(), boundRect2[sel].br(), Scalar(0, 255, 0), 1, 8, 0);

                    for (int i = 0; i < boundRect2.size(); i++) {
                        if (boundRect2[sel].tl().x > boundRect2[i].tl().x) {
                            continue;

                        }
                        deltaX = abs(boundRect2[sel].tl().x - boundRect2[i].tl().x);
                        if (deltaX > 50) {
                            continue;

                        }
                        deltaY = abs(boundRect2[sel].tl().y - boundRect2[i].tl().y);
                        if (deltaX == 0) {
                            deltaX = 1;

                        }
                        if (deltaY == 0) {
                            deltaY = 1;

                        }
                        gradient = deltaY / deltaX;
                        if (gradient < 0.25) {
                            sel = i;
                            carNum.push_back(boundRect2[i]);
                            rectangle(cp2_imgOg, boundRect2[i].tl(), boundRect2[i].br(), Scalar(0, 255, 0), 1, 8, 0);
                            cnt++;

                        }

                    }

                    // 기울기 조절
                    // 플레이트의 센터, 크기 및 기울기
                    if (6 < carNum.size() && carNum.size() < 9) {
                        Point center1 = (carNum[0].tl() + carNum[0].br()) * 0.5;
                        Point center2 = (carNum[carNum.size() - 1].tl() + carNum[carNum.size() - 1].br()) * 0.5;
                        xPlateCenter = (int)(center1.x + center2.x) * 0.5;
                        yPlateCenter = (int)(center1.y + center2.y) * 0.5;

                        sumHeight = 0;
                        for (int i = 0; i < carNum.size(); i++) {
                            sumHeight += carNum[i].height;

                        }

                        widthPlate = (-center1.x + center2.x + carNum[carNum.size() - 1].width) * 1.05;
                        heightPlate = (int)(sumHeight / carNum.size()) * 1.2;
                        deltaX = center1.x - center2.x;
                        deltaY = center1.y - center2.y;

                        // 수평맞추기
                        angleDegree = (atan(deltaY / deltaX)) * (double)(180 / 3.141592);
                        imgRotation = getRotationMatrix2D(Point(xPlateCenter, yPlateCenter), angleDegree, 1.0);
                        warpAffine(imgFinal, imgFinal, imgRotation, Size(widthOg, heightOg));
                        // imshow("Rotated", imgFinal);

                        // 원본 번호판 부분, 최종 이미지 전처리
                        getRectSubPix(imgFinal, Size(widthPlate, heightPlate), Point(xPlateCenter, yPlateCenter), imgFinal, -1);
                        cvtColor(imgFinal, imgFinal, COLOR_BGR2GRAY);
                        GaussianBlur(imgFinal, imgFinal, Size(5, 5), 0);

                        // 적응형이진화, 블럭사이즈 조절하기, 19
                        adaptiveThreshold(imgFinal, imgFinal, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 19, 0);
                        copyMakeBorder(imgFinal, imgFinal, 10, 10, 10, 10, BORDER_CONSTANT, Scalar(0, 0, 0));
                        imwrite("./img/temp/temp.jpg", imgFinal);

                        // Tesseract
                        tesseract::TessBaseAPI *api = new tesseract:: TessBaseAPI();
                        api->Init(NULL, "kor3", tesseract::OEM_TESSERACT_ONLY);  //kor, kor3 확인
                        api->SetPageSegMode(tesseract::PSM_SINGLE_LINE);
                        Pix* carNumber = pixRead("./img/temp/temp.jpg");
                        api->SetImage(carNumber);
                        outText = api->GetUTF8Text();

                        // text 필터링
                        text = "";
                        cntTextPlate = 0;
                        chkChar = 0;
                        cntNumsPlate = 0;

                        for (int i = 0; i < outText.length(); i++) {
                            if (text == "" && !(48 <= outText[i] && outText[i] <= 57)) {
                                continue;

                            } else if (((chkChar < 3) && ((outText[i] & 0x80) == 0x80)) || (48 <= outText[i] && outText[i] <= 57)) {
                                text.push_back(outText[i]);
                                cntTextPlate++;

                                if ((outText[i] & 0x80) == 0x80) {
                                    chkChar++;

                                }

                            }
                            if ((chkChar == 3) && (48 <= outText[i] && outText[i] <= 57)) {
                                cntNumsPlate++;

                            }
                            if (cntNumsPlate == 4) {
                                break;

                            }
                        }

                        api->End();
                        delete api;
                        pixDestroy(&carNumber);
                        // cout << "Car Num : " << text << endl;

                        // DB
                        MYSQL conn;
                        MYSQL* connPtr = NULL;
                        MYSQL_RES* res;
                        MYSQL_ROW row;;

                        //정보검색
                        mysql_init(&conn);
                        connPtr = mysql_real_connect(&conn, DB_HOST, DB_USER, DB_PW, DB_NAME, DB_PORT, (char*)NULL, 0);
                        const char* sqlSel = "SELECT * FROM tbl_license_plate_search";
                        stat = mysql_query(connPtr, sqlSel);
                        res = mysql_store_result(connPtr);

                        while ((row = mysql_fetch_row(res)) != NULL) {
                            if (text == row[1]) {
                                // 이미지 이름
                                curTime = time(NULL);
                                t = localtime(&curTime);
                                now = to_string(1900+t->tm_year) 
                                + (t->tm_mon+1 < 10 ? '0' + to_string(t->tm_mon+1) : to_string(t->tm_mon+1)) 
                                + (t->tm_mday < 10 ? '0' + to_string(t->tm_mday) : to_string(t->tm_mday)) 
                                + (t->tm_hour < 10 ? '0' + to_string(t->tm_hour) : to_string(t->tm_hour)) 
                                + (t->tm_min < 10 ? '0' + to_string(t->tm_min) : to_string(t->tm_min)) 
                                + (t->tm_sec < 10 ? '0' + to_string(t->tm_sec) : to_string(t->tm_sec));
                                nameImg = text + "_" + now + "_" + DEVICE + ".jpg";
                                
                                // 일치 정보 삽입
                                strSql = "INSERT INTO tbl_license_plate_info (l_info, l_info_reg_date, l_img_name, c_no, s_no) VALUES ('" + text + "', NOW(), '" + nameImg +"', " + DEVICE + ", " + row[0] + ")";
                                char* sqlIns = new char[strSql.size() + 1];
                                copy(strSql.begin(), strSql.end(), sqlIns);
                                sqlIns[strSql.size()] = '\0';
                                stat = mysql_query(connPtr, sqlIns);
                                delete sqlIns;

                                // 이미지 파일 전송 및 삭제
                                imwrite("./img/detected/" + nameImg, imgOg);
                                cmd = "sudo sshpass -p " + IMG_PW + " scp -P 23 ./img/detected/" + nameImg + " " + IMG_USER + "@" + IMG_HOST + ":" + IMG_PATH;  // sshpass 설치
                                system(const_cast<char*>(cmd.c_str()));
                                cmd = "sudo rm ./img/detected/" + nameImg;  // 파일 삭제
                                system(const_cast<char*>(cmd.c_str()));

                                break;

                            }
                        }
                        mysql_free_result(res);
                        mysql_close(connPtr);

                    }
                }
            }
        }

        // imshow("Plate", cp2_imgOg);
        // imshow("Cropped Image", imgFinal);

        if (waitKey(10) == 27) {
            break;

        }
    }

    return 0;
    
}
