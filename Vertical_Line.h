#ifndef VERTICAL_LINE_H
#define VERTICAL_LINE_H
#include "Shape.h"

class Vertical_Line: public Shape{

public:
    Vertical_Line(Scene & s);
    Vertical_Line(unsigned  h, Scene& s);
    Vertical_Line(unsigned  x,unsigned  y, unsigned  h, Scene& s);
    void Draw();
    ~Vertical_Line();
};

#endif // VERTICAL_LINE_H
