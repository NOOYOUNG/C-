#include "HardwareException.h"
#include <iostream>
using namespace std;

HardwareException::HardwareException(string step, string msg) {
	this->step = step;
	this->msg = msg;
}

string HardwareException::getStep() {
	return step;
}

string HardwareException::getMsg() {
	return msg;
}

void HardwareException::setMsg(string msg) {
	this->msg = msg;
}

void HardwareException::what() {
	cout << step;
}