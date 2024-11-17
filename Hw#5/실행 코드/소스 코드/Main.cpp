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
    Shape* getGraphic(int n) {//���ϴ� ��ü ����
		if (count == 0) {//ó���� �� ������ ����
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
		Shape* prev = NULL;  // ���� ��ü�� �����ϴ� ������

		while (p != NULL) {
			if (i == n) {
				Shape* q = p->getNext();  // ���� ��ü�� �̸� ����
				delete p;  // ���� ��ü ����

				//��ü ����Ʈ���� �����Ǿ����� ���������� �����ϴ� �۾�
				if (prev != NULL) {//����Ʈ �߰��� ���� ������ ���
					prev->getShape(q);  
					// �߰��� ��ü�� �����ϰ� ������ ��ä�� ����� q�� 
					// prev�� ����
					// prev = pó�� ���� ��ü�� �������� �����Ͽ� ��ü ����Ʈ�� ������
				}
				else {
					pStart = q;  // ù ��° ��ü�� ������ ��� pStart�� ����
				}

				break;  // ���� �� ���� ����
			}
			i++;
			prev = p;  // ���� ��ü�� ����, ������ ��ü�� ���� ��ü�� ����
			p = p->getNext();  // ���� ��ü�� ����Ŵ
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
		cout << "�׷��� �������Դϴ�." << endl;
		check = 0; 
	}
	void Insertion() {
		cout << "��:1, ��:2, �簢��:3 >> ";
		cin >> check;
		edit.getGraphic(check);
	}
	void Delete() {
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
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
		cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
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
