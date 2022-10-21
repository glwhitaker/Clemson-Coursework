#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void quatbits(int a);
void octalbits(int a);
void hexbits(int a);

int main(){
    //take valid user input, loop if not valid
    char userChoice;
    while(1){
        printf("\nEnter a Quaternary, Octal, or Hexadecimal Number (lead with Q, O, or H, respectively): ");
        scanf("%c", &userChoice);

        if(toupper(userChoice) == 'Q' || toupper(userChoice) == 'O' || toupper(userChoice) == 'H') break;

        printf("\n\033[1;31mPlease Enter a Valid Number.\033[0m");
    }
	if(toupper(userChoice) == 'Q'){
		int a =1;
		quatbits(a);
	}
	else if(toupper(userChoice) == 'O'){
		int a = 1;
		octalbits(a);
	}
	else if(toupper(userChoice) == 'H'){
		int a = 1;
		hexbits(a);
	}
}

void quatbits(int a){
	int quatInput;
	scanf("%d", &quatInput);
}

void octalbits(int a){
	unsigned int octInput;
	scanf("%o", &octInput);
	printf("Hexadecimal: 0x%hX\n", toupper(octInput));
}

void hexbits(int a){ 
	unsigned int hexInput;
  	scanf("%x", &hexInput);
	printf("Octal: %o\n", hexInput);
}
