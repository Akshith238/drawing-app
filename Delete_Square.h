#ifndef DELETE_SQUARE_H
#define DELETE_SQUARE_H
#include "Rectangle.h"

class Delete_Square: public Rectangle{
	
public:
    Delete_Square(Scene & s);
    Delete_Square(unsigned  h, Scene& s);
    Delete_Square(unsigned  x,unsigned  y, unsigned  h, Scene& s);
    void Draw();
    ~Delete_Square();
};

#endif // DELETE_SQUARE_H
