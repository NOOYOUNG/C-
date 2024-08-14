#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*���� ũ�� �˾Ƴ���*/
long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end); // �����͸� ������ �� ������ �̵�
	long length = fin.tellg(); // ������ ��ġ �˾Ƴ����� ���� ����
	return length;
}

int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin(file);
	if (!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}
	cout << file << "�� ũ���" << getFileSize(fin);
	fin.close();
}


/* ��Ʈ�� ���°˻�
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
		cout << noExistFile << " ���� ����" << endl;
		showStreamState(fin);

		cout << existFile << " ���� ����" << endl;
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


/* ���̳ʸ� ���� �б� ����
int main() {
	const char* file = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\data.dat";

	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if (!fout) {
		cout << "���� ���� ����";
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
		cout << "���� ���� ����";
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


/* read�� �̹��� ����
int main() {
	const char* srcFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\tekapo.bmp";
	const char* destFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\readcptekapo.bmp";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	char buf[1024];
	while (!fsrc.eof()) {
		fsrc.read(buf, 1024);
		int n = fsrc.gcount();
		fdest.write(buf, n);
	}

	cout << srcFile << "�� " << destFile << "�� ����Ϸ�" << endl;
	fsrc.close();
	fdest.close();
}
*/


/* ��� ���� �ؽ�Ʈ �б�
int main() {
	const char* file = "C:\\Windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}

	int cnt = 0;
	char s[32];
	while (!fin.eof()) { // ���� ������ �б�
		fin.read(s, 32); // �ִ� 32����Ʈ �а� �迭 s�� ����
		int n = fin.gcount(); // ������ ���� ����Ʈ ��
		cout.write(s, n); // ���ۿ� �ִ� n���� ����Ʈ ���
		cnt += n;
	}
	cout << "���� ����Ʈ ���� " << cnt << endl;
	fin.close();
}
*/


/* �̹��� ���� �����ϱ�
int main() {
	const char* srcFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\tekapo.bmp";
	const char* destFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\cptekapo.bmp";

	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	ofstream fdest(destFile, ios::out | ios::binary);
	if (!fdest) {
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	int c;
	while ((c = fsrc.get()) != EOF) { // �ҽ� ������ ������ �ѹ���Ʈ�� ����
		fdest.put(c); //���� ����Ʈ ���Ͽ� ���
	}

	cout << srcFile << "�� " << destFile << "�� ����Ϸ�\n";
	fsrc.close();
	fdest.close();
}
*/


/* ���� �а� �ܾ� �˻�
void fileRead(vector<string>& v, ifstream& fin) {
	string line;
	while (getline(fin, line)) {
		v.push_back(line); // fin ���Ͽ��� �� �پ� �о� vector�� ����
	}
}

void search(vector<string>& v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word); // ���� v���� wordã�� ���
		if (index != -1)
			cout << v[i] << endl;
	}
}

int main() {
	vector<string> wordVector;
	ifstream fin("word.txt");
	if (!fin) {
		cout << "word.txt ������ ã�� �� �����ϴ�.";
		return 0;
	}

	fileRead(wordVector, fin);
	fin.close();

	cout << "word.txt ������ �о����ϴ�.";
	while (true) {
		cout << "�˻��� �ܾ �Է��ϼ���>> ";
		string word;
		getline(cin, word);
		if (word == "exit") break;
		search(wordVector, word);
	}
	cout << "���α׷��� �����մϴ�." << endl;
}
*/


/* �� �� ������ �б�
int main() {
	ifstream fin("C:\\Windows\\system.ini");
	if (!fin) {
		cout << "C:\\Windows\\system.ini ���� ����" << endl;
		return 0;
	}

	char buf[81]; // �� ���� �ִ� 80�� ���ڷ� �����ȴٰ� ����
	while (fin.getline(buf, 81)) {
		cout << buf << endl;
	}

	fin.close();
}
*/


/* �� ���� ���� �����ϱ�
int main() {
	const char* firstFile = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt"; //�����Ͱ� �ٸ� ���ڿ��� ����ų �� ������ �����Ͱ� ����Ű�� ���ڿ��� �������� �ʱ⸦ ���� �� �Ϲ����� ����
	const char* secondFile = "C:\\Windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);
	if (!fout) {
		cout << firstFile << " ���� ����";
		return 0;
	}

	fstream fin(secondFile, ios::in);
	if (!fin) {
		cout << secondFile << " ���� ����";
		return 0;
	}

	int c;
	while ((c = fin.get()) != EOF) {
		fout.put(c); // fin���� ���� ���� fout ���
	}

	fin.close();
	fout.close();
}
*/


/* get�� ���� ���Ͽ��� ���� �б�
int main() {
	const char* file = "C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt";
	ifstream fin(file);
	if (!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}

	int cnt = 0;
	int c;
	while ((c = fin.get()) != EOF) {
		cout << (char)c;
		cnt++;
	}

	cout << "���� ����Ʈ ���� " << cnt << endl;
	fin.close();
}
*/


/* ���� �б�
int main() {
	ifstream fin;
	fin.open("C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt");
	if (!fin) {
		cout << "������ �� �� �����ϴ�.";
		return 0;
	}

	char name[10], dept[20];
	int sid;

	fin >> name;
	fin >> sid;
	fin >> dept;

	cout << "�̸��� " << name << endl;
	cout << "�й��� " << sid << endl;
	cout << "�а��� " << dept << endl;

	fin.close();
}
*/


/* ���� ����
int main() {
	char name[10], dept[20];
	int sid;

	cout << "�̸�>> ";
	cin >> name;
	cout << "�й�(���ڷ�)>> ";
	cin >> sid;
	cout << "�а�>> ";
	cin >> dept;

	ofstream fout("C:\\Users\\CHOI\\Desktop\\C++\\240812_file_inout\\student.txt");
	if (!fout) {
		cout << "������ �� �� �����ϴ�.";
		return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
}
*/