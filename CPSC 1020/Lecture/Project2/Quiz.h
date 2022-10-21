// Grayson Whitaker
// CPSC 1020
// 10/28/2022
// This file includes definition for Quiz class

#ifndef QUIZ_H
#define QUIZ_H

class Quiz{
    private:
        std::string question {""};
        std::string answer {""};
        static int score;
    public:
        Quiz() = default;
        Quiz(std::string q, std::string a) : question {q}, answer {a} {}
        std::string getQuestion();
        std::string getAnswer();
        static int getScore();
        static void updateScore(int val);
        // make printResult a friend function
        friend std::string printResult(int questions, int correct, int wrong, Quiz q);
};

#endif