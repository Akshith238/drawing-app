#ifndef SHAPE_H
#define SHAPE_H
#include "Scene.h"

class Shape{
private:
    unsigned  height;
    unsigned  x;
    unsigned  y;
protected:
    Scene& c;
public:
    virtual void Draw() = 0;

    void set_height (unsigned  h) { height = h; }
    void set_x ( unsigned  x1) { x = x1; }
    void set_y (unsigned  y1) { y = y1; }
    unsigned  get_height() { return height; }
    unsigned  get_x( ) { return x; }
    unsigned  get_y() { return y; }

    Shape(Scene & s);
    Shape(unsigned  x, Scene & s);
    Shape(unsigned  x, unsigned  y,unsigned  height, Scene & s);
    ~Shape();
};

#endif // SHAPE_H
