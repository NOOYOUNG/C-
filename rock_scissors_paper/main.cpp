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
        gbb[0] = "����";
        gbb[1] = "����";
        gbb[2] = "��";
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
            if (rcp == "����" || rcp == "����" || rcp == "��") return rcp;
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
    cout << "***** ��ǻ�Ϳ� ����� ���� ���� �� ����� ��Ĩ�ϴ�. *****" << endl;
    cout << "���� �̸��� �Է��ϼ���>> ";
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
        else if (hturn == "����") {
            if (cturn == "����") cout << c.getName() << " is winner" << endl;
            else cout << h.getName() << " is winner" << endl;
        }
        else if (hturn == "����") {
            if (cturn == "����") cout << h.getName() << " is winner" << endl;
            else cout << c.getName() << " is winner" << endl;
        }
        else if (hturn == "��") {
            if (cturn == "����") cout << c.getName() << " is winner" << endl;
            else cout << h.getName() << " is winner" << endl;
        }
    }
}