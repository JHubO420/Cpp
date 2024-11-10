#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufactuer;
	int printedCount, availableCount;//printedCount:인쇄할 종이양, availableCount: 남은 종이
public:
	Printer() {
		this->model = "";
		this->manufactuer = "";
		this->availableCount = 0;
		this->printedCount = 0;
	}
	Printer(string model, string manuf, int count) {
		this->model = model;
		this->manufactuer = manuf;
		this->availableCount = count;
	}
	bool print(int pages) {
		if (pages > availableCount) {
			cout << "용지가 부족하여 프린트를 할 수 없습니다." << endl;
			return false;
		}
		else {
			this->printedCount += pages;
			this->availableCount -= pages;
			return true;
		}
	}
	string getManu() { return manufactuer; }
	string getModel() { return model; }
	int getCount() { return availableCount; }
};

class Ink :virtual public Printer {
	int availableInk;//남은 잉크양
public:
	Ink(string model, string manuf, int count, int ink) : Printer(model, manuf, count) {//명시적으로 기본 클래스 Printer의 생성자를 호출
		this->availableInk = ink;
	}
	bool printInkJek(int pages = 0) {
		if (print(pages)) {
			if (availableInk < pages) {
				cout << "잉크가 부족하여 프린트 할 수 없습니다" << endl;
				return false;
			}
			else
			{
				this->availableInk -= pages;
				return true;
			}
		}
		else{
			return false;
		}
	}
	void show() {
		cout << getModel() << " : " << getManu() << " ,남은 종이" << getCount() << "장 ,남은 잉크" << availableInk << endl;
	}
};

class Laser :virtual public Printer {
	int availableToner;//남은 토너양
public:
	Laser(string model, string manuf, int count, int toner) : Printer(model, manuf, count) {
		this->availableToner = toner;
	}
	bool printInkLaser(int pages = 0) {
		if (print(pages)) {
			if (availableToner < pages) {
				cout << "잉크가 부족하여 프린트 할 수 없습니다" << endl;
				return false;
			}
			else
			{
				this->availableToner -= pages;
				return true;
			}
		}
		else {
			return false;
		}
	}
	void show() {
		cout << getModel() << " ," << getManu() << " ,남은 종이" << getCount() << "장 ,남은 토너" << availableToner << endl;
	}

};


int main() {
	Ink* ink = new Ink("Officejet v40","HP", 5, 10);
	Laser* laser = new Laser("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
	cout << "잉크젯 : ";
	ink->show();
	cout << "레이저 : ";
	laser->show();

	char chek = 'y';
	int type, num;

	while (true) {
		if (chek == 'y') {
			cout << endl;
			cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
			cin >> type >> num;
			if (type == 1) {
				if (ink->printInkJek(num)) {
					cout << "프린트하였습니다." << endl;
				}
				ink->show();
				laser->show();
				cout << "계속 프린트 하시겠습니까(y/n)>>";
				cin >> chek;
				continue;
			}
			else if(type == 2){
				if (laser->printInkLaser(num)) {
					cout << "프린트하였습니다." << endl;
				}
				ink->show();
				laser->show();
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