#include "Shape.h"

Shape::Shape(Scene & scene): c(scene) {}

Shape::Shape(unsigned  x, Scene & scene): c(scene){
    
    this-> x = x;
}

//we use that constructor
Shape::Shape(unsigned  x, unsigned  y,unsigned  height, Scene & scene): c(scene){

    this-> x = x;
    this-> y = y;
    this-> height = height;
}

void Shape::Draw() {}
Shape::~Shape() {}
