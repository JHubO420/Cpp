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
    void getGraphic(int n) {//���ϴ� ��ü ����
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
	void show() {//��ü ��ü ����Ʈ ���
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