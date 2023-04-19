#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <iostream>
using namespace std;
class Scene{

private:
    unsigned  width_screen,height_screen;
    string **arr;

public:
    void set_width_screen (unsigned  w) { width_screen=w; }
    void set_height_screen (unsigned  h) { height_screen=h; }

    unsigned  get_width_screen(){ return width_screen; }
    unsigned  get_height_screen() { return height_screen; }

    Scene();
    Scene(unsigned  w,unsigned  h);
    void draw ();
    bool exc_handle(unsigned height,unsigned x,unsigned y);
    Scene(const Scene &obj);
    Scene operator = (const Scene & obj);


    class Array{

    public:
        Array(string * arr):arr1(arr) {}
        string& operator[](unsigned  index) { return arr1[index]; }
        string* arr1;
    };

    Array operator[](unsigned  index)
	{ 
	     return Array(arr[index]); 
	}
    friend istream &operator>>(istream &input,Scene &s);
    friend ostream &operator<<(ostream &output,Scene &s);
    void saveToFile(ofstream &fileHandler);
    void loadFromFile(ifstream& fileHandler);

    ~Scene();

};

#endif // SCENE_H
