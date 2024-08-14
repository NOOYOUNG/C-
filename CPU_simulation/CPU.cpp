#include "CPU.h"
#include "HardwareException.h"

#include <iostream>
#include <string>

using namespace std;

void CPU::fetch() {
	HardwareException h("fetch");
	getline(cin, this->instruction, '\n');
	if (instruction == "") {
		h.setMsg("��� ���� ����");
		throw h;
	}
}

void CPU::decode() {
	HardwareException h("decode");

	int instIdx = instruction.find(' ');
	if (instIdx == -1) { // �ѵ���� �Էµ� ���
		if (instruction == "ADD" || instruction == "SUB" || instruction == "MUL" || instruction == "DIV") {
			h.setMsg("�ǿ����� ����");
			throw h;
		}
		else {
			h.setMsg("Invalid ��ɾ� ����");
			throw h;
		}
	}

	this->cmd = instruction.substr(0, instIdx); // 0���� instIdx���� ���ڿ� ��ȯ
	if (this->cmd != "ADD" && this->cmd != "SUB" && this->cmd != "MUL" && this->cmd != "DIV") {
		h.setMsg("Invalid ��ɾ� ����");
		throw h;
	}

	int opIdx = instruction.find(' ', instIdx + 1);
	if (opIdx == -1) { // �ε���� �Էµ� ���
		h.setMsg("�ǿ����� ����");
		throw h;
	}

	this->op1 = stoi(this->instruction.substr(instIdx + 1, (opIdx - instIdx - 1)));
	this->op2 = stoi(this->instruction.substr(opIdx + 1));
}

void CPU::execute() {
	HardwareException h("execute");
	if (cmd == "DIV" && op2 == 0) {
		h.setMsg("0���� ������ ����");
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
			cout << a.getStep() << " ���ܿ��� ���� �߻�" << endl;
		}
	}
}