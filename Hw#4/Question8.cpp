#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufactuer;
	int printedCount, availableCount;//printedCount:�μ��� ���̾�, availableCount: ���� ����
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
			cout << "������ �����Ͽ� ����Ʈ�� �� �� �����ϴ�." << endl;
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
	int availableInk;//���� ��ũ��
public:
	Ink(string model, string manuf, int count, int ink) : Printer(model, manuf, count) {//��������� �⺻ Ŭ���� Printer�� �����ڸ� ȣ��
		this->availableInk = ink;
	}
	bool printInkJek(int pages = 0) {
		if (print(pages)) {
			if (availableInk < pages) {
				cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�" << endl;
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
		cout << getModel() << " : " << getManu() << " ,���� ����" << getCount() << "�� ,���� ��ũ" << availableInk << endl;
	}
};

class Laser :virtual public Printer {
	int availableToner;//���� ��ʾ�
public:
	Laser(string model, string manuf, int count, int toner) : Printer(model, manuf, count) {
		this->availableToner = toner;
	}
	bool printInkLaser(int pages = 0) {
		if (print(pages)) {
			if (availableToner < pages) {
				cout << "��ũ�� �����Ͽ� ����Ʈ �� �� �����ϴ�" << endl;
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
		cout << getModel() << " ," << getManu() << " ,���� ����" << getCount() << "�� ,���� ���" << availableToner << endl;
	}

};


int main() {
	Ink* ink = new Ink("Officejet v40","HP", 5, 10);
	Laser* laser = new Laser("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : ";
	ink->show();
	cout << "������ : ";
	laser->show();

	char chek = 'y';
	int type, num;

	while (true) {
		if (chek == 'y') {
			cout << endl;
			cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
			cin >> type >> num;
			if (type == 1) {
				if (ink->printInkJek(num)) {
					cout << "����Ʈ�Ͽ����ϴ�." << endl;
				}
				ink->show();
				laser->show();
				cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
				cin >> chek;
				continue;
			}
			else if(type == 2){
				if (laser->printInkLaser(num)) {
					cout << "����Ʈ�Ͽ����ϴ�." << endl;
				}
				ink->show();
				laser->show();
				cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
				cin >> chek;
				continue;
			}
		}
		else if (chek == 'n') {
			break;
		}

	}
}