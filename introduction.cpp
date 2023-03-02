#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "introduction.h"
#include "gameroom.h"

Introduction::Introduction(){

};

// run the introduction
void Introduction::RunIntroduction()
{
    Welcome();
    RegisterOrLogin();
}

// returns the number of tokens the player has
int Introduction::getTokens()
{
    std::ifstream readFile("data.txt");
    std::string CurrentLine;
    std::string t;
    int Tokens;

    while (getline(readFile, CurrentLine))
    {
        bool has_only_digits = (CurrentLine.find_first_not_of("0123456789") == std::string::npos);
        if (has_only_digits)
        {
            t = CurrentLine;
            break;
        }
    }

    std::stringstream ss;
    ss << t;
    ss >> Tokens;
    return Tokens;
}

// Be able top adjust and set new token amount in the file
void Introduction::setTokens(int tokens)
{
    std::ifstream dataFile;
    dataFile.open("data.txt");

    std::fstream tmp("test.txt", std::ios::out);

    std::string CurrentLine;
    std::string line;

    while (getline(dataFile, CurrentLine))
    {
        tmp << CurrentLine << std::endl;
    }

    tmp.close();
    dataFile.close();

    std::ifstream t("test.txt");
    std::fstream data;
    data.open("data.txt", std::ios::out);

    while (getline(t, line))
    {
        bool has_only_digits = (line.find_first_not_of("0123456789") == std::string::npos);

        if (!has_only_digits)
        {
            data << line << std::endl;
        }
        else if (has_only_digits)
        {
            data << std::to_string(tokens) << std::endl;
        }
    }

    t.close();
    remove("test.txt");
    data.close();
}

// prints a welcome banner and adds space to clear terminal window
void Introduction::Welcome()
{

    int time = 400;
    int VisualDelay = 500;
    // clear console
    system("clear");

    // welcome banner
    std::cout << "\n";
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(VisualDelay));
    std::cout << "   ***       ***     *******     ***         ***   **********    ************" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ***       ***  ***       ***  ***         *** ***        ***  ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ***       *** ***         *** ***         *** *****           ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ************* ***         *** ***         ***      ****       **********" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ***       *** ***         *** ***         ***           ***** ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ***       ***  ***       ***  ****       **** ***        ***  ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "   ***       ***     *******       ***********     **********    ************" << std::endl;
}

// Validates user's input
bool Introduction::InputValidation(int userInput)
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
    if (userInput == (1) || userInput == (2))
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

// called if the user wants to login
void Introduction::login()
{
    // spacer
    system("clear");

    std::string username;
    std::string password;
    std::string CurrentLine;
    std::string NextLine;

    std::string pleaseWait = "                PLEASE WAIT WHILE WE BRING YOU TO THE GAME FLOOR\n";

    int WaitTime = 5000;

    bool InfoFound = false;

    // spacingBuffer(neededSpace);
    std::cout << "\n\n\n\n                                 LOGIN MENU \n\n\n\n\n\n\n";
    std::cout << "                           ENTER YOUR USERNAME: ";
    std::cin >> username;
    std::cout << "                           ENTER YOUR PASSWORD: ";
    std::cin >> password;

    std::ifstream readFile("data.txt");

    while (getline(readFile, CurrentLine))
    {

        getline(readFile, NextLine);

        if ((username == CurrentLine) && (password == NextLine))
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n                               LOGIN SUCCESSFUL\n";
            std::cout << "                              YOU HAVE " << getTokens() << " TOKENS\n";
            std::cout << pleaseWait;
            std::this_thread::sleep_for(std::chrono::milliseconds(WaitTime));

            InfoFound = true;
        }
        std::cout << "\n";
    }
    readFile.close();

    if (!InfoFound)
    {
        int neededSpace = 5;
        system("clear");
        spacingBuffer(neededSpace);
        std::cout << "         COULD NOT FIND AN ACCOUNT WITH THE GIVEN USERNAME AND PASSWORD" << std::endl;
        std::cout << "                    PLEASE REGISTER OR TRY TO LOGIN AGAIN"
                  << std::endl;
        RegisterOrLogin();
    }

    GameRoom gameFloor;
    gameFloor.RunGameRoom();
}

// called if the user does not have a login and wants to register
void Introduction::reg()
{
    int time = 4000;
    system("clear");
    std::string username;
    std::string password;
    int InitTokens = 10;

    std::fstream dataFile;
    dataFile.open("data.txt", std::ios::out);

    std::cout << "\n\n\n\n                              REGISTRATION MENU \n\n\n\n\n\n\n";
    std::cout << "                             CREATE A USERNAME: ";
    std::cin >> username;
    std::cout << "                             CREATE A PASSWORD: ";
    std::cin >> password;
    system("clear");
    std::cout << "\n\n\n\n\n\n\n\n\n\n                     REGISTRATION COMPLETE, LOGIN TO CONTINUE. \n";
    std::cout << "\n";

    dataFile << username << std::endl;
    dataFile << password << std::endl;
    dataFile << InitTokens << std::endl;

    dataFile.close();
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    login();
    // RegisterOrLogin();
}

// direct input to either register or login method
void Introduction::InputControlFlow(int userInput)
{
    int LoginOption = 1;
    int RegisterOption = 2;

    if (userInput == (LoginOption))
    {
        login();
    }
    else if (userInput == (RegisterOption))
    {
        reg();
    }
}

// prompts user to register or login
void Introduction::RegisterOrLogin()
{
    bool isValid;
    int userInput;

    do
    {
        std::cout << "\n\n\n\n\n";
        std::cout << "                                 1: LOGIN \n";
        std::cout << "                                 2: REGISTER \n\n";
        std::cout << "                               SELECT AN OPTION: ";
        std::cin >> userInput;
        isValid = InputValidation(userInput);
        system("clear");
        std::cout << "\n\n\n\n";

    } while (!isValid);

    InputControlFlow(userInput);
}

// added white space to make program more visually appealing
void Introduction::spacingBuffer(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        std::cout << "\n";
    };
}
