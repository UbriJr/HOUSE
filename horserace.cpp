#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
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
#include "revive.h"

// horserace.cpp centered in both x and y

// need to know how much the user wagered across functions
int users_wager;
int users_horse;
Introduction token_access;

// constructor
HorseRace::HorseRace(){

};

// kicks off the horse race game
void HorseRace::run_horse_race()
{
    horse_race_menu();
};

// Prompts user to either read the instruction or start playing horse race.
void HorseRace::horse_race_menu()
{
    // available options
    int instruction = 1;
    int play = 2;

    // pause / delay time
    int time = 3000;

    // users input is stored and checked if valid in these variables
    int users_input;
    bool is_valid_input;

    // prompts user for a response, will loop until a valid response is given
    do
    {
        // clear the console
        system("clear");

        std::cout << "\n\n\n\n\n\n\n\n\n"; 
        std::cout << "                                   HORSE RACE"<< std::endl;
        std::cout << "\n"; 
        std::cout << "                           1: HOW TO PLAY HORSE RACE" << std::endl;
        std::cout << "                               2: PLAY HORSE RACE" << std::endl;
        std::cout << "\n"; 
        std::cout << "                            PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;

        // if user inputs anything other then int type, cin will fail
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = false;
        }
        else if ((users_input == 1) || (users_input == 2))
        {
            is_valid_input = true;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = false;
        }

    } while (!is_valid_input);

    // once valid response is given, breaks out of do while loop and directs player to instructions or to play
    if (users_input == (instruction))
    {
        instructions();
    }
    else if (users_input == (play))
    {
        place_wager();
    }
}

// Gives user instructions and information on how to play
void HorseRace::instructions()
{
    bool is_valid_input = false;
    int users_input;
    int time = 3000;

    /*
    Prompt the user for input (play or return to game floor)
    If the user enters an invalid response, it will loop and keep prompting a new input until a valid one is given
    */
    do
    {
        // clear the console
        system("clear");

        std::cout << "\n\n" << "                                   HORSE RACE" << "\n\n\n\n" << "                  -EACH HORSE IS REPRESENTED BY A NUMBER (1-8)" << "\n\n" << "      -THE PLAYER SELECTS ONE HORSE FROM EIGHT OPTIONS AND PLACES A WAGER" << "\n\n" << "  -IF THE PLAYERS HORSE COMES IN FIRST, THE PLAYER WINS FIVE TIMES THEIR WAGER" << "\n\n" << "   -IF THE PLAYERS HORSE DOES NOT COME IN FIRST, THEY LOSE THE WAGERED AMOUNT"; //c

        std::cout << "\n\n\n\n" << "                               1: PLAY HORSE RACE" << std::endl;
        std::cout << "                          2: RETURN TO THE GAME FLOOR" << std::endl;
        std::cout << "\n" << "                            PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = true;
        }
        else if ((users_input == 1) || (users_input == 2))
        {
            is_valid_input = false;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = true;
        }

    } while (is_valid_input);

    if ((users_input) == (1))
    {
        place_wager();
    }
    // returns user to game room (other games)
    else if ((users_input) == (2))
    {
        Gameroom game_room;
        game_room.return_to_games_menu();
    }
}

// Prompts user to enter wager / bet amount.
void HorseRace::place_wager()
{
    // clear console
    system("clear");

    std::string key;
    int time = 3000;
    bool is_valid_response;

    // this object is used to check the # of tokens the user has in their account
    Introduction token_access_obj;

    // prompts user to enter a horse to bet on and the wager amount
    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n" << "                                   HORSE RACE";
        std::cout << "\n\n" << "                             SELECT A HORSE (1-8): ";
        std::cin >> users_horse;

        // checks if input is INT type and if user selected a valid horse
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_response = false;
            continue;
        }
        else if (users_horse > 8 || users_horse < 1)
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_response = false;
            continue;
        }

        std::cout << "\n" << "                                 WAGER AMOUNT: ";
        std::cin >> users_wager;

        // check if wager was INT type and if the user wagered a valid amount
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_response = false;
            continue;
        }
        else if (users_wager > token_access_obj.get_tokens())
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_response = false;
            continue;
        }

        std::cout << "\n" << "                         YOU WAGERED " << users_wager << " TOKENS ON HORSE #" << users_horse << "\n";
        std::cout << "\n\n\n\n" << "                           ENTER ANY KEY TO CONTINUE: ";
        std::cin >> key;

        // if all conditions are met user entered valid information and breaks out of loop
        is_valid_response = true;

    } while (!is_valid_response);

    // call race once user selects a horse to bet on and the amount once inputs are validated.
    animate_race();
}

// returns a random horse if there is a tie
int HorseRace::tie_breaker(int total_horses)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, total_horses);
    int winning_horse = dist6(rng);
    return winning_horse;
}

// returns how many spaces the horse should run between 0-2
int HorseRace::get_random_spaces()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 2);
    int spaces = dist6(rng);
    return spaces;
}

// builds the path length the horse will run
std::string HorseRace::build_racers_path()
{

    int path_length = 11;
    std::string current_horse = "";
    std::string line = "|";

    for (int i = 0; i <= path_length; i++)
    {
        int spaces = get_random_spaces();

        for (int j = 0; j < spaces; j++)
        {
            current_horse = current_horse + line;
        }
    }

    return current_horse;
}

// checks if the user lost or won his bet and modifies their account
void HorseRace::check_outcome(int winning_horse)
{
    Visuals visuals_obj;

    // user picked the winning horse. they win
    if (users_horse == winning_horse)
    {
        std::cout << "\n\n" << "                       YOUR HORSE WON. YOU WON " << (users_wager * 5) << " TOKENS" << std::endl;
        token_access.set_tokens(token_access.get_tokens() + (users_wager * 5));
    }
    // otherwise they picked the wrong horse and lost.
    else
    {
        std::cout << "\n\n" << "                      YOUR HORSE LOST. YOU LOST " << (users_wager) << " TOKENS" << std::endl;
        token_access.set_tokens(token_access.get_tokens() - (users_wager));
    }
}

// promtps user to either play again or return to gameroom
void HorseRace::replay()
{
    int users_input;
    int time = 3000;
    bool is_valid_input = false;

    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n";
        std::cout << "                         WOULD YOU LIKE TO PLAY AGAIN?" << std::endl;
        std::cout << "\n";
        std::cout << "                                 1: PLAY AGAIN" << std::endl;
        std::cout << "                             2: RETURN TO GAMEROOM" << std::endl;
        std::cout << "\n"; 
        std::cout << "                            PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = true;
        }
        else if ((users_input == 1) || (users_input == 2))
        {
            is_valid_input = false;
        }
        else
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "                         PLEASE ENTER A VALID RESPONSE";
            std::cout << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            is_valid_input = true;
        }

    } while (is_valid_input);

    if (users_input == (1))
    {
        place_wager();
    }
    else if (users_input == (2))
    {
        Gameroom GRobj;
        GRobj.return_to_games_menu();
    }
}

// This is where we animate the horse race
void HorseRace::animate_race()
{

    // clear console
    system("clear");

    // Time delays
    int title_timer = 1000;
    int race_timer = 400;
    int outcome_timer = 5000;

    // Horses & their paths
    int number_of_horses = 8;
    int longest_path = 0;

    std::string h1 = build_racers_path();
    std::string h2 = build_racers_path();
    std::string h3 = build_racers_path();
    std::string h4 = build_racers_path();
    std::string h5 = build_racers_path();
    std::string h6 = build_racers_path();
    std::string h7 = build_racers_path();
    std::string h8 = build_racers_path();

    std::string horses[8] = {h1, h2, h3, h4, h5, h6, h7, h8};
    std::string winner;

    // horses that are tied
    std::vector<std::string> tied_horses;
    std::vector<int> tied_horse_positions;
    int corresponding_position;

    // find longest path
    for (int i = 0; i < number_of_horses; i++)
    {
        int winningHorse = ((horses[i]).length());

        if (longest_path < winningHorse)
        {
            longest_path = winningHorse;
        }
    }

    // check how many horses are tied
    for (int x = 0; x < number_of_horses; x++)
    {
        if (horses[x].length() == longest_path)
        {
            tied_horses.push_back(horses[x]);
            tied_horse_positions.push_back(x);
        }
    }

    // if there is a tie, pick a random horse from the pile and add 1 extra line to make it the winner.
    if (tied_horses.size() > 1)
    {
        int random_number = tie_breaker(tied_horses.size());
        winner = tied_horses[random_number - 1]; // maybe causes seg fault if the - 1 is not there
        corresponding_position = tied_horse_positions[random_number - 1];
        winner = winner + "|";
    }
    else
    {
        winner = tied_horses[0];
        corresponding_position = tied_horse_positions[0];
    }

    horses[corresponding_position] = winner;
    longest_path = winner.length();

    // make all horse strings the same length
    for (int j = 0; j < number_of_horses; j++)
    {
        std::string horse_in_construction = horses[j];

        for (int k = 0; horse_in_construction.length() < longest_path; k++)
        {
            horse_in_construction = horse_in_construction + " ";
        }
        horses[j] = horse_in_construction;
    }

    std::string ready = "                                  READY";
    std::string set =   "                                       SET";
    std::string go =    "                                           GO!";

    std::cout << "\n\n\n\n\n\n\n\n\n\n"
              << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(title_timer));
    std::cout << ready << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(title_timer));
    std::cout << set << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(title_timer));
    std::cout << go << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(title_timer));

    // clear console so only the horse race is displayed
    system("clear");

    std::cout << "" << std::endl;
    std::string lane_numbers = "           1       2       3       4       5       6       7       8"; 
    std::string line;
    std::string first_lane_spacer = "           ";
    std::string lane_spacer = "       ";

    std::cout << lane_numbers << std::endl;

    // display the horses and their paths in the terminal
    for (int i = 0; i < longest_path; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(race_timer));

        line = first_lane_spacer + horses[0].at(i) + lane_spacer + horses[1].at(i) + lane_spacer + horses[2].at(i) + lane_spacer + horses[3].at(i) + lane_spacer + horses[4].at(i) + lane_spacer + horses[5].at(i) + lane_spacer + horses[6].at(i) + lane_spacer + horses[7].at(i);
        std::cout << line << std::endl;
    }

    corresponding_position = corresponding_position + 1;

    check_outcome(corresponding_position);

    std::this_thread::sleep_for(std::chrono::milliseconds(outcome_timer));

    // user is out of tokens
    Introduction token_access_obj; 

    if(token_access_obj.get_tokens() < 1){
        Revive revive_obj; 
        revive_obj.Explanation(); 
        Gameroom gameroom_obj; 
        gameroom_obj.return_to_games_menu();
    }
    else{
        replay();
    }
}