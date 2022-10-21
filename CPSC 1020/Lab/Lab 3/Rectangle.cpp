#include <iostream>
#include "Rectangle.h"

double Rectangle::getLength(){
    return length;
}

bool Rectangle::setLength(double b){
    if(b > 0){
    	length = b;
    	return true;
    }
    else{
    	return false;
    }
}

double Rectangle::getWidth(){
    return width;
}

bool Rectangle:: setWidth(double h){
    if(h > 0){
    	width = h;
    	return true;
    }
    else{
    	return false;
    }
}

double Rectangle::calcArea(){
    return getLength() * getWidth();
}
