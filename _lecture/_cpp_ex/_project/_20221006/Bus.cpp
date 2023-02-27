#include "Bus.h"

// ±¸ÇöºÎ
void Bus:: gear_p() {
	cout << "gear_p" << endl;

}

void Bus::gear_r() {
	cout << "gear_r" << endl;

}

void Bus::gear_n() {
	cout << "gear_n" << endl;

}

void Bus::gear_d() {
	cout << "gear_d" << endl;

}

void Bus::printBusInfo() {
	cout << "owner : " << getOwner() << endl;
	cout << "length : " << getLength() << endl;
	cout << "displacement : " << getDisplacement() << endl;
	cout << "color : " << getColor() << endl;
}