#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle:public Shape{

public:
    Triangle(Scene & s);
    Triangle(unsigned  h, Scene& s);
    Triangle(unsigned  x,unsigned  y, unsigned  h, Scene& s);
    void Draw();
    ~Triangle();
};

#endif // TRIANGLE_H
