#include "CPU.h"
#include "HardwareException.h"

#include <iostream>
#include <string>

using namespace std;

void CPU::fetch() {
	HardwareException h("fetch");
	getline(cin, this->instruction, '\n');
	if (instruction == "") {
		h.setMsg("명령 라인 없음");
		throw h;
	}
}

void CPU::decode() {
	HardwareException h("decode");

	int instIdx = instruction.find(' ');
	if (instIdx == -1) { // 한덩어리만 입력된 경우
		if (instruction == "ADD" || instruction == "SUB" || instruction == "MUL" || instruction == "DIV") {
			h.setMsg("피연산자 예외");
			throw h;
		}
		else {
			h.setMsg("Invalid 명령어 예외");
			throw h;
		}
	}

	this->cmd = instruction.substr(0, instIdx); // 0에서 instIdx까지 문자열 반환
	if (this->cmd != "ADD" && this->cmd != "SUB" && this->cmd != "MUL" && this->cmd != "DIV") {
		h.setMsg("Invalid 명령어 예외");
		throw h;
	}

	int opIdx = instruction.find(' ', instIdx + 1);
	if (opIdx == -1) { // 두덩어리만 입력된 경우
		h.setMsg("피연산자 예외");
		throw h;
	}

	this->op1 = stoi(this->instruction.substr(instIdx + 1, (opIdx - instIdx - 1)));
	this->op2 = stoi(this->instruction.substr(opIdx + 1));
}

void CPU::execute() {
	HardwareException h("execute");
	if (cmd == "DIV" && op2 == 0) {
		h.setMsg("0으로 나누는 예외");
		throw h;
	}

	if (cmd == "ADD") {
		cout << "ADD " << op1 << " + " << op2 << " = " << op1 + op2 << endl;
	}
	else if (cmd == "SUB") {
		cout << "SUB " << op1 << " - " << op2 << " = " << op1 - op2 << endl;
	}
	else if (cmd == "MUL") {
		cout << "MUL " << op1 << " * " << op2 << " = " << op1 * op2 << endl;
	}
	else if (cmd == "DIV") {
		cout << "DIV " << op1 << " / " << op2 << " = " << op1 / op2 << endl;
	}
}

void CPU::run() {
	while (true) {
		try {
			fetch();
			decode();
			execute();
		}
		catch (HardwareException a) {
			cout << a.getStep() << " 스텝에서 오류 발생" << endl;
		}
	}
}