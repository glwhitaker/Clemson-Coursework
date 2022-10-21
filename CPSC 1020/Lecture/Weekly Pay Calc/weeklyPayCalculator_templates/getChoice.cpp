// Accepts and returns user's validated menu choice
#include <iostream>
#include "getChoice.h"
using namespace std;

char getChoice()
{
	char letter;        // Holds user's letter choice
	
	// Get the user's choice
	cin >> letter;

	// Validate the choice
	while (letter != 'H' && letter != 'h' 
	    && letter != 'S' && letter != 's')
	{	
		cout << "Enter H or S: ";
		cin  >> letter;
	}
	// Return the choice
	return letter;
}
