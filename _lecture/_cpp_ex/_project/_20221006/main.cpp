#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector> // �⺻ ������� <>
#include <map>
#include "Bus.h"  // �������� ��������� ""

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
//public: // public �Ӽ�, ��ɵ�
//	double pi = 3.14;
//	int radius;
//	string color;
//
//	Circle() {  // �⺻������, ������ �����Ϸ��� ����
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
//	// ���� ������, getter, setter �и����� ����, �Ϲ� ��ɵ�, �޼���, �Լ��鸸 �и�
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
//		cout << (*this).name << "�� �����Ѵ�." << endl;
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
//		cout << (*this).name << "�� ��Ʈģ��." << endl;
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
//		cout << (*this).name << "�� �����´�." << endl;
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
//		cout << (*this).name << "�� �������Ѵ�." << endl;
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
//		cout << (*this).name << "�� �����´�." << endl;
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

	// 3���� ������ �ִ밪 �Լ� �ִ밪 ���
	//int arrs[3];
	//for (int i = 0; i < 3; i++) {
	//	cout << i + 1 << "��° ���� : ";
	//	cin >> arrs[i];
	//}
	//int maxInt = getMax(arrs);
	//cout << "�ִ밪 : " << maxInt << endl;

	// 2�� 100���� �Ҽ� ã�� �Լ�, �Ҽ� ���
	//vector<int> result = getPrime();
	//cout << "2�� 100������ �Ҽ� : ";
	//for (int i : result) {
	//	cout << result.at(i) << " ";
	//}

	// (02)-1234-4567 (042)-123-4567 --> ---�� �Լ�
	//string phoneNum1 = "(02)-1234-4567", phoneNum2 = "(042)-123-4567";
	//string returnNum1 = changeForm(phoneNum1);
	//string returnNum2 = changeForm(phoneNum2);
	//cout << "reform num1 : " << returnNum1 << endl;
	//cout << "reform num2 : " << returnNum2 << endl;

	// 0���� 9���� ���� 100�� ������ �� ���� ���� ������ ���� ����ϴ� �Լ�
	//string maxGenInt = getMaxGenInt();
	//cout << "���� ���� ������ ���� : " << maxGenInt << endl;
	 
	// ����ڰ� �Է��� ��ȣ �ҹ��� �빮�� ���� ��� ���ԵǾ����� Ȯ���ϴ� �Լ�
	//string pw;
	//while (true) {
	//	cout << "��ȣ : ";
	//	cin >> pw;
	//	bool result = chkPw(pw);
	//	if (result) {
	//		cout << "��ȣ����" << endl;
	//		break;
	//	}
	//	else {
	//		cout << "��, �ҹ��ڿ� ���ڸ� ��� �����ϼ���." << endl;
	//	}
	//}

	//////////// Ŭ����
	//Circle circle1;
	//cout << "circle1.getCalcArea() : " << circle1.getCalcArea() << endl;
	//circle1.radius = 100;
	//cout << "circle1.getCalcArea() : " << circle1.getCalcArea() << endl;
	//circle1.printCircleColor();
	//circle1.color = "red";
	//circle1.printCircleColor();

	//�簢��Ŭ����, �簢���� ���̸� ���
	//Rectangle rectangle(10, 2.4);
	//cout << "���� : " << rectangle.getArea() << endl;

	// Car, ���� ���� ��ⷮ �̸� ���
	//Car car(3000, 3000, 3000, "����");
	//car.printCarInfo();

	// ķ�� �����ϱ� ��Ʈġ�� ��¢�� �������ϱ� ������ Ŭ������, xx�� xx �Ѵ�
	//Drive drive("����");
	//drive.doDrive();
	//Tent tent("����");
	//tent.setTent();
	//Meal meal("�ٴ�");
	//meal.makeMeal();
	//Dishwash dishwash("���");
	//dishwash.washDish();
	//Meat meat("����");
	//meat.grillMeat();

	//PrintData printData;
	//printData.print(10);
	//printData.print(10.44);
	//printData.print("string");  // �޼��� �����ε�

	// Ŭ���� �ܺ�����, �����(Bus.h), ��ɱ�����(Bus.cpp) ������
	//Bus bus;
	//bus.setOwner("��");
	//bus.setLength(5);
	//bus.setDisplacement(3000);
	//bus.setColor("white");
	//bus.gear_p();
	//bus.gear_r();
	//bus.gear_n();
	//bus.gear_d();
	//bus.printBusInfo();

	// ������ �����ε�
	//Student student1;
	//student1.printStudentInfo();
	//student1.name = "������";
	//student1.age = 12;
	//student1.grade = 1;
	//student1.major = "��";
	//student1.printStudentInfo();
	//Student student2("�󸶹�", 20, 2, "��");
	//student2.printStudentInfo();

	// ��ü�� �Լ� ���ڰ����� ����, call by reference
	//upgradeStudentInfo(student2);
	//student2.printStudentInfo();

	//// ��, (key : value)
	//map<string, Student> student_map;

	//Student student1;
	//student1.setNo("s00001");
	//student1.setName("����ȣ");

	//Student student2;
	//student2.setNo("s00002");
	//student2.setName("�ڼ���");

	//// ������ �߰�
	//student_map.insert({ student1.getNo(), student1});
	//student_map.insert({ student2.getNo(), student2});

	//for (auto iter = student_map.begin(); iter != student_map.end(); iter++) {  // iterator, ���� ����, ���� ������, ����
	//	cout << iter->first << endl;  // key
	//	cout << iter->second.getName() << endl;  // value
	//}

	// ã��
	//auto iter = student_map.find("s00001");
	//cout << iter->second.getName() << endl;

	// ������ ����
	//if (student_map.find("s00001") != student_map.end()) {
	//	cout << "o" << endl;
	//}
	//else {
	//	cout << "x" << endl;
	//}

	// ������ ����
	//student_map.erase("s00001");

	// ��ü ����
	//student_map.clear();

	//for (auto iter = student_map.begin(); iter != student_map.end(); iter++) {
	//	cout << iter->first << endl;
	//}

	//// �л����� ���, ��ȸ, ����, ����
	//����, s_no, s_name, s_age, s_grade, s_major
	// ��ȸ, Ư��, ��ü
	// �л� ���� ����, Ư�������г�����, ��ü ���� �г� ����
	// ����, Ư��, ��ü

	map<string, Student> students;
	int selectedFunc, selectedSearch, selectedModify, selectedDelete, cnt_no = 0;
	string searchName, noModify, noDelete;
	bool flag = true;
	while (flag) {
		cout << "1. ���  2. ��ȸ  3. ����  4. ����  0. ���� ";
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
			cout << "\n  �̸� : ";
			cin >> s_name;
			cout << "  ���� : ";
			cin >> s_age;
			cout << "  �г� : ";
			cin >> s_grade;
			cout << "  ���� : ";
			cin >> s_major;
			cout << endl;
			student.setS_no(s_no);
			student.setS_name(s_name);
			student.setS_age(s_age);
			student.setS_grade(s_grade);
			student.setS_major(s_major);
			students.insert({ s_no, student });
		} else if (selectedFunc == 2) {
			cout << "  1) Ư���л� ���� ��ȸ  2) ��ü�л� ���� ��ȸ ";
			cin >> selectedSearch;
			if (selectedSearch == 1) {
				cout << "\n    ��ȸ�� �л� �̸� : ";
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
			cout << "  1) Ư���л� ���� ����  2) ��ü�л� �г�, ���� ���� ";
			cin >> selectedModify;
			if (selectedModify == 1) {
				cout << "\n    ������ �л� �̸� : ";
				cin >> searchName;
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					if (iter->second.getS_name() == searchName) {
						printStudentInfo(iter->second);
					}
				}
				cout << "    ������ �л� �й� : ";
				cin >> noModify;
				if (students.find(noModify) != students.end()) {
					cout << "    ���� ���� : ";
					cin >> s_age;
					cout << "    �г� ���� : ";
					cin >> s_grade;
					cout << "    ���� ���� : ";
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
			cout << "  1) Ư���л� ���� ����  2) ��ü�л� ���� ���� ";
			cin >> selectedDelete;
			if (selectedDelete == 1) {
				cout << "\n    �̸� : ";
				cin >> searchName;
				for (auto iter = students.begin(); iter != students.end(); iter++) {
					if (iter->second.getS_name() == searchName) {
						printStudentInfo(iter->second);
					}
				}
				cout << "    ������ �л� �й� : ";
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
	cout << "\n  �� s_no : " << student.getS_no() << endl;
	cout << "     s_name : " << student.getS_name() << endl;
	cout << "     s_age : " << student.getS_age() << endl;
	cout << "     s_grade : " << student.getS_grade() << endl;
	cout << "     s_major : " << student.getS_major() << " ��\n" << endl;
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
//	printf("���� : %.2fmm, ���� : %d����, ��ⷮ : %dcc, �̸� : %s", this->length, this->price, this->displacement, this->name.c_str());
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