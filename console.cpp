#include "console.hpp"

Console::Console():heartMessage(" Hey Sep ")
{

}

Console::Console(std::string msg):heartMessage(msg)
{

}

void Console::clearScreen()
{

    std::string str(100,'\n');
    std::cout<<str;
}

void Console::drawHeart()
{
    double x, y, size=10;
    std::string message = heartMessage;
    int print_line = 4;
    if (message.length() % 2 != 0) message += " ";

    for (x=0;x<size;x++)
    {
        for (y=0;y<=4*size;y++)
        {
            double dist1 = sqrt( pow(x-size,2) + pow(y-size,2) );
            double dist2 = sqrt( pow(x-size,2) + pow(y-3*size,2) );

            if (dist1 < size + 0.5 || dist2 < size + 0.5 ) {
                std::cout << "V";
            }
            else std::cout << " ";
        }
       std::cout<<"\n";
    }

    for (x=1;x<2*size;x++)
    {
        for(y=0;y<x;y++) std::cout << " ";

        for (y=0; y<4*size + 1 - 2*x; y++)
        {
            if (x >= print_line - 1 && x <= print_line + 1) {
                int idx = y - (4*size - 2*x - message.length()) / 2;
                if (idx < message.length() && idx >= 0) {
                    if (x == print_line) std::cout<<message[idx];
                    else std::cout << " ";
                }
                else std::cout << "V";
            }
            else std::cout << "V";
        }
        std::cout<<std::endl;
    }


}

void Console::consoleStart()
{
    char c;
    this->Console::drawHeart();
    std::cout<<"\n       Press 's' Key to Continue\n"<<std::endl;
    while(std::cin>>c)
    {

        if(c == 's')
        {
            this->Console::clearScreen();
            break;
        }
        else
        {
            std::cout<<"       It says press 's' Sep, can't you read (-_-) ? "<<std::endl;
        }


    }
}
