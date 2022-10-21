// Grayson Whitaker
// CPSC 1020
// 10/28/2022
// This file includes implementation for printResult function to build string containing quiz statistics for user

#include <string>
#include <sstream>
#include "Quiz.h"
#include "printResult.h"

std::string printResult(int questions, int correct, int wrong, Quiz q){
    // use stringstream to create string
    std::stringstream result;
    result << "Number of questions: " << questions << std::endl;
    result << "Number of correct answers: " << correct << std::endl;
    result << "Number of wrong answers: " << wrong << std::endl;
    result << "Final score: " << q.score << std::endl;
    return result.str();
}