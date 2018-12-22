#include <iostream>
#include <cstdio>
#include "sep.hpp"

using namespace std;

int quizStruct::numberOfCorrectAnswers = 0;

int main()
{
    Sep *sepObj = new Sep(" Hey Sep ");
    sepObj->quizStart();

    return 0;
}


