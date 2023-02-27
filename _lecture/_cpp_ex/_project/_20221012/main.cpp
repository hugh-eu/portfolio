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
//	void fun_fire() {  // �Լ�, Ŭ���� ��� ��������
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
//	Student(string s_no, string s_name, int s_age, int s_grade) : s_no( s_no ), s_name{ s_name }, s_age{ s_age }, s_grade{ s_grade } {}  // ����ʵ� �ʱ�ȭ ����Ʈ, �Ұ�ȣ, �߰�ȣ
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
//	Student2(int s_no, string s_name) : s_no(s_no), s_name{ s_name } {}  // ����ʵ� �ʱ�ȭ ����Ʈ, �Ұ�ȣ, �߰�ȣ
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

	// namespace ���̽� ���, �ڹ� ��Ű���� ���
	//ns_01::fun_fire();
	//ns_02::fun_fire();
	// 20221007 ������Ʈ ���ӽ����̽��� ó����

	//// Ŭ���� �Ӽ� + ���, ���
	//// ��� �ʵ�(�Ӽ�) + ��� �Լ�(���)
	//// Ŭ���� ��ü, �ν��Ͻ�
	//// Ŭ����. ����ʵ� �ʱ�ȭ, �ʱ�ȭ ����Ʈ, class student
	//Student student1;
	//cout << "s_no : " << student1.getS_no() << endl;
	//cout << "s_name : " << student1.getS_name() << endl;
	//cout << "s_age : " << student1.getS_age() << endl;
	//cout << "s_grade : " << student1.getS_grade() << endl;

	//Student student2("s00001", "ȫ�浿", 19, 1);
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

	//// �簢�� Ŭ���� Rectangle ���� �ѷ����� ���
	//Rectangle rectangle(10, 20);
	//rectangle.calcArea();
	//rectangle.calcPerimeter();
	//cout << "area : " << rectangle.getArea() << endl;
	//cout << "perimeter : " << rectangle.getPerimeter() << endl;

	//// ��ü �迭
	//Student2 students1[10];
	//for (int i = 0; i < sizeof(students1) / sizeof(Student2); i++) {
	//	students1[i].setS_no(i);
	//	students1[i].setS_name("student " + to_string(i));
	//}
	//for (int i = 0; i < sizeof(students1) / sizeof(Student2); i++) {
	//	printf("s_no : %d, s_name : %s\n", students1[i].getS_no(), students1[i].getS_name().c_str());
	//}
	//
	//Student2 students2[]{ Student2(0, "ȫ�浿"), Student2(1, "������"), Student2(2, "������") };
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
	//vector<int> scores1{ 10,20,30,40,50 };  // ����� �ʱ�ȭ ���ÿ�
	//for (auto score : scores1) {
	//	cout << "score : " << score << endl;
	//}
	//for (int i = 0; i < scores1.size(); i++) {
	//	printf("score[%d] : %d\n", i, scores1[i]);
	//}
	//
	//vector<Student2> students1;
	//students1.push_back(Student2(0, "������"));  // ���ʺ��� �߰�
	//students1.push_back(Student2(1, "������"));
	//students1.push_back(Student2(2, "�ٴٴ�"));
	//for (auto iter = students1.begin(); iter != students1.end(); iter++) {
	//	printf("s_no : %d, s_name : %s\n", (*iter).getS_no(), (*iter).getS_name().c_str());
	//}
	//auto iter = students1.begin();
	//cout << (*(iter + 1)).getS_no() << endl;
	//cout << "students1.size() : " << students1.size() << endl;
	//students1.pop_back();  // ���ʺ��� ����
	//cout << "students1.size() : " << students1.size() << endl;
	//students1.pop_back();  // ���ʺ��� ����
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
	//scores1.erase(scores1.begin() + 2);  // Ư�� �ε��� ����
	//for (auto score : scores1) {
	//	cout << "score : " << score << endl;
	//}
	//
	//cout << "scores1.size() : " << scores1.size() << endl;
	//scores1.clear();  // ��ü ����
	//cout << "scores1.size() : " << scores1.size() << endl;
	//
	//vector<int> vec1{ 1,2,3,4,5 };
	//vector<int> vec2{ vec1 };  // ���� ����
	//for (auto vec : vec2) {
	//	cout << vec << endl;
	//}
	//if (vec1 == vec2) {
	//	cout << "����" << endl;
	//}
	//else {
	//	cout << "�ٸ���" << endl;
	//}
	//cout << &vec1 << endl;
	//cout << &vec2 << endl;
	//
	//*(vec2.begin() + 1) = 100;
	//if (vec1 == vec2) {
	//	cout << "����" << endl;
	//}
	//else {
	//	cout << "�ٸ���" << endl;
	//}

	//// �ڷᱸ�� STL: standard template library, �ڹ� �÷���, ���̽� �����̳�
	//// ����(sort)
	//vector<Student3> students;
	//students.push_back(Student3("����ȣ", 19, 4));
	//students.push_back(Student3("�ڼ���", 17, 2));
	//students.push_back(Student3("������", 22, 6));
	//students.push_back(Student3("�迬��", 40, 1));
	//students.push_back(Student3("�̽¿�", 45, 3));
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}
	//sort(students.begin(), students.end(), compare_student_age);  // ���� ��ü����, compare �Լ��� ���� ���� ����
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}
	//sort(students.begin(), students.end(), compare_student_grade);
	//for (auto student : students) {
	//	printf("name : %s\n", student.getName().c_str());
	//}

	// Q) ����ڷκ��� ������ ������ �Է¹޾�, ������ ������ŭ ����ڷκ��� ������ �Է¹޾Ƽ� ���Ϳ� �����Ѵ�.
    //    ���Ϳ� ����� ���� �߿��� �ִ񰪰� �ּڰ��� ã�� ���α׷��� ������.
	//vector<int> nums;
	//int qty;
	//cout << "������ ���� : ";
	//cin >> qty;
	//for (int i = 0; i < qty; i++) {
	//	int n;
	//	cout << i + 1 << "��° ���� : ";
	//	cin >> n;
	//	nums.push_back(n);
	//}
	//vector<int> result = getMaxAndMin(nums);
	//printf("�ִ밪 : %d, �ּҰ� : %d\n", result[0], result[1]);

    // Q) ����ڷκ��� ���ڿ��� ������ �Է¹޾�, ������ŭ ���ڿ�(���ĺ�)�� �Է¹޾� ���Ϳ� �����Ѵ�.
    //    ���Ϳ� ����� ���ڿ��� ���ĺ������� ������ ����.
	//vector<string> strs;
	//int qty;
	//cout << "���ڿ�(���ĺ�)�� ���� : ";
	//cin >> qty;
	//for (int i = 0; i < qty; i++) {
	//	string s;
	//	cout << i + 1 << "��° ���ĺ� : ";
	//	cin >> s;
	//	strs.push_back(s);
	//}
	//sort(strs.begin(), strs.end(), compare_strs_alphabet);
	//for (string str : strs) {
	//	cout << str << " ";
	//}

    // Q) �簢�� Ŭ����(Rectangle)�� ���������ϰ� ���ο� ������ ���̰� ����(1~100)�ϰ� �ʱ�ȭ �ǵ��� �Ѵ�.
    //    �簢���� ���̰� �Ҽ��� ������ �簢�� 5���� ����� ����.
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
	//	printf("���� : %d\n", rectangle.getWidth());
	//	printf("���� : %d\n", rectangle.getHeight());
	//	printf("���� : %d\n\n", rectangle.getArea());
	//}

    // Q) ��ü �л����� �˼� ���� ��Ȳ���� ��� �л��� ������ �Է��ϰ� ������ ����� ����ϴ� �ڵ带 �ۼ�����.
	//vector<int> scores;
	//int selNum, score, total = 0;
	//while (true) {
	//	cout << "1. �����Է�  2. ���� ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		cout << "���� : ";
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
	//cout << "���� : " << total << ", ��� : " << (double)total / scores.size() << endl;

    // Q) �л� Ŭ����(Student)�� �����ϰ�, �̸�, ����, ������ ��� �ʵ�(�Ӽ�)�� �����Ѵ�.
    //    ���͸� �̿��ؼ� �������� Student�� �����ϰ�, ����ڷ� ���� �Ӽ� ������ �Է¹޾�
    //    ���̿� ������ ���� �������� ������ �������.
	//vector<Student> students;
	//int selNum, age, score;
	//string name;
	//while (true) {
	//	cout << "1. �л� ���� �Է�  2. ���� ";
	//	cin >> selNum;
	//	if (selNum == 1) {
	//		cout << "�̸� : ";
	//		cin >> name;
	//		cout << "���� : ";
	//		cin >> age;
	//		cout << "���� : ";
	//		cin >> score;
	//		students.push_back(Student(name, age, score));
	//	}
	//	else if (selNum == 2) {
	//		break;
	//	}
	//}
	//sort(students.begin(), students.end(), compare_student_age);
	//cout << "���̿� ���� �������� ���" << endl;
	//for (auto iter = students.begin(); iter != students.end(); iter++) {
	//	printf("���̸� : %s\n", iter->getName().c_str());
	//	printf("  ���� : %d\n", iter->getAge());
	//	printf("  ���� : %d��\n", iter->getScore());
	//}
	//sort(students.begin(), students.end(), compare_student_score);
	//cout << "������ ���� �������� ���" << endl;
	//for (auto iter = students.begin(); iter != students.end(); iter++) {
	//	printf("���̸� : %s\n", iter->getName().c_str());
	//	printf("  ���� : %d\n", iter->getAge());
	//	printf("  ���� : %d��\n", iter->getScore());
	//}

    // Q) ����ó�� ������.
    //    - vector�� �̿�����.
    //    - �޴��� ����� ������ ����� ��������.
    //      - ����ó �߰�, ����ó ����, ����ó �˻�, ����ó ���� ����, ���α׷� ����
	//vector<Number> numbers;
	//string selNum, name, phone;
	//int idx;
	//while (true) {
	//	cout << "1. ����ó �߰�  2. ����ó �˻�  3.  ��ü ����ó �˻�  4. ����ó ����  5. ��ü ����ó ����  0. ���� ";
	//	cin >> selNum;
	//	if (selNum == "1") {
	//		cout << "  �̸� : ";
	//		cin >> name;
	//		cout << "  ����ó : ";
	//		cin >> phone;
	//		cout << endl;
	//		Number number(name, phone);
	//		numbers.push_back(number);
	//	}
	//	else if (selNum == "2") {
	//		cout << "  �˻��� �̸� : ";
	//		cin >> name;
	//		for (Number number : numbers) {
	//			if (number.getName() == name) {
	//				cout << endl;
	//				cout << "���̸� : " << number.getName() << endl;
	//				cout << "  ����ó : " << number.getPhone() << "��" << endl;
	//				cout << endl;
	//			}
	//		}
	//	}
	//	else if (selNum == "3") {
	//		for (Number number : numbers) {
	//			cout << endl;
	//			cout << "���̸� : " << number.getName() << endl;
	//			cout << "  ����ó : " << number.getPhone() << "��" << endl;
	//			cout << endl;
	//		}
	//	}
	//	else if (selNum == "4") {
	//		cout << "  ������ �̸� : ";
	//		cin >> name;
	//		for (int i = 0; i < numbers.size(); i++) {
	//			if (numbers[i].getName() == name) {
	//				cout << endl;
	//				cout << "����ȣ : " << i + 1 << endl;
	//				cout << "  �̸� : " << numbers[i].getName() << endl;
	//				cout << "  ����ó : " << numbers[i].getPhone() << "��" << endl;
	//				cout << endl;
	//			}
	//		}
	//		cout << "  ������ ��ȣ : ";
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
