#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <regex>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cmath>
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

    int time = 3000; 
    bool are_valid_numbers; 
    bool is_valid_wager = false; 
    int wagered_amount;

    do{
        system("clear");
        std::cout << "\n\n                                      KENO\n\n\n" << std::endl; 
        int counter = 0;  
        std::string add_space = "                "; 
        std::string wagered_numbers; 
        
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

        std::cout << "\n\n                      SELECT BETWEEN 2-10 NUMBERS TO BET ON:" << std::endl; 
        std::cout << "                             "; 
        std::getline(std::cin >> std::ws, wagered_numbers); 
        are_valid_numbers = validate_wagered_numbers(wagered_numbers);
        std::cout << "\n                                   WAGER AMOUNT: "; 
        std::cin >> wagered_amount; 

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continue; 
        }

        is_valid_wager = validate_wager(wagered_amount); 

        if(!are_valid_numbers || !is_valid_wager){
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                    PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }

    } while (!are_valid_numbers || !is_valid_wager); 

}

// validates that the user wagered a valid amount (i.e they have the funds)
bool Keno::validate_wager(int wager){
    
    Introduction account_checker; 
    
    if(wager < 0){
        return false;
    }
    else if(wager > account_checker.get_tokens()){
        return false; 
    }
    return true;
}

// validates that the string of wagered numbers is valid
bool Keno::validate_wagered_numbers(std::string users_input){

    std::string working_input; 

    // remove all whitespace
    working_input.erase(std::remove_if(working_input.begin(), working_input.end(), ::isspace),working_input.end());

    // check if the string contains only numbers
    bool valid_digits = is_digit(working_input);
    
    if(valid_digits == false){
        return false; 
    }

    // check to see if all digits are between 1 - 80

    // remove leading spaces
    users_input = std::regex_replace(users_input, std::regex("^ +"), "");

    // remove trailing spaces
    users_input = std::regex_replace(users_input, std::regex(" +$"), "");

    // removing extra spaces 
    users_input = regex_replace(users_input, std::regex(" +"), " ");

    users_input = users_input + " "; 

    // convert to a vector
    std::vector<float> wagered_numbers_vector = {};

    std::string number_builder; 

    for(int i = 0; i < users_input.length(); i++)
    {
        if(users_input[i] == '.'){
            number_builder = number_builder + '.'; 
        }
        else if(users_input[i] != ' '){
            int t = users_input[i] - '0';  
            number_builder = number_builder + std::to_string(t);
        }

        if(users_input[i+1] == ' '){
            wagered_numbers_vector.insert(wagered_numbers_vector.end(), stof(number_builder)); 
            number_builder = ""; 
            continue; 
        }
        
    }

    if(wagered_numbers_vector.size() > 10 || wagered_numbers_vector.size() < 2){ 
        return false; 
    }


    for(int j = 0; j < wagered_numbers_vector.size(); j++){

        if(wagered_numbers_vector.at(j) != std::floor(wagered_numbers_vector.at(j))){ 
            return false; 
        }

        if(wagered_numbers_vector.at(j) < 1 || wagered_numbers_vector.at(j) > 80){
            return false; 
        }
    }

    return true; 
}

// check if input is only digits 
bool Keno::is_digit(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

// validate the users input for main menu
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
