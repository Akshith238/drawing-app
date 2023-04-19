#include "Delete_Square.h"
#include<fstream>
#include<time.h>
Delete_Square::Delete_Square(Scene & s): Rectangle(s) {}

Delete_Square::Delete_Square(unsigned  h, Scene& s): Rectangle(s) { set_height(h); }

Delete_Square::Delete_Square(unsigned  x,unsigned  y, unsigned  h, Scene& s): Rectangle(x,y,h,s) {}

// Delete a Square like Eraser
// get_height() is the height of the Delete_Square
// get_x() & get_y() for the position
void Delete_Square::Draw(){
  
  for(unsigned  z=0; z<get_height()&&z+get_x()<c.get_width_screen(); z++){

        for(unsigned  a=0; a<get_height()&&a+get_y()<c.get_height_screen(); a++){

            c[z+get_x()][a+get_y()]=" ";
        }
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Erased!"<<endl;
    fout.close();
}

Delete_Square::~Delete_Square(){}
