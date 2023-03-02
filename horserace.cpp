#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <regex>
#include <random>
#include "horserace.h"
#include "introduction.h"
#include "visuals.h"
#include "gameroom.h"

HorseRace::HorseRace(){

};

// kicks off the horse race game
void HorseRace::RunHorseRace()
{
    HorseRaceSelection();
};
// need to know how much the user wagered across functions
int usersWager;
int usersHorse;
Introduction tk;

// Prompts user to either read the instruction or start playing horse race.
void HorseRace::HorseRaceSelection()
{
    // available options
    int instruction = 1;
    int play = 2;

    // pause / delay time
    int time = 3000;

    // users input is stored and checked if valid in these variables
    int userInput;
    bool validInput;

    // prompts user for a response, will loop until a valid response is given
    do
    {
        // clear the console
        system("clear");

        std::cout << "\n\n\n\n\n\n\n                                 HORSE RACE\n"
                  << std::endl;
        std::cout << "                          1: HOW TO PLAY HORSE RACE" << std::endl;
        std::cout << "                          2: PLAY HORSE RACE" << std::endl;
        std::cout << "\n                          PLEASE SELECT AN OPTION: ";
        std::cin >> userInput;

        // if user inputs anything other then int type, cin will fail
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            validInput = false;
        }
        else if ((userInput == 1) || (userInput == 2))
        {
            validInput = true;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            validInput = false;
        }

    } while (!validInput);

    // once valid response is given, breaks out of do while loop and directs player to instructions or to play
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
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }
        else if ((userInput == 1) || (userInput == 2))
        {
            continueInput = false;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }

    } while (continueInput);

    if ((userInput) == (1))
    {
        wager();
    }
    // returns user to game room (other games)
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

    std::string key;
    int time = 3000;
    bool allValidResponses;

    // this object is used to check the # of tokens the user has in their account
    Introduction tokenCheckerObj;

    // prompts user to enter a horse to bet on and the wager amount
    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n                                  HORSE RACE";
        std::cout << "\n\n                             SELECT A HORSE (1-8): ";
        std::cin >> usersHorse;

        // checks if input is INT type and if user selected a valid horse
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            allValidResponses = false;
            continue;
        }
        else if (usersHorse > 8 || usersHorse < 1)
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            allValidResponses = false;
            continue;
        }

        std::cout << "\n                                 WAGER AMOUNT: ";
        std::cin >> usersWager;

        // check if wager was INT type and if the user wagered a valid amount
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            allValidResponses = false;
            continue;
        }
        else if (usersWager > tokenCheckerObj.getTokens())
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            allValidResponses = false;
            continue;
        }

        std::cout << "\n                         YOU WAGERED " << usersWager << " TOKENS ON HORSE #" << usersHorse << "\n";
        std::cout << "\n\n\n                           ENTER ANY KEY TO CONTINUE: ";
        std::cin >> key;

        // if all conditions are met user entered valid information and breaks out of loop
        allValidResponses = true;

    } while (!allValidResponses);

    // call race once user selects a horse to bet on and the amount once inputs are validated.
    race();
}

// Returns a random horse if there is a tie
int HorseRace::RandomHorseWinner(int totalHorses)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, totalHorses);
    int WinningHorse = dist6(rng);
    return WinningHorse;
}

// returns how many spaces the horse should run between 0-2
int HorseRace::HorseRunSpaces()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 2);
    int spacesRun = dist6(rng);
    return spacesRun;
}

// builds the path length the horse will run
std::string HorseRace::buildRunner()
{

    int runLength = 11;
    std::string currentHorse = "";
    std::string line = "|";

    for (int i = 0; i <= runLength; i++)
    {
        int spaces = HorseRunSpaces();

        for (int j = 0; j < spaces; j++)
        {
            currentHorse = currentHorse + line;
        }
    }

    return currentHorse;
}

// checks if the user lost or won his bet and modifies their account
void HorseRace::winChecker(int winningHorse)
{
    Visuals visObject;

    // user picked the winning horse. they win
    if (usersHorse == winningHorse)
    {
        std::cout << "\n\n                      YOUR HORSE WON. YOU WON " << (usersWager * 5) << " TOKENS" << std::endl;
        tk.setTokens(tk.getTokens() + (usersWager * 5));
    }
    // otherwise they picked the wrong horse and lost.
    else
    {
        std::cout << "\n\n                      YOUR HORSE LOST. YOU LOST " << (usersWager) << " TOKENS" << std::endl;
        tk.setTokens(tk.getTokens() - (usersWager));
    }
}

void HorseRace::replay()
{
    int userInput;
    int time = 3000;
    bool continueInput = false;

    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n                          WOULD YOU LIKE TO PLAY AGAIN?" << std::endl
                  << "\n";
        std::cout << "                               1: PLAY AGAIN" << std::endl;
        std::cout << "                               2: RETURN TO GAMEROOM" << std::endl;
        std::cout << "\n                             PLEASE SELECT AN OPTION: ";
        std::cin >> userInput;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }
        else if ((userInput == 1) || (userInput == 2))
        {
            continueInput = false;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continueInput = true;
        }

    } while (continueInput);

    if (userInput == (1))
    {
        wager();
    }
    else if (userInput == (2))
    {
        GameRoom GRobj;
        GRobj.ReturnToGameOptions();
    }
}

// This is where we animate the horse race
void HorseRace::race()
{
    int outcomeTimer = 5000;
    // clear console
    system("clear");

    // Time delays
    int titleTime = 1000;
    int raceTime = 400;

    // Horses & their paths
    int numberOfHorses = 8;
    int longestPath = 0;

    std::string h1 = buildRunner();
    std::string h2 = buildRunner();
    std::string h3 = buildRunner();
    std::string h4 = buildRunner();
    std::string h5 = buildRunner();
    std::string h6 = buildRunner();
    std::string h7 = buildRunner();
    std::string h8 = buildRunner();

    std::string horses[8] = {h1, h2, h3, h4, h5, h6, h7, h8};

    std::string winner;

    // horses that are tied
    std::vector<std::string> tiedHorses;
    std::vector<int> tiedHorsePositions;
    int posFromVec;

    // find longest path
    for (int i = 0; i < numberOfHorses; i++)
    {
        int winningHorse = ((horses[i]).length());

        if (longestPath < winningHorse)
        {
            longestPath = winningHorse;
        }
    }

    // check how many horses are tied
    for (int x = 0; x < numberOfHorses; x++)
    {
        if (horses[x].length() == longestPath)
        {
            tiedHorses.push_back(horses[x]);
            tiedHorsePositions.push_back(x);
        }
    }

    // if there is a tie, pick a random horse from the pile and add 1 extra line to make it the winner.
    if (tiedHorses.size() > 1)
    {
        int randomWinner = RandomHorseWinner(tiedHorses.size());
        winner = tiedHorses[randomWinner - 1]; // maybe causes seg fault if the - 1 is not there
        posFromVec = tiedHorsePositions[randomWinner - 1];
        winner = winner + "|";
    }
    else
    {
        winner = tiedHorses[0];
        posFromVec = tiedHorsePositions[0];
    }

    horses[posFromVec] = winner;
    longestPath = winner.length();

    // make all horse strings the same length
    for (int j = 0; j < numberOfHorses; j++)
    {
        std::string tmpHorse = horses[j];

        for (int k = 0; tmpHorse.length() < longestPath; k++)
        {
            tmpHorse = tmpHorse + " ";
        }
        horses[j] = tmpHorse;
    }

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

    std::cout << "" << std::endl;
    std::string horseNumber = "            1       2       3       4       5       6       7       8";
    std::string line;
    std::string firstLaneBuffer = "            ";
    std::string laneSpacer = "       ";

    std::cout << horseNumber << std::endl;

    // display the horses and their paths in the terminal
    for (int i = 0; i < longestPath; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(raceTime));

        line = firstLaneBuffer + horses[0].at(i) + laneSpacer + horses[1].at(i) + laneSpacer + horses[2].at(i) + laneSpacer + horses[3].at(i) + laneSpacer + horses[4].at(i) + laneSpacer + horses[5].at(i) + laneSpacer + horses[6].at(i) + laneSpacer + horses[7].at(i);
        std::cout << line << std::endl;
    }

    // std::cout << tiedHorses.size();
    posFromVec = posFromVec + 1;

    winChecker(posFromVec);

    std::this_thread::sleep_for(std::chrono::milliseconds(outcomeTimer));

    replay();
}