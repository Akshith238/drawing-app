#include "Circle.h"
#include <math.h>

Circle::Circle(Scene &s):Shape(s) {}

Circle::Circle(unsigned  r, Scene& s):Shape(s){ set_height(r); }

Circle::Circle(unsigned  x,unsigned  y, unsigned  r, Scene& s):Shape(x,y,r,s) {}

unsigned  Circle:: radius(unsigned  x,unsigned  y){ return round(sqrt(pow(x,2) + pow(y,2))); }

void Circle::Draw(){
    
    unsigned  si,sj;
    si = (get_x() - get_height()) < 0 ? 0 : get_x() - get_height();
    sj = (get_y() - get_height()) < 0 ? 0 : get_y() - get_height();

    for(unsigned i = si; i <= 2 * get_height() + si && i < c.get_width_screen(); i++){

        for(unsigned j = sj; j <= 2 * get_height() + sj && j < c.get_height_screen(); j++){

            if(get_height() == radius(i - get_x(),j - get_y())){
                
                c[i][j]="*";
            }
        }
    }
}

Circle::~Circle() {}
