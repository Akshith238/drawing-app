#include "Rectangle.h"
#include<fstream>
#include<time.h>
Rectangle::Rectangle(Scene & s): Shape(s) {}
Rectangle::Rectangle(unsigned  w, Scene& s):Shape(w,s) { set_width(w); }
Rectangle::Rectangle(unsigned  h,unsigned  w, Scene& s):Shape(s)
{
    set_height(h);
    set_width(w);
}
Rectangle::Rectangle(unsigned  x,unsigned  y, unsigned  h, Scene& s):Shape(x,y,h,s){}
Rectangle::Rectangle(unsigned  x,unsigned  y, unsigned  h,unsigned  w, Scene& s):Shape(x,y,h,s) 
{ 
   set_width(w); 
}

//get_width is the width of the Rectangle
//get_height is the height of the Rectangle
//get_x() & get_y() for the position
void Rectangle::Draw()
{
    for(unsigned z = 0; z < get_width() && z + get_x() < c.get_width_screen(); z++){

        for(unsigned a = 0; a < get_height() && a + get_y() < c.get_height_screen(); a++){

            if (z == 0){
			 c[get_x()][a + get_y()] = "*"; 
			 }
            else if (a == 0) { 
			 c[z + get_x()][get_y()] = "*"; 
			 }
            else if (z == get_width() - 1) { 
			 c[z + get_x()][a + get_y()] = "*"; 
			 }
            else if (a == get_height() - 1) { 
			 c[z + get_x()][a + get_y()] = "*"; 
			 }
        }
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Rectangle is drawn!"<<endl;
    fout.close();
    
}

Rectangle::~Rectangle() {}
