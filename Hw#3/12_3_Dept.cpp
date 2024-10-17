#include <iostream>
using namespace std;

#include <string>

class Dept {
	int size;
	int* scores;
public:
	Dept(int size) {//생성자
		this->size = size;
		scores = new int[size];
	}
	~Dept();//소멸자
	int getSize() { return size; }
	void read();//입력받기
	bool isOver60(int index);//60점 이상인지 확인
};

void Dept::read() {
	cout << "10개 점수 입력>>";
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
	com.read();//입력받기
	int n = countPass(com);//복사 적용
	cout << "60점 이상은 " << n << "명" << endl;
}

//문제 입력은 제대로 전부 들어간다 
//하지만 60점 이상인지 아닌지를 판단을 못함
