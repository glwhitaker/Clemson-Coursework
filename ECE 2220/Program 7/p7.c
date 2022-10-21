#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

#define PLANTTOP "\\|/\n"
#define PLANTMID "--|--\n"
#define PLANTBOT "-------------------------\n"
#define PLANTSTEM "| |\n"

int plantFert = 10000, plantWat = 1000;

void printTitleScreen(void);
void farmerFunction(int *pid);
void clearinputBuffer(void);
void plantFunction(FILE *plantOutput, int plantID);
void plantFullGrown(FILE *plantOutput, int plantID);
void subtractFert(void);
void subtractWat(void);
void feedSignal(int signal);
void waterSignal(int signal);
void printWarning(FILE *plantOutput);

int main(void){
    // print title screen
    printTitleScreen();

    // create variables and arrays for opening pseudoterminals
    int i, j, ptsNum[20], ptsCount = 0;
    FILE *fp;
    char ptsName[20];

    // attempt to open pts
    for(i = 1; i < 30; i++){
        sprintf(ptsName, "/dev/pts/%d", i);
        if((fp = fopen(ptsName, "r")) != NULL){
            ptsNum[ptsCount] = i;
            ptsCount++;
            fclose(fp);
        }
    }

    // open terminals to write child processes to
    FILE *plantTerm[3];
    for(i = ptsCount - 3, j = 0; i < ptsCount; i++, j++){
        sprintf(ptsName, "/dev/pts/%d", ptsNum[i]);
        plantTerm[j] = fopen(ptsName, "w");
    }

    signal(SIGUSR1, feedSignal);
    signal(SIGUSR2, waterSignal);

    int pid[3];
    // create child processes
    pid[2] = fork();
    if(pid[2] > 0){
        pid[1] = fork();
        if(pid[1] > 0){
            pid[0] = fork();
            if(pid[0] > 0){
                //printf("%d %d %d %d\n", getpid(), pid[0], pid[1], pid[2]);
                farmerFunction(pid);
            }
            else plantFunction(plantTerm[2], 1);
        }
        else plantFunction(plantTerm[1], 2);
    }
    else plantFunction(plantTerm[0], 3);

    // close terminals
    fclose(plantTerm[0]);
    fclose(plantTerm[1]);
    fclose(plantTerm[2]);

    return 0;
}

void printTitleScreen(void){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    printf("\e[1;1H\e[2J");
    for(int i = 0; i < w.ws_col; i++){
        printf("-");
    }
    printf("\n");

    // feed me title screen
    printf("\e[1m");
    printf("%*c", w.ws_col/2 - 17, ' ');
    printf(" ____ ____ ____ ____    _  _ ____ \n");
    printf("%*c", w.ws_col/2 - 17, ' ');
    printf("(  __|  __|  __|    \\  ( \\/ |  __)\n");
    printf("%*c", w.ws_col/2 - 17, ' ');
    printf(" ) _) ) _) ) _) ) D (  / \\/ \\) _) \n");
    printf("%*c", w.ws_col/2 - 17, ' ');
    printf("(__) (____|____|____/  \\_)(_(____)\n\n");
    printf("\e[0m");

    for(int i = 0; i < w.ws_col; i++){
        printf("-");
    }
    printf("\n");

    // instructions to start
    printf("%*c", w.ws_col/2 - 16, ' ');
    printf("Make sure to have a terminal open\n");
    printf("%*c", w.ws_col/2 - 15, ' ');
    printf("for each of your three plants.\n\n");
    printf("%*c", w.ws_col/2 - 11, ' ');
    printf("Press enter to start...\n");

    for(int i = 0; i < w.ws_col; i++){
        printf("-");
    }
    printf("\n");
    while(fgetc(stdin) != '\n');
}

void farmerFunction(int *pid){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    signal(SIGUSR1, SIG_DFL);
    signal(SIGUSR2, SIG_DFL);

    // print date and time
    time_t t;
    time(&t);
    printf("\e[1;1H\e[2J%s\n", ctime(&t));

    // print instructions
    for(int i = 0; i < w.ws_col; i++){
        printf("-");
    }
    printf("\n");
    printf("%*c", w.ws_col/2 - 3, ' ');
    printf("\e[1mFEED ME\e[0m\n");
    printf("%*c", w.ws_col/2 - 18, ' ');
    printf("\"fn\" - fertilize Plant \"n\"\n");
    printf("%*c", w.ws_col/2 - 18, ' ');
    printf("\"wn\" - water Plant \"n\"\n");
    printf("%*c", w.ws_col/2 - 18, ' ');
    printf("\"s\" - list ID's of all living Plants\n");
    printf("%*c", w.ws_col/2 - 18, ' ');
    printf("\"q\" - exit game\n");
    for(int i = 0; i < w.ws_col; i++){
        printf("-");
    }
    printf("\n\n\n\n");
    
    // take input
    char input;
    int identifier;
    while(1){
        for(int i = 0; i < w.ws_col; i++){
            printf("-");
        }
        printf("\n");
        printf("\33[2KInput: ");
        input = fgetc(stdin);

        if(toupper(input) == 'F'){
            identifier = fgetc(stdin) - '0';
            kill(pid[identifier - 1], SIGUSR1);
            printf("\r\033[5A\33[2KFed Plant\n\33[2K\n\33[2K\n");
            clearinputBuffer();
        }
        else if(toupper(input) == 'W'){
            identifier = fgetc(stdin) - '0';
            kill(pid[identifier - 1], SIGUSR2);
            printf("\r\033[5A\33[2KWatered Plant %d\n\33[2K\n\33[2K\n", identifier);
            clearinputBuffer();
        }
        else if(toupper(input) == 'S'){
            printf("\r\033[5A\33[2KPlant 1: %d\nPlant 2: %d\nPlant 3: %d\n", pid[0], pid[1], pid[2]);
            clearinputBuffer();
        }
        else if(toupper(input) == 'Q'){
		kill(pid[0], SIGKILL);
		kill(pid[1], SIGKILL);
		kill(pid[2], SIGKILL);
        exit(0);
        }
        else {
            printf("\r\033[5A\33[2KInvalid Input\n\33[2K\n\33[2K\n");
            clearinputBuffer();
        }
    }
}

void clearinputBuffer(void){
    char c = 0;
	while ((c = getchar()) != '\n' && c != EOF);
}

void plantFunction(FILE *plantOutput, int plantID){
    srand(getpid());
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    // initialize starting values
    int stem = 0, seconds = 0, plantDeath = 0;

    fprintf(plantOutput, "\e[?25l");

    while(1){
        if(seconds > 0 ){
            subtractFert();
            subtractWat();
        }
        // add stem if plant meets fertilizer and water requirements
        if(plantFert > 0 && plantWat > 0){
            if((seconds % 5) == 0){
                if(seconds > 0) stem++;
                fprintf(plantOutput, "\e[1;1H\e[2J");
                fprintf(plantOutput, "Days: %2d", seconds / 5);
                fprintf(plantOutput, "%*c", w.ws_col/2 - 11, ' ');
                fprintf(plantOutput, "\e[1mPlant %d\e[0m", plantID);
                fprintf(plantOutput, "%*c", w.ws_col/2 - 10, ' ');
                fprintf(plantOutput, "%d\n\n", getpid());

                // print newlines above plant
                for(int i = 10; i > stem; i--){
                    fprintf(plantOutput,"\n");
                }

                fprintf(plantOutput, "%*c", w.ws_col/2 - 1, ' ');
                fprintf(plantOutput, "%s", PLANTTOP);
                fprintf(plantOutput, "%*c", w.ws_col/2 - 2, ' ');
                fprintf(plantOutput, "%s", PLANTMID);

                // plant amount of stems
                for(int i = 0; i < stem; i++){
                    fprintf(plantOutput, "%*c", w.ws_col/2 - 1, ' ');
                    fprintf(plantOutput, "%s", PLANTSTEM);
                }

                fprintf(plantOutput, "%*c", w.ws_col/2 - 12, ' ');
                fprintf(plantOutput, "%s", PLANTBOT);
            }
            
            // print warnings for fertilizer and water
            printWarning(plantOutput);

            // if plant has reached full growth
            if(stem == 10){
                fprintf(plantOutput, "%*c", w.ws_col/2 - 8, ' ');
                fprintf(plantOutput, "\33[2KReady to Harvest.\n");
                break;
            }
            
        }
        // if plant has had no nutrients for 5 seconds
        else {
            plantDeath++;
            if (plantDeath == 5) {
                fprintf(plantOutput, "\r");
                fprintf(plantOutput, "%*c", w.ws_col/2 - 5, ' ');
                fprintf(plantOutput, "\33[2KPlant Dead.\n");
                break;
            }
        }
        unsigned timer = 1;

        while(timer) timer = sleep(timer);

        seconds++;
    }
    fprintf(plantOutput, "\e[?25h");
}

void subtractFert(void){
    plantFert -= (rand() % (3001 - 1000) + 1000);
    //printf("%d\n", plantFert);
    //return plantFert;
}

void subtractWat(void){
    plantWat -= (rand() % (301 - 100) + 100);
    //return plantWat;
}

void feedSignal(int signal){
    plantFert += 4000;
}

void waterSignal(int signal){
    plantWat += 400;
}

void printWarning(FILE *plantOutput){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

    // reset warning
    int fertWarning = 0, watWarning = 0;

    // check for low fertilizer and warning
    if(plantFert < 5000) fertWarning = 1;
    if(plantWat < 500) watWarning = 1;

    // print warnings
    if(fertWarning == 1 && watWarning == 1){
        fprintf(plantOutput, "%*c", w.ws_col/2 - 13, ' ');
        fprintf(plantOutput, "\33[2KNeeds Fertilizer and Water.\n\r\033[A");
    }
    else if(fertWarning == 1){
        fprintf(plantOutput, "%*c", w.ws_col/2 - 8, ' ');
        fprintf(plantOutput, "\33[2KNeeds Fertilizer.\n\r\033[A");
    }
    else if(watWarning == 1){
        fprintf(plantOutput, "%*c", w.ws_col/2 - 6, ' ');
        fprintf(plantOutput, "\33[2KNeeds Water.\n\r\033[A");
    }
    else {
        fprintf(plantOutput, "\33[2K");
    }
}
