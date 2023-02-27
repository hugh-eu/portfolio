#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <list>


using namespace std;

//class Color {
//private:
//	int r;
//	int g;
//	int b;
//public:
//	Color() {}
//
//	Color(int r, int g, int b) : r{ r }, g{ g }, b{ b } {}
// 
//	~Color(){
//		cout << "Color destructor" << endl;
//	}
//
//	void setR(int r) { this->r = r; }
//	int getR() { return this->r; }
//	void setG(int g) { this->g = g; }
//	int getG() { return this->g; }
//	void setB(int b) { this->b = b; }
//	int getB() { return this->b; }
//
//};

//class Circle {
//private:
//
//	int xCoordinate;
//	int yCoordinate;
//	int radius;
//	double area;
//	Color* colorPtr = nullptr;
//
//public:
//
//	Circle() {}
//
//	Circle(int xCoordinate, int yCoordinate, int radius) : xCoordinate{ xCoordinate }, yCoordinate{ yCoordinate }, radius{ radius } {
//		this->area = 3.14 * pow(radius, 2);
//	}
// 
//	~Circle(){
//
//		cout << "Circle destructor" << endl;
//		delete colorPtr;
// 
//	}
//
//	void setXCoordinate(int xCoordinate) {
//		this->xCoordinate = xCoordinate;
//	}
//	int getXCoordinate() {
//		return this->xCoordinate;
//	}
//	void setYCoordinate(int yCoordinate) {
//		this->yCoordinate = yCoordinate;
//	}
//	int getYCoordinate() {
//		return this->yCoordinate;
//	}
//	void setRadius(int radius) {
//		this->radius = radius;
//	}
//	int getRadius() {
//		return this->radius;
//	}
//	void setArea() {
//		this->area = 3.14 * pow(radius, 2);
//	}
//	double getArea() {
//		return this->area;
//	}
//	void setColor(Color* colorPtr) {
//		this->colorPtr = colorPtr;
//	}
//	Color* getColor() {
//		return colorPtr;
//	}
//
//};

//class Car {
//private:
//
//	string name;
//	int length;
//
//public:
//
//	Car(string name, int length) : name{ name }, length{ length } {}
//
//	string getName() {
//		return this->name;
//	}
//	int getLength() {
//		return this->length;
//	}
//
//};

//class VisitCount {
//private:
//
//	string name;
//
//public:
//
//	static int visit_total_cnt;
//	VisitCount(string name) : name{ name } {}
//
//	string getName() { return this->name; }
//	static int getVisit_total_cnt() { return VisitCount::visit_total_cnt; }
//
//};
//int VisitCount::visit_total_cnt = 0;  // c++���� static ������ Ŭ���� ���ο��� �ʱ�ȭ �Ұ�

//class ParentClass {
//private:
//
//	int num;
//	string str;
//
//public:
//
//	ParentClass() {
//		cout << "ParentClass constructor" << endl;
//	}
//
//	ParentClass(int num, string str) : num{ num }, str{ str } {}
//
//	void setNum(int num) {
//		this->num = num;
//	}
//	int getNum() {
//		return this->num;
//	}
//	void setStr(string str) {
//		this->str = str;
//	}
//	string getStr() {
//		return this->str;
//	}
//
//};

//class ChildClass : public ParentClass {  // ���
//private:
//
//
//
//public:
//
//	ChildClass() {
//		cout << "ChildClass constructor" << endl;
//	}
//
//};

//class Calculator {
//private:
//
//public:
//
//	int addFun(int n1, int n2) {
//		return n1 + n2;
//	}
//
//	int subFun(int n1, int n2) {
//		return n1 - n2;
//	}
//
//	int mulFun(int n1, int n2) {
//		return n1 * n2;
//	}
//
//	double divFun(int n1, int n2) {
//		return (double)n1 / n2;
//	}
//
//};

//class NewCalculator : public Calculator {
//private:
//
//public:
//
//	int powFun(int n, int p) {
//		int result = 1;
//		for (int i = 0; i < p; i++) {
//			result *= n;
//		}
//		return result;
//	}
//
//};

//class ParentCar {
//private:
//
//	string name;
//	int length;
//	int price;
//
//public:
//
//	ParentCar(string name, int length, int price) : name{ name }, length{ length }, price{ price } {}
//
//	void goForward() {
//		cout << "30km/h�� ����" << endl;
//	}
//
//	void goBackward() {
//		cout << "5km/h�� ����" << endl;
//	}
//
//	void printInfos() {
//		cout << "name : " << this->name << endl;
//		cout << "length : " << this->length << endl;
//		cout << "price : " << this->price << endl;
//	}
//
//};

//class ChildCar : public ParentCar {
//private:
//
//	string color;
//
//public:
//
//	ChildCar(string name, int length, int price, string color) : ParentCar(name, length, price), color{color} {}
//
//	void goForward() {
//		cout << "50km/h�� ����" << endl;
//	}
//
//	void printInfos() {
//		ParentCar::printInfos();
//		cout << "color : " << this->color << endl;
//	}
//
//};

//class SuperCar1 {
//public:
//	void drive() {
//		cout << "SuperCar1 drive()" << endl;
//	}
//};
//
//class SuperCar2 {
//public:
//	void drive() {
//		cout << "SuperCar2 drive()" << endl;
//	}
//};
//
//class SuperCar3 {
//public:
//	void drive() {
//		cout << "SuperCar3 drive()" << endl;
//	}
//};
//
//class SubCar : public SuperCar1, public SuperCar2, public SuperCar3 {
//public:
//	void drive() {
//		cout << "SubCar drive()" << endl;
//	}
//};

//class Animal {
//private:
//
//public:
//	virtual void run() {
//		cout << "Animal run()" << endl;
//	}
//	//virtual void run() = 0;  //�������̵� ����ȭ
//
//};
//
//class Dog : public Animal {
//private:
//
//public:
//	void run() {
//		cout << "Dog run()" << endl;
//	}
//};
//
//class Rabbit : public Animal {
//private:
//
//public:
//	void run() {
//		cout << "Rabbit run()" << endl;
//	}
//};

//class Shape {
//private:
//	int width;
//	int height;
//public:
//	Shape(int width, int height) : width{ width }, height{ height } {}
//
//	virtual void printArea() {}
//
//	int getWidth() { return this->width; }
//	int getHeight() { return this->height; }
//};
//
//class Triangle : public Shape {
//private:
//public:
//	Triangle(int width, int height) : Shape{ width, height } {}
//
//	void printArea() {
//		cout << "Triangle printArea()" << endl;
//		double area = Shape::getWidth() * Shape::getHeight() / 2;
//		cout << "triangle area : " << area << endl;
//	}
//};
//
//class Rectangle : public Shape {
//private:
//public:
//	Rectangle(int width, int height) : Shape{ width, height } {}
//
//	void printArea() {
//		cout << "Rectangle printArea()" << endl;
//		double area = Shape::getWidth() * Shape::getHeight();
//		cout << "Rectangle area : " << area << endl;
//	}
//};
//
//class Circle : public Shape {
//private:
//public:
//	Circle(int width, int height) : Shape{ width, height } {}
//
//	void printArea() {
//		cout << "Circle printArea()" << endl;
//		double area = 3.14 * (Shape::getWidth() / 2) * (Shape::getWidth() / 2);
//		cout << "Circle area : " << area << endl;
//	}
//};

//class ParentClass {
//private:
//public:
//	ParentClass() {
//		cout << "ParentClass constructor" << endl;
//	}
//	virtual ~ParentClass() {
//		cout << "ParentClass destructor" << endl;
//	}
//};
//
//class ChildClass : public ParentClass {
//private:
//public:
//	ChildClass() {
//		cout << "ChildClass constructor" << endl;
//	}
//	~ChildClass() {
//		cout << "ChildClass destructor" << endl;
//	}
//};

//class Toy {
//public:
//
//	Toy() {
//		cout << "Toy Constructor" << endl;
//	}
//
//	virtual ~Toy() {
//		cout << "Toy Destructor" << endl;
//	}
//
//	virtual void run() = 0;
//
//};
//
//class RobotToy : public Toy {
//public:
//
//	RobotToy() {
//		cout << "RobotToy Constructor" << endl;
//	}
//
//	~RobotToy() {
//		cout << "RobotToy Destructor" << endl;
//	}
//
//	void run() {
//		cout << "RobotToy run()" << endl;
//	}
//
//};
//
//class CarToy : public Toy {
//public:
//
//	CarToy() {
//		cout << "CarToy Constructor" << endl;
//	}
//
//	~CarToy() {
//		cout << "CarToy Destructor" << endl;
//	}
//
//	void run() {
//		cout << "CarToy run()" << endl;
//	}
//
//};

//void printDeque(deque<int>& dq) {
//	for (auto d : dq) {
//		cout << d << " ";
//	}
//	cout << endl;
//}

//void printList(list<int>& nums) {
//	for (auto i : nums) {
//		cout << i << " ";
//	}
//	cout << endl;
//}


int main() {

	// �� Circle 3�� ��������, ���� ���
	// x��ǥ y��ǥ ������ ���� ����RGB
	//int xCoordinate, yCoordinate, radius, r, g ,b;
	//Circle* circle = nullptr;
	//vector<Circle*>* circles = new vector<Circle*>;  // ���� Ư���� �޸� ���Ҵ��� ����, ��ü�� �״�� �߰��Ұ�� ���� �� �ӵ� �鿡�� �Ҹ�, ���� �����͸� �߰��ϴ°��� ���ϰ� ����
	//for (int i = 0; i < 3; i++) {
	//	cout << "# �� " << i + 1 << endl;
	//	cout << "�� x��ǥ : ";
	//	cin >> xCoordinate;
	//	cout << "�� y��ǥ : ";
	//	cin >> yCoordinate;
	//	cout << "�� ������ : ";
	//	cin >> radius;
	//	cout << "�� ����R : ";
	//	cin >> r;
	//	cout << "�� ����G : ";
	//	cin >> g;
	//	cout << "�� ����B : ";
	//	cin >> b;
	//	cout << endl;
	//	circle = new Circle(xCoordinate, yCoordinate, radius);
	//	circle->setColor(new Color(r, g, b));
	//	circles->push_back(circle);
	//}
	//for (int i = 0; i < 3; i++) {
	//	cout << "# �� " << i + 1 << endl;
	//	printf("x��ǥ : %d\n", circles->at(i)->getXCoordinate());
	//	printf("y��ǥ : %d\n", (*circles)[i]->getYCoordinate());
	//	printf("���� : %.2f\n", circles->at(i)->getArea());
	//	printf("���� : R %d, G %d, B %d\n", circles->at(i)->getColor()->getR(), circles->at(i)->getColor()->getG(), circles->at(i)->getColor()->getB());
	//	cout << endl;
	//}
	//for (auto iter = circles->begin(); iter != circles->end(); iter++) {  // �����͸� ���Ϳ� �߰������Ƿ� ���ͷ����ͷ� ����
	//	delete (*iter);
	//}
	//delete circles;

	// ���������
	//Car* car1 = new Car("genesis", 5);
	//cout << "car1->getName() : " << car1->getName() << endl;
	//cout << "car1->getLength() : " << car1->getLength() << endl;
	//Car* car2 = new Car(*car1);
	//cout << "car2->getName() : " << car2->getName() << endl;
	//cout << "car2->getLength() : " << car2->getLength() << endl;
	//cout << car1 << endl;
	//cout << car2 << endl;  // ���� �ٸ� ��ü
	//delete car1;
	//delete car2;

	// static, ��������, �Լ�
	//VisitCount* visitCountPtr = nullptr;
	//visitCountPtr = new VisitCount("������");
	//VisitCount::visit_total_cnt++;
	//cout << "�̸� : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "��° �湮���Դϴ�." << endl;
	//delete visitCountPtr;
	//visitCountPtr = new VisitCount("�󸶹�");
	//VisitCount::visit_total_cnt++;
	//cout << "�̸� : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "��° �湮���Դϴ�." << endl;
	//delete visitCountPtr;
	//visitCountPtr = new VisitCount("�����");
	//VisitCount::visit_total_cnt++;
	//cout << "�̸� : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "��° �湮���Դϴ�." << endl;
	//delete visitCountPtr;

	//// ���
	//ChildClass childClass;
	//childClass.setNum(1);
	//childClass.setStr("str");
	//cout << "childClass.getNum() : " << childClass.getNum() << endl;
	//cout << "childClass.getStr() : " << childClass.getStr() << endl;

	//NewCalculator newCalculator;
	//cout << " 4+3 = " << newCalculator.addFun(4, 3) << endl;
	//cout << " 4-3 = " << newCalculator.subFun(4, 3) << endl;
	//cout << " 4*3 = " << newCalculator.mulFun(4, 3) << endl;
	//cout << " 4/3 = " << newCalculator.divFun(4, 3) << endl;
	//cout << " 4^3 = " << newCalculator.powFun(4, 3) << endl;

	//ChildCar childCar("genesis", 5, 8000, "black");
	//childCar.goForward();  // �θ�Ŭ�������� ���θ���
	//childCar.goBackward();
	//childCar.printInfos();

	////���� ���, �����ϸ� ���ϱ�
	//SubCar subCar;
	//subCar.SuperCar1::drive();
	//subCar.SuperCar2::drive();
	//subCar.SuperCar3::drive();
	//subCar.drive();

	//// �߻�Ŭ����, �������̽�, ������
	//Animal* aPtr = new Dog();
	//aPtr->run();
	//delete aPtr;
	//aPtr = new Rabbit();
	//aPtr->run();
	//delete aPtr;

	//Shape* shapePtr = nullptr;
	//shapePtr = new Triangle(10, 20);
	//shapePtr->printArea();
	//delete shapePtr;
	//shapePtr = new Rectangle(10, 20);
	//shapePtr->printArea();
	//delete shapePtr;
	//shapePtr = new Circle(10, 20);
	//shapePtr->printArea();
	//delete shapePtr;
	//Triangle triangle(10, 20);
	//Shape& refShape = triangle;  // ������, ���� �ּҰ�
	//refShape.printArea();

	//ParentClass* ptr = new ChildClass();
	//delete ptr;  // super Ŭ������ �Ҹ��ڿ� virtual �ٿ��� ����Ŭ���� ����.

	// �߻�Ŭ����, ����, virtual �Ҹ���, virtual �Լ�=0, 
	//Toy* toyPtr = nullptr;
	//toyPtr = new RobotToy();
	//toyPtr->run();
	//delete toyPtr;
	//toyPtr = new CarToy();
	//toyPtr->run();
	//delete toyPtr;

	//// �����̳� �ڷᱸ��
	// list : vector, deque, list
	// set : set, multiset
    // map : map
	
	// deque
	//deque<int> dq{1, 2, 3, 4, 5};
	//printDeque(dq);
	//dq.push_front(0);
	//printDeque(dq);
	//dq.push_back(6);
	//printDeque(dq);
	//dq.insert(dq.begin() + 3, 100);
	//printDeque(dq);
	//dq.pop_front();
	//printDeque(dq);
	//dq.pop_back();
	//printDeque(dq);
	//dq.erase(dq.begin() + 2);
	//printDeque(dq);
	//dq.erase(dq.begin(), dq.end() - 3);
	//printDeque(dq);
	//cout << dq.front() << endl;
	//cout << dq.back() << endl;
	//dq.push_back(7);
	//printDeque(dq);
	//auto iter = find(dq.begin(), dq.end(), 7);
	//auto idx = distance(dq.begin(), iter);
	//if (dq.size() <= idx) {
	//	cout << "out of range";
	//}
	//else {
	//	cout << "idx(7) : " << idx << endl;
	//}
	//cout << "dq.at(0) : " << dq.at(0) << endl;
	//cout << "dq[0] : " << dq[0] << endl;
	//dq.clear();
	//cout << dq.size() << endl;

	// list
	//list<int> nums{ 1,2,3,4,5 };
	//nums.push_front(0);
	//printList(nums);
	//nums.push_back(6);
	//printList(nums);
	//auto ptr = nums.begin();
	//advance(ptr, 3);
	//nums.insert(ptr, 100);
	//advance(ptr, -1);
	//nums.insert(ptr, 99);
	//printList(nums);
	//nums.insert(ptr, 5, -1);
	//printList(nums);
	//nums.pop_front();
	//printList(nums);
	//nums.pop_back();
	//printList(nums);
	//ptr = nums.begin();
	//nums.erase(ptr);
	//printList(nums);
	//ptr = nums.begin();
	//advance(ptr, 7);
	//nums.erase(ptr);
	//printList(nums);
	//auto firstPtr = nums.begin();
	//auto endPtr = nums.end();
	//advance(firstPtr, 2);
	//advance(endPtr, -3);
	//nums.erase(firstPtr, endPtr);
	//printList(nums);
	//cout << "nums.size() : " << nums.size() << endl;
	//auto iPtr = find(nums.begin(), nums.end(), 3);
	//auto idx = distance(nums.begin(), iPtr);
	//cout << "find(nums.begin(), nums.end(), 3) : " << *iPtr << endl;
	//cout << "idx(3) : " << idx << endl;



	return 0;
}