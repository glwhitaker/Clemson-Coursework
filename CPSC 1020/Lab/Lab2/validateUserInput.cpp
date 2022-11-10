#include <iostream>

using namespace std;

// ensure user input > 0
bool validateUserInput(double userInput){
    if(userInput < 0){
      return 0;
    }
    else{
      return 1;
    }
}
