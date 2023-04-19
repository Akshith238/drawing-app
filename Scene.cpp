#include "Scene.h"
#include <string>
#include <fstream>
#include<iostream>
#include<time.h>
using namespace std;
//Default Constructor
Scene::Scene():width_screen(20),height_screen(20){
	
    arr = new string* [width_screen];
    for(unsigned  i =0 ; i < width_screen; i++){

        arr[i] = new string[height_screen];

    }

    for (unsigned  i=0; i<width_screen; i++) {

        for(unsigned  c=0; c<height_screen; c++){

            arr[i][c]=" ";
        }
    }
}
//Parameterized Constructor
Scene::Scene(unsigned  w,unsigned  h):width_screen(w),height_screen(h){

    arr = new string* [width_screen];

    for(unsigned  i =0 ; i < width_screen; i++) {

        arr[i] = new string[height_screen];
    }

    for (unsigned  i=0; i < width_screen; i++) {

        for(unsigned  c=0; c < height_screen; c++) {

            arr[i][c]=" ";
        }
    }
}

// operator >> for the input of width and height of the screen
//Actually we use that for determine the height & width of the screen
istream &operator>>(istream &input,Scene &s){

    cout<<"The Width Of Scene";
    input>>s.width_screen;
    cout<<"The Height Of Scene";
    input>>s.height_screen;
    while((s.height_screen>200 && s.width_screen>200) ||s.width_screen>200||s.height_screen>200 ){

        cout<<"Sorry, your sketch will be ugly, so choose small width & height"<<endl;
        input>>s.width_screen;
        input>>s.height_screen;
    }
    s.arr = new string* [s.width_screen];
    for(unsigned  i = 0 ; i<s.width_screen; i++){

        s.arr[i] = new string[s.height_screen];
    }

    for (unsigned  i = 0; i < s.width_screen; i++){

        for(unsigned  c = 0; c < s.height_screen; c++){

            s.arr[i][c]=" ";
        }
    }
    return input;
}

// operator << for the output of the scene
ostream &operator<<(ostream &output,Scene &s){

    output<<"............  Scene  ............"<<endl;

    for (unsigned i = 0; i < s.width_screen; i++){

        for(unsigned c = 0; c < s.height_screen; c++){

            output<<s.arr[i][c];
        }
        output<<endl;
    }
    return output;
}

// Draw in the Scene class
void Scene::draw (){

    for(unsigned i = 0; i < width_screen; i++) {

        for(unsigned j = 0; j < height_screen; j++) {

            cout<<arr[i][j];
        }
        cout<<endl;
    }
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Scene is created!";
    fout.close();
}

//Big three

// First the copy constructor
Scene::Scene(const Scene &obj){

    width_screen=obj.width_screen;
    height_screen=obj.height_screen;
    string **arr = new string* [width_screen];
    
    for(unsigned i = 0 ; i < width_screen; i++){

        arr[i] = new string[height_screen];
    }

    for(unsigned z = 0; z < width_screen; z++){

        for(unsigned x = 0; x < height_screen; x++){

            arr[z][x] = obj.arr[z][x];
        }
    }
}

//Second the operator =
Scene Scene :: operator = (const Scene & obj){

    width_screen = obj.width_screen;
    height_screen = obj.height_screen;
//why i delete the array
//because the pointer point to another array
//so i want to delete that pointer
//and reserve a new one to put on it
    for(unsigned i = 0; i < width_screen; i++){

        for(unsigned j = 0; j < height_screen; j++){

            delete []arr[i];
        }
        delete []arr;
    }

    string **arr = new string* [width_screen];
    
    for(unsigned  i = 0 ; i < width_screen; i++){

        arr[i] = new string[height_screen];
    }

    for(unsigned  z = 0; z < width_screen; z++){

        for(unsigned  x = 0; x < height_screen; x++){

            arr[z][x] = obj.arr[z][x];
        }
    }
    return obj;
}

//Third the destructor
//to delete the dynamic array
Scene::~Scene(){
    for(unsigned j = 0; j < width_screen; j++) {
        
        delete []arr[j];
    }
    delete []arr;
}

void Scene::saveToFile(ofstream& fileHandler){

// Here we assume that the file is opened and ready to be read
// write width and height of the scene
    fileHandler << width_screen << " " << height_screen << " "; 

    for(unsigned  i = 0; i < width_screen; i++) {

        for(unsigned  j = 0; j < height_screen; j++) {

            if(arr[i][j].compare("*") == 0)
                fileHandler << arr[i][j] << " ";

            else  // This is the case of Space we will choose another character like #
                fileHandler << "#" << " ";
        }
    }
    cout<<"Ended saving from file \n\n";
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Scene saved to file!"<<endl;
    fout.close();
}

void Scene::loadFromFile(ifstream& fileHandler){

//delete the actually dynamic array

    for(unsigned  j = 0; j < width_screen; j++) {
        
        delete []arr[j];
    }
    delete []arr;

    string ch;
    fileHandler >> width_screen >> height_screen;
    //we read the height & width
    //to make a dynamic array use the old pointer to point on it
    arr = new string* [width_screen];

    for(unsigned  i = 0 ; i < width_screen; i++) {
        
        arr[i] = new string[height_screen];
    }

    for (unsigned  i = 0; i < width_screen; i++) {
        for(unsigned  c = 0; c < height_screen; c++) {
            
            arr[i][c] = " ";
        }
    }

    for(unsigned  i = 0; i < width_screen ; i++) {

        for(unsigned  j = 0; j < height_screen; j++) {

            fileHandler >> ch;
            
            if(ch.compare("*") == 0) 
			{ 
			    arr[i][j] = ch; 
			}
            else if(ch.compare("#") == 0) 
			{ 
			    arr[i][j] = " "; 
		    }
        }
    }
    cout<<"Ended loading from file \n\n";
    ofstream fout;
    fout.open("Log file.txt",ios::app);
    time_t curr_time=time(NULL);
    fout<<ctime(&curr_time)<<"Loaded from file!"<<endl;
    fout.close();
}
bool Scene::exc_handle(unsigned height,unsigned x,unsigned y)
{
	if(height>height_screen||x>height_screen||y>width_screen)
	{
		return false;
	}
	else
	{
		return true;
	}
}
