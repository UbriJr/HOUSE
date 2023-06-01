#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include "gameroom.h"
#include "introduction.h"
#include "casinowar.h"
#include "horserace.h"
#include "keno.h"

// constructor
Gameroom::Gameroom(){

};

// kicks off gameroom
void Gameroom::run_gameroom()
{
    welcome();
}

// brings user back to menu with all game options
void Gameroom::return_to_games_menu()
{
    game_options();
}

// generates a slow displaying welcome message
void Gameroom::welcome()
{
    system("clear");
    int text_display_delay = 35; // was 125
    int next_func_delay = 5000;  // was 3000
    std::string welcome_message = "\n\n\n\n\n\n\n                           WELCOME TO THE GAME FLOOR \n                      THIS IS WHERE ALL THE GAMES ARE HELD \n             HAVE FUN AND RELAX, BUT REMEMBER, THE HOUSE ALWAYS WINS.\n";
    unsigned long length = welcome_message.length();

    for (int i = 0; i < length; i++)
    {
        std::cout << welcome_message[i];
        std::this_thread::sleep_for(std::chrono::milliseconds(text_display_delay));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(next_func_delay));
    game_options();
}

// displays the current games implemented and prompts user to select one
void Gameroom::game_options()
{
    system("clear");
    bool is_valid_input;
    int users_input;

    Introduction token_access_obj;
    int tokens = token_access_obj.get_tokens();

    do
    {
        std::cout << "                                                                      TOKENS: " << tokens << std::endl;
        std::cout << "\n\n\n\n\n\n\n                                 GAME FLOOR\n\n";
        std::cout << "                               1: CASINO WAR \n";
        std::cout << "                               2: HORSE RACE \n";
        std::cout << "                               3: KENO \n";
        std::cout << "\n                              SELECT AN OPTION: ";
        std::cin >> users_input;
        is_valid_input = validate_input(users_input);
        system("clear");
    } while (!is_valid_input);

    direct_game_flow(users_input);
}

// validates the users input
bool Gameroom::validate_input(int users_input)
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
    if (users_input == (1) || users_input == (2) || users_input == (3))
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

// directs user to the game of their choice
void Gameroom::direct_game_flow(int users_input)
{
    int game_one = 1;
    int game_two = 2;
    int game_three = 3;

    if (users_input == (game_one))
    {
        CasinoWar casino_war;
        casino_war.run_casino_war();
    }
    else if (users_input == (game_two))
    {
        HorseRace horse_race;
        horse_race.run_horse_race();
    }
    else if (users_input == game_three)
    {
        Keno keno;
        keno.run_keno(); 
    }
}
