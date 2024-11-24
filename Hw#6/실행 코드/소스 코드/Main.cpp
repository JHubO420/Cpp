#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

#include <vector>

class GraphicEditor {
	Shape* p = NULL;
	vector<Shape*> v;
public:
	GraphicEditor() { }
    void getGraphic(int n) {//원하는 객체 생성
		if (n == 1) {
			p = new Line();
			v.push_back(p);
		}
		else if (n == 2) {
			p = new Circle();
			v.push_back(p);
		}
		else if (n == 3) {
			p = new Rect();
			v.push_back(p);
		}
	}
	void delGraphic(int n) {
		vector<Shape*>::iterator it;
		it = v.begin();
		if (n > 0) {
			for (int i = 0; i < n; i++) {
				it++;
			}
		}
		it = v.erase(it);

	}
	void show() {//전체 객체 리스트 출력
		for (int i = 0; i < v.size(); i++) {
			cout << i << " : ";
			v[i]->paint();
		}
	}
};

class UI {
	int check;
	GraphicEditor edit;
	int i = 0;
public:
	UI() { 
		cout << "그래픽 에디터입니다." << endl;
		check = 0; 
	}
	void Insertion() {
		cout << "선:1, 원:2, 사각형:3 >> ";
		cin >> check;
		edit.getGraphic(check);
	}
	void Delete() {
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> check;
		edit.delGraphic(check);
	}
	void Show() {
		edit.show();
	}
};
int main() {
	UI ui;
	int a;
	while (true) {
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> a;
		if (a == 1) {
			ui.Insertion();
		}
		else if (a == 2) {
			ui.Delete();
		}
		else if (a == 3) {
			ui.Show();
		}
		else if (a == 4) {
			break;
		}
	}
}