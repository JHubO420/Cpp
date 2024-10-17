#include <iostream>
using namespace std;

#include <string>

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {//������
		this->size = size;
		scores = new int[size];
	}
	~Dept();//�Ҹ���
	int getSize() { return size; }
	void read();//�Է¹ޱ�
	bool isOver60(int index);//60�� �̻����� Ȯ��
};

void Dept::read() {
	cout << "10�� ���� �Է�>>";
	for (int i = 0; i < size; i++) {
		cin >> scores[i];
	}
}

bool Dept::isOver60(int index) {
	if (this->scores[index] > 60) {
		return true;
	}
	else
	{
		return false;
	}
}

Dept::~Dept() {
	delete[] scores;
}

int countPass(Dept& dept) {
	int count = 0;
	for (int i = 0; i < dept.getSize(); i++) {
		if (dept.isOver60(i)) count++;
	}
	return count;
}

int main() {
	Dept com(10);
	com.read();//�Է¹ޱ�
	int n = countPass(com);//���� ����
	cout << "60�� �̻��� " << n << "��" << endl;
}

//���� �Է��� ����� ���� ���� 
//������ 60�� �̻����� �ƴ����� �Ǵ��� ����