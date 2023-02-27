#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;  // std 라이브러리 사용하여 cout, endl 사용


auto add(int n1, int n2) {
	int result = n1 + n2;
	return result;
}

bool isPass(int n1, int n2, int n3) {
	if ((n1 + n2 + n3) / 3.0 >= 80) {
		return true;
	}
	else {
		return false;
	}

}


int main() {

	//std::cout << "Hello World\n" << "hi" << endl;  // consolout, using namespace 대신 std::하여 위치 설정하여 사용가능

	//int num1 = 0;
	//cout << "num : " << num1 << endl;
	//num1 = 100;
	//cout << "num : " << num1 << endl;
	//int num2{ 200 };  // int num2 = 200;
	//cout << "num2 : " << num2 << endl;
	//int num3 = { 300 };  // int num3 = 300;
	//cout << "num3 : " << num3 << endl;
	//printf("num3 : %d\n", num3);

	//float f1 = 3.14;
	//cout << "f1 : " << f1 << endl;
	//double d1 = 3.141592;
	//cout << "d1 : " << d1 << endl;

	//char c1 = 'a';
	//cout << "c1 : " << c1 << endl;

	//string str1 = "Hello cpp";
	//cout << "str1 : " << str1 << endl;
	//string str2 = "Good morning";
	//string str3 = " ";
	//string str4 = "Hugh";

	//string str5 = str2 + str3 + str4;
	//cout << "str5 : " << str5 << endl;

	//bool flag1 = true;
	//cout << "flag1 : " << flag1 << endl;  // 1
	//flag1 = false;
	//cout << "flag1 : " << flag1 << endl;  // 0

	//string str6 = "hello";
	//string str7 = "hello";
	//bool result = str6 == str7;
	//cout << "result : " << result << endl;

	//string str8 = "man ";
	//string str9 = str8 + to_string(5) + "명";  // to_string str 변환 함수
	//cout << "str9 : " << str9 << endl;

	//const double TAX_RATE = 0.25;  // 상수 선언, 상수명은 보통 대문자로, 상단에 명시
	//int income = 10000;
	//income = income * (1 - TAX_RATE);
	//cout << "순수익 : " << income << endl;

	// 개인의 이름 나이 신장 몸무게 발사이즈를 변수에 담고 출력
	//string name;
	//int age, height, weight;

	//cout << "이름 : ";
	//cin >> name;
	//cout << "나이 : ";
	//cin >> age;
	//cout << "신장 : ";
	//cin >> height;
	//cout << "몸무게 : ";
	//cin >> weight;
	//cout << "이름 : " << name << "\n나이 : " << age << "\n신장 : " << height << "\n몸무게 : " << weight << endl;

	// bmi지수 출력
	//int height, weight;
	//float bmi;
	//cout << "신장 : ";
	//cin >> height;
	//cout << "몸무게 : ";
	//cin >> weight;
	//bmi = weight / pow((height / 100.0), 2);
	//cout << "BMI : " << bmi << endl;

	//int num4 = 123;
	//cout << "num4 : " << num4 << endl;
	//auto num5 = 123;  // auto 자료형 자동으로 판단
	//cout << "num5 : " << num5 << endl;
	//cout << "sizeof(num5) : " << sizeof(num5) << endl;
	//auto num6 = 123.0;
	//cout << "num6 : " << num6 << endl;
	//cout << "sizeof(num6) : " << sizeof(num6) << endl;

	//double d2 = 42.41243781248923;
	//cout << "d2 : " << d2 << endl;  // 소수점 잘려나옴
	//cout.precision(10);  // 숫자의 개수
	//cout << "d2, precision : " << d2 << endl;
	//cout << fixed;  // 소수점 아래 출력범위 설정하기 위해
	//cout.precision(10);  // 숫자의 개수
	//cout << "d2, fixed, precision : " << d2 << endl;

	// 함수
	//cout << "add(10, 20) : " << add(10, 20) << endl;
	//cout << "sizeof(add(10, 20)) : " << sizeof(add(10, 20)) << endl;

	// 출력
	//int n1 = 10;
	//int n2 = 20;
	//cout << n1 << endl;
	//cout << n2 << endl;
	//string str1 = "Hello";
	//string str2 = "Hi";
	//cout << str1 << endl;
	//cout << str2 << endl;
	//printf("str1 : %s\n", str1.c_str());
	//printf("str2 : %s\n", str2.c_str());

	// 입력
	//int n3 = 100;
	//cout << "n3 : " << n3 << endl;
	//cin >> n3;
	//cout << "n3 : " << n3 << endl;
	//cin.ignore();  // 버퍼 비우기

	//double d1;
	//cin >> d1;
	//cout << "d1 : " << d1 << endl;

	//string nameStr;
	//cout << "이름 : ";
	//cin >> nameStr;
	//cout << "이름 : " << nameStr << endl;

	// 이름, 메일, 신장, 몸무게, 발사이즈 입력 출력
	//string name, mail;
	//float height, weight, sizef;
	//cout << "이름 : ";
	//cin >> name;
	//cout << "메일 : ";
	//cin >> mail;
	//cout << "신장 : ";
	//cin >> height;
	//cout << "몸무게 : ";
	//cin >> weight;
	//cout << "발사이즈 : ";
	//cin >> sizef;
	//
	//cout << "\n이름 : " << name << endl;
	//cout << "메일 : " << mail << endl;
	//cout << fixed;
	//cout.precision(1);
	//cout << "신장 : " << height << endl;
	//cout << "몸무게 : " << weight << endl;
	//cout << "발사이즈 : " << sizef << endl;

	//int n1 = 10, n2 = 20;
	//cout << "n1 + n2 = " << n1 + n2 << endl;
	//cout << "n1 - n2 = " << n1 - n2 << endl;
	//cout << "n1 * n2 = " << n1 * n2 << endl;
	//cout << "n1 / (float)n2 = " << n1 / (float)n2 << endl;
	//cout << "n1 % n2 = " << n1 % n2 << endl;

	//int n1 = 10;
	//n1++;
	//cout << "n1 : " << n1 << endl;
	//n1--; n1--;
	//cout << "n1 : " << n1 << endl;

	// 10000원으로 1100 원 컵라면 몇개, 잔돈
	//cout << "컵라면 " << 10000 / 1100 << "개, 잔돈 " << 10000 % 1100 << "원" << endl;
	//
	//// cm 를 inch로 변환, 2.5
	//float inputCm;
	//cout << "cm : ";
	//cin >> inputCm;
	//cout << fixed;
	//cout.precision(2);
	//cout << inputCm << "cm는 " << inputCm / 2.5 << "inch" << endl;

	//// 2050년의 자신의 나이
	//int age;
	//cout << "현재 나이 : ";
	//cin >> age;
	//cout << "2050년의 나이 : " << age + (2050 - 2022) << endl;

	//// 가로세로 입력 삼각형 사각형 넓이
	//float width, length;
	//cout << "가로 : ";
	//cin >> width;
	//cout << "세로 : ";
	//cin >> length;
	//cout << fixed;
	//cout.precision(2);
	//cout << "삼각형의 넓이 : " << width * length / 2 << "\n사각형의 넓이 : " << width * length << endl;

	// 시, 분, 초 환산
	//int _hour, _min, _sec;
	//cout << "시간 : ";
	//cin >> _hour;
	//cout << "분 : ";
	//cin >> _min;
	//cout << "초 : ";
	//cin >> _sec;
	//printf("%d시간 %d분 %d초 : %d초", _hour, _min, _sec, _hour * 3600 + _min * 60 + _sec);

	//// 국영수 입력, 총점 평균, 소수2자리
	//float korscr, engscr, mathscr;
	//cout << "국어점수 : ";
	//cin >> korscr;
	//cout << "영어점수 : ";
	//cin >> engscr;
	//cout << "수학점수 : ";
	//cin >> mathscr;
	//cout << fixed;
	//cout.precision(2);
	//cout << "총점 : " << korscr + engscr + mathscr << " 평균 : " << (korscr + engscr + mathscr) / 3 << endl;

	//// 현재 시스템 날짜 시간 출력
	//time_t t = time(NULL);
	//struct tm *ptm = localtime(&t);
	//char now[20];
	//strftime(now, 20, "%Y-%m-%d %H:%M:%S", ptm);
	//cout << "현재 시간 : " << now << endl;

	//int num1 = 100, num2 = 200;
	//cout << "num1 == num2 : " << (num1 == num2) << endl;
	//cout << "num1 != num2 : " << (num1 != num2) << endl;
	//cout << "num1 > num2 : " << (num1 > num2) << endl;
	//cout << "num1 < num2 : " << (num1 < num2) << endl;
	//cout << "num1 >= num2 : " << (num1 >= num2) << endl;
	//cout << "num1 <= num2 : " << (num1 <= num2) << endl;

	//cout << "true && false : " << (true && false) << endl;
	//cout << "true || false : " << (true && false) << endl;
	//cout << "!true : " << (!true) << endl;

	// 주사위게임
	//srand(time(NULL));  // 새로운 시드
	//char _enter[5];
	//int com_rand_num = rand() % 6 + 1;
	//cout << "주사위를 던지려면 엔터키를 누르세요.";
	//cin.getline(_enter, 5);
	//srand(time(NULL));
	//int my_rand_num = rand() % 6 + 1;
	//if (com_rand_num < my_rand_num) {
	//	printf("컴퓨터 : %d  나 : %d, 이겼습니다!!", com_rand_num, my_rand_num);
	//} else if (com_rand_num > my_rand_num) {
	//	printf("컴퓨터 : %d  나 : %d, 졌습니다!!", com_rand_num, my_rand_num);
	//} else {
	//	printf("컴퓨터 : %d  나 : %d, 비겼습니다!!", com_rand_num, my_rand_num);
	//}

	//int num1{ 100 }, num2{ 200 };
	//if (num1 > num2) {
	//	cout << "num1은 num2보다 크다." << endl;
	//}
	//else if (num1 < num2) {
	//	cout << "num1은 num2보다 작다." << endl;
	//}
	//else {
	//	cout << "num1과 num2는 같다." << endl;
	//}

	//int inputNum;
	//cin >> inputNum;
	//switch (inputNum) {
	//case 1:
	//	cout << "Hi" << endl;
	//	break;
	//case 2:
	//	cout << "Hello" << endl;
	//	break;
	//default:
	//	cout << "Bye" << endl;
	//	break;
	//}

	//bool result = isPass(60, 100, 90);

	//if (result) {
	//	cout << "합격" << endl;
	//}
	//else {
	//	cout << "불합격" << endl;
	//}

	// 사과분류, 무게 입력, 100g 이하 소, 200이하 중, 그외 대
	//double weightApple;
	//cout << "사과무게(g) : ";
	//cin >> weightApple;
	//if (weightApple > 200) {
	//	cout << "대" << endl;
	//}
	//else if (100 < weightApple && weightApple <= 200) {
	//	cout << "중" << endl;
	//}
	//else {
	//	cout << "소" << endl;
	//}

	// 정수 5개 입력 가장 큰수 작은수 출력
	//int inputNums[5];
	//for (int i = 0; i < 5; i++) {
	//	cout << i + 1 << "번째 정수 입력 : ";
	//	cin >> inputNums[i];
	//	cin.ignore();
	//}
	//cout << "최대값 : " << *max_element(inputNums, inputNums + 5) << endl;
	//cout << "최소값 : " << *min_element(inputNums, inputNums + 5) << endl;


	// 컴퓨터가 알파벳 입력하면 사용자가 맞춤, 10번기회 오답일시 알파벳 위치 알려주기
	//string alphabet[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
	//			"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
	//			"U", "V", "W", "X", "Y", "Z" };
	//srand(time(NULL));
	//int com_rand_num = rand() % 26;
	//string com_str = alphabet[com_rand_num], my_str;
	//int i = 0;
	//while (true) {
	//	i++;
	//	cout << "알파벳 하나를 입력하세요 : ";
	//	cin >> my_str;
	//	my_str[0] = toupper(my_str[0]);
	//	if (com_str == my_str) {
	//		cout << "정답입니다." << endl;
	//		break;
	//	}
	//	else {
	//		cout << "틀렸습니다. ";
	//		if (i == 10) {
	//			cout << "기회를 모두 사용하였습니다.\n정답은 " << com_str << "입니다." << endl;
	//			break;
	//		}
	//		else {
	//			if (com_str < my_str) {
	//				cout << "입력한 것보다 앞쪽의 알파벳입니다." << endl;
	//			}
	//			else {
	//				cout << "입력한 것보다 뒷쪽의 알파벳입니다." << endl;

	//			}
	//		}
	//	}
	//}

	// 시험 점수 입력, 점수가 >=90 a, 80 b, 70 c, 60 d, f
	//double testScore;
	//cout << "시험 점수 : ";
	//cin >> testScore;
	//int chkGrade = (int)(testScore / 10);
	//switch (chkGrade) {
	//case 10:
	//	cout << "A+++++" << endl;
	//	break;
	//case 9:
	//	cout << "A" << endl;
	//	break;
	//case 8:
	//	cout << "B" << endl;
	//	break;
	//case 7:
	//	cout << "C" << endl;
	//	break;
	//case 6:
	//	cout << "D" << endl;
	//	break;
	//default:
	//	cout << "F" << endl;
	//	break;
	//}

	//for (int i = 0; i < 5; i++) {
	//	cout << i << endl;
	//}

	//for (int num : inputNums) {
	//	cout << num << endl;
	//}

	//int i = 0;
	//while (i < 5) {
	//	cout << i << endl;
	//	i++;
	//}

	//string word;
	//do {
	//	cout << "하고싶은말 : ";
	//	getline(cin, word);  // cin으로는 띄어쓰기 구분하기때문에 getline(입력, 변수) 사용
	//	cout << "word : " << word << endl;
	//} while (word != "end");

	// 사용자가 원하는 구구단
	//int inputNum;
	//cout << "원하는 단 : ";
	//cin >> inputNum;
	//for (int i = 1; i < 10; i++) {
	//	cout << inputNum <<  " X " << i << " == " << inputNum * i << endl;
	//}

	// 구구단 전체
	//for (int i = 1; i < 10; i++) {
	//	for (int j = 2; j < 10; j++) {
	//		printf("%d X %d = %d\t", j, i, i * j);
	//	}
	//	cout << endl;
	//}


	// 1부터 사용자 입력 정수까지의 합, 곱
	//unsigned long long inputNum, sum=0, mul=1;
	//cout << "정수 입력 : ";
	//cin >> inputNum;
	//for (int i = 1; i < inputNum + 1; i++) {
	//	sum += i;
	//	mul *= i;
	//}
	//cout << "합 : " << sum << ", 곱 : " << mul << endl;

	/*for (int i = 0; i < 10; i++) {
		if (i % 2 == 0) {
			continue;
		}
		cout << i << endl;
		if (i == 5) break;
	}*/

	// 1000, 3의배수 개수
	//int cnt = 0;
	//for (int i = 1; i < 1001; i++) {
	//	if (i % 3 == 0) cnt++;
	//}
	//cout << "1000이하의 3의 배수 개수 : " << cnt << endl;

	// 1 99 3 6 9
	//for (int i = 1; i < 100; i++) {
	//	string strI = to_string(i);
	//	cout << i << " : ";
	//	for (int j = 0; j < strI.length(); j++) {
	//		if (strI[j] == '3' or strI[j] == '6' or strI[j] == '9') {
	//			cout << "짝!";
	//		}
	//	}
	//	cout << endl;
	//}

	// 문자입력 자음 모음 개수, 반복
	//string inputStr;
	//int vowels, selectedNum, etc;
	//while (true) {
	//	cout << "1. 영문장 자모음 개수 판별  2. 종료 ";
	//	cin >> selectedNum;
	//	if (selectedNum == 1) {
	//		cin.ignore();
	//		vowels = 0;
	//		etc = 0;
	//		cout << "영문자 입력 : ";
	//		getline(cin, inputStr);
	//		for (int i = 0; i < inputStr.length(); i++) {
	//			if (inputStr[i] == ' ' or inputStr[i] == '\n') {
	//				etc++;
	//			}
	//			else if (inputStr[i] == 'a' or inputStr[i] == 'e' or inputStr[i] == 'i' or inputStr[i] == 'o' or inputStr[i] == 'u') {
	//				vowels++;
	//			}
	//		}
	//		cout << "자음 : " << inputStr.length() - vowels - etc << "개, 모음 : " << vowels << "개" << endl;
	//	}
	//	else {
	//		break;
	//	}
	//}


	// 1 100 난수 맞추고 높고 낮음.
	//srand((unsigned int)time(NULL));
	//int randInt = (rand() % 100) + 1, inputInt;
	//int i = 0;
	//while (true) {
	//	i++;
	//	cout << "랜덤한 정수 맞추기 : ";
	//	cin >> inputInt;
	//	if (randInt == inputInt) {
	//		cout << "정답입니다." << endl;
	//		break;
	//	}
	//	else {
	//		cout << "틀렸습니다." << endl;
	//		if (i == 10) {
	//			cout << "도전기회 초과, 정답은 " << randInt << "입니다." << endl;
	//			break;
	//		}
	//		else {
	//			if (randInt < inputInt) {
	//				cout << "입력한 수보다 낮은 수 입니다." << endl;
	//			}
	//			else {
	//				cout << "입력한 수보다 높은 수 입니다." << endl;
	//			}
	//		}
	//	}
	//}

	// 1 1000 덧뺼셈 자동 출제
	//int inputNum, num1, num2, answer;
	//bool flag = true;
	//while (flag) {
	//	cout << "1. 덧셈문제  2. 뺼셈문제  3. 종료 ";
	//	cin >> inputNum;
	//	srand((unsigned int)time(NULL));
	//	num1 = (rand() % 1000) + 1, num2 = (rand() % 1000) + 1;
	//	switch (inputNum)
	//	{
	//	case 1:
	//		cout << num1 << " + " << num2 << " = ";
	//		cin >> answer;
	//		if (answer == num1 + num2) {
	//			cout << "정답입니다." << endl;
	//		}
	//		else {
	//			cout << "오답입니다.\n" << "정답 : " << num1 + num2 << endl;
	//		}
	//		break;
	//	case 2:
	//		cout << num1 << " - " << num2 << " = ";
	//		cin >> answer;
	//		if (answer == num1 - num2) {
	//			cout << "정답입니다." << endl;
	//		}
	//		else {
	//			cout << "오답입니다.\n" << "정답 : " << num1 - num2 << endl;
	//		}
	//		break;
	//	case 3:
	//		flag = false;
	//		break;
	//	}
	//}


	return 0;

}
