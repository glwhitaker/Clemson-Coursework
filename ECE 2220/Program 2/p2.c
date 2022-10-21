#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "countryList.h"

void countrySelect(char letter);
//Company Info
char companyName[32] = "Unknown", companyCountry[32] = "Unknown", companyPhone[15] = "Unknown", companyEmail[32] = "Unknown";
//Shot Info
float shotCost = 0.00, shotDosage = 0.0;
int shotDoses = 0;
//Shot Application
int FDA = 2;
long shotSold = 0;
double shotSales = 0.00;
int shotInjuries = 0, shotDeaths = 0;

int main(){
    while(1){
        printf("\033[2J\033");
        //create menu
        printf("\n\n\t\t\e[1mCOVID-19 Shots\e[0m\n\n\n");
        printf("1. Enter Company Information \n");
        printf("2. Enter Shot Information \n");
        printf("3. Enter Shot Application \n");
        printf("4. Display All Data \n");
        printf("5. Clear All Data \n");
        printf("6. Quit \n");
        
        //ensure valid choice
        int userchoice;
        while(1){
            printf("\nEnter Your Choice (1-6): ");

            if(scanf("%d", &userchoice) == 1 &&
                userchoice >= 1 && userchoice <= 5) break;
            else if(userchoice == 6) exit(0);

            printf("\033[1;31mPlease Enter a Valid Choice.\033[0m\n");
            fflush(stdin);
        }
        printf("\n");

        //display choice for user to enter information
        switch(userchoice){
            case 1:
                printf("\033[2J\033");
                printf("Company Name: ");
                scanf(" %[^\n]", companyName);
                char countryLetter = 'A';
                printf("First Letter of Company Country: ");
                scanf(" %c", &countryLetter);
                countrySelect(countryLetter);
                int phonechange = 0;
                while(1){
                    printf("Company Phone Number: ");
                    phonechange = 1;

                    scanf("%s", companyPhone);
                    if(strlen(companyPhone) >= 10 && strlen(companyPhone) <= 12) break;

                    printf("\033[1;31mPlease Enter a Valid Phone Number.\033[0m\n");
                }
                while(1){
                    printf("Company E-mail Address: ");

                    scanf(" %s", companyEmail);
                    if(strchr(companyEmail, '@') != NULL && strchr(companyEmail, '.') != NULL) break;

                    printf("\033[1;31mPlease Enter a Valid E-mail Address.\033[0m\n");
                }
                break;
            
            case 2:
                printf("\033[2J\033");
                printf("Shot Cost in US Dollars: ");
                scanf(" %f", &shotCost);
                while(1){
                    printf("Recommended Shot Doses (1-255): ");

                    if(scanf("%d", &shotDoses) == 1 &&
                        shotDoses >=1 && shotDoses <=255) break;
                    
                    printf("\033[1;31mPlease Enter a Valid Number.\033[0m\n");
                }
                while(1){
                    printf("Recommended Shot Dosage (0.1-100.0 mL): ");

                    if(scanf("%f", &shotDosage) == 1 &&
                        shotDosage >= 0.1 && shotDosage <= 100) break;
                    
                    printf("\033[1;31mPlease Enter a Valid Number.\033[0m\n");
                }
                break;
            
            case 3: ;
                printf("\033[2J\033");
                while(1){
                    char FDAchoice;
                    printf("FDA Approval (Y/N): ");

                    if(scanf(" %c", &FDAchoice) == 1){
                        if(FDAchoice == 'Y' || FDAchoice == 'y'){
                            FDA = 1;
                            break;
                        }
                        else if(FDAchoice == 'N' || FDAchoice == 'n'){
                            FDA = 0;
                            break;
                        }
                    }
                    printf("\033[1;31mPlease Enter a Valid Choice.\033[0m\n");                    
                }
                printf("Shot Doses Sold: ");
                scanf(" %ld", &shotSold);
                printf("Total Shot Sales in US Dollars: ");
                scanf(" %lf", &shotSales);
                printf("Total Shot Injuries: ");
                scanf(" %d", &shotInjuries);
                float percentInjuries = (float)shotInjuries/shotSold * 100;
                printf("Total Shot Deaths: ");
                scanf(" %d", &shotDeaths);
                float percentDeaths = (float)shotDeaths/shotSold * 100;
                break;

            case 4:
                printf("\033[2J\033");
            //print all values
                printf("\n\n");
                printf("\e[1mCompany Name:\e[0m\t\t\t%s\n", companyName);
                printf("\e[1mCompany Country:\e[0m\t\t%s\n", companyCountry);
                printf("\e[1mCompany Phone:\e[0m\t\t\t");
                if(phonechange == 1){
                    if(strlen(companyPhone) == 12){
                        for(int p = 0; p < 12; p++){
                            if(p == 2 || p == 5 || p == 8){
                                printf("-");
                            }
                        printf("%c", companyPhone[p]);
                        }
                    }
                    else if(strlen(companyPhone) == 11){
                        for(int p = 0; p < 11; p++){
                            if(p == 1 || p == 4 || p == 7){
                                printf("-");
                            }
                        printf("%c", companyPhone[p]);
                        }      
                    }
                    else{
                        for(int p = 0; p < 10; p++){
                            if(p == 3 || p == 6){
                                printf("-");
                            }
                        printf("%c", companyPhone[p]);
                        }
                    }
                }
                else{
                    printf("%s", companyPhone);
                }
                printf("\n");
                printf("\e[1mCompany E-mail Address:\e[0m\t\t%s\n", companyEmail);
                printf("\e[1mShot Cost:\e[0m\t\t\t$%0.2f\n", shotCost);
                printf("\e[1mRecommended Shot Doses:\e[0m\t\t%d\n", shotDoses);
                printf("\e[1mRecommended Shot Dosage:\e[0m\t%0.1f mL\n", shotDosage);
                if(FDA == 1){
                    printf("\e[1mFDA Approval:\e[0m\t\t\tYes\n");
                }
                else if(FDA == 2){
                    printf("\e[1mFDA Approval:\e[0m\t\t\tN/A\n");
                }
                else {
                    printf("\e[1mFDA Approval:\e[0m\t\t\tNo\n");
                }
                printf("\e[1mShot Doses Sold:\e[0m\t\t%ld\n", shotSold);
                printf("\e[1mTotal Shot Sales:\e[0m\t\t$%0.2lf\n", shotSales);
                printf("\e[1mInjuries Per Dose:\e[0m\t\t%0.1f%%\n", percentInjuries);
                printf("\e[1mDeaths Per Dose:\e[0m\t\t%0.1f%%\n", percentDeaths);
                printf("\n");
                printf("1. Back\n2. Quit\n");
                int back;
                while(1){
                    back = 0;
                    printf("Enter Choice: ");
                    scanf("%d", &back);
                    if(back == 1) break;
                    else if(back == 2) exit(0);

                    printf("\033[1;31mPlease Enter a Valid Choice.\033[0m\n");
                }
                break;


            case 5:
            //reset all values to original
                strcpy(companyName, "Unknown");
                strcpy(companyCountry, "Unknown");
                strcpy(companyPhone, "Unknown");
                phonechange = 0;
                strcpy(companyEmail, "Unknown");
                shotCost = 0.00;
                shotDosage = 0.0;
                shotDoses = 0;
                FDA = 2;
                shotSold = 0;
                shotSales = 0.00;
                shotInjuries = 0;
                percentInjuries = 0;
                shotDeaths = 0;
                percentDeaths = 0;
                printf("\033[2J\033");
                printf("\n\e[1mCleared.\e[0m\n");
                sleep(2);
                printf("\033[2J\033");
                break;
        }

    }
    return 0;
}

//country selector using countryList header file
void countrySelect(char letter) {
    //display countries
    printf("\n");
    for(int i = 0; i <= 247; i++){
        if(countryList[i][4] == toupper(letter)){
            printf("%s\n", countryList[i]);
        }
    }
    printf("\n");
    
    //choose country from two letter code
    char countryCode[2];
    printf("Enter Two Letter Country Code: ");
    scanf(" %s", countryCode);
    for(int j = 0; j <= 247; j++){
        if(countryList[j][0] == toupper(countryCode[0]) && countryList[j][1] == toupper(countryCode[1])){
            int length = strlen(countryList[j]);
            for(int k = 4; k <= length; k++){
                companyCountry[k-4] = countryList[j][k];
            }
        }
    }
}