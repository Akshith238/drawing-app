#include "Square.h"
#include<fstream>
#include<time.h>
Square::Square(Scene & s): Rectangle(s) {}
Square::Square(unsigned  h, Scene& s):Rectangle(s){
    set_height(h);
}
//we use that constructor
Square::Square(unsigned  x,unsigned  y, unsigned  h, Scene& s):Rectangle(x,y,h,s) {}

// that function for draw a square
//get_height() is the height of the square
//get_x() & get_y() for the position
void Square:: Draw(){

    for(unsigned  z = 0; z<get_height()&&z+get_x()<c.get_width_screen(); z++) {

        for(unsigned  a = 0; a<get_height()&&a+get_y()<c.get_height_screen(); a++) {

            if (z == 0) { c[get_x()][a + get_y()]="*"; }  

            else if (a == 0) { c[z + get_x()][get_y()]="*"; }
            
            else if (z == get_height() - 1) { c[z + get_x()][a + get_y()]="*"; }
            
            else if (a == get_height() - 1) { c[z + get_x()][a + get_y()]="*"; }
        }
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Square is drawn!"<<endl;
    fout.close();
}
Square::~Square() {}
