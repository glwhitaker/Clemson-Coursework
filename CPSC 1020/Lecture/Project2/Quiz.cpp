// Grayson Whitaker
// CPSC 1020
// 10/28/2022
// This file includes implementation for Quiz class

#include <string>
#include "Quiz.h"

int Quiz::score = 0;

std::string Quiz::getQuestion(){
    return question;
}

std::string Quiz::getAnswer(){
    return answer;
}

int Quiz::getScore(){
    return score;
}

void Quiz::updateScore(int val){
    // prevent score from being less than 0
    if((score + val) >= 0){
        score += val;
    }
}