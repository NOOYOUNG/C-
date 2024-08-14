#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*파일 크기 알아내기*/
long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end); // 포인터를 파일의 맨 끝으로 이동
	long length = fin.tellg(); // 포인터 위치 알아내내서 길이 측정
	return length;
}

int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin(file);
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}
	cout << file << "의 크기는" << getFileSize(fin);
	fin.close();
}


/* 스트림 상태검사
void showStreamState(ios& stream) {
	cout << "eof()" << stream.eof() << endl;
	cout << "fail()" << stream.fail() << endl;
	cout << "bad()" << stream.bad() << endl;
	cout << "good()" << stream.good() << endl;
}

int main() {
	const char* noExistFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\noexist.txt";
	const char* existFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt";

	ifstream fin(noExistFile);
	if (!fin) {
		cout << noExistFile << " 열기 오류" << endl;
		showStreamState(fin);

		cout << existFile << " 파일 열기" << endl;
		fin.open(existFile);
		showStreamState(fin);
	}

	int c;
	while ((c = fin.get()) != EOF) {
		cout.put((char)c);
	}

	cout << endl;
	showStreamState(fin);

	fin.close();
}
*/


/* 바이너리 파일 읽기 저장
int main() {
	const char* file = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\data.dat";

	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if (!fout) {
		cout << "파일 열기 오류";
		return 0;
	}

	int n[] = { 0,1,2,3,4,5,6,7,8,9 };
	double d = 3.15;
	fout.write((char*)n, sizeof(n));
	fout.write((char*)(&d), sizeof(d));
	fout.close();

	for (int i = 0; i < 10; i++) n[i] = 99;
	d = 8.15;

	cout << n[1] << endl << d << endl;

	ifstream fin(file, ios::in);
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}

	fin.read((char*)n, sizeof(n));
	fin.read((char*)(&d), sizeof(d));

	for (int i = 0; i < 10; i++) {
		cout << n[i] << ' ';
	}
	cout << endl << d << endl;
	fin.close();
}
*/


/* read로 이미지 복사
int main() {
	const char* srcFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\tekapo.bmp";
	const char* destFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\readcptekapo.bmp";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}

	char buf[1024];
	while (!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n);
	}

	cout << srcFile << "을 " << destFile << "로 복사완료" << endl;
	fsrc.close();
	fdest.close();
}
*/


/* 블록 단위 텍스트 읽기
int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "파일 열기 오류";
		return 0;
	}

	int cnt = 0;
	char s[32];
	while (!fin.eof()) { // 파일 끝까지 읽기
		fin.read(s, 32); // 최대 32바이트 읽고 배열 s에 저장
		int n = fin.gcount(); // 실제로 읽은 바이트 수
		cout.write(s, n); // 버퍼에 있는 n개의 바이트 출력
		cnt += n;
	}
	cout << "읽은 바이트 수는 " << cnt << endl;
	fin.close();
}
*/


/* 이미지 파일 복사하기
int main() {
	const char* srcFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\tekapo.bmp";
	const char* destFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\cptekapo.bmp";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}

	int c;
	while ((c = fsrc.get()) != EOF) { // 소스 파일을 끝까지 한바이트씩 읽음
		fdest.put(c); //읽은 바이트 파일에 출력
	}

	cout << srcFile << "을 " << destFile << "로 복사완료\n";
	fsrc.close();
	fdest.close();
}
*/


/* 파일 읽고 단어 검색
void fileRead(vector<string>& v, ifstream& fin) {
	string line;
	while (getline(fin, line)) {
		v.push_back(line); // fin 파일에서 한 줄씩 읽어 vector에 저장
	}
}

void search(vector<string>& v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word); // 벡터 v에서 word찾아 출력
		if (index != -1)
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	ifstream fin("word.txt");
	if (!fin) {
		cout << "word.txt 파일을 찾을 수 없습니다.";
		return 0;
	}

	fileRead(wordVector, fin);
	fin.close();

	cout << "word.txt 파일을 읽었습니다.";
	while (true) {
		cout << "검색할 단어를 입력하세요>> ";
		string word;
		getline(cin, word);
		if (word == "exit") break;
		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다." << endl;
}
*/


/* 한 줄 단위로 읽기
int main() {
	ifstream fin("C:\\Windows\\system.ini");
	if (!fin) {
		cout << "C:\\Windows\\system.ini 열기 실패" << endl;
		return 0;
	}

	char buf[81]; // 한 줄이 최대 80개 문자로 구성된다고 가정
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}

	fin.close();
}
*/


/* 두 개의 파일 연결하기
int main() {
	const char* firstFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt"; //포인터가 다른 문자열을 가리킬 수 있지만 포인터가 가리키는 문자열을 수정하지 않기를 원할 때 일반적인 형식
	const char* secondFile = "C:\\Windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << firstFile << " 열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in);
	if (!fin) {
		cout << secondFile << " 열기 오류";
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c); // fin에서 읽은 문자 fout 기록
	}

	fin.close();
	fout.close();
}
*/


/* get을 통한 파일에서 문자 읽기
int main() {
	const char* file = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt";
	ifstream fin(file);
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}

	int cnt = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		cnt++;
	}

	cout << "읽은 바이트 수는 " << cnt << endl;
	fin.close();
}
*/


/* 파일 읽기
int main() {
	ifstream fin;
	fin.open("C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt");
	if (!fin) {
		cout << "파일을 열 수 없습니다.";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << "이름은 " << name << endl;
	cout << "학번은 " << sid << endl;
	cout << "학과는 " << dept << endl;

	fin.close();
}
*/


/* 파일 쓰기
int main() {
	char name[10], dept[20];
	int sid;

	cout << "이름>> ";
	cin >> name;
	cout << "학번(숫자로)>> ";
	cin >> sid;
	cout << "학과>> ";
	cin >> dept;

	ofstream fout("C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt");
	if (!fout) {
		cout << "파일을 열 수 없습니다.";
		return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
}
*/