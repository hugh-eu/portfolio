#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>  // std algorithm

using namespace std;


//namespace ns_01 {
//	void  fun_fire() {
//		cout << "ns_01 : Fire!!" << endl;
//	}
//}
//
//namespace ns_02 {
//	void fun_fire() {  // 함수, 클래스 등등 구현가능
//		cout << "ns_02 : Fire!!" << endl;
//	}
//}

//class Student {
//private:
//	string s_no;
//	string s_name;
//	int s_age;
//	int s_grade;
//
//public:
//
//	Student() {
//		cout << "Student DEFAULT CONSTRUCTOR" << endl;
//	}
//
//	//Student(string s_no, string s_name, int s_age, int s_grade) {
//	//	cout << "Student OVERLOADING CONSTRUCTOR" << endl;
//	//	this->s_no = s_no;
//	//	this->s_name = s_name;
//	//	this->s_age = s_age;
//	//	this->s_grade = s_grade;
//	//}
//
//	Student(string s_no, string s_name, int s_age, int s_grade) : s_no( s_no ), s_name{ s_name }, s_age{ s_age }, s_grade{ s_grade } {}  // 멤버필드 초기화 리스트, 소괄호, 중괄호
//
//	Student(int s_age, int s_grade) : s_age{ 19 }, s_grade{ 1 } {}
//
//	string getS_no() {
//		return s_no;
//	}
//	string getS_name() {
//		return s_name;
//	}
//	int getS_age() {
//		return s_age;
//	}
//	int getS_grade() {
//		return s_grade;
//	}
//
//};

//class Triangle {
//private:
//
//	int width;
//	int height;
//	double area;
//
//public:
//
//	Triangle(int width, int height) : width{ width }, height{ height } {}
//
//	void calculateArea() {
//		this->area = (this->width * this->height) / 2.0;
//	}
//	
//	double getArea() {
//		return area;
//	}
//
//};

//class Rectangle {
//private:
//	int width;
//	int length;
//	int area;
//	int perimeter;
//
//public:
//
//	Rectangle(int width, int length) : width{width}, length{length}{}
//
//	void calcArea() {
//		this->area = this->width * this->length;
//	}
//
//	void calcPerimeter() {
//		this->perimeter = (this->width + this->length) * 2;
//	}
//
//	int getArea() {
//		return area;
//	}
//
//	int getPerimeter() {
//		return perimeter;
//	}
//
//};

//class Student2 {
//private:
//
//	int s_no;
//	string s_name;
//
//public:
//
//	Student2() {
//
//	}
//
//	Student2(int s_no, string s_name) : s_no(s_no), s_name{ s_name } {}  // 멤버필드 초기화 리스트, 소괄호, 중괄호
//
//	void setS_no(int s_no) {
//		this->s_no = s_no;
//	}
//	int getS_no() {
//		return s_no;
//	}
//	void setS_name(string s_name) {
//		this->s_name = s_name;
//	}
//	string getS_name() {
//		return s_name;
//	}
//};

//class Student3 {
//private:
//	string name;
//	int age;
//	int grade;
//
//public:
//	Student3(string name, int age, int grade) : name{ name }, age{ age }, grade{ grade } {}
//
//	void setName(string name) {
//		this->name = name;
//	}
//	string getName() {
//		return this->name;
//	}
//	void setAge(int age) {
//		this->age = age;
//	}
//	int getAge() {
//		return this->age;
//	}
//	void setGrade(int grade) {
//		this->grade = grade;
//	}
//	int getGrade() {
//		return this->grade;
//	}
//
//};
//bool compare_student_age(Student3 s1, Student3 s2) {
//	return s1.getAge() > s2.getAge();
//}
//bool compare_student_grade(Student3 s1, Student3 s2) {
//	return s1.getGrade() > s2.getGrade();
//}

vector<int> getMaxAndMin(vector<int> nums) {
	int max = 0, min = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (i == 0) {
			max = nums[i];
			min = nums[i];
		}
		else {
			if (nums[i] > max) {
				max = nums[i];
			}
			if (nums[i] < min) {
				min = nums[i];
			}
		}
	}
	vector<int> result{ max, min };
	return result;
}

bool compare_strs_alphabet(string s1, string s2) {
	return s1 < s2;
}



class Rectangle {
private:
	int width;
	int height;
	int area;

public:

	Rectangle(int width, int height) {
		this->width = width;
		this->height = height;
		this->area = this->width * this->height;
	}

	int getWidth() {
		return this->width;
	}
	int getHeight() {
		return this->height;
	}
	int getArea() {
		return this->area;
	}

};

class Student {
private:
	string name;
	int age;
	int score;

public:
	Student(string name, int age, int score) : name{name}, age{age}, score{score} {}

	string getName() {
		return this->name;
	}
	int getAge() {
		return this->age;
	}
	int getScore() {
		return this->score;
	}

};

bool compare_student_age(Student s1, Student s2) {
	return s1.getAge() > s2.getAge();
}

bool compare_student_score(Student s1, Student s2) {
	return s1.getScore() > s2.getScore();
}

class Number {
private:
	string name;
	string phone;

public:
	Number() {}
	Number(string name, string phone) : name{name}, phone{phone} {}

	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return this->name;
	}

	void setPhone(string phone) {
		this->phone = phone;
	}
	string getPhone() {
		return this->phone;
	}
};


int main() {

	// namespace 파이썬 모듈, 자바 패키지와 비슷
	//ns_01::fun_fire();
	//ns_02::fun_fire();
	// 20221007 프로젝트 네임스페이스로 처리완

	//// 클래스 속성 + 기능, 멤버
	//// 멤버 필드(속성) + 멤버 함수(기능)
	//// 클래스 객체, 인스턴스
	//// 클래스. 멤버필드 초기화, 초기화 리스트, class student
	//Student student1;
	//cout << "s_no : " << student1.getS_no() << endl;
	//cout << "s_name : " << student1.getS_name() << endl;
	//cout << "s_age : " << student1.getS_age() << endl;
	//cout << "s_grade : " << student1.getS_grade() << endl;

	//Student student2("s00001", "홍길동", 19, 1);
	//cout << "s_no : " << student2.getS_no() << endl;
	//cout << "s_name : " << student2.getS_name() << endl;
	//cout << "s_age : " << student2.getS_age() << endl;
	//cout << "s_grade : " << student2.getS_grade() << endl;

	//Student student3(22, 4);
	//cout << "s_no : " << student3.getS_no() << endl;
	//cout << "s_name : " << student3.getS_name() << endl;
	//cout << "s_age : " << student3.getS_age() << endl;
	//cout << "s_grade : " << student3.getS_grade() << endl;

	////class Triangle
	//Triangle triangle(100, 200);
	//triangle.calculateArea();
	//cout << "area : " << triangle.getArea() << endl;

	//// 사각형 클래스 Rectangle 넓이 둘레길이 출력
	//Rectangle rectangle(10, 20);
	//rectangle.calcArea();
	//rectangle.calcPerimeter();
	//cout << "area : " << rectangle.getArea() << endl;
	//cout << "perimeter : " << rectangle.getPerimeter() << endl;

	//// 객체 배열
	//Student2 students1[10];
	//for (int i = 0; i < sizeof(students1) / sizeof(Student2); i++) {
	//	students1[i].setS_no(i);
	//	students1[i].setS_name("student " + to_string(i));
	//}
	//for (int i = 0; i < sizeof(students1) / sizeof(Student2); i++) {
	//	printf("s_no : %d, s_name : %s\n", students1[i].getS_no(), students1[i].getS_name().c_str());
	//}
	//
	//Student2 students2[]{ Student2(0, "홍길동"), Student2(1, "가나다"), Student2(2, "나나나") };
	//for (int i = 0; i < sizeof(students2) / sizeof(Student2); i++) {
	//	printf("s_no : %d, s_name : %s\n", students2[i].getS_no(), students2[i].getS_name().c_str());
	//}
	//
	//Student2 students3[]{Student2(), Student2(), Student2()};
	//for (int i = 0; i < sizeof(students3) / sizeof(Student2); i++) {
	//	students3[i].setS_no(i);
	//	students3[i].setS_name("student " + to_string(i));
	//}
	//for (int i = 0; i < sizeof(students3) / sizeof(Student2); i++) {
	//	printf("s_no : %d, s_name : %s\n", students3[i].getS_no(), students3[i].getS_name().c_str());
	//}

	////vector
	//vector<int> scores1{ 10,20,30,40,50 };  // 선언과 초기화 동시에
	//for (auto score : scores1) {
	//	cout << "score : " << score << endl;
	//}
	//for (int i = 0; i < scores1.size(); i++) {
	//	printf("score[%d] : %d\n", i, scores1[i]);
	//}
	//
	//vector<Student2> students1;
	//students1.push_back(Student2(0, "가나다"));  // 뒤쪽부터 추가
	//students1.push_back(Student2(1, "나나나"));
	//students1.push_back(Student2(2, "다다다"));
	//for (auto iter = students1.begin(); iter != students1.end(); iter++) {
	//	printf("s_no : %d, s_name : %s\n", (*iter).getS_no(), (*iter).getS_name().c_str());
	//}
	//auto iter = students1.begin();
	//cout << (*(iter + 1)).getS_no() << endl;
	//cout << "students1.size() : " << students1.size() << endl;
	//students1.pop_back();  // 뒤쪽부터 삭제
	//cout << "students1.size() : " << students1.size() << endl;
	//students1.pop_back();  // 뒤쪽부터 삭제
	//cout << "students1.size() : " << students1.size() << endl;
	//
	//for (auto score : scores1) {
	//	score = score * 10;
	//}
	//for (auto iter = scores1.begin(); iter != scores1.end(); iter++) {
	//	cout << "score : " << *iter << endl;
	//}
	//
	//for (auto &score : scores1) {
	//	score = score * 10;
	//}
	//for (auto iter = scores1.begin(); iter != scores1.end(); iter++) {
	//	cout << "score : " << *iter << endl;
	//}
	//
	//for (auto iter = scores1.begin(); iter != scores1.end(); iter++) {
	//	*iter = *iter * 10;
	//}
	//for (auto iter = scores1.begin(); iter != scores1.end(); iter++) {
	//	cout << "score : " << *iter << endl;
	//}
	//
	//// front & back, value
	//cout << "scores1.front() : " << scores1.front() << endl;
	//cout << "scores1.back() : " << scores1.back() << endl;
	//
	//// begin & end, reference
	//cout << "*scores1.begin() : " << *scores1.begin() << endl;
	//cout << "*(scores1.end() - 1) : " << *(scores1.end() - 1) << endl;
	//
	//scores1.erase(scores1.begin() + 2);  // 특정 인덱스 삭제
	//for (auto score : scores1) {
	//	cout << "score : " << score << endl;
	//}
	//
	//cout << "scores1.size() : " << scores1.size() << endl;
	//scores1.clear();  // 전체 삭제
	//cout << "scores1.size() : " << scores1.size() << endl;
	//
	//vector<int> vec1{ 1,2,3,4,5 };
	//vector<int> vec2{ vec1 };  // 벡터 복사
	//for (auto vec : vec2) {
	//	cout << vec << endl;
	//}
	//if (vec1 == vec2) {
	//	cout << "같다" << endl;
	//}
	//else {
	//	cout << "다르다" << endl;
	//}
	//cout << &vec1 << endl;
	//cout << &vec2 << endl;
	//
	//*(vec2.begin() + 1) = 100;
	//if (vec1 == vec2) {
	//	cout << "같다" << endl;
	//}
	//else {
	//	cout << "다르다" << endl;
	//}

	//// 자료구조 STL: standard template library, 자바 컬렉션, 파이썬 컨테이너
	//// 정렬(sort)
	//vector<Student3> students;
	//students.push_back(Student3("박찬호", 19, 4));
	//students.push_back(Student3("박세리", 17, 2));
	//students.push_back(Student3("박지성", 22, 6));
	//students.push_back(Student3("김연경", 40, 1));
	//students.push_back(Student3("이승엽", 45, 3));
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}
	//sort(students.begin(), students.end(), compare_student_age);  // 벡터 전체범위, compare 함수로 오름 내림 정렬
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}
	//sort(students.begin(), students.end(), compare_student_grade);
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}

	// Q) 사용자로부터 정수의 개수를 입력받아, 정수의 개수만큼 사용자로부터 정수를 입력받아서 벡터에 저장한다.
    //    벡터에 저장된 정수 중에서 최댓값과 최솟값을 찾는 프로그램을 만들어보자.
	//vector<int> nums;
	//int qty;
	//cout << "정수의 개수 : ";
	//cin >> qty;
	//for (int i = 0; i < qty; i++) {
	//	int n;
	//	cout << i + 1 << "번째 정수 : ";
	//	cin >> n;
	//	nums.push_back(n);
	//}
	//vector<int> result = getMaxAndMin(nums);
	//printf("최대값 : %d, 최소값 : %d\n", result[0], result[1]);

    // Q) 사용자로부터 문자열의 개수를 입력받아, 개수만큼 문자열(알파벳)을 입력받아 벡터에 저장한다.
    //    벡터에 저장된 문자열을 알파벳순으로 정렬해 보자.
	//vector<string> strs;
	//int qty;
	//cout << "문자열(알파벳)의 개수 : ";
	//cin >> qty;
	//for (int i = 0; i < qty; i++) {
	//	string s;
	//	cout << i + 1 << "번째 알파벳 : ";
	//	cin >> s;
	//	strs.push_back(s);
	//}
	//sort(strs.begin(), strs.end(), compare_strs_alphabet);
	//for (string str : strs) {
	//	cout << str << " ";
	//}

    // Q) 사각형 클래스(Rectangle)를 동적생성하고 가로와 세로의 길이가 렌덤(1~100)하게 초기화 되도록 한다.
    //    사각형의 넓이가 소수가 나오는 사각형 5개를 만들어 보자.
	//vector<Rectangle> rectangles;
	//int width, height, area, chk;
	//srand(time(NULL));
	//while (true) {
	//	width = rand() % 100 + 1;
	//	height = rand() % 100 + 1;
	//	Rectangle rectangle{width, height};
	//	area = rectangle.getArea();
	//	if (area > 1) {
	//		chk = 0;
	//		for (int i = 0; i < area; i++) {
	//			if (area % (i + 1) == 0) {
	//				chk++;
	//			}
	//		}
	//		if (chk == 2) {
	//			rectangles.push_back(rectangle);
	//		}
	//	}
	//	if (rectangles.size() == 5) {
	//		break;
	//	}
	//}
	//for (Rectangle rectangle : rectangles) {
	//	printf("가로 : %d\n", rectangle.getWidth());
	//	printf("세로 : %d\n", rectangle.getHeight());
	//	printf("넓이 : %d\n\n", rectangle.getArea());
	//}

    // Q) 전체 학생수를 알수 없는 상황에서 모든 학생의 성적을 입력하고 총점과 평균을 출력하는 코드를 작성하자.
	//vector<int> scores;
	//int selNum, score, total = 0;
	//while (true) {
	//	cout << "1. 성적입력  2. 종료 ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		cout << "점수 : ";
	//		cin >> score;
	//		scores.push_back(score);
	//	}
	//	else if (selNum == 2) {
	//		break;
	//	}
	//}
	//for (int score : scores) {
	//	total += score;
	//}
	//cout << "총점 : " << total << ", 평균 : " << (double)total / scores.size() << endl;

    // Q) 학생 클래스(Student)를 정의하고, 이름, 나이, 성적을 멤버 필드(속성)로 정의한다.
    //    벡터를 이용해서 동적으로 Student를 생성하고, 사용자로 부터 속성 정보를 입력받아
    //    나이와 성적에 대한 내림차순 정렬을 출력하자.
	//vector<Student> students;
	//int selNum, age, score;
	//string name;
	//while (true) {
	//	cout << "1. 학생 정보 입력  2. 종료 ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		cout << "이름 : ";
	//		cin >> name;
	//		cout << "나이 : ";
	//		cin >> age;
	//		cout << "점수 : ";
	//		cin >> score;
	//		students.push_back(Student(name, age, score));
	//	}
	//	else if (selNum == 2) {
	//		break;
	//	}
	//}
	//sort(students.begin(), students.end(), compare_student_age);
	//cout << "나이에 대한 내림차순 출력" << endl;
	//for (auto iter = students.begin(); iter != students.end(); iter++) {
	//	printf("「이름 : %s\n", iter->getName().c_str());
	//	printf("  나이 : %d\n", iter->getAge());
	//	printf("  점수 : %d」\n", iter->getScore());
	//}
	//sort(students.begin(), students.end(), compare_student_score);
	//cout << "성적에 대한 내림차순 출력" << endl;
	//for (auto iter = students.begin(); iter != students.end(); iter++) {
	//	printf("「이름 : %s\n", iter->getName().c_str());
	//	printf("  나이 : %d\n", iter->getAge());
	//	printf("  점수 : %d」\n", iter->getScore());
	//}

    // Q) 연락처를 만들어보자.
    //    - vector를 이용하자.
    //    - 메뉴를 만들고 각각의 기능을 구현하자.
    //      - 연락처 추가, 연락처 삭제, 연락처 검색, 연락처 몽땅 삭제, 프로그램 종료
	//vector<Number> numbers;
	//string selNum, name, phone;
	//int idx;
	//while (true) {
	//	cout << "1. 연락처 추가  2. 연락처 검색  3.  전체 연락처 검색  4. 연락처 삭제  5. 전체 연락처 삭제  0. 종료 ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "  이름 : ";
	//		cin >> name;
	//		cout << "  연락처 : ";
	//		cin >> phone;
	//		cout << endl;
	//		Number number(name, phone);
	//		numbers.push_back(number);
	//	}
	//	else if (selNum == "2") {
	//		cout << "  검색할 이름 : ";
	//		cin >> name;
	//		for (Number number : numbers) {
	//			if (number.getName() == name) {
	//				cout << endl;
	//				cout << "「이름 : " << number.getName() << endl;
	//				cout << "  연락처 : " << number.getPhone() << "」" << endl;
	//				cout << endl;
	//			}
	//		}
	//	}
	//	else if (selNum == "3") {
	//		for (Number number : numbers) {
	//			cout << endl;
	//			cout << "「이름 : " << number.getName() << endl;
	//			cout << "  연락처 : " << number.getPhone() << "」" << endl;
	//			cout << endl;
	//		}
	//	}
	//	else if (selNum == "4") {
	//		cout << "  삭제할 이름 : ";
	//		cin >> name;
	//		for (int i = 0; i < numbers.size(); i++) {
	//			if (numbers[i].getName() == name) {
	//				cout << endl;
	//				cout << "「번호 : " << i + 1 << endl;
	//				cout << "  이름 : " << numbers[i].getName() << endl;
	//				cout << "  연락처 : " << numbers[i].getPhone() << "」" << endl;
	//				cout << endl;
	//			}
	//		}
	//		cout << "  삭제할 번호 : ";
	//		cin >> idx;
	//		cout << endl;
	//		numbers.erase(numbers.begin() + idx - 1);
	//	}
	//	else if (selNum == "5") {
	//		numbers.clear();
	//	}
	//	else if (selNum == "0") {
	//		break;
	//	}
	//}


	return 0;
}
