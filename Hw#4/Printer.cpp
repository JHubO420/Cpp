#include <iostream>
#include <string>
using namespace std;

class Printer {
	string model;
	string manufactuer[2];
	int printedCount, availableCount;//printedCount:�μ��� ���̾�, availableCount: ���� ����
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
			cout << ",���� ���� : " << availableCount << "��";
		}
		else {
			this->printedCount += pages;
			this->availableCount -= pages;
			cout << ",���� ���� : " << availableCount << "��";
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
	int availableInk;//���� ��ũ��
public:
	Ink(string m, int p, int a) : Printer(m, p) {//��������� �⺻ Ŭ���� Printer�� �����ڸ� ȣ��
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
		cout << ",���� ��ũ " << availableInk << endl;

	}
};

class Laser :virtual public Printer {
	int availableToner;//���� ��ʾ�
public:
	Laser(string m, int p, int a) : Printer(m, p) {
		setManu("SCX-6x45", "�Ｚ����");
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
		cout << ",���� ��� " << availableToner << endl;
	}
};


int main() {
	Ink ink("��ũ��", 5, 10);
	Laser laser("������", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	ink.printModel(); ink.printInkJek();
	laser.printModel(); laser.printInkLaser();

	char chek = 'y';

	while (true) {
		if (chek == 'y') {
			cout << endl;
			cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
			int type, num;
			cin >> type >> num;
			if (type == 1) {
				if (ink.Count(num)) {
					cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				}
				else
				{
					cout << "����Ʈ�Ͽ����ϴ�." << endl;
				}
				ink.printInkJek(num);
				laser.printInkLaser();
				cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
				cin >> chek;
				continue;
			}
			else if(type == 2){
				if (laser.Count(num)) {
					cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				}
				else
				{
					cout << "����Ʈ�Ͽ����ϴ�." << endl;
				}
				ink.printInkJek();
				laser.printInkLaser(num);
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