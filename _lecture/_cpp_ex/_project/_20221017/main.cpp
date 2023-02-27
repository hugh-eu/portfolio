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
//	~Car(){  // 소멸자, 생성자 반대로 객체가 사라질때 호출
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
//		printf("%02d시 %02d분 %02d초 알람.\n", this->getHour(), this->getMinute(), this->getSecond());
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
//		delete turboPtr;  // Car 소멸시 Turbo 소멸
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
//			cout << "할인율 : " << this->getDcRate() << "%" << endl;
//		}
//		else {
//			setDcRate(30);
//			cout << "할인율 : " << this->getDcRate() << "%" << endl;
//		}
//	}
//
//	void setDcRate(int dcRate) { this->dcRate = dcRate; }
//	int getDcRate() { return this->dcRate; }
//
//
//};


int main() {

	//// 포인터
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
	//delete p1;  // 포인터가 가리키는 객체 메모리 삭제, 포인터는 남음

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

	// 동적 객체 생성
	//Car* cPtr = nullptr;
	//cPtr = new Car("mycar", 5);
	//cout << "cPtr->getName() : " << cPtr->getName() << endl;
	//cout << "cPtr->getLength() : " << cPtr->getLength() << endl;
	//delete cPtr;
	//cPtr = new Car("yourcar", 1);
	//cout << "cPtr->getName() : " << cPtr->getName() << endl;
	//cout << "cPtr->getLength() : " << cPtr->getLength() << endl;
	//delete cPtr;

	// Q) 동적 배열을 만든다. 배열의 사이즈는 사용자가 직접 입력한다.
    //    생성된 배열에 사용자로부터 받은 정수를 저장하는 코드를 작성하자.
	//int size;
	//int* arrPtr = nullptr;
	//cout << "size : ";
	//cin >> size;
	//arrPtr = new int[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "정수 " << i + 1 << " : ";
	//	cin >> *(arrPtr + i);
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("정수 %d : %d\n", i + 1, *(arrPtr + i));
	//}
	//delete[] arrPtr;

    // Q) 동적 배열을 만든다. 배열의 사이즈는 사용자가 직접 입력한다.
    //    생성된 배열에 사용자로부터 받은 이름을 저장하는 코드를 작성하자.
	//int size;
	//string* arrPtr = nullptr;
	//cout << "size : ";
	//cin >> size;
	//arrPtr = new string[size];
	//for (int i = 0; i < size; i++) {
	//	cout << "이름 " << i + 1 << " : ";
	//	cin >> *(arrPtr + i);
	//}
	//for (int i = 0; i < size; i++) {
	//	printf("이름 %d : %s\n", i + 1, (*(arrPtr + i)).c_str());
	//}
	//delete[] arrPtr;

    // Q) Circle 클래스를 다음과 같이 만든다.
    //     - 멤버 필드: 반지름(radius, 1~100 사이 난수 이용), 넓이(area), 둘레길이(outLength)
    //     + 멤버 함수: 넓이 출력(printArea), 둘레 길이 출력(printOutLength)
    //    동적 배열을 만들고 넓이가 5000이상이고 둘레길이가 150이상인 Circle 클래스를 5개 저장하자.
    //    저장된 5개 Circle의 넓이와 둘레길이를 출력하자.
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
	//	printf("반지름 : %d, 넓이 : %.2f, 둘레길이 : %.2f\n", (arrPtr + i)->getRadius(), (arrPtr + i)->getArea(), (arrPtr + i)->getOutLength());
	//}
	//delete[] arrPtr;

    // Q) 알람 기록 프로그램을 만들자.
    //    시간, 분, 초를 멤버 필드(private)로 갖는 AlarmTime 클래스를 만들고,
    //    사용자가 알람을 추가할 때 마다 동적으로 AlarmTime 클래스를 생성하자.
    //    생성된 AlarmTime 인스턴스는 vector에 저장하고 시간을 기준으로 오름차순으로 출력는 기능을 구현하자.
	//int hour, minute, second;
	//string selNum;
	//AlarmTime* alarmPtr = nullptr;
	//vector<AlarmTime> alarms;
	//while (true) {
	//	cout << "1. 알람 추가  2. 알람 출력  3. 종료  ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "시 : ";
	//		cin >> hour;
	//		cout << "분 : ";
	//		cin >> minute;
	//		cout << "초 : ";
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

    // Q) 학생의 이름, 국어 점수, 영어 점수, 수학 점수를 멤버 필드로 갖는
    //    학생 클래스(Student)를 동적 생성하고 vector에 저장한다.
    //    전체 학생 수를 알 수 없는 상황에서 모든 학생의 정보를 입력받았다면
    //    이름과 과목별 점수를 기준으로 내림 차순과 오름 차숨으로 정렬하는 프로그램을 만들자.
	//int korScr, engScr, matScr;
	//string selNum, selSub, selAorD, name;
	//vector<Student> students;
	//Student* studentPtr = nullptr;
	//while (true) {
	//	cout << "1. 점수 입력  2. 출력  3. 종료  ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "이름 : ";
	//		cin >> name;
	//		cout << "국어 : ";
	//		cin >> korScr;
	//		cout << "영어 : ";
	//		cin >> engScr;
	//		cout << "수학 : ";
	//		cin >> matScr;
	//		studentPtr = new Student(name, korScr, engScr, matScr);
	//		students.push_back(*studentPtr);
	//		delete studentPtr;
	//	}
	//	else if (selNum == "2") {
	//		cout << "  1. 이름 정렬  2. 점수 정렬  ";
	//		cin >> selNum;
	//		if (selNum == "1") {
	//			cout << "    1. 오름차순  2. 내림차순  ";
	//			cin >> selAorD;
	//			if (selAorD == "1") {
	//				sort(students.begin(), students.end(), compare_name_ascending);
	//				for (Student s : students) {
	//					printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//				}
	//			}
	//			else if (selAorD == "2") {
	//				sort(students.begin(), students.end(), compare_name_descending);
	//				for (Student s : students) {
	//					printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//				}
	//			}
	//		}
	//		else if (selNum == "2") {
	//			cout << "    1. 국어점수기준  2. 영어점수기준  3. 수학점수기준  ";
	//			cin >> selSub;
	//			cout << "      1. 오름차순  2. 내림차순  ";
	//			cin >> selAorD;
	//			if (selSub == "1") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_korScr_ascending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_korScr_descending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//			else if (selSub == "2") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_engScr_ascending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_engScr_descending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//			else if (selSub == "3") {
	//				if (selAorD == "1") {
	//					sort(students.begin(), students.end(), compare_matScr_ascending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//				else if (selAorD == "2") {
	//					sort(students.begin(), students.end(), compare_matScr_descending);
	//					for (Student s : students) {
	//						printf("이름 : %s, 국어 : %d, 영어 : %d, 수학 : %d\n", s.getName().c_str(), s.getKorScr(), s.getEngScr(), s.getMatScr());
	//					}
	//				}
	//			}
	//		}
	//	}
	//	else if (selNum == "3") {
	//		break;
	//	}
	//}

	// 클래스 내에서 동적 객체 생성
	//Car* carPtr = nullptr;
	//carPtr = new Car("genesis", 5, 1000);
	//carPtr->printCarInfo();
	//delete carPtr;
	//carPtr = new Car("GV80", 6, 2000);
	//carPtr->setTurboPtr(new Turbo(200));  // 터보란 기능을 동적생성하여 set
	//carPtr->printCarInfo();
	//delete carPtr;  // Car 소멸자에 delete turboPtr

	//Q) 인터넷 가입 이벤트를 진행한다. 
    //   가입자수가 5명 이상이면 30%할인 이벤트를 진행하고
    //   가입자수가 5명 미만이면 이벤트를 취소한다.
    //   이벤트(InternetEvent)와 사용자(User)를 만들고 
    //   사용자 수에 따라 이벤트 할인률이 출력되는 코드를 만들어보자.
	//User* userPtr = nullptr;
	//vector<User>* usersPtr = nullptr;
	//InternetEvent* eventPtr = nullptr;
	//usersPtr = new vector<User>;
	//string selNum, id, pw, email;
	//while (true) {
	//	cout << "1. 회원가입  2. 가입 이벤트 시작  3. 이벤트 할인률 출력  4. 종료  ";
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
	//			cout << "진행중인 이벤트가 없습니다." << endl;
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