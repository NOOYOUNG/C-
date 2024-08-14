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
    word.push_back(Word("human", "인간"));
    word.push_back(Word("society", "사회"));
    word.push_back(Word("doll", "인형"));
    word.push_back(Word("emotion", "감정"));
    word.push_back(Word("painting", "그림"));
    word.push_back(Word("bear", "곰"));
    word.push_back(Word("baby", "아기"));
    word.push_back(Word("picture", "사진"));
    word.push_back(Word("trade", "거래"));
    word.push_back(Word("friend", "친구"));

    cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;

    srand((unsigned)time(NULL));

    string example[4]{ "" };
    int n;
    while (true) {
        int index = rand() % word.size(); //무작위 단어 선택
        cout << word[index].getEng() << "?" << endl;

        int exIndex = rand() % 4; //4개 보기 중 정답 설정

        example[exIndex] = word[index].getKor();

        for (int i = 0; i < 4; i++) {
            if (i != exIndex) { //정답 제외 보기 추가
                bool dbcheck = true;
                while (dbcheck) { //보기 중복 확인
                    n = rand() % word.size();
                    if (example[0] != word[n].getKor() && example[1] != word[n].getKor() && example[2] != word[n].getKor() && example[3] != word[n].getKor()) {
                        example[i] = word[n].getKor();
                        dbcheck = false;
                    }
                }
            }
        }

        //보기 출력
        for (int i = 0; i < 4; i++) {
            cout << "(" << i + 1 << ")" << example[i] << " ";
        }
        cout << ":>";

        int answer;
        cin >> answer;

        if (answer >= 1 && answer <= 4) {
            if (exIndex == answer - 1) {
                cout << "맞았습니다!" << endl;
            }
            else {
                cout << "틀렸습니다!" << endl;
            }
        }
        else {
            cout << "종료합니다" << endl;
            break;
        }
    }
    for (int i = 0; i < 4; i++) {
        example[i] = "";
    }
}