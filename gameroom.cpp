#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "gameroom.h"
#include "introduction.h"
#include "casinowar.h"
#include "horserace.h"

GameRoom::GameRoom(){

};

void GameRoom::RunGameRoom()
{
    Welcome();
}

void GameRoom::ReturnToGameOptions()
{
    GameOptions();
}

void GameRoom::Welcome()
{
    system("clear");
    int TextTime = 35;        // was 125
    int ClearWaitTime = 5000; // was 3000
    std::string welcomeText = "\n\n\n\n\n\n\n                           WELCOME TO THE GAME FLOOR \n                      THIS IS WHERE ALL THE GAMES ARE HELD \n             HAVE FUN AND RELAX, BUT REMEMBER, THE HOUSE ALWAYS WINS.\n";
    unsigned long length = welcomeText.length();

    for (int i = 0; i < length; i++)
    {
        std::cout << welcomeText[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(TextTime));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(ClearWaitTime));
    GameOptions();
}

void GameRoom::GameOptions()
{
    system("clear");
    bool isValid;
    int userInput;

    Introduction IntroObj;
    int tokens = IntroObj.getTokens();

    do
    {
        std::cout << "                                                                      TOKENS: " << tokens << std::endl;
        std::cout << "\n\n\n\n\n\n\n                                 GAME FLOOR\n\n";
        std::cout << "                               1: CASINO WAR \n";
        std::cout << "                               2: HORSE RACE \n";
        std::cout << "                               3: GAME 3 \n";
        std::cout << "\n                              SELECT AN OPTION: ";
        std::cin >> userInput;
        isValid = InputValidation(userInput);
        system("clear");
    } while (!isValid);
    InputControlFlow(userInput);
}

bool GameRoom::InputValidation(int userInput)
{

    // clear console
    system("clear");

    int time = 3000;

    // Check if user even entered a digit
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }

    // Check if digit is one of the available options
    if (userInput == (1) || userInput == (2) || userInput == (3))
    {
        return true;
    }
    else
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }
}

void GameRoom::InputControlFlow(int userInput)
{
    int GameOneOption = 1;
    int GameTwoOption = 2;
    int GameThreeOption = 3;

    if (userInput == (GameOneOption))
    {
        CasinoWar CasinoWarObject;
        CasinoWarObject.runCasinoWar();
    }
    else if (userInput == (GameTwoOption))
    {
        HorseRace HorseRaceObject;
        HorseRaceObject.RunHorseRace();
    }
    else if (userInput == GameThreeOption)
    {
        std::cout << "GameThree\n";
        // GameThree();
    }
}
