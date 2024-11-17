#ifndef RECT_H
#define RECT_H

#include <iostream>
#include "Shape.h" 
using namespace std;

class Rect : public Shape {
protected:
    virtual void draw();  
};

#endif // RECT_H
