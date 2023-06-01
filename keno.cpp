#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include "introduction.h"
#include "gameroom.h"
#include "keno.h"

// constructor 
Keno::Keno(){

}

// kicks off the keno game
void Keno::run_keno(){
    keno_menu(); 
}

// keno insturctions 
void Keno::keno_instructions(){

    system("clear");
    bool valid_input;
    int users_input;

    do
    {
        system("clear");
        std::string instruction_message = "\n\n\n                                  KENO\n\n";
        

        std::cout << instruction_message;
        

        std::cout << "\n\n                          1: PLAY KENO";
        std::cout << "\n                          2: RETURN TO THE GAME FLOOR\n";
        std::cout << "\n                          PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;
        valid_input = validate_input(users_input);

    } while (!valid_input);

    if (users_input == (1))
    {
        play_keno();
    }
    else if (users_input == (2))
    {
        Gameroom game_room_obj;
        game_room_obj.return_to_games_menu();
    }

}

// prompt user with the keno menu to either play or display instructions
void Keno::keno_menu(){

    int instructions = 1;
    int play = 2;
    int users_input;
    bool valid_input;

    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n                                 KENO\n"
                  << std::endl;
        std::cout << "                          1: HOW TO PLAY KENO" << std::endl;
        std::cout << "                          2: PLAY KENO" << std::endl;
        std::cout << "\n                          PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;
        valid_input = validate_input(users_input);

    } while (!valid_input);

    if (users_input == (instructions))
    {
        keno_instructions();
    }
    else if (users_input == (play))
    {
        play_keno();
    }
}

// plays keno 
void Keno::play_keno(){

    system("clear");
    std::cout << "\n\n                                      KENO\n\n" << std::endl; 

    int counter = 0; 
    std::string add_space = "                "; 

    for(int x = 1; x <= 80; x++){

        if(counter == 0){
            std::cout << add_space; 
        }

        if(x < 10 && x > 0){
            std::cout << " ";  
        }

        std::cout << " [" + std::to_string(x) + "]"; 

        counter++; 

        if(counter >= 10){
            std::cout << "" << std::endl; 
            counter = 0; 
        }
    }
}

// validate the users input 
bool Keno::validate_input(int users_input){

    system("clear");
    const int time = 3000;

    // Check if user even entered a digit
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }

    // Check if digit is one of the available options
    if (users_input == (1) || users_input == (2))
    {
        return true;
    }
    else
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n                    THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }

}
