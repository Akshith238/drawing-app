#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape{

public:
    Circle(Scene &s);
    Circle(unsigned  radius,Scene &s);
    Circle(unsigned  x,unsigned  y, unsigned  radius, Scene &s);
    void Draw();
    unsigned  radius(unsigned  x,unsigned  y);
    ~Circle();
};

#endif // CIRCLE_H
