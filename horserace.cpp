#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "horserace.h"
#include "visuals.h"

HorseRace::HorseRace(){

};

void HorseRace::RunHorseRace()
{
    HorseRaceSelection();
};

// Prompts user to either read the instruction or start playing horse race.
void HorseRace::HorseRaceSelection()
{
    int instruction = 1;
    int play = 2;
    int userInput;

    system("clear");
    std::cout << "\n\n\n\n\n\n\n                                 HORSE RACE\n"
              << std::endl;
    std::cout << "                          1: HOW TO PLAY HORSE RACE" << std::endl;
    std::cout << "                          2: PLAY HORSE RACE" << std::endl;
    std::cout << "\n                          PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    if (userInput == (instruction))
    {
        instructions();
    }
    else if (userInput == (play))
    {
        wager();
    }
}

// Gives user instructions and information on how to play
void HorseRace::instructions()
{
    // clear the console
    system("clear");

    // store users input
    int userInput;

    std::string message = "\n\n\n                                  HORSE RACE\n\n -EACH HORSE IS REPRESENTED BY A NUMBER (1-8).\n -THE PLAYER SELECTS ONE HORSE, OUT OF EIGHT, AND PLACES A WAGER ON THAT HORSE.\n -IF THE PLAYERS HORSE COMES IN FIRST, THE PLAYER WINS FIVE TIMES THEIR WAGER.\n -IF THE PLAYERS HORSE DOES NOT COME IN FIRST, THEY LOSE THE WAGERED AMOUNT.";

    std::cout << message;

    std::cout << "\n\n                          1: PLAY HORSE RACE";
    std::cout << "\n                          2: RETURN TO THE GAME FLOOR\n";
    std::cout << "\n                          PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    // Make sure to validate users input !!!
    // InputValidation(userInput);
}

// Prompts user to enter wager / bet amount.
void HorseRace::wager()
{
    // clear console
    system("clear");

    int wager;
    int horse;
    std::string key;

    std::cout << "\n\n\n\n\n\n                                  HORSE RACE";
    std::cout << "\n\n                             SELECT A HORSE (1-8): ";
    std::cin >> horse;
    std::cout << "\n                                 WAGER AMOUNT: ";

    std::cin >> wager;

    // make sure to validate the wager and make sure its an int
    // WagerChecker();

    std::cout << "\n                         YOU WAGERED " << wager << " TOKENS ON HORSE #" << horse << "\n";

    std::cout << "\n\n\n                           ENTER ANY KEY TO CONTINUE: ";
    std::cin >> key;

    // ShowDealtCards();

    // Call race once user selects a horse to bet on and the amount.
    race();
}

// This is where we animate the horse race
void HorseRace::race()
{
    // clear console
    system("clear");

    // Time delays
    int titleTime = 1000;
    int raceTime = 400;

    std::string ready = "                               READY";
    std::string set = "                                     SET";
    std::string go = "                                          GO!";

    std::cout << "\n\n\n\n\n\n\n\n\n"
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(titleTime));
    std::cout << ready << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(titleTime));
    std::cout << set << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(titleTime));
    std::cout << go << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(titleTime));

    // clear console so only the horse race is displayed
    system("clear");

    std::cout << ""
              << std::endl;
    std::string horseNumber = "            1       2       3       4       5       6       7       8";
    std::string line = "            |       |       |       |       |       |       |       |";

    std::cout << horseNumber << std::endl;

    for (int i = 0; i < 15; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(raceTime));
        std::cout << line << std::endl;
    }

    Visuals visObject;
    visObject.standardHorse();
}