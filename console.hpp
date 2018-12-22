#ifndef _CONSOLE_
#define _CONSOLE_

#include <iostream>
#include <cmath>
#include <cstdio>



class Console
{
public:
std::string heartMessage;
Console();
Console(std::string msg);
void clearScreen();
void drawHeart();
void consoleStart();
};

#endif
