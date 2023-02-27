#include <iostream>
#include <string>

using namespace std;

class Bus {
private:
	string owner;
	int length;
	int displacement;
	string color;

public:
	void gear_p();

	void gear_r();

	void gear_n();

	void gear_d();

	void printBusInfo();


	string getOwner() {
		return this->owner;
	}
	void setOwner(string owner) {
		this->owner = owner;
	}
	int getLength() {
		return this->length;
	}
	void setLength(int length) {
		this->length = length;
	}
	int getDisplacement() {
		return this->displacement;
	}
	void setDisplacement(int displacement) {
		this->displacement = displacement;
	}
	string getColor() {
		return this->color;
	}
	void setColor(string color) {
		this->color = color;
	}

};