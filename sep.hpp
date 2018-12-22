#ifndef _SEP_
#define _SEP_

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "quiz.hpp"
#include "console.hpp"


class Sep
{
public:
std::string heartMessage;
Sep(std::string msg);
void quizStart();
private:
Quiz sepQuiz;
Console console;
bool is_already_completed;
};

#endif
