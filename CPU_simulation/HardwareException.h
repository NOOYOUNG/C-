#pragma once
#include <string>
using namespace std;

class HardwareException {
	string step;
	string msg;
public:
	HardwareException(string step = "", string msg = "");
	string getStep();
	string getMsg();
	void setMsg(string msg);
	void what();
};