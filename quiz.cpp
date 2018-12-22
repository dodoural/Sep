#include "quiz.hpp"
#include <chrono>


Quiz::Quiz():console()
{

}

quizStruct::quizStruct(std::string Q, std::string A, std::string B, std::string C, std::string D, char answer):question(Q),optionA(A),optionB(B),optionC(C),optionD(D),correctAnswer(answer)
{

}

bool quizStruct::printQuestion()
{
    char choice;
    std::cout<<" Q)\t"<<question<<'\n'<<std::endl;
    std::cout<<" a)\t"<<optionA<<std::endl;
    std::cout<<" b)\t"<<optionB<<std::endl;
    std::cout<<" c)\t"<<optionC<<std::endl;
    std::cout<<" d)\t"<<optionD<<'\n'<<std::endl;
    std::cout<<" Make a choice and press enter ...\n"<<std::endl;
    while(std::cin>>choice)
    {
        if(choice == 'a' || choice == 'A' || choice == 'b' || choice == 'B' || choice == 'c' || choice == 'C' || choice == 'd' || choice == 'D')
        {
            if (choice == correctAnswer)
            {
                numberOfCorrectAnswers++;
                return true;
            }

            return false;
        }
        else
        {
            std::cout<<"\n Make a valid choice Sep, accepted inputs are : a|A b|B c|C d|D \n\n";
        }

    }
    return false;
}

void Quiz::prepareQuiz()
{
    questions.push_back(new quizStruct("What is Dogus's favourite color ?","Purple","Blue","Black","Red",'c'));
    questions.push_back(new quizStruct("What is Dogus's birthday (Day | Month | Year) ?","11.09.1989","09.11.1989","08.05.1989","09.09.1989",'a'));
    questions.push_back(new quizStruct("Which one is grammatically correct ?","Bende var o gömleğin aynısından","Geldimde bulamadım seni","Görüyorumki iyice salmışsın kendini","Güneşli günler de bu kremi kullanabilirsin.",'a'));
    questions.push_back(new quizStruct("What is the date Dogus wrote to Sep for the first time ?","15th of July","25th of August","27th of August","24th of August",'d'));
    questions.push_back(new quizStruct("You gotta reach real deep for me. Find me on the bone . Which song does this line belong to ?","Echoes","Map of Africa","Land Down Under","Allah Belanı Versin",'b'));
    questions.push_back(new quizStruct("A farmer has seventeen cows; all but eight die. How many cows does the farmer have left?","11","9","8","0",'c'));
    questions.push_back(new quizStruct("What is the square root of 121","12","11","13","14",'b'));
    questions.push_back(new quizStruct("Which is NOT a prime number?","7","13","27","29",'c'));
    questions.push_back(new quizStruct("Divide 30 by 1/2 and add 10. What is the answer?","10","25","50","70",'d'));
    questions.push_back(new quizStruct("If it takes 5 machines 5 minutes to make 5 widgets, how long would it take 100 machines to make 100 widgets?","5","100","50","1",'a'));

}

void Quiz::printQuiz()
{
 std::vector<quizStruct*>::iterator  itr;
 console.clearScreen();
 for(itr = questions.begin() ; itr != questions.end() ; itr ++ )
 {
     (*itr)->printQuestion();
     console.clearScreen();
 }


}

 int quizStruct::testResultGetter()const
 {

    return numberOfCorrectAnswers;

 };

 void quizStruct::testResultSetter(int set )
 {
     this->numberOfCorrectAnswers = set;
 }

 bool Quiz::evaluateQuiz()
 {
     int result = (questions.at(0))->testResultGetter();
     bool pass = false;
     switch(result)
     {
         case 0:
         std::cout<<"0 correct answer Sep, seriously ? ZEEEEROOO "<<std::endl;
         break;
         case 1:
         std::cout<<"1 correct answer (-.-)Zzz..."<<std::endl;
         break;
         case 2:
         std::cout<<"2 correct answers Sep [{-_-}] ZZZzz zz z... "<<std::endl;
         break;
         case 3:
         std::cout<<"3 correct answers Sep, ┌∩┐(◣_◢)┌∩┐"<<std::endl;
         break;
         case 4:
         std::cout<<"4 correct answers Sep, ♫♪.ılılıll|̲̅̅●̲̅̅|̲̅̅=̲̅̅|̲̅̅●̲̅̅|llılılı.♫♪ BOOOMBOX"<<std::endl;
         break;
         case 5:
         std::cout<<"5 correct answers Sep \,,/(^_^)\,,/ "<<std::endl;
         break;
         case 6:
         std::cout<<"6 correct answers Sep, come on ε(´סּ︵סּ`)з"<<std::endl;
         break;
         case 7:
         std::cout<<"7 correct answers Sep, almost there  ۜ\(סּںסּَ` )/ۜ "<<std::endl;
         break;
         case 8:
         std::cout<<"8 correct answers Sep, that's my girl --------{---(@ "<<std::endl;
         break;
         case 9:
         std::cout<<"9 correct answers Sep, daaaaaamn you are killing it giiiirl       ̿' ̿'\̵͇̿̿\з=(◕_◕)=ε/̵͇̿̿/'̿'̿ ̿"<<std::endl;
         pass = true;
         break;
         case 10:
         std::cout<<"10 correct answers Sep, you are perfection (♥_♥)"<<std::endl;
         pass = true;
         break;


     }
     (questions.at(0))->testResultSetter(0);
     std::cout<<"\nYou scored "<<result<<" out of 10 questions and"<<(pass == true ? " passed !!!\n":" failed :(\n")<<std::endl;

     return pass;

 }

void Quiz::revealPrize()
{
    while(1)
    {
        quizPrize.calculateTimeDiff();

        sleep(1);
    }

}

 void Quiz::endQuiz()
 {
    char input;
    std::ofstream myfile;
    myfile.open ("sep.txt");
    myfile << "SUCCESS";
    myfile.close();
    std::cout<<"Congratulations, you have beaten the test, type anything press enter to reveal the prize :)\n\n ";
    std::cin>>input;

    revealPrize();
 }

 Prize::Prize()
 {
     flightDate = new tm;
     flightDate->tm_hour = 16;
     flightDate->tm_mday = 25;
     flightDate->tm_min = 50;
     flightDate->tm_sec = 0;
     flightDate->tm_year = 2018;
     flightDate->tm_mon = 12;

 }
 Prize::~Prize()
 {
     delete flightDate;
 }

 tm* Prize::getCurrentTime()
 {
     time ( &rawtime );
     today= localtime ( &rawtime );
     return today;

 }
void Prize::calculateTimeDiff()
 {

   struct tm* current = getCurrentTime();
   struct tm* diffTime = new tm;

   if(flightDate->tm_sec >= current->tm_sec)
   {
       diffTime->tm_sec = flightDate->tm_sec - current->tm_sec;
   }
   else
   {
       current->tm_min++;
       diffTime->tm_sec = flightDate->tm_sec - current->tm_sec + SECONDS_IN_A_MINUTE;

   }

   if(flightDate->tm_min >= current->tm_min)
   {
       diffTime->tm_min = flightDate->tm_min - current->tm_min;
   }
   else
   {
       current->tm_hour++;
       diffTime->tm_min = flightDate->tm_min - current->tm_min + MINUTES_IN_A_HOUR;
   }

    if(flightDate->tm_hour >= current->tm_hour)
   {
       diffTime->tm_hour = flightDate->tm_hour - current->tm_hour;
   }
   else
   {
       current->tm_mday++;
       diffTime->tm_hour = flightDate->tm_hour - current->tm_hour + HOURS_IN_A_DAY;
   }
   diffTime->tm_mday = flightDate->tm_mday - current->tm_mday;


   std::cout << "Time left until 25th of December: "<< diffTime->tm_mday << (diffTime->tm_mday >= 2 ? " Days " : " Day ");
   std::cout << diffTime->tm_hour << ":";
   std::cout << (diffTime->tm_min < 10 ? "0" : "");
   std::cout << diffTime->tm_min << ":";
   std::cout << (diffTime->tm_sec < 10 ? "0" : "");
   std::cout << diffTime->tm_sec <<"\n"<<std::endl;
   std::cout<<"                 ༼ つ ◕_◕ ༽つ \n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;
   delete diffTime;
 }
