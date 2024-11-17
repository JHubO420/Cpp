#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;

class GraphicEditor {
	Shape* pStart = NULL;
	Shape* pLast;
	Shape* p = pStart;
	int count;
public:
	GraphicEditor() { count = 0; }
    Shape* getGraphic(int n) {//원하는 객체 생성
		if (count == 0) {//처음에 원 도형을 생성
			if (n == 1) {
				pStart = new Line();
				pLast = pStart;
				count++;
			}
			else if (n == 2) {
				pStart = new Circle();
				pLast = pStart;
				count++;
			}
			else if (n == 3) {
				pStart = new Rect();
				pLast = pStart;
				count++;
			}
		}
		else
		{
			if (n == 1) {
				pLast = pLast->add(new Line());
				count++;
			}
			else if (n == 2) {
				pLast = pLast->add(new Circle());
				count++;
			}
			else if (n == 3) {
				pLast = pLast->add(new Rect());
				count++;
			}
		}
		
		p = pStart;
		for (int i = 0; i < n+1; i++) {
			p->getNext();
		}
		return p;
	}
	void delGraphic(int n) {
		p = pStart;
		int i = 0;
		Shape* prev = NULL;  // 이전 객체를 추적하는 포인터

		while (p != NULL) {
			if (i == n) {
				Shape* q = p->getNext();  // 다음 객체를 미리 추적
				delete p;  // 현재 객체 삭제

				//객체 리스트에서 삭제되었을때 나머지들을 연결하는 작업
				if (prev != NULL) {//리스트 중간에 것을 삭제한 경우
					prev->getShape(q);  
					// 중간에 객체를 삭제하고 다음에 객채가 저장된 q를 
					// prev에 저장
					// prev = p처럼 다음 객체를 이전으로 설정하여 객체 리스트를 연결함
				}
				else {
					pStart = q;  // 첫 번째 객체를 삭제한 경우 pStart를 갱신
				}

				break;  // 삭제 후 루프 종료
			}
			i++;
			prev = p;  // 이전 객체를 갱신, 지금의 객체를 이전 객체로 변경
			p = p->getNext();  // 다음 객체를 가리킴
		}
	}
	void show() {
		p = pStart;
		int i = 0;
		while (p != NULL) {
			cout << i << " : ";
			p->paint();
			p = p->getNext();
			i++;
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
