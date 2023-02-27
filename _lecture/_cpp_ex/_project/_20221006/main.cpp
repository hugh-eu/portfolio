#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector> // 기본 헤더파일 <>
#include <map>
#include "Bus.h"  // 직접만든 헤더파일은 ""

using namespace std;


//int getMax(int arrs[3]);
//
//vector<int> getPrime();
//
//string changeForm(string str);
//
//string getMaxGenInt();
//
//bool chkPw(string pw);
//
//class Circle {
//public: // public 속성, 기능들
//	double pi = 3.14;
//	int radius;
//	string color;
//
//	Circle() {  // 기본생성자, 없으면 컴파일러가 생성
//
//	}
//
//	double getCalcArea() {
//		return pi * radius * radius;
//	}
//
//	void printCircleColor() {
//		cout << "color : " << color << endl;
//	}
//
//
//};
//
//class Rectangle {
//public:
//	double width = 0;
//	double length = 0;
//
//	Rectangle() {
//
//	}
//
//	Rectangle(double width, double length) {
//		this->width = width;
//		this->length = length;
//	}
//
//	double getArea() {
//		return width * length;
//	}
//};
//
//class Car {
//public:
//	double length;
//	int price;
//	int displacement;
//	string name;
//
//	Car(double length, int price, int displacement, string name) {
//		this->length = length;
//		this->price = price;
//		this->displacement = displacement;
//		this->name = name;
//	}
//
//	// 보통 생성자, getter, setter 분리하지 않음, 일반 기능들, 메서드, 함수들만 분리
//	void printCarInfo();
//
//};
//
//class Drive {
//public:
//	string name;
//
//	Drive() {
//
//	}
//
//	Drive(string name) {
//		this->name = name;
//	}
//
//	string getName() {
//		return name;
//	}
//
//	void doDrive() {
//		cout << (*this).name << "가 운전한다." << endl;
//	}
//
//};
//
//class Tent {
//public:
//	string name;
//
//	Tent() {
//
//	}
//
//	Tent(string name) {
//		this->name = name;
//	}
//
//	string getName() {
//		return name;
//	}
//
//	void setTent() {
//		cout << (*this).name << "가 텐트친다." << endl;
//	}
//};
//
//class Meal {
//public:
//	string name;
//
//	Meal() {
//
//	}
//
//	Meal(string name) {
//		this->name = name;
//	}
//
//	string getName() {
//		return name;
//	}
//
//	void makeMeal() {
//		cout << (*this).name << "가 밥짓는다." << endl;
//	}
//};
//
//class Dishwash {
//public:
//	string name;
//
//	Dishwash() {
//
//	}
//
//	Dishwash(string name) {
//		this->name = name;
//	}
//
//	string getName() {
//		return name;
//	}
//
//	void washDish() {
//		cout << (*this).name << "가 설거지한다." << endl;
//	}
//};
//
//class Meat {
//public:
//	string name;
//
//	Meat() {
//
//	}
//
//	Meat(string name) {
//		this->name = name;
//	}
//
//	string getName() {
//		return name;
//	}
//
//	void grillMeat() {
//		cout << (*this).name << "가 고기굽는다." << endl;
//	}
//};
//
//class PrintData {
//public:
//	void print(int i) {
//		cout << "i : " << i << endl;
//	}
//	void print(double d) {
//		cout << "d : " << d << endl;
//	}
//	void print(string s) {
//		cout << "s : " << s << endl;
//	}
//};
//
////class Student {
////private:
////public:
////	string name;
////	int age;
////	int grade;
////	string major;
////	Student() {
////
////	}
////	Student(string name, int age, int grade, string major) {
////		this->name = name;
////		this->age = age;
////		this->grade = grade;
////		this->major = major;
////	}
////
////	void printStudentInfo();
////
////};
//
////void upgradeStudentInfo(Student &s);
//
//class Student {
//private:
//	string no;
//	string name;
//	int age;
//	int grade;
//	string major;
//public:
//	void setNo(string no) {
//		this->no = no;
//	}
//	string getNo() {
//		return this->no;
//	}
//	void setName(string name) {
//		this->name = name;
//	}
//	string getName() {
//		return this->name;
//	}
//};

class Student {
private:
	string s_no;  // s00001
	string s_name;
	int s_age;
	int s_grade;
	string s_major;
public:
	string getS_no() {
		return this->s_no;
	}
	void setS_no(string s_no) {
		this->s_no = s_no;
	}
	string getS_name() {
		return this->s_name;
	}
	void setS_name(string s_name) {
		this->s_name = s_name;
	}
	int getS_age() {
		return this->s_age;
	}
	void setS_age(int s_age) {
		this->s_age = s_age;
	}
	int getS_grade() {
		return this->s_grade;
	}
	void setS_grade(int s_grade) {
		this->s_grade = s_grade;
	}
	string getS_major() {
		return this->s_major;
	}
	void setS_major(string s_major) {
		this->s_major = s_major;
	}
};


void printStudentInfo(Student student);

int main() {

	// 3개의 정수중 최대값 함수 최대값 출력
	//int arrs[3];
	//for (int i = 0; i < 3; i++) {
	//	cout << i + 1 << "번째 정수 : ";
	//	cin >> arrs[i];
	//}
	//int maxInt = getMax(arrs);
	//cout << "최대값 : " << maxInt << endl;

	// 2와 100사이 소수 찾는 함수, 소수 출력
	//vector<int> result = getPrime();
	//cout << "2와 100사이의 소수 : ";
	//for (int i : result) {
	//	cout << result.at(i) << " ";
	//}

	// (02)-1234-4567 (042)-123-4567 --> ---로 함수
	//string phoneNum1 = "(02)-1234-4567", phoneNum2 = "(042)-123-4567";
	//string returnNum1 = changeForm(phoneNum1);
	//string returnNum2 = changeForm(phoneNum2);
	//cout << "reform num1 : " << returnNum1 << endl;
	//cout << "reform num2 : " << returnNum2 << endl;

	// 0부터 9까지 난수 100번 생성한 후 가장 많이 생성된 정수 출력하는 함수
	//string maxGenInt = getMaxGenInt();
	//cout << "가장 많이 생성된 정수 : " << maxGenInt << endl;
	 
	// 사용자가 입력한 암호 소문자 대문자 숫자 모두 포함되었는지 확인하는 함수
	//string pw;
	//while (true) {
	//	cout << "암호 : ";
	//	cin >> pw;
	//	bool result = chkPw(pw);
	//	if (result) {
	//		cout << "암호생성" << endl;
	//		break;
	//	}
	//	else {
	//		cout << "대, 소문자와 숫자를 모두 포함하세요." << endl;
	//	}
	//}

	//////////// 클래스
	//Circle circle1;
	//cout << "circle1.getCalcArea() : " << circle1.getCalcArea() << endl;
	//circle1.radius = 100;
	//cout << "circle1.getCalcArea() : " << circle1.getCalcArea() << endl;
	//circle1.printCircleColor();
	//circle1.color = "red";
	//circle1.printCircleColor();

	//사각형클래스, 사각형의 넓이를 출력
	//Rectangle rectangle(10, 2.4);
	//cout << "넓이 : " << rectangle.getArea() << endl;

	// Car, 길이 가격 배기량 이름 출력
	//Car car(3000, 3000, 3000, "차차");
	//car.printCarInfo();

	// 캠핑 운전하기 텐트치기 밥짖기 설거지하기 고기굽기 클래스들, xx가 xx 한다
	//Drive drive("가가");
	//drive.doDrive();
	//Tent tent("나나");
	//tent.setTent();
	//Meal meal("다다");
	//meal.makeMeal();
	//Dishwash dishwash("라라");
	//dishwash.washDish();
	//Meat meat("마마");
	//meat.grillMeat();

	//PrintData printData;
	//printData.print(10);
	//printData.print(10.44);
	//printData.print("string");  // 메서드 오버로딩

	// 클래스 외부파일, 선언부(Bus.h), 기능구현부(Bus.cpp) 나누기
	//Bus bus;
	//bus.setOwner("나");
	//bus.setLength(5);
	//bus.setDisplacement(3000);
	//bus.setColor("white");
	//bus.gear_p();
	//bus.gear_r();
	//bus.gear_n();
	//bus.gear_d();
	//bus.printBusInfo();

	// 생성자 오버로딩
	//Student student1;
	//student1.printStudentInfo();
	//student1.name = "가나다";
	//student1.age = 12;
	//student1.grade = 1;
	//student1.major = "컴";
	//student1.printStudentInfo();
	//Student student2("라마바", 20, 2, "스");
	//student2.printStudentInfo();

	// 객체를 함수 인자값으로 전달, call by reference
	//upgradeStudentInfo(student2);
	//student2.printStudentInfo();

	//// 맵, (key : value)
	//map<string, Student> student_map;

	//Student student1;
	//student1.setNo("s00001");
	//student1.setName("박찬호");

	//Student student2;
	//student2.setNo("s00002");
	//student2.setName("박세리");

	//// 아이템 추가
	//student_map.insert({ student1.getNo(), student1});
	//student_map.insert({ student2.getNo(), student2});

	//for (auto iter = student_map.begin(); iter != student_map.end(); iter++) {  // iterator, 맵의 시작, 맵의 끝까지, 증가
	//	cout << iter->first << endl;  // key
	//	cout << iter->second.getName() << endl;  // value
	//}

	// 찾기
	//auto iter = student_map.find("s00001");
	//cout << iter->second.getName() << endl;

	// 아이템 유무
	//if (student_map.find("s00001") != student_map.end()) {
	//	cout << "o" << endl;
	//}
	//else {
	//	cout << "x" << endl;
	//}

	// 아이템 삭제
	//student_map.erase("s00001");

	// 전체 삭제
	//student_map.clear();

	//for (auto iter = student_map.begin(); iter != student_map.end(); iter++) {
	//	cout << iter->first << endl;
	//}

	//// 학생정보 등록, 조회, 수정, 제거
	//정보, s_no, s_name, s_age, s_grade, s_major
	// 조회, 특정, 전체
	// 학생 정보 수정, 특정나이학년전공, 전체 나이 학년 수정
	// 제거, 특정, 전체

	map<string, Student> students;
	int selectedFunc, selectedSearch, selectedModify, selectedDelete, cnt_no = 0;
	string searchName, noModify, noDelete;
	bool flag = true;
	while (flag) {
		cout << "1. 등록  2. 조회  3. 수정  4. 제거  0. 종료 ";
		cin >> selectedFunc;
		if (selectedFunc == 1) {
			cnt_no++;
			Student student;
			string s_no, s_name, s_major;
			string str_no = to_string(cnt_no);
			s_no += "s";
			for (int i = 0; i < 4 - str_no.length(); i++) {
				s_no += "0";
			}
			s_no += str_no;
			int s_age, s_grade;
			cout << "\n  이름 : ";
			cin >> s_name;
			cout << "  나이 : ";
			cin >> s_age;
			cout << "  학년 : ";
			cin >> s_grade;
			cout << "  전공 : ";
			cin >> s_major;
			cout << endl;
			student.setS_no(s_no);
			student.setS_name(s_name);
			student.setS_age(s_age);
			student.setS_grade(s_grade);
			student.setS_major(s_major);
			students.insert({ s_no, student });
		} else if (selectedFunc == 2) {
			cout << "  1) 특정학생 정보 조회  2) 전체학생 정보 조회 ";
			cin >> selectedSearch;
			if (selectedSearch == 1) {
				cout << "\n    조회할 학생 이름 : ";
				cin >> searchName;
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					if (iter->second.getS_name() == searchName) {
						printStudentInfo(iter->second);
					}
				}
			}
			else if (selectedSearch == 2) {
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					printStudentInfo(iter->second);
				}
			}
		
		}
		else if (selectedFunc == 3) {
			string s_major;
			int s_age, s_grade;
			cout << "  1) 특정학생 정보 수정  2) 전체학생 학년, 나이 증가 ";
			cin >> selectedModify;
			if (selectedModify == 1) {
				cout << "\n    수정할 학생 이름 : ";
				cin >> searchName;
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					if (iter->second.getS_name() == searchName) {
						printStudentInfo(iter->second);
					}
				}
				cout << "    수정할 학생 학번 : ";
				cin >> noModify;
				if (students.find(noModify) != students.end()) {
					cout << "    나이 수정 : ";
					cin >> s_age;
					cout << "    학년 수정 : ";
					cin >> s_grade;
					cout << "    전공 수정 : ";
					cin >> s_major;
					students.find(noModify)->second.setS_age(s_age);
					students.find(noModify)->second.setS_grade(s_grade);
					students.find(noModify)->second.setS_major(s_major);
				}
			}
			else if (selectedModify == 2) {
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					iter->second.setS_age(iter->second.getS_age() + 1);
					iter->second.setS_grade(iter->second.getS_grade() + 1);
				}
			}

		}
		else if (selectedFunc == 4) {
			cout << "  1) 특정학생 정보 삭제  2) 전체학생 정보 삭제 ";
			cin >> selectedDelete;
			if (selectedDelete == 1) {
				cout << "\n    이름 : ";
				cin >> searchName;
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					if (iter->second.getS_name() == searchName) {
						printStudentInfo(iter->second);
					}
				}
				cout << "    삭제할 학생 학번 : ";
				cin >> noDelete;
				if (students.find(noDelete) != students.end()) {
					students.erase(noDelete);
				}
			}
			else if (selectedDelete == 2) {
				students.clear();
			}
		}
		else if (selectedFunc == 0) {
			flag = false;
		}
	}

	return 0;
}

void printStudentInfo(Student student) {
	cout << "\n  「 s_no : " << student.getS_no() << endl;
	cout << "     s_name : " << student.getS_name() << endl;
	cout << "     s_age : " << student.getS_age() << endl;
	cout << "     s_grade : " << student.getS_grade() << endl;
	cout << "     s_major : " << student.getS_major() << " 」\n" << endl;
}


//int getMax(int arrs[3]) {
//	int maxInt = 0;
//	for (int i = 0; i < 3; i++) {
//		if (maxInt < arrs[i]) {
//			maxInt = arrs[i];
//		}
//	}
//
//	return maxInt;
//}
//
//vector<int> getPrime() {
//	vector<int> result;
//	for (int i = 2; i < 101; i++) {
//		int chk = 0;
//		for (int j = 1; j < i + 1; j++) {
//			if (i % j == 0) {
//				chk++;
//			}
//		}
//		if (chk == 2) {
//			result.push_back(i);
//		}
//	}
//	return result;
//}
//
//string changeForm(string str) {
//	string result = "";
//	for (char c : str) {
//		if ((c != '(') && (c != ')')) {
//			result += c;
//		}
//	}
//	return result;
//}
//
//string getMaxGenInt() {
//	int nums[10];
//	for (int i = 0; i < 10; i++) {
//		nums[i] = 0;
//	}
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < 100; i++) {
//		int n = rand() % 10;
//		nums[n] += 1;
//	}
//	string result = "";
//	int max = 0;
//	cout << "nums[10] = {";
//	for (int i = 0; i < 10; i++) {
//		if (i != 9) {
//			cout << nums[i] << ", ";
//		}
//		else {
//			cout << nums[i] << "}" << endl;
//		}
//		if (max < nums[i]) {
//			max = nums[i];
//		}
//	}
//	for (int i = 0; i < 10; i++) {
//		if (nums[i] == max) {
//			result += to_string(i) + " ";
//		}
//	}
//	return result;
//}
//
//bool chkPw(string pw) {
//	int u = 0, l = 0, n = 0;
//	for (char c : pw) {
//		if (65 <= c && c <= 90) {
//			u++;
//		}
//		else if (97 <= c && c <= 122) {
//			l++;
//		}
//		else if (48 <= c && c <= 57) {
//			n++;
//		}
//	}
//	if (u != 0 && l != 0 && n != 0) {
//		return true;
//	}
//	else return false;
//}
//
//void Car::printCarInfo() {
//	printf("길이 : %.2fmm, 가격 : %d만원, 배기량 : %dcc, 이름 : %s", this->length, this->price, this->displacement, this->name.c_str());
//}

//void Student::printStudentInfo() {
//	cout << "name : " << this->name << endl;
//	cout << "age : " << this->age << endl;
//	cout << "grade : " << this->grade << endl;
//	cout << "major : " << this->major << endl;
//}

//void upgradeStudentInfo(Student &s) {
//	s.age++;
//	s.grade++;
//	cout << "s.age : " << s.age << endl;
//	cout << "s.grade : " << s.grade << endl;
//}