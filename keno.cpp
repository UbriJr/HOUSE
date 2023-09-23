#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
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
        std::string instruction_message = "\n\n\n                                  KENO\n\n -THE PLAYER SELECTS BETWEEN 2-10 NUMBERS RANGING FROM 1 TO 80 AND PLACES A \n  WAGER ON THAT POOL OF NUMBERS.\n\n -THEN, 20 NUMBERS ARE DRAWN AT RANDOM.\n\n -THE PLAYER WINS BASED ON MATCHING SELECTED NUMBERS TO THE DRAWN ONES.\n\n -THE PAYOUTS VARY BASED ON THE TOTAL NUMBER OF SELECTED NUMBERS.\n  (SEE GITHUB README FOR DETAILS) \n\n -IF NONE OF THE SELECTED NUMBERS MATCH, THEY LOSE THE WAGERED AMOUNT.\n";
        

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

    int time = 6000; 
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
                std::cout << " [0" + std::to_string(x) + "]";  
            }

            else{
                std::cout << " [" + std::to_string(x) + "]";
            } 

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
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                        PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
            continue; 
        }

        is_valid_wager = validate_wager(wagered_amount); 

        if(!are_valid_numbers || !is_valid_wager){
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                        PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }

        else {

            std::vector<float> winning_numbers_vector = {};

            // draw 20 winning numbers
            while(winning_numbers_vector.size() < 20){
                int random_number = random_number_generator(); 

                // check if random number is already in the vector
                if(std::count(winning_numbers_vector.begin(), winning_numbers_vector.end(), random_number)){
                    continue;
                }
                else{
                    winning_numbers_vector.insert(winning_numbers_vector.end(), random_number); 
                }
            }

            system("clear");
            std::this_thread::sleep_for(std::chrono::milliseconds(time / 3));
            std::cout << "\n\n\n                            THE WINNING NUMBERS ARE: \n\n" << std::endl; 
            std::this_thread::sleep_for(std::chrono::milliseconds(time / 2));

            for(int x = 1; x <= 80; x++){

                    if(counter == 0){
                        std::cout << add_space; 
                    }

                    if(x < 10 && x > 0){
                        std::cout << "";  
                    }

                    // the number is in the winning numbers pool
                    if(std::count(winning_numbers_vector.begin(), winning_numbers_vector.end(), x)){
                        std::cout << " [XX]";
                    }

                    else 
                    {   
                        if(x < 10 && x > 0){
                            std::cout << " [0" + std::to_string(x) + "]";   
                        }
                        else{
                            std::cout << " [" + std::to_string(x) + "]"; 
                        }
                    }

                    counter++; 

                    if(counter >= 10){
                        std::cout << "" << std::endl; 
                        counter = 0; 
                    }
                }

            std::cout << "\n\n            "; 

            for(float i = 0; i < winning_numbers_vector.size(); i++){
                std::cout << winning_numbers_vector.at(i) << " ";
            }

            std::cout << "\n\n                         YOUR NUMBERS: "; 

            int hits = 0; 

            // convert to a vector
            std::vector<float> wagered_numbers_vector = {};

            std::string number_builder; 

            wagered_numbers = wagered_numbers + " "; 

            for(int i = 0; i < wagered_numbers.length(); i++)
            {
                if(wagered_numbers[i] == '.'){
                    number_builder = number_builder + '.'; 
                }
                else if(wagered_numbers[i] != ' '){
                    int t = wagered_numbers[i] - '0';  
                    number_builder = number_builder + std::to_string(t);
                }

                if(wagered_numbers[i+1] == ' '){
                    wagered_numbers_vector.insert(wagered_numbers_vector.end(), stof(number_builder)); 
                    number_builder = ""; 
                    continue; 
                }
                
            }

            // check how many hits (matched numbers by user input and drawing) and print their wagered numbers
            for(int i = 0; i < wagered_numbers_vector.size(); i++){

                std::cout << wagered_numbers_vector.at(i) << " ";
                
                if(std::count(winning_numbers_vector.begin(), winning_numbers_vector.end(), wagered_numbers_vector.at(i))){
                    hits++;
                }
            }

            std::cout << "\n                         HITS: " << hits << "\n\n"; 

            outcome_checker(hits, wagered_numbers_vector.size(), wagered_amount);
            std::this_thread::sleep_for(std::chrono::milliseconds(time));
        }

    } while (!are_valid_numbers || !is_valid_wager); 

    play_again(); 

}

void Keno::play_again(){

    int input;
    bool outcome = false;  
    
    do{
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n                          WOULD YOU LIKE TO PLAY AGAIN?" << std::endl
                  << "\n";
        std::cout << "                               1: PLAY AGAIN" << std::endl;
        std::cout << "                               2: RETURN TO GAMEROOM" << std::endl;
        std::cout << "\n                             PLEASE SELECT AN OPTION: ";
        std::cin >> input;

        bool outcome = validate_input(input);

        if ((input) == (1))
        {
            play_keno();
        }

    // returns user to game room (other games)
        else if ((input) == (2))
        {
            Gameroom game_room;
            game_room.return_to_games_menu();
        }

    } while(!outcome);

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

    std::string working_input = users_input; 

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
        std::cout << "\n\n\n\n\n\n\n\n\n\n                      THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
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
        std::cout << "\n\n\n\n\n\n\n\n\n\n                      THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }

}

int Keno::random_number_generator(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 80);
    int number = dist6(rng);
    return number;
}

// check how many hits and add tokens to profile
void Keno::outcome_checker(int hits, int spots, int wager){

    int won_tokens = 0; 

    switch (spots)
    {
    case 2:

        switch(hits)
        {
            case 2:
                won_tokens = wager * 15;
                break; 
        }
        break;

    case 3:
    switch(hits)
        {
            case 2:
                won_tokens = wager;
                break; 
            case 3:
                won_tokens = wager * 16;
                break; 
        }
        break;
    case 4:
    switch(hits)
        {
            case 2:
                won_tokens = wager;
                break; 
            case 3:
                won_tokens = wager * 2;
                break; 
            case 4:
                won_tokens = wager * 25;
                break; 
        }
        break;
    case 5:
    switch(hits)
        {
            case 3:
                won_tokens = wager;
                break; 
            case 4:
                won_tokens = wager * 3;
                break; 
            case 5:
                won_tokens = wager * 160;
                break; 
        }
        break;
    case 6:
    switch(hits)
        {
            case 3:
                won_tokens = wager;
                break; 
            case 4:
                won_tokens = wager;
                break; 
            case 5:
                won_tokens = wager * 15;
                break; 
            case 6:
                won_tokens = wager * 270;
                break; 
        }
        break;
    case 7:
    switch(hits)
        {
            case 3:
                won_tokens = wager;
                break; 
            case 4:
                won_tokens = wager * 2;
                break; 
            case 5:
                won_tokens = wager * 4;
                break; 
            case 6:
                won_tokens = wager * 70;
                break; 
            case 7:
                won_tokens = wager * 1000; 
                break; 
        }
        break; 
    case 8:
    switch(hits)
        {
            case 4:
                won_tokens = wager * 2;
                break; 
            case 5:
                won_tokens = wager * 3;
                break; 
            case 6:
                won_tokens = wager * 16;
                break; 
            case 7:
                won_tokens = wager * 240;
                break; 
            case 8:
                won_tokens = wager * 1250;
                break; 
        }
        break;
    case 9:
    switch(hits)
        {
            case 4:
                won_tokens = wager;
                break; 
            case 5:
                won_tokens = wager * 5;
                break; 
            case 6:
                won_tokens = wager * 7;
                break; 
            case 7:
                won_tokens = wager * 50;
                break; 
            case 8:
                won_tokens = wager * 580;
                break; 
            case 9:
                won_tokens = wager * 1111;
                break; 
        }
        break;
    case 10:
        switch(hits)
        {
            case 5:
                won_tokens = wager * 3;
                break; 
            case 6:
                won_tokens = wager * 4;
                break; 
            case 7:
                won_tokens = wager * 20;
                break; 
            case 8:
                won_tokens = wager * 125; 
                break; 
            case 9:
                won_tokens = wager * 600; 
                break; 
            case 10:
                won_tokens = wager * 1500; 
                break; 
        }
        break;
    default:
        std::cout << "Something went wrong" << std::endl;
    }

    // access tokens to add and remove tokens from balance
    Introduction token_access; 

    if(won_tokens == 0){
        std::cout << "                                  YOU LOST " << std::to_string(wager) << " TOKENS\n\n";
        token_access.set_tokens(token_access.get_tokens() - wager);
    }
    else{
        std::cout << "                                YOU WON " << std::to_string(won_tokens) << " TOKENS\n\n";
        token_access.set_tokens(token_access.get_tokens() + won_tokens);
    }

}
