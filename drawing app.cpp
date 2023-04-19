#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "Shape.h"
#include "Scene.h"
#include "Square.h"
#include "Horizontal_Line.h"
#include "Vertical_Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Delete_Square.h"

using namespace std;

int main ()
{
    Scene sc;
    cin>>sc;
    int choose;
    for (int v=1; v!=0; v++)
    {
        Shape *s=NULL;
        unsigned height,width,x,y;
        cout<<"..............................Welcome.............................."<<endl<<endl;
        cout<<"Choose what you want"<<endl;
        cout<<"____________________"<<endl<<endl;
        cout<<"1----->Square"<<"\n"<<"2----->Rectangle"<<"\n"<<"3----->Triangle"<<"\n"
            <<"4----->Horizontal_Line"<<"\n"<<"5----->Vertical_Line"<<
            "\n"<<"6----->Circle"<<"\n"<<"7----->Save file"<<"\n"<<"8----->load file"<<"\n"
            <<"9----->Use the Eraser\n"<< "press any thing for-----> "<<"Exit"<<"\n";
        cin>>choose;

        //if the user enter integer then char like (1b)

        if(cin.fail())
        {
            cout<<"oooooohhhhhhhhhhhhhhhhhhhh"<<endl;
            cout<<"sorry, Enter correct number :)"<<endl;
            return 0;
        }

        switch (choose)
        {
        case 1:
        {
            cout <<"..........Let's draw a Square.........."<<endl;
            cout <<"Enter the height "<<endl;
            cin>>height;
            cout<<"where did you want to put it"<<endl;
            cout<<"Enter the first point at the left in your square"<<endl;
            cin>>x>>y;
            s=new Square(x,y,height,sc);
            s->Draw();
            break;
        }

        case 2:
        {
            cout <<"..........Let's draw a Rectangle.........."<<endl;
            cout <<"Enter the width"<<endl;
            cin>>height;
            cout <<"Enter the height"<<endl;
            cin>>width;
            cout<<"where did you want to put it "<<endl;
            cout<<"Enter the first point at the left of your Rectangle"<<endl;
            cin>>x>>y;
            s=new Rectangle(x,y,height,width,sc);
            s->Draw();
            break;
        }

        case 3:
        {
            cout <<"..........Let's draw a Triangle.........."<<endl;
            cout <<"Enter the height"<<endl;
            cin>>height;
            cout<<"where did you want to put it"<<endl;
            cout<<"Enter the first point at the left of your Triangle"<<endl;
            cin>>x>>y;
            s=new Triangle(x,y,height,sc);
            s->Draw();
            break;
        }

        case 4:
        {
            cout <<"..........Let's draw a Horizontal_Line.........."<<endl;
            cout <<"Enter the length"<<endl;
            cin>>height;
            cout<<"where did you want to put it"<<endl;
            cout<<"Enter the first point at the left of your Horizontal_Line"<<endl;
            cin>>x>>y;
            s=new Horizontal_Line(x,y,height,sc);
            s->Draw();
            break;
        }

        case 5:
        {
            cout <<"Let's draw a Vertical_Line.........."<<endl;
            cout <<"Enter the length"<<endl;
            cin>>height;
            cout<<"where did you want to put it"<<endl;
            cout<<"Enter the first point at the left of your Vertical_Line"<<endl;
            cin>>x>>y;
            s=new Vertical_Line(x,y,height,sc);
            s->Draw();
            break;
        }

        case 6:
        {
            cout <<"..........Let's draw a Circle.........."<<endl;
            cout <<"Enter the radius"<<endl;
            cin>>height;
            cout<<"where did you want to put it"<<endl;
            cout<<"Enter the first point at the left of your Circle"<<endl;
            cin>>x>>y;
            s=new Circle(x,y,height,sc);
            s->Draw();
            break;
        }

        case 7:
        {
            //Let's ask the user to enter the file he wants to save it too.
            cout<<"Save file to: ..\n";
            string fileName=" ";
            cin>>fileName;
            //after that we need to open that file and have a handler to deal with it

            ofstream file(fileName.c_str(),std::ofstream::out|std::ofstream::trunc);
            if(file.is_open())
            {
                //this Code will be executed if the file opened successfully
                sc.saveToFile(file);
            }
            else cout <<"File is not opened\n";
            //We should not forget to close the file
            file.close();
            break;
        }

        case 8:
        {
            cout<<"load from file : ..\n";
            string fileName=" ";
            cin>>fileName;
            ifstream file(fileName.c_str(),std::ifstream::in);
            if(file.is_open())
            {
                sc.loadFromFile(file);
            }
            else cout <<"File is not opened\n";

            file.close();
            break;
        }

        case 9:
        {
            cout <<"..........Let's use the Eraser.........."<<endl;
            cout <<"Enter the height "<<endl;
            cin>>height;
            cout<<"where did you want to start delete"<<endl;
            cout<<"Enter the first point at the left"<<endl;
            cin>>x>>y;
            s=new Delete_Square(x,y,height,sc);
            s->Draw();
            break;
        }
        default:
            return 0;
        }
        cout<<sc;
    }

    return 0;
}
