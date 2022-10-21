#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

#define BORDER "======================================================"
#define EMPTY "           "
#define SPACE "                          "
#define BORDER2 "======================="

void userInput(void);
void genNum(void);
void gameDone(void);
void gameWon(void);
void gameReset(void);
void upArrow(void);
void downArrow(void);
void rightArrow(void);
void leftArrow(void);

// initialize global arrays for number board
int numberSelect[10] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 4};
int numberBoard[4][4];

// initialize global variables
int highScore = 0;
int score = 0;
int start = 0;
int range = 9;
int gameOver = 1;
int win = 0;

int main(void){
    // seed rand function
    srand(time(NULL));

    // generate random starting board
    genNum();

    // open window and start game
    initscr();
    noecho();
    curs_set(0);

    // initialize color pairs
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);

    // initialize logo
    char logo1[] = " ____   ___  _  _    ___";
    char logo2[] = "|___ \\ / _ \\| || |  ( _ )";
    char logo3[] = "  __) | | | | || |_ / _ \\";
    char logo4[] = " / __/| |_| |__   _| (_) |";
    char logo5[] = "|_____|\\___/   |_|  \\___/";

    // print start screen with logo
    printw("Score: %-5d", score);
    printw("%s", SPACE);
    printw("High Score: %-5d", highScore);
    printw("\n");
    printw("%s\n", BORDER);
    printw("||\t       %s\t\t    ||\n", logo1);
    printw("||\t       %s\t    ||\n", logo2);
    printw("||\t       %s\t    ||\n", logo3);
    printw("||\t       %s\t    ||\n", logo4);
    printw("||\t       %s\t    ||\n", logo5);
    printw("||\t\t\t\t\t\t    ||\n");
    printw("||\t\tPRESS ANY KEY TO BEGIN...\t    ||\n");
    printw("%s\n", BORDER);
    getch();
    
    // enter loop to play game
    while(1){
        erase();
        // print starting board
        printw("Score: %-5d", score);
        printw("%s", SPACE);
        printw("High Score: %-5d", highScore);
        printw("\n");
        for(int j = 0; j < 4; j++){
            printw("%s\n", BORDER);
            printw("|");
                for(int k = 0; k < 4; k++){
                    if(numberBoard[j][k] != 0) printw("|  %4d     |", numberBoard[j][k]);
                    else printw("|%s|", EMPTY);
                    
                }
            printw("|\n");
        }
        printw("%s\n", BORDER);
        printw("          Use Arrow Keys to Play || Q to Exit\n");
        refresh();

        // take arrow input or quit with q
        userInput();
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(numberBoard[j][k] == 2048 && win == 0) gameWon();
            }
        }
    }
    return 0;
}

void genNum(void){
    // generate numbers
    int randBoard1, randBoard2, randNumber;
    for(int i = 0; i < 2; i++){
        // only generate 1 number if past start
        if(start != 0){
            i = 1;
        }
        randBoard1 = rand() % 4;
        randBoard2 = rand() % 4;
        randNumber = rand() % range;
        // make sure same location on the array is not selected
        if(numberBoard[randBoard1][randBoard2] == 0){
            numberBoard[randBoard1][randBoard2] = numberSelect[randNumber];
        }
        else i = 0;
        gameOver = 1;
        for(int j= 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(numberBoard[j][k] == 0) gameOver = 0;
            }
        }
        if(gameOver == 1){
            i = 1;
            gameDone();
        }
    }
    start = 1;
    range = 10;
}

void userInput(void){
    // take user Input
    char inputexit = getch();
    if(inputexit == '\033' || inputexit == 'Q' || inputexit == 'q' || inputexit == 'R' || inputexit == 'r'){
        // quit if user presses q
        if(inputexit == 'Q' || inputexit == 'q'){
            endwin();
            exit(0);
        }
        // reset board if user presses r
        else if(inputexit == 'R' || inputexit == 'r'){
            gameReset();
        }
        else{
            getch();
            switch(getch()){
                case 'A': // up arrow
                    erase();
                    upArrow();
                    genNum();
                    if(score >= highScore) highScore = score;
                    refresh();
                    break;
                case 'B': // down arrow
                    erase();
                    downArrow();
                    genNum();
                    if(score >= highScore) highScore = score;
                    refresh();
                    break;
                case 'C': // right arrow
                    erase();
                    rightArrow();
                    genNum();
                    if(score >= highScore) highScore = score;
                    refresh();
                    break;
                case 'D': // left arrow
                    erase();
                    leftArrow();
                    genNum();
                    if(score >= highScore) highScore = score;
                    refresh();
                    break;
                }
        }
    }
}

void upArrow(void){
    // check each array location and move or combine based on conditions
    for(int j = 0; j < 3; j++){
        for(int k = 0; k < 4; k++){
            for(int l = 1; 4 - l != j; l++){
                if(numberBoard[j][k] == 0 || numberBoard[j+l][k] == numberBoard[j][k]){
                    if(numberBoard[j+l][k] == numberBoard[j][k] && (numberBoard[j+l-1][k] == 0 || numberBoard[j+l-1][k] == numberBoard[j][k])){
                        numberBoard[j][k] = numberBoard[j+l][k] * 2;
                        score += numberBoard[j][k];
                        if(score >= highScore){
                            highScore = score;
                        }
                    }
                    else if(numberBoard[j+l][k] == numberBoard[j][k]) break;
                    else numberBoard[j][k] = numberBoard[j+l][k];
                    numberBoard[j+l][k] = 0;
                }
            }
        }
    }
}

void downArrow(void){
    // check each array location and move or combine based on conditions
    for(int j = 3; j > 0; j--){
        for(int k = 0; k < 4; k++){
            for(int l = 1; l <= j; l++){
                if(numberBoard[j][k] == 0 || numberBoard[j-l][k] == numberBoard[j][k]){
                    if(numberBoard[j-l][k] == numberBoard[j][k] && (numberBoard[j-l+1][k] == 0 || numberBoard[j-l+1][k] == numberBoard[j][k])){
                        numberBoard[j][k] = numberBoard[j-l][k] * 2;
                        score += numberBoard[j][k];
                        if(score >= highScore){
                            highScore = score;
                        }
                    }
                    else if(numberBoard[j-l][k] == numberBoard[j][k]) break;
                    else numberBoard[j][k] = numberBoard[j-l][k];
                    numberBoard[j-l][k] = 0;
                }
            }
        }
    }
}

void rightArrow(void){
    // check each array location and move or combine based on conditions
    for(int j = 0; j < 4; j++){
        for(int k = 3; k > 0; k--){
            for(int l = 1; l <= k; l++){
                if(numberBoard[j][k] == 0 || numberBoard[j][k-l] == numberBoard[j][k]){
                    if(numberBoard[j][k-l] == numberBoard[j][k] && (numberBoard[j][k-l+1] == 0 || numberBoard[j][k-l+1] == numberBoard[j][k])){
                        numberBoard[j][k] = numberBoard[j][k-l] * 2;
                        score += numberBoard[j][k];
                        if(score >= highScore){
                            highScore = score;
                        }
                    }
                    else if(numberBoard[j][k-l] == numberBoard[j][k]) break;
                    else numberBoard[j][k] = numberBoard[j][k-l];
                    numberBoard[j][k-l] = 0;
                }
            }
        }
    }    
}

void leftArrow(void){
    // check each array location and move or combine based on conditions
    for(int j = 0; j < 4; j++){
        for(int k = 0; k < 3; k++){
            for(int l = 1; 4 - l != k; l++){
                if(numberBoard[j][k] == 0 || numberBoard[j][k+l] == numberBoard[j][k]){
                    if(numberBoard[j][k+l] == numberBoard[j][k] && (numberBoard[j][k+l-1] == 0 || numberBoard[j][k+l-1] == numberBoard[j][k])){
                        numberBoard[j][k] = numberBoard[j][k+l] * 2;
                        score += numberBoard[j][k];
                        if(score >= highScore){
                            highScore = score;
                        }
                    }
                    else if(numberBoard[j][k+l] == numberBoard[j][k]) break;
                    else numberBoard[j][k] = numberBoard[j][k+l];
                    numberBoard[j][k+l] = 0;
                }
            }
        }
    }    
}

void gameWon(void){
    // show victory screen in green and allow player to continue
    printw("Score: %-5d", score);
    printw("%s", SPACE);
    printw("High Score: %-5d", highScore);
    printw("\n");
    for(int j = 0; j < 4; j++){
        if(j == 2){
            printw("%s", BORDER2);
            attron(COLOR_PAIR(2));
            printw("VICTORY!");
            attroff(COLOR_PAIR(2));
            printw("%s\n", BORDER2);
        }
        else printw("%s\n", BORDER);
        printw("|");
            for(int k = 0; k < 4; k++){
                if(numberBoard[j][k] != 0) printw("|  %4d     |", numberBoard[j][k]);
                else printw("|%s|", EMPTY);
            }
        printw("|\n");
    }
    printw("%s\n", BORDER);
    printw("   Continue as Normal || R to Restart || Q to Exit\n");
    refresh();
    win = 1;
    userInput();
}

void gameDone(void){
    // show game over screen and allow player to retry or quit
    printw("Score: %-5d", score);
    printw("%s", SPACE);
    printw("High Score: %-5d", highScore);
    printw("\n");
    for(int j = 0; j < 4; j++){
        if(j == 2){
            printw("%s", BORDER2);
            attron(COLOR_PAIR(1));
            printw("GAMEOVER");
            attroff(COLOR_PAIR(1));
            printw("%s\n", BORDER2);
        }
        else printw("%s\n", BORDER);
        printw("|");
            for(int k = 0; k < 4; k++){
                if(numberBoard[j][k] != 0) printw("|  %4d     |", numberBoard[j][k]);
                else printw("|%s|", EMPTY);
            }
        printw("|\n");
    }
    printw("%s\n", BORDER);
    printw("            Any Key to Retry || Q to Exit\n");
    refresh();
    gameReset();
    userInput();
}

void gameReset(void){
    // reset board if player chooses to
    gameOver = 0;
    win = 0;
    start = 0;
    score = 0;
    for(int j= 0; j < 4; j++){
        for(int k = 0; k < 4; k++){
            numberBoard[j][k] = 0;
        }
    }
    genNum();
    refresh();
}
