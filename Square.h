#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"

class Square: public Rectangle{

public:
    Square(Scene & scene);
    Square(unsigned  height, Scene& scene);
    Square(unsigned  x,unsigned  y, unsigned  height, Scene& scene);
    void exc_handle(unsigned height);
    void Draw();
    ~Square();
};

#endif // SQUARE_H
