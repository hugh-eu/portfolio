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
//int VisitCount::visit_total_cnt = 0;  // c++에서 static 변수는 클래스 내부에서 초기화 불가

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

//class ChildClass : public ParentClass {  // 상속
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
//		cout << "30km/h로 전진" << endl;
//	}
//
//	void goBackward() {
//		cout << "5km/h로 후진" << endl;
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
//		cout << "50km/h로 전진" << endl;
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
//	//virtual void run() = 0;  //오버라이딩 강제화
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

	// 원 Circle 3개 동적생성, 정보 출력
	// x좌표 y좌표 반지름 넓이 색상RGB
	//int xCoordinate, yCoordinate, radius, r, g ,b;
	//Circle* circle = nullptr;
	//vector<Circle*>* circles = new vector<Circle*>;  // 벡터 특성상 메모리 재할당이 많아, 객체를 그대로 추가할경우 에러 및 속도 면에서 불리, 따라서 포인터를 추가하는것이 편하고 빠름
	//for (int i = 0; i < 3; i++) {
	//	cout << "# 원 " << i + 1 << endl;
	//	cout << "원 x좌표 : ";
	//	cin >> xCoordinate;
	//	cout << "원 y좌표 : ";
	//	cin >> yCoordinate;
	//	cout << "원 반지름 : ";
	//	cin >> radius;
	//	cout << "원 색상R : ";
	//	cin >> r;
	//	cout << "원 색상G : ";
	//	cin >> g;
	//	cout << "원 색상B : ";
	//	cin >> b;
	//	cout << endl;
	//	circle = new Circle(xCoordinate, yCoordinate, radius);
	//	circle->setColor(new Color(r, g, b));
	//	circles->push_back(circle);
	//}
	//for (int i = 0; i < 3; i++) {
	//	cout << "# 원 " << i + 1 << endl;
	//	printf("x좌표 : %d\n", circles->at(i)->getXCoordinate());
	//	printf("y좌표 : %d\n", (*circles)[i]->getYCoordinate());
	//	printf("넓이 : %.2f\n", circles->at(i)->getArea());
	//	printf("색상 : R %d, G %d, B %d\n", circles->at(i)->getColor()->getR(), circles->at(i)->getColor()->getG(), circles->at(i)->getColor()->getB());
	//	cout << endl;
	//}
	//for (auto iter = circles->begin(); iter != circles->end(); iter++) {  // 포인터를 벡터에 추가했으므로 이터레이터로 해제
	//	delete (*iter);
	//}
	//delete circles;

	// 복사생성자
	//Car* car1 = new Car("genesis", 5);
	//cout << "car1->getName() : " << car1->getName() << endl;
	//cout << "car1->getLength() : " << car1->getLength() << endl;
	//Car* car2 = new Car(*car1);
	//cout << "car2->getName() : " << car2->getName() << endl;
	//cout << "car2->getLength() : " << car2->getLength() << endl;
	//cout << car1 << endl;
	//cout << car2 << endl;  // 둘은 다른 객체
	//delete car1;
	//delete car2;

	// static, 정적변수, 함수
	//VisitCount* visitCountPtr = nullptr;
	//visitCountPtr = new VisitCount("가나다");
	//VisitCount::visit_total_cnt++;
	//cout << "이름 : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "번째 방문객입니다." << endl;
	//delete visitCountPtr;
	//visitCountPtr = new VisitCount("라마바");
	//VisitCount::visit_total_cnt++;
	//cout << "이름 : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "번째 방문객입니다." << endl;
	//delete visitCountPtr;
	//visitCountPtr = new VisitCount("사아자");
	//VisitCount::visit_total_cnt++;
	//cout << "이름 : " << visitCountPtr->getName() << endl;
	//cout << VisitCount::getVisit_total_cnt() << "번째 방문객입니다." << endl;
	//delete visitCountPtr;

	//// 상속
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
	//childCar.goForward();  // 부모클래스보다 본인먼저
	//childCar.goBackward();
	//childCar.printInfos();

	////다중 상속, 가능하면 피하기
	//SubCar subCar;
	//subCar.SuperCar1::drive();
	//subCar.SuperCar2::drive();
	//subCar.SuperCar3::drive();
	//subCar.drive();

	//// 추상클래스, 인터페이스, 다형성
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
	//Shape& refShape = triangle;  // 참조자, 같은 주소값
	//refShape.printArea();

	//ParentClass* ptr = new ChildClass();
	//delete ptr;  // super 클래스의 소멸자에 virtual 붙여야 다형클래스 삭제.

	// 추상클래스, 실제, virtual 소멸자, virtual 함수=0, 
	//Toy* toyPtr = nullptr;
	//toyPtr = new RobotToy();
	//toyPtr->run();
	//delete toyPtr;
	//toyPtr = new CarToy();
	//toyPtr->run();
	//delete toyPtr;

	//// 컨테이너 자료구조
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