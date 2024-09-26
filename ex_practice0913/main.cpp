/*217p 13번
#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string str;
public:
	Histogram(string str);
	void put(string plusstr);
	void putc(char ch);
	void print();
};

Histogram::Histogram(string str) {
	this->str = str;
}

void Histogram::put(string plusstr) {
	str += plusstr;
}

void Histogram::putc(char ch) {
	str += ch;
}

void Histogram::print() {
	cout << str << endl << endl;

	int cnt = 0;
	int alphabet[27] = { 0 };
	char buf[10000];

	strcpy_s(buf, sizeof(buf), str.c_str());

	for (int i = 0; i < strlen(buf); i++) {
		if (isalpha(buf[i])) {
			if (buf[i] < 91) {
				buf[i] = tolower(buf[i]);
			}
			cnt++;
			alphabet[buf[i] - 97]++;
		}
	}

	cout << "총 알파벳 수 : " << cnt << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 'a') << "(" << alphabet[i] << ") : ";
		for (int j = 0; j < alphabet[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
*/


/*151p 6번
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random{
public:
  int next();
  int nextInRange(int start, int end);
};

int Random::next(){
  while(true){
	int n=rand(); // 0부터 RAND_MAX까지의 정수 값을 반환
	if(n%2==0)
	  return n;
  }
}

int Random::nextInRange(int start, int end){
  while(true){
	int n=rand()%(end-start+1)+start;
	if(n%2==0)
	  return n;
  }
}

int main(){
  srand((unsigned)time(0));

  Random r;
  cout<<"--0에서 "<<RAND_MAX<<"까지의 랜덤 정수 10개--"<<endl;

  for(int i=0; i<10; i++){
	int n=r.next();
	cout<<n<<' ';
  }

  cout<<endl<<endl<<"--2에서 10까지의 랜덤 정수 10개--"<<endl;

  for(int i=0; i<10; i++){
	int n=r.nextInRange(2,10);
	cout<<n<<' ';
  }
}
*/

/*151p 5번
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random{
public:
  int next();
  int nextInRange(int start, int end);
};

int Random::next(){
  int n=rand(); // 0부터 RAND_MAX까지의 정수 값을 반환
  return n;
}

int Random::nextInRange(int start, int end){
  int n=rand()%(end-start+1)+start;
  return n;
}

int main(){
  srand((unsigned)time(0));

  Random r;
  cout<<"--0에서 "<<RAND_MAX<<"까지의 랜덤 정수 10개--"<<endl;

  for(int i=0; i<10; i++){
	int n=r.next();
	cout<<n<<' ';
  }

  cout<<endl<<endl<<"--2에서 4까지의 랜덤 정수 10개--"<<endl;

  for(int i=0; i<10; i++){
	int n=r.nextInRange(2,4);
	cout<<n<<' ';
  }
}
*/

/*150p 3번
#include <iostream>

using namespace std;

class Account{
private:
  string name;
  int id;
  int balance;
public:
  Account(string name, int id, int balance);
  string getOwner();
  void deposit(int money);
  void withdraw(int money);
  int inquiry();
};

Account::Account(string name, int id, int balance){
  this->name=name;
  this->id=id;
  this->balance=balance;
}

string Account::getOwner(){
  return name;
}

int Account::inquiry(){
  return balance;
}

void Account::deposit(int m){
  balance+=m;
}

void Account::withdraw(int m){
  balance-=m;
}

int main(){
  Account a("kitea", 1, 5000);
  a.deposit(50000);
  cout<<a.getOwner()<<"의 잔액은 "<<a.inquiry()<<endl;
  a.withdraw(20000);
  cout<<a.getOwner()<<"의 잔액은 "<<a.inquiry()<<endl;
}
*/

/* 149p 1번
#include <iostream>
using namespace std;

class Tower {
public:
	int height;
	Tower() {
		height = 1;
	}
	Tower(int h) {
		height = h;
	}
	int getHeight() {
		return height;
	}
};

int main() {
	Tower myTower;
	Tower seoulTower(100);

	cout << "myTower" << myTower.getHeight() << endl;
	cout << "seoulTower" << seoulTower.getHeight() << endl;
}
*/