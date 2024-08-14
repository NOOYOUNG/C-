#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

void fileRead(vector<string>& v, ifstream& fin);

int main() 
{
	cout << "지금부터 행맨 게임을 시작합니다!" << endl;

	vector<string> words;
	ifstream fin("words.txt");
	if (!fin) {
		cout << "words.txt 파일을 열 수 없습니다." << endl;
		return 0;
	}
	fileRead(words, fin);
	fin.close();

	srand((unsigned)time(NULL));

	while (true) {
		size_t n = rand() % words.size();
		string quest = words.at(n);
		size_t length = quest.length();
		char* cquest = new char[length + 1];
		strcpy_s(cquest, length + 1, quest.c_str());

		int c1, c2;
		while (true) {
			c1 = rand() % length;
			c2 = rand() % length;
			if (c1 != c2) break;
		}
		char answer1 = cquest[c1];
		char answer2 = cquest[c2];

		for (size_t i = 0; i < length; i++) {
			cquest[c1] = '-';
			cquest[c2] = '-';
			cout << cquest[i];
		}

		int cnt = 0;
		while (true) {
			cout << endl << ">> ";
			char aswr;
			cin >> aswr;
			bool wordGuessed = false;
			if (aswr == answer1 && aswr == answer2) {
				for (size_t i = 0; i < length; i++) {
					cout << quest << endl;
					wordGuessed = true;
					break;
				}
			}
			else if (aswr == answer1) {
				for (size_t i = 0; i < length; i++) {
					cquest[c1] = aswr;
					cout << cquest[i];
					if(cquest[c1]!='-' && cquest[c2]!='-')
						wordGuessed = true;
				}
			}
			else if (aswr == answer2) {
				for (size_t i = 0; i < length; i++) {
					cquest[c2] = aswr;
					cout << cquest[i];
					if (cquest[c1] != '-' && cquest[c2] != '-')
						wordGuessed = true;
				}
			}
			else {
				for (size_t i = 0; i < length; i++) {
					cout << cquest[i];
				}
				cnt++;
			}

			if (cnt == 5) {
				cout << "5번 실패하였습니다." << endl;
				cout << quest << endl;
				break;
			}

			if (wordGuessed) {
				cout << "정답입니다!" << endl;
				break;
			}
		}

		cout << "Next(y/n)?";
		char again;
		cin >> again;
		if (again == 'n') {
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}

void fileRead(vector<string>& v, ifstream& fin) {
	string line;
	while (getline(fin, line)) {
		v.push_back(line);
	}
}