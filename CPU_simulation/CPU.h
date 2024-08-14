#pragma once
#include <string>
#include "HardwareException.h"
using namespace std;

class CPU {
	string instruction;
	int op1, op2;
	string cmd;
	void fetch() throw(HardwareException);
	void decode() throw(HardwareException);
	void execute() throw(HardwareException);
public:
	void run();
};