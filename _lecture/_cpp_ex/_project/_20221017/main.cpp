#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


//class Car {
//private:
//
//	string name;
//	int length;
//
//public:
//
//	Car(string name, int length) : name{name}, length{length} {}
//
//	~Car(){  // �Ҹ���, ������ �ݴ�� ��ü�� ������� ȣ��
//		cout << "destructor" << endl;
//	}
//
//	string getName() { return this->name; };
//	int getLength() { return this->length; };
//
//};

//class Circle {
//private:
//
//	int radius;
//	double area, outLength;
//
//public:
//
//	Circle() {
//
//	}
//
//	Circle(int radius) : radius{ radius } {
//		this->area = pow(this->radius, 2) * 3.14;
//		this->outLength = this->radius * 2 * 3.14;
//	};
//
//	void printArea() {
//		printf("area : %f\n", this->area);
//	}
//
//	void printOutLength() {
//		printf("outLength : %f\n", this->outLength);
//	}
//
//	int getRadius() {
//		return this->radius;
//	}
//
//	double getArea() {
//		return this->area;
//	}
//
//	double getOutLength() {
//		return this->outLength;
//	}
//
//};

//class AlarmTime {
//private:
//
//	int hour;
//	int minute;
//	int second;
//
//public:
//
//	AlarmTime(int hour, int minute, int second) : hour{ hour }, minute{ minute }, second{ second } {};
//
//	void printAlarmTime() {
//		printf("%02d�� %02d�� %02d�� �˶�.\n", this->getHour(), this->getMinute(), this->getSecond());
//	}
//
//	int getHour() {
//		return this->hour;
//	}
//	int getMinute() {
//		return this->minute;
//	}
//	int getSecond() {
//		return this->second;
//	}
//
//};

//bool compareAlarm(AlarmTime a1, AlarmTime a2) {
//	if (a1.getHour() < a2.getHour()) {
//		return true;
//	}
//	else if (a1.getHour() == a2.getHour()) {
//		if (a1.getMinute() < a2.getMinute()) {
//			return true;
//		}
//		else if (a1.getMinute() == a2.getMinute()) {
//			if (a1.getSecond() < a2.getSecond()) {
//				return true;
//			}
//		}
//	}
//	return false;
//}

//class Student {
//private:
//	string name;
//	int korScr;
//	int engScr;
//	int matScr;
//public:
//
//	Student(string name, int korScr, int engScr, int matScr) : name{name}, korScr{korScr}, engScr{engScr}, matScr{matScr} {};
//
//	string getName() { return this->name; };
//	int getKorScr() { return this->korScr; };
//	int getEngScr() { return this->engScr; };
//	int getMatScr() { return this->matScr; };
//
//
//};

//bool compare_name_ascending(Student s1, Student s2) {
//	return s1.getName() < s2.getName();
//}
//bool compare_name_descending(Student s1, Student s2) {
//	return s1.getName() > s2.getName();
//}
//bool compare_korScr_ascending(Student s1, Student s2) {
//	return s1.getKorScr() < s2.getKorScr();
//}
//bool compare_korScr_descending(Student s1, Student s2) {
//	return s1.getKorScr() > s2.getKorScr();
//}
//bool compare_engScr_ascending(Student s1, Student s2) {
//	return s1.getEngScr() < s2.getEngScr();
//}
//bool compare_engScr_descending(Student s1, Student s2) {
//	return s1.getEngScr() > s2.getEngScr();
//}
//bool compare_matScr_ascending(Student s1, Student s2) {
//	return s1.getMatScr() < s2.getMatScr();
//}
//bool compare_matScr_descending(Student s1, Student s2) {
//	return s1.getMatScr() > s2.getMatScr();
//}


//class Turbo {
//private:
//
//	int price;
//
//public:
//
//	Turbo(int price) : price{ price } {}
//
//	~Turbo() {
//		cout << "Turbo destructor." << endl;
//	}
//
//	void setPrice(int price) {
//		this->price = price;
//	}
//	int getPrice() {
//		return this->price;
//	}
//
//};

//class Car {
//private:
//
//	string name;
//	int length;
//	int base_price;
//	Turbo* turboPtr = nullptr;
//
//public:
//
//	Car(string name, int length, int base_price) : name{ name }, length{ length }, base_price{ base_price } {}
//
//	~Car() {
//		cout << "Car destructor." << endl;
//		delete turboPtr;  // Car �Ҹ�� Turbo �Ҹ�
//	}
//
//	void printCarInfo() {
//		cout << "name : " << this->getName() << endl;
//		cout << "length : " << this->getLength() << endl;
//		cout << "price : ";
//		if (turboPtr == nullptr) {
//			cout << this->getBase_price() << endl;
//		}
//		else {
//			cout << this->getBase_price() + this->turboPtr->getPrice() << endl;
//		}
//	}
//
//	void setTurboPtr(Turbo* turboPtr) { this->turboPtr = turboPtr; }
//	string getName() { return this->name; }
//	int getLength() { return this->length; }
//	int getBase_price() { return this->base_price; }
//
//};

//class User {
//private:
//
//	string id;
//	string pw;
//	string email;
//
//public:
//
//	User(string id, string pw, string email) : id{ id }, pw{ pw }, email{ email } {}
//
//};

//class InternetEvent {
//private:
//
//	vector<User>* usersPtr = nullptr;
//	int dcRate;
//
//public:
//
//	InternetEvent(vector<User>* usersPtr) : usersPtr{ usersPtr } {}
//
//	void printDcRate() {
//		if (usersPtr->size() < 5) {
//			setDcRate(0);
//			cout << "������ : " << this->getDcRate() << "%" << endl;
//		}
//		else {
//			setDcRate(30);
//			cout << "������ : " << this->getDcRate() << "%" << endl;
//		}
//	}
//
//	void setDcRate(int dcRate) { this->dcRate = dcRate; }
//	int getDcRate() { return this->dcRate; }
//
//
//};


int main() {

	//// ������
	//short s = 10;
	//int i = 20;
	//double d = 3.14;

	//short* sPtr;
	//int* iPtr;
	//double* dPtr;

	//sPtr = &s;
	//iPtr = &i;
	//dPtr = &d;

	//cout << "s : " << s << endl;
	//cout << "i : " << i << endl;
	//cout << "d : " << d << endl;
	//cout << "sPtr : " << sPtr << endl;
	//cout << "iPtr : " << iPtr << endl;
	//cout << "dPtr : " << dPtr << endl;
	//cout << "*sPtr : " << *sPtr << endl;
	//cout << "*iPtr : " << *iPtr << endl;
	//cout << "*dPtr : " << *dPtr << endl;

	//int* p1 = nullptr;
	//p1 = new int{ 5 };
	//cout << "*p1 : " << *p1 << endl;
	//delete p1;  // �����Ͱ� ����Ű�� ��ü �޸� ����, �����ʹ� ����

	//int* p2 = nullptr;
	//p2 = new int[5];
	//p2[0] = 10;
	//p2[1] = 20;
	//p2[2] = 30;
	//p2[3] = 40;
	//p2[4] = 50;
	//for (int i = 0; i < 5; i++) {
	//	printf("*(p2 + &d) : %d\n", i, *(p2 + i));
	//}
	//delete[] p2;

	//int* p3 = nullptr;
	//p3 = new int[3]{10, 20, 30};

	// ���� ��ü ����
	//Car* cPtr = nullptr;
	//cPtr = new Car("mycar", 5);
	//cout << "cPtr->getName() : " << cPtr->getName() << endl;
	//cout << "cPtr->getLength() : " << cPtr->getLength() << endl;
	//delete cPtr;
	//cPtr = new Car("yourcar", 1);
	//cout << "cPtr->getName() : " << cPtr->getName() << endl;
	//cout << "cPtr->getLength() : " << cPtr->getLength() << endl;
	//delete cPtr;

	// Q) ���� �迭�� �����. �迭�� ������� ����ڰ� ���� �Է��Ѵ�.
    //    ������ �迭�� ����ڷκ��� ���� ������ �����ϴ� �ڵ带 �ۼ�����.
	//int size;
	//int* arrPtr = nullptr;
	//cout << "size : ";
	//cin >> size;
	//arrPtr = new int[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "���� " << i + 1 << " : ";
	//	cin >> *(arrPtr + i);
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("���� %d : %d\n", i + 1, *(arrPtr + i));
	//}
	//delete[] arrPtr;

    // Q) ���� �迭�� �����. �迭�� ������� ����ڰ� ���� �Է��Ѵ�.
    //    ������ �迭�� ����ڷκ��� ���� �̸��� �����ϴ� �ڵ带 �ۼ�����.
	//int size;
	//string* arrPtr = nullptr;
	//cout << "size : ";
	//cin >> size;
	//arrPtr = new string[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "�̸� " << i + 1 << " : ";
	//	cin >> *(arrPtr + i);
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("�̸� %d : %s\n", i + 1, (*(arrPtr + i)).c_str());
	//}
	//delete[] arrPtr;

    // Q) Circle Ŭ������ ������ ���� �����.
    //     - ��� �ʵ�: ������(radius, 1~100 ���� ���� �̿�), ����(area), �ѷ�����(outLength)
    //     + ��� �Լ�: ���� ���(printArea), �ѷ� ���� ���(printOutLength)
    //    ���� �迭�� ����� ���̰� 5000�̻��̰� �ѷ����̰� 150�̻��� Circle Ŭ������ 5�� ��������.
    //    ����� 5�� Circle�� ���̿� �ѷ����̸� �������.
	//int i=0, radius;
	//Circle* circle = nullptr;
	//Circle* arrPtr = nullptr;
	//arrPtr = new Circle[5];
	//srand(time(NULL));
	//while (true) {
	//	radius = rand() % 100 + 1;
	//	circle = new Circle(radius);
	//	if (circle->getArea() >= 5000 && circle->getOutLength() >= 150) {
	//		*(arrPtr + i) = *circle;
	//		i++;
	//	}
	//  delete circle;
	//	if (i == 5) {
	//		break;
	//	}
	//}
	//for (int i = 0; i < 5; i++) {
	//	printf("������ : %d, ���� : %.2f, �ѷ����� : %.2f\n", (arrPtr + i)->getRadius(), (arrPtr + i)->getArea(), (arrPtr + i)->getOutLength());
	//}
	//delete[] arrPtr;

    // Q) �˶� ��� ���α׷��� ������.
    //    �ð�, ��, �ʸ� ��� �ʵ�(private)�� ���� AlarmTime Ŭ������ �����,
    //    ����ڰ� �˶��� �߰��� �� ���� �������� AlarmTime Ŭ������ ��������.
    //    ������ AlarmTime �ν��Ͻ��� vector�� �����ϰ� �ð��� �������� ������������ ��´� ����� ��������.
	//int hour, minute, second;
	//string selNum;
	//AlarmTime* alarmPtr = nullptr;
	//vector<AlarmTime> alarms;
	//while (true) {
	//	cout << "1. �˶� �߰�  2. �˶� ���  3. ����  ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "�� : ";
	//		cin >> hour;
	//		cout << "�� : ";
	//		cin >> minute;
	//		cout << "�� : ";
	//		cin >> second;
	//		alarmPtr = new AlarmTime(hour, minute, second);
	//		alarms.push_back(*alarmPtr);
	//		delete alarmPtr;
	//	}
	//	else if (selNum == "2") {
	//		sort(alarms.begin(), alarms.end(), compareAlarm);
	//		for (int i = 0; i < alarms.size(); i++) {
	//			alarms[i].printAlarmTime();
	//		}
	//	}
	//	else if (selNum == "3") {
	//		break;
	//	}
	//}

    // Q) �л��� �̸�, ���� ����, ���� ����, ���� ������ ��� �ʵ�� ����
    //    �л� Ŭ����(Student)�� ���� �����ϰ� vector�� �����Ѵ�.
    //    ��ü �л� ���� �� �� ���� ��Ȳ���� ��� �л��� ������ �Է¹޾Ҵٸ�
    //    �̸��� ���� ������ �������� ���� ������ ���� �������� �����ϴ� ���α׷��� ������.
	//int korScr, engScr, matScr;
	//string selNum, selSub, selAorD, name;
	//vector<Student> students;
	//Student* studentPtr = nullptr;
	//while (true) {
	//	cout << "1. ���� �Է�  2. ���  3. ����  ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "�̸� : ";
	//		cin >> name;
	//		cout << "���� : ";
	//		cin >> korScr;
	//		cout << "���� : ";
	//		cin >> engScr;
	//		cout << "���� : ";
	//		cin >> matScr;
	//		studentPtr = new Student(name, korScr, engScr, matScr);
	//		students.push_back(*studentPtr);
	//		delete studentPtr;
	//	}
	//	else if (selNum == "2") {
	//		cout << "  1. �̸� ����  2. ���� ����  ";
	//		cin >> selNum;
	//		if (selNum == "1") {
	//			cout << "    1. ��������  2. ��������  ";
	//			cin >> selAorD;
	//			if (selAorD == "1") {
	//				sort(students.begin(), students.end(), compare_name_ascending);
	//				for (Student s : students) {
	//					printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//				}
	//			}
	//			else if (selAorD == "2") {
	//				sort(students.begin(), students.end(), compare_name_descending);
	//				for (Student s : students) {
	//					printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//				}
	//			}
	//		}
	//		else if (selNum == "2") {
	//			cout << "    1. ������������  2. ������������  3. ������������  ";
	//			cin >> selSub;
	//			cout << "      1. ��������  2. ��������  ";
	//			cin >> selAorD;
	//			if (selSub == "1") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_korScr_ascending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_korScr_descending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//			else if (selSub == "2") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_engScr_ascending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_engScr_descending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//			else if (selSub == "3") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_matScr_ascending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_matScr_descending);
	//					for (Student s : students) {
	//						printf("�̸� : %s, ���� : %d, ���� : %d, ���� : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else if (selNum == "3") {
	//		break;
	//	}
	//}

	// Ŭ���� ������ ���� ��ü ����
	//Car* carPtr = nullptr;
	//carPtr = new Car("genesis", 5, 1000);
	//carPtr->printCarInfo();
	//delete carPtr;
	//carPtr = new Car("GV80", 6, 2000);
	//carPtr->setTurboPtr(new Turbo(200));  // �ͺ��� ����� ���������Ͽ� set
	//carPtr->printCarInfo();
	//delete carPtr;  // Car �Ҹ��ڿ� delete turboPtr

	//Q) ���ͳ� ���� �̺�Ʈ�� �����Ѵ�. 
    //   �����ڼ��� 5�� �̻��̸� 30%���� �̺�Ʈ�� �����ϰ�
    //   �����ڼ��� 5�� �̸��̸� �̺�Ʈ�� ����Ѵ�.
    //   �̺�Ʈ(InternetEvent)�� �����(User)�� ����� 
    //   ����� ���� ���� �̺�Ʈ ���η��� ��µǴ� �ڵ带 ������.
	//User* userPtr = nullptr;
	//vector<User>* usersPtr = nullptr;
	//InternetEvent* eventPtr = nullptr;
	//usersPtr = new vector<User>;
	//string selNum, id, pw, email;
	//while (true) {
	//	cout << "1. ȸ������  2. ���� �̺�Ʈ ����  3. �̺�Ʈ ���η� ���  4. ����  ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "ID : ";
	//		cin >> id;
	//		cout << "PW : ";
	//		cin >> pw;
	//		cout << "Email : ";
	//		cin >> email;
	//		userPtr = new User(id, pw, email);
	//		usersPtr->push_back(*userPtr);
	//	}
	//	else if (selNum == "2") {
	//		if (eventPtr == nullptr) {
	//			eventPtr = new InternetEvent(usersPtr);
	//		}
	//	}
	//	else if (selNum == "3") {
	//		if (eventPtr == nullptr) {
	//			cout << "�������� �̺�Ʈ�� �����ϴ�." << endl;
	//		}
	//		else {
	//			eventPtr->printDcRate();
	//		}
	//	}
	//	else if (selNum == "4") {
	//		break;
	//	}
	//}

	
}