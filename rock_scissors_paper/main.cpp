#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

class AbstractPlayer {
    string name;
protected:
    string gbb[3];
public:
    AbstractPlayer(string name) {
        this->name = name;
        gbb[0] = "가위";
        gbb[1] = "바위";
        gbb[2] = "보";
    }
    virtual string turn() = 0;
    string getName() { return name; }
};

class Human : public AbstractPlayer {
public:
    Human(string name) :AbstractPlayer(name) { ; }
    string turn() {
        string rcp;
        while (1) {
            cout << getName() << ">>";
            getline(cin, rcp);
            if (rcp == "가위" || rcp == "바위" || rcp == "보") return rcp;
        }
    }
};

class Computer : public AbstractPlayer {
public:
    Computer() :AbstractPlayer("Computer") { srand((unsigned)time(NULL)); }
    string turn() {
        int n = rand() % 3;
        return gbb[n];
    }
};

int main() {
    string name;
    cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****" << endl;
    cout << "선수 이름을 입력하세요>> ";
    getline(cin, name);

    Human h(name);
    Computer c;

    while (1) {
        string hturn = h.turn();
        string cturn = c.turn();

        cout << c.getName() << ": " << cturn << endl;

        if (hturn == cturn) {
            cout << "the same" << endl;
        }
        else if (hturn == "가위") {
            if (cturn == "바위") cout << c.getName() << " is winner" << endl;
            else cout << h.getName() << " is winner" << endl;
        }
        else if (hturn == "바위") {
            if (cturn == "가위") cout << h.getName() << " is winner" << endl;
            else cout << c.getName() << " is winner" << endl;
        }
        else if (hturn == "보") {
            if (cturn == "가위") cout << c.getName() << " is winner" << endl;
            else cout << h.getName() << " is winner" << endl;
        }
    }
}