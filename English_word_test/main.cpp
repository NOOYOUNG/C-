#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

class Word {
    string eng;
    string kor;
public:
    Word(string eng, string kor) {
        this->eng = eng;
        this->kor = kor;
    }
    string getEng() { return eng; }
    string getKor() { return kor; }
};

int main() {
    vector<Word> word;
    word.push_back(Word("human", "�ΰ�"));
    word.push_back(Word("society", "��ȸ"));
    word.push_back(Word("doll", "����"));
    word.push_back(Word("emotion", "����"));
    word.push_back(Word("painting", "�׸�"));
    word.push_back(Word("bear", "��"));
    word.push_back(Word("baby", "�Ʊ�"));
    word.push_back(Word("picture", "����"));
    word.push_back(Word("trade", "�ŷ�"));
    word.push_back(Word("friend", "ģ��"));

    cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� �����մϴ�." << endl;

    srand((unsigned)time(NULL));

    string example[4]{ "" };
    int n;
    while (true) {
        int index = rand() % word.size(); //������ �ܾ� ����
        cout << word[index].getEng() << "?" << endl;

        int exIndex = rand() % 4; //4�� ���� �� ���� ����

        example[exIndex] = word[index].getKor();

        for (int i = 0; i < 4; i++) {
            if (i != exIndex) { //���� ���� ���� �߰�
                bool dbcheck = true;
                while (dbcheck) { //���� �ߺ� Ȯ��
                    n = rand() % word.size();
                    if (example[0] != word[n].getKor() && example[1] != word[n].getKor() && example[2] != word[n].getKor() && example[3] != word[n].getKor()) {
                        example[i] = word[n].getKor();
                        dbcheck = false;
                    }
                }
            }
        }

        //���� ���
        for (int i = 0; i < 4; i++) {
            cout << "(" << i + 1 << ")" << example[i] << " ";
        }
        cout << ":>";

        int answer;
        cin >> answer;

        if (answer >= 1 && answer <= 4) {
            if (exIndex == answer - 1) {
                cout << "�¾ҽ��ϴ�!" << endl;
            }
            else {
                cout << "Ʋ�Ƚ��ϴ�!" << endl;
            }
        }
        else {
            cout << "�����մϴ�" << endl;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        example[i] = "";
    }
}