#include "sep.hpp"
#include <fstream>



Sep::Sep(std::string msg =" Hey Sep "):heartMessage(msg), console(heartMessage)
{
    is_already_completed = false;
    std::string line;
    std::ifstream myfile ("sep.txt");

    if (myfile.is_open()) {

        while (getline (myfile, line)) {
            if(line.compare("SUCCESS") == 0)
                is_already_completed = true;
        }
        myfile.close();
    }
}


void Sep::quizStart()
{
    char input;

    if (is_already_completed)
    {
        std::cout<<"You have already completed the test , press y to proceed to the Sep timer or n to proceed with the quiz"<<std::endl;
        std::cin>>input;
        if(input == 'n' || input == 'N')
        {
            // Do Nothing
        }
        else if(input == 'y' || input == 'Y')
        {
            sepQuiz.revealPrize();
            return;
        }
        else
        {
            std::cout<<"Invalid input continuing with the test...\n\n"<<std::endl;
        }

    }

    console.consoleStart();
    sepQuiz.prepareQuiz();
    sepQuiz.printQuiz();
    while(sepQuiz.evaluateQuiz() == false)
    {
        std::cout<<"Press 'r' to retry or 'q' to quit the program\n\n";
        while(std::cin>>input)
        {

            if(input == 'r' || input == 'R')
            {
                sepQuiz.printQuiz();
                break;
            }
            else if(input == 'q' || input == 'Q')
            {
                std::exit(EXIT_SUCCESS);
            }
            else
            {
                std::cout<<"It says press 'r' or 'q' Sep, can't you read (-_-) ? "<<std::endl;
            }

        }

    }
    sepQuiz.endQuiz();

}
