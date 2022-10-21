/*
GRAYSON WHITAKER
ECE 2220-001
PROGRAM 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 50

void main(int argc, char* argv[]){
    int continueGame = 0;
    while(continueGame == 0){
        // exit program if the user does not input enough command line arguments
        if(argc <= 3){
            printf("\033[0;31mNot enough command line arguments...\033[0m\n");
            exit(0);
        }
        
        // exit program if file is not opened
        FILE *dictionary = fopen(argv[1], "r");
        if (dictionary == NULL){
            printf("\033[0;31mUnable to open file \"%s\"...\033[0m\n", argv[1]);
            exit(0);
        }

        // exit program if value if number of letters/guesses entered is not between 3 and 12
        if(atoi(argv[2]) > 12 || atoi(argv[2]) < 3){
            printf("\033[0;31mNumber of letters/guesses must both be between 3 and 12...\033[0m\n");
            exit(0);
        }
        else if(atoi(argv[3]) > 12 || atoi(argv[3]) < 3){
            printf("\033[0;31mNumber of letters/guesses must both be between 3 and 12...\033[0m\n");
            exit(0);
        }

        // initialize variables
        int letterAmount = atoi(argv[2]);
        int guessAmount = atoi(argv[3]);
        char word[MAX_CHARS];
        int i = 0;

        // get number of rows to allocate
        int rows = 0, columns = letterAmount;
        while(fgets(word, MAX_CHARS, dictionary)){
            if(strlen(word) == letterAmount + 2){
                rows++;
            }
        }

        rewind(dictionary);

        // copy string from dictionary into tempList and allocate memory
        char **tempList = malloc(rows * sizeof(char *));
        i = 0;
        while(fgets(word, MAX_CHARS, dictionary) && i < rows){
            if(strlen(word) == letterAmount + 2){
                tempList[i] = malloc(strlen(word)+1);
                if(tempList[i] != NULL){
                    strcpy(tempList[i], word);
                }
                i++;
            }
        }

        // make upper case copy to use for program
        char wordList[rows][columns+1];
        for(i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                wordList[i][j] = toupper(tempList[i][j]);
                wordList[i][j+1] = '\0';
            }
        }

        free(tempList);

        // prompt user to enter word to start
        printf("\nEnter A %d Letter Word:", letterAmount);
        
        int turnCount = 0, gameWon = 1;
        char currentGuess[letterAmount], feedback[letterAmount];
        char allGuesses[guessAmount][letterAmount];
        char *p;
        do {
            gameWon = 1;
            // print previous guesses as well as prompt for new guess
            for(int i = 0; i <= turnCount; i++){
                if(i == 0) printf("\n");
                printf("\n");
                printf("    Guess %d = ", (i + 1));
                for(int j = 0; j < letterAmount; j++){
                    if(allGuesses[i][j] && i != turnCount) printf("%c", allGuesses[i][j]);
                }
            }
            // take guess input
            if(fgets(currentGuess, letterAmount + 1, stdin)){
                if(p = strchr(currentGuess,'\n')) *p = 0;
                else {
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }
            // keep track of guesses
            for(int i = 0; i < letterAmount; i++){
                allGuesses[turnCount][i] = currentGuess[i];
            }
            // take feedback input
            printf("    Feedback: ");
            if(fgets(feedback, letterAmount + 1, stdin)){
                if(p = strchr(feedback,'\n')) *p = 0;
                else {
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
            }
            for(int i = 0; i < letterAmount; i++){
                if(feedback[i] != '^' && feedback[i] != '\0') gameWon = 0;
            }
            turnCount++;
            printf("\n");

            // create array of double letters
            int doubleLetter = 0;
            char repeatLetter[letterAmount+1];
            for(int i = 0; i < letterAmount + 1; i++){
                repeatLetter[i] = '*';
            }
            for(int i = 0; i < letterAmount; i++){
                for(int j = 0; j < letterAmount; j++){
                    if(currentGuess[i] == currentGuess[j] && i != j){
                        repeatLetter[i] = toupper(currentGuess[i]);
                        repeatLetter[j] = toupper(currentGuess[j]);
                    }
                }
            }

            // edit dictionary array based on feedback input and print out possible words
            char correct, position, incorrect;
            int location, index;
            char *ptr;
            if (gameWon == 0) printf("Possible Word(s):\n\n");
            for(int i = 0; i < letterAmount; i++){
                if(feedback[i] == '^'){
                    correct = currentGuess[i];
                    ptr = strchr(currentGuess, correct);
                    index = (int)(ptr - currentGuess);
                    for(int j = 0; j < rows; j++){
                        if((strchr(wordList[j], toupper(correct))) - wordList[j] != index){
                            if(strchr(repeatLetter, toupper(correct))){
                                doubleLetter = 1;
                            }
                            memset(wordList[j], 0, strlen(wordList[j]));
                        }
                    }
                }
                else if(feedback[i] == '>'){
                    position = currentGuess[i];
                    ptr = strchr(currentGuess, position);
                    index = (int)(ptr - currentGuess);
                    for(int j = 0; j < rows; j++){
                        if(!(strchr(wordList[j], toupper(position))) || (strchr(wordList[j], toupper(position))) - wordList[j] == index){
                            memset(wordList[j], 0, strlen(wordList[j]));
                        }
                    }
                }
                else if(feedback[i] == 'x' || feedback[i] == 'X'){
                    incorrect = currentGuess[i];
                    ptr = strchr(currentGuess, incorrect);
                    index = (int)(ptr - currentGuess);
                    for(int j = 0; j < rows; j++){
                        if(strchr(wordList[j], toupper(incorrect)) && doubleLetter == 0){
                            memset(wordList[j], 0, strlen(wordList[j]));
                        }
                    }
                }
            }

            // create columns of words if player has not already won
            int wordCount = 0;
            if(gameWon == 0){
                for(int i = 0; i < rows; i++){
                    if(wordList[i][0] != '\0'){
                        printf("%s\t", wordList[i]);
                        wordCount++;
                        if(wordCount%10 == 0) printf("\n");
                    }
                }
        }   
        } while(turnCount < guessAmount && gameWon == 0);

        // printf victory or game over based on whether the player has gotten the word correct or not
        if(gameWon == 0){
            printf("Game Over :(\n");
        }
        else if(gameWon == 1){
            printf("Victory!!!\n");
        }
        printf("\n");
        
        
        printf("Play again? (y/n): ");
        char continueChoice = getchar();
        if(continueChoice == 'n' || continueChoice == 'N'){
            continueGame = 1;
        }
        while ((getchar()) != '\n');
    }
}