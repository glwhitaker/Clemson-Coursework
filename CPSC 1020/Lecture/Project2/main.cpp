// Grayson Whitaker
// CPSC 1020
// 10/28/2022
// This file includes main program to administer quiz to user, keep score, and display quiz statistics at the end

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Quiz.h"
#include "printResult.h"

using namespace std;

int main(int argc, char* argv[]){
    // seed srand
    srand(unsigned(time(0)));

    // intialize vector of Quiz objects
    vector<Quiz> quizVector;

    // initialize input file
    ifstream inputQuiz;

    // open input file designated by argv[1]
    inputQuiz.open(argv[1]);

    // initialize string variables to take input from file
    string q, a;

    // if input file is open, read lines of questions/answers until there aren't any left
    if(inputQuiz.is_open()){
        while(getline(inputQuiz, q) && getline(inputQuiz, a)){
            // instantiate objects in quizVector with constructer using strings as arguments
            quizVector.emplace_back(q,a);
        }
    }

    // close file, no longer needed
    inputQuiz.close();

    // random shuffle quizVector
    random_shuffle(quizVector.begin(), quizVector.end());

    // initialize variables needed to take user input and track questions
    string userInput;
    int correct = 0, wrong = 0;

    cout << endl;

    // for loop from 0 to size of vector
    for(size_t i = 0; i < quizVector.size(); i++){
        // output question and prompt for user input
        cout << quizVector[i].getQuestion() << endl;
        cout << "Type in your answer: ";
        getline(cin, userInput);
        // compare userInput to answer starting at index 3 (skipping past "A: ")
        if(quizVector[i].getAnswer().compare(3, string::npos, userInput) == 0){
            // add 1 to correct answers, update score, display current score
            correct++;
            quizVector[i].updateScore(1);
            cout << "Correct!" << endl;
            cout << "Current score: " << quizVector[i].getScore() << endl << endl;
        }
        else{
            // add 1 to wrong answers, update score, display correct answer and current score
            wrong++;
            quizVector[i].updateScore(-1);
            cout << "Wrong! Correct Answer: " << quizVector[i].getAnswer().substr(3) << endl;
            cout << "Current score: " << quizVector[i].getScore() << endl << endl;
        }
    }
    
    // print results from quiz
    cout << printResult(quizVector.size(), correct, wrong, quizVector[0]) << endl;

    return 0;
}