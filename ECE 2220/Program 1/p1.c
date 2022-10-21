/*
Grayson Whitaker
ECE-2220
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float graphfunction(int userchoice, float x);

int main() {
    //loop until user quits
    int loop = 0;
    while(loop == 0){
        //prompt user to choose function
        printf("\nChoose one of the following functions to graph:\
        \n\n1. e(x)\n2. ln(x)\n3. sine(x)\n4. cosine(x)\n5. tangent(x)\
        \n\nOr type 'q' to quit.\n");
        char tempchoice;
        int userchoice;
        int validchoice = 0;
        while(validchoice == 0) {

            printf("\n(Type 1-5, q): ");
            scanf(" %c", &tempchoice);
            if(tempchoice == 'q') {
                exit(0);
            }
            else if(tempchoice - '0' >= 1 && tempchoice - '0' <= 5) {
                userchoice = tempchoice - '0';
                validchoice = 1;
            }
            else {
                printf("\n\033[1;31mPlease Make a Valid Choice.\033[0m");
            }

        }

        //prompt user to choose maximum and minimum for input range
        int validmaxmin = 0;
        float min_input, max_input;
        while(validmaxmin == 0) {
            printf("\nEnter minimum value for range of inputs: ");
            scanf(" %f", &min_input);
            printf("Enter maximum value for range of inputs: ");
            scanf(" %f", &max_input);
            if(min_input < max_input) {
                validmaxmin = 1;
            }
            else {
                printf("\n\033[1;31mPlease Choose Valid Range.\033[0m");
            }
        }

        //prompt user to choose number of rows/columns
        int validrowcol = 0;
        int row, column;
        while(validrowcol == 0) {
            printf("\nEnter number of rows (1-50): ");
            scanf(" %d", &row);
            printf("Enter number of columns (1-200): ");
            scanf(" %d", &column);
            if(row <= 50 && column <= 200) {
                validrowcol = 1;
            }
            else {
                printf("\n\033[1;31mPlease Choose Valid Number of Rows/Columns.\033[0m");
            }
        }
        printf("\n");

        //calculate outputs
        float output;
        float inputinc = (max_input - min_input)/column;
        float max_output = 0, min_output = 0;
        for(float i = min_input; i <= max_input; i = i + inputinc) {
            output = graphfunction(userchoice, i);
            printf("y[%f] = %f\n", i, output); 
            if(output > max_output) {
            max_output = output;
            }
            else if(output < min_output) {
            min_output = output;
            }   
        }
        float outputinc = (max_output - min_output)/row;

        //create array
        char * bin[row][column];
        float current_out, current_in, current_val;
        for(int i = 0; i < row; i++) {
            current_out = max_output - (outputinc*(i+1));
            for(int j = 0; j < column; j++) {
                current_in = min_input + (inputinc*j);
                current_val = graphfunction(userchoice, current_in);
                if(current_val <= current_out + outputinc/2 && current_val >= current_out - outputinc/2) {
                    bin[i][j] = "X";
                }
                else {
                    bin[i][j] = " ";
                }
            }
        }

        //print graph
        printf("\n");
        for(int i = 0; i < row; i++) {
            current_out = max_output - (outputinc*(i+1));
            printf("%2d: %12.6f - ", row - (i+1), current_out);
            for(int j = 0; j < column; j++) {
                printf("%s ", bin[i][j]);

            }
            printf("\n");
        }

        //prompt user to repeat
        int validloop = 0;
        while(validloop == 0){
            char loopchoice;
            printf("\nGraph another function? (Type 'c' to continue or type 'q' to quit): ");
            scanf(" %s", &loopchoice);
            if(loopchoice == 'q') {
                validloop = 1;
                loop = 1;
            }
            else if(loopchoice == 'c') {
                validloop = 1;
            }
            else {
                printf("\n\033[1;31mPlease Make a Valid Choice.\033[0m");
            }
        }
    }
}


//function to calculate outputs
float graphfunction(int userchoice, float x) {
    float output;
        if(userchoice == 1) {
            output = exp(x);
        }
        else if(userchoice == 2) {
            if(x == 0){
                output = 0.0 / 0.0;
            }
            else {
                output = log(x);
            }
        }
        else if(userchoice == 3) {
            output = sin(x);
        }
        else if(userchoice == 4) {
            output = cos(x);
        }
        else if(userchoice == 5) {
            output = tan(x);
        }
    return output;
}