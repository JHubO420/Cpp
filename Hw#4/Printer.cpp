#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufactuer[2];
	int printedCount, availableCount;//printedCount:인쇄할 종이양, availableCount: 남은 종이
public:
	Printer() {
		this->model = "";
		this->manufactuer[0] = "";
		this->manufactuer[1] = "";
		this->availableCount = 0;
		this->printedCount = 0;
	}
	Printer(string m, int p) {
		this->model = m;
		this->availableCount = p;
	}
	void print(int pages) {
		if (pages > availableCount) {
			this->printedCount = printedCount;
			this->availableCount = availableCount;
			cout << ",남은 종이 : " << availableCount << "장";
		}
		else {
			this->printedCount += pages;
			this->availableCount -= pages;
			cout << ",남은 종이 : " << availableCount << "장";
		}
	}
	void setManu(string a, string b) {
		this->manufactuer[0] = a;
		this->manufactuer[1] = b;
	}
	void printModel() {
		cout << model << " : ";
	}
	void manu() {
		cout << manufactuer[0] << ", " << manufactuer[1]<<" ";
	}
	bool Count(int p) {
		if (p > availableCount) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

class Ink:virtual public Printer {
	int availableInk;//남은 잉크양
public:
	Ink(string m, int p, int a) : Printer(m, p) {//명시적으로 기본 클래스 Printer의 생성자를 호출
		setManu("Officejet v40", "HP");
		availableInk = a;
	}
	void printInkJek(int pages = 0) {
		if (Count(pages)) {
			this->availableInk -= 0;
		}
		else
		{
			this->availableInk -= pages;
		}
		manu();
		print(pages);
		cout << ",남은 잉크 " << availableInk << endl;

	}
};

class Laser :virtual public Printer {
	int availableToner;//남은 토너양
public:
	Laser(string m, int p, int a) : Printer(m, p) {
		setManu("SCX-6x45", "삼성전자");
		availableToner = a;
	}
	void printInkLaser(int pages = 0) {
		if (Count(pages)) {
			this->availableToner -= 0;
		}
		else
		{
			this->availableToner -= pages;
		}
		manu();
		print(pages);
		cout << ",남은 토너 " << availableToner << endl;
	}
};


int main() {
	Ink ink("잉크젯", 5, 10);
	Laser laser("레이저", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	ink.printModel(); ink.printInkJek();
	laser.printModel(); laser.printInkLaser();

	char chek = 'y';

	while (true) {
		if (chek == 'y') {
			cout << endl;
			cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
			int type, num;
			cin >> type >> num;
			if (type == 1) {
				if (ink.Count(num)) {
					cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				}
				else
				{
					cout << "프린트하였습니다." << endl;
				}
				ink.printInkJek(num);
				laser.printInkLaser();
				cout << "계속 프린트 하시겠습니까(y/n)>>";
				cin >> chek;
				continue;
			}
			else if(type == 2){
				if (laser.Count(num)) {
					cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				}
				else
				{
					cout << "프린트하였습니다." << endl;
				}
				ink.printInkJek();
				laser.printInkLaser(num);
				cout << "계속 프린트 하시겠습니까(y/n)>>";
				cin >> chek;
				continue;
			}
		}
		else if (chek == 'n') {
			break;
		}

	}
}