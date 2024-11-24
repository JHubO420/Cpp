#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
using namespace std;

class Shape {
    Shape* next;
protected:
    virtual void draw() = 0;
public:
    Shape() { next = NULL; }
    virtual ~Shape() {}
    void paint();
    Shape* add(Shape* p);
    Shape* getNext() { return next; }
    Shape* getShape(Shape* shape) {
        next = shape;
        return next;
    }
};

#endif // SHAPE_H

//#ifndef, #define, #endif 
