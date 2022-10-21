#include <iostream>
#include "Square.h"

double Square::getSide(){
    return side;
}

bool Square::setSide(double b){
    if(b > 0){
      side = b;
      return true;
    }
    else{
      return false;
    }
}

double Square::calcArea(){
    return getSide() * getSide();
}
