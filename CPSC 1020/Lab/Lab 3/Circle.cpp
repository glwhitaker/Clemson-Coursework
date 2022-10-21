#include <iostream>
#include "Circle.h"


double Circle::getRadius(){
  	return radius;
}

bool Circle::setRadius(double r){
    if(r > 0){
      	radius = r;
      	return true;
    }
    else{
      	return false;
    }
}

double Circle::calcArea(){
 	const double PI = 3.14159;
  	return PI * (getRadius() * getRadius());
}
