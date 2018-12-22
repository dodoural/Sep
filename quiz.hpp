#ifndef _QUIZ_
#define _QUIZ_

#include <iostream>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <fstream>
#include "console.hpp"
#define QUESTION_COUNT 10
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_A_HOUR 60
#define HOURS_IN_A_DAY 24

struct quizStruct;

class Prize
{
 time_t rawtime;
 struct tm * today;
 struct tm * flightDate;
 tm* getCurrentTime();
 public:
 Prize();
 ~Prize();
 void calculateTimeDiff();
};

class Quiz
{
    public:
    Quiz();
    void prepareQuiz();
    void printQuiz();
    bool evaluateQuiz();
    void revealPrize();
    void endQuiz();
    private:
    Console console;
    Prize quizPrize;
    std::vector<quizStruct*> questions;
};


struct quizStruct
{
    bool printQuestion();
    int testResultGetter()const;
    void testResultSetter(int set = 0);
    quizStruct(std::string Q, std::string A, std::string B, std::string C, std::string D, char answer);
    private:
    std::string question;
    std::string optionA;
    std::string optionB;
    std::string optionC;
    std::string optionD;
    char correctAnswer;
    static int numberOfCorrectAnswers;
};



#endif
