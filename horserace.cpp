#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <regex>
#include <random>
#include "horserace.h"
#include "visuals.h"
#include "gameroom.h"

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
    bool continueInput = false;
    int userInput;
    int time = 3000;

    /*
    Prompt the user for input (play or return to game floor)
    If the user enters an invalid response, it will loop and keep prompting a new input until a valid one is given
    */
    do
    {
        // clear the console
        system("clear");

        std::string message = "\n\n\n                                  HORSE RACE\n\n -EACH HORSE IS REPRESENTED BY A NUMBER (1-8).\n -THE PLAYER SELECTS ONE HORSE, OUT OF EIGHT, AND PLACES A WAGER ON THAT HORSE.\n -IF THE PLAYERS HORSE COMES IN FIRST, THE PLAYER WINS FIVE TIMES THEIR WAGER.\n -IF THE PLAYERS HORSE DOES NOT COME IN FIRST, THEY LOSE THE WAGERED AMOUNT.";
        std::cout << message;

        std::cout << "\n\n                          1: PLAY HORSE RACE";
        std::cout << "\n                          2: RETURN TO THE GAME FLOOR\n";
        std::cout << "\n                          PLEASE SELECT AN OPTION: ";
        std::cin >> userInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }
        else if ((userInput == 1) || (userInput == 2))
        {
            continueInput = false;
        }
        else
        {
            std::cout << "\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }

    } while (continueInput);

    if ((userInput) == (1))
    {
        wager();
    }
    else if ((userInput) == (2))
    {
        GameRoom GameRoomObj;
        GameRoomObj.ReturnToGameOptions();
    }
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

// Returns a random horse to win the race between 1-8
int HorseRace::RandomHorseWinner()
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 8);
    int WinningHorse = dist6(rng);
    return WinningHorse;
}

// This is where we animate the horse race
void HorseRace::race()
{
    // clear console
    system("clear");

    // Time delays
    int titleTime = 1000;
    int raceTime = 400;

    int winningHorse = RandomHorseWinner();

    std::cout << winningHorse << std::endl;

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