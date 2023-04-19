#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle: public Shape{
	
private:
    unsigned  width;
public:
    Rectangle(Scene & s);
    Rectangle(unsigned  w, Scene& s);
    Rectangle(unsigned  h,unsigned  w, Scene& s);
    Rectangle(unsigned  x,unsigned  y, unsigned  h, Scene& s);
    Rectangle(unsigned  x,unsigned  y, unsigned  h,unsigned  w, Scene& s);
    
    void set_width (unsigned  w) { width = w; }
    unsigned  get_width () { return width; }

    void Draw();
    ~Rectangle();
};

#endif // RECTANGLE_H
