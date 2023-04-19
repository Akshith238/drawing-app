#ifndef HORIZONTAL_LINE_H
#define HORIZONTAL_LINE_H
#include "Shape.h"
class Horizontal_Line: public Shape{
	
public:
    Horizontal_Line(Scene & s);
    Horizontal_Line(unsigned  h, Scene & s);
    Horizontal_Line(unsigned  x,unsigned  y, unsigned  h, Scene & s);
    void Draw();
    ~Horizontal_Line();
};

#endif // HORIZONTAL_LINE_H
