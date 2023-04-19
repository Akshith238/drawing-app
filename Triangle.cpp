#include "Triangle.h"
#include<fstream>
#include<time.h>
using namespace std;
Triangle::Triangle (Scene & s): Shape(s){}

Triangle::Triangle (unsigned  h, Scene& s):Shape(s){

    set_height(h);
}

//we use that constructor
Triangle::Triangle (unsigned  x,unsigned  y, unsigned  h, Scene& s):Shape(x,y,h,s){}

//get_height() is the height of the Triangle
//get_x() & get_y() for the position
void Triangle::Draw(){

    for(unsigned  z = 0; z < get_height() && z + get_x() < c.get_width_screen(); z++){
    
        for(unsigned  a = 0; a < z + 1 && a + get_y() < c.get_height_screen(); a++){

            c[z + get_x()][a + get_y()] = "*";
        }
        cout<<endl;
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Triangle is drawn!"<<endl;
    fout.close();
}

Triangle::~Triangle () {}
