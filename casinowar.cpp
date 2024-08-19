#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <thread>
#include <random>
#include "gameroom.h"
#include "introduction.h"
#include "casinowar.h"
#include "visuals.h"
#include "revive.h"

std::string preconverted_wager;
Introduction token_access_obj;

// constructor
CasinoWar::CasinoWar(){

};

// kicks off the casino war option
void CasinoWar::run_casino_war()
{
    casino_war_menu();
}

// validates user's input
bool CasinoWar::validate_input(std::string users_input)
{
    system("clear");
    const int time = 3000;

    // Check if digit is one of the available options
    if (users_input == ("1") || users_input == ("2"))
    {
        return true;
    }
    else
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                         PLEASE ENTER A VALID RESPONSE";
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }
}

// brings up the casino war menu
void CasinoWar::casino_war_menu()
{
    int instructions = 1;
    int play = 2;
    std::string users_input;
    int user_converted_input; 
    bool valid_input;

    // Clear the input buffer
    std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n";
        std::cout << "                                   CASINO WAR"; // centered //c
        std::cout << "\n"<< std::endl;
        std::cout << "                           1: HOW TO PLAY CASINO WAR" << std::endl; // centered //c
        std::cout << "                               2: PLAY CASINO WAR" << std::endl; // c //c
        std::cout << "\n";
        std::cout << "                           PLEASE SELECT AN OPTION: "; //c //c
        
        std::getline(std::cin, users_input);

        valid_input = validate_input(users_input);

    } while (!valid_input);

    user_converted_input = std::stoi(users_input);

    if (user_converted_input == (instructions))
    {
        casino_war_instructions();
    }
    else if (user_converted_input == (play))
    {
        play_casino_war();
    }
}

// Checks if the player has the wagered amount in their balance.
bool CasinoWar::check_wager(std::string str_wager)
{
    int max_possible_bet = token_access_obj.get_tokens();

    const int time = 3000;

    // Check if the input is empty or contains only whitespace
    if (str_wager.empty() || std::all_of(str_wager.begin(), str_wager.end(), ::isspace))
    {
        std::cin.clear();
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                         PLEASE ENTER A VALID RESPONSE";
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }
    // Check if user even entered a digit
    else if (!(std::all_of(str_wager.begin(), str_wager.end(), ::isdigit)))
    {
        std::cin.clear();
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                         PLEASE ENTER A VALID RESPONSE"; 
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }
    else if ((std::stoi(str_wager)) > max_possible_bet)
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                  YOU WAGERED " << str_wager << token_or_tokens(str_wager) << " BUT ONLY HAVE" << " " << max_possible_bet << token_or_tokens(str_wager) << std::endl; //c //c
        std::cout << "\n";
        std::cout << "                       PLEASE ENTER A VALID WAGER AMOUNT" << std::endl; //c //c
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        system("clear");
        return false;
    }
    return true;
}

// plays the casino war game
void CasinoWar::play_casino_war()
{
    system("clear");
    bool valid_input;
    // std::string preconverted_wager; 

    do
    {
        std::cout << "\n\n\n\n\n\n\n";
        std::cout << "                                   CASINO WAR" << std::endl; //c //c
        std::cout << "\n";
        std::cout << "                                  WAGER AMOUNT: "; //c //c

        std::getline(std::cin, preconverted_wager); // fix this, wager should be string, checked, then converted to int, this way we account for the enter key. 

        valid_input = check_wager(preconverted_wager);

    } while (!valid_input);

    //std::cin.clear();
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    std::cout << "\n"; 
    std::cout << "                               YOU WAGERED " << preconverted_wager << token_or_tokens(preconverted_wager) << std::endl; //c //c 
    std::cout << "\n\n\n";
    std::cout << "                           ENTER ANY KEY TO CONTINUE: "; //c //c
    std::cin.ignore();

    reveal_cards();
}

// instructions for casino war
void CasinoWar::casino_war_instructions() //cc //c whole thing
{
    system("clear");
    bool valid_input;
    std::string users_input;
    int user_converted_input; 

    do
    {
        system("clear");
        std::cout << "\n\n" << "                                   CASINO WAR" << "\n\n" << "               -THE PLAYER AND THE DEALER ARE EACH DEALT ONE CARD" << "\n\n" << "               -IF THE PLAYER'S CARD IS HIGHER THEN THE DEALER'S" << "\n" <<  "                    THE PLAYER WINS TWICE THE WAGERED AMOUNT" << "\n\n" << "                 -OTHERWISE THE PLAYER LOSES THE WAGERED AMOUNT" << "\n\n" << " -A TIE OCCURS WHEN THE PLAYER AND THE DEALER EACH HAVE CARDS OF THE SAME RANK" << "\n" << "      THE PLAYER AND DEALER ARE DEALT ANOTHER CARD TO DETERMINE THE WINNER" << std::endl; //c 
        std::cout << "\n" << "               CARD RANKS (IN ORDER FROM THE HIGHEST TO LOWEST):" << "\n" << "               ACE, KING, QUEEN, JACK, 10, 9, 8, 7, 6, 5, 4, 3, 2" << std::endl; //c

        std::cout << "\n\n";
        std::cout << "                               1: PLAY CASINO WAR" << std::endl; //c
        std::cout << "                          2: RETURN TO THE GAME FLOOR" << std::endl; //c
        std::cout << "\n";
        std::cout << "                             PLEASE SELECT AN OPTION: "; //c
        
        std::getline(std::cin, users_input); 

        valid_input = validate_input(users_input);

    } while (!valid_input);

    user_converted_input = std::stoi(users_input);

    if (user_converted_input == (1))
    {
        play_casino_war();
    }
    else if (user_converted_input == (2))
    {
        Gameroom game_room_obj;
        game_room_obj.return_to_games_menu();
    }
}

// generates random number which corresponds to a card
int CasinoWar::random_card_generator()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2, 14);
    int card = dist6(rng);
    return card;
}

// prompts the user to play casino war again or return them to the gameroom
void CasinoWar::play_again() //c //c
{
    std::string user_input;
    bool valid_input;
    int user_converted_input; 

    std::cin.clear();

    do
    {
        system("clear");
        std::cout << "\n\n\n\n\n\n\n\n\n";
        std::cout << "                         WOULD YOU LIKE TO PLAY AGAIN?" << std::endl; //c
        std::cout << "\n";
        std::cout << "                                 1: PLAY AGAIN" << std::endl; //c
        std::cout << "                             2: RETURN TO GAMEROOM" << std::endl; //c
        std::cout << "\n"; 
        std::cout << "                            PLEASE SELECT AN OPTION: "; //c
        
        std::getline(std::cin, user_input);

        valid_input = validate_input(user_input);

    } while (!valid_input);

    user_converted_input = std::stoi(user_input);

    if (user_converted_input == (1))
    {
        play_casino_war();
    }
    else if (user_converted_input == (2))
    {
        Gameroom game_room_obj;
        game_room_obj.return_to_games_menu();
    }
}

// displays the players and dealers card in the terminal
void CasinoWar::reveal_cards() //cant be centered
{
    system("clear");
    int players_card;
    int dealers_card;
    std::string players_spacing = "                                               ";
    std::string dealers_spacing = "                          ";

    dealers_card = random_card_generator();

    std::cout << "\n\n                         DEALERS CARD " << std::endl;
    draw_cards(dealers_card, dealers_spacing);

    players_card = random_card_generator();

    std::cout << "\n                                               YOUR CARD " << std::endl;

    draw_cards(players_card, players_spacing);
    check_outcome(players_card, dealers_card);
}

// checked if the player won or lost the wager. Takes in the players card and the dealers card.
void CasinoWar::check_outcome(int players_card, int dealers_card)
{
    const int tie_timer = 7000;
    const int win_lose_timer = 4000; 
    Introduction coin_access_obj;

    if (players_card > dealers_card)
    {
        std::cout << "\n" << "                                    YOU WON" << std::endl; //c
        std::cout << "\n" << "                                YOU WON " << preconverted_wager << token_or_tokens(preconverted_wager) << std::endl; //c 
        coin_access_obj.set_tokens(token_access_obj.get_tokens() + (std::stoi(preconverted_wager)));
        std::this_thread::sleep_for(std::chrono::milliseconds(win_lose_timer));
    }
    else if (players_card == dealers_card)
    {
        std::cout << "\n" << "                                THERE WAS A TIE" << std::endl; //c
        std::cout << "        EACH PLAYER WILL BE DEALT ANOTHER CARD TO DETERMINE THE WINNER" << std::endl; //c
        std::this_thread::sleep_for(std::chrono::milliseconds(tie_timer));
        reveal_cards();
    }
    else if (dealers_card > players_card)
    {
        std::cout << "\n" << "                                 THE DEALER WON" << std::endl; //c
        std::cout << "\n" << "                                YOU LOST " << preconverted_wager << token_or_tokens(preconverted_wager) << std::endl; //c
        coin_access_obj.set_tokens(token_access_obj.get_tokens() - (std::stoi(preconverted_wager)));
        std::this_thread::sleep_for(std::chrono::milliseconds(win_lose_timer));
    }

    // user is out of tokens
    if(token_access_obj.get_tokens() < 1){
        Revive revive_obj; 
        revive_obj.Explanation(); 
        Gameroom gameroom_obj; 
        gameroom_obj.return_to_games_menu();
    }
    else{
        play_again();
    }
}

// this will take in the token amount and return the string "TOKEN" or "TOKENS" depending on how many
std::string CasinoWar::token_or_tokens(std::string token_amount){
    if((std::stoi(token_amount)) == 1){
        return " TOKEN"; 
    }
    else{
        return " TOKENS"; 
    }
}; 

// thanks john wiech for the contribution
void CasinoWar::draw_cards(int card, std::string spacing)
{
    Visuals cards;

    switch (card)
    {
    case 2:
        cards.two_card(spacing);
        break;
    case 3:
        cards.three_card(spacing);
        break;
    case 4:
        cards.four_card(spacing);
        break;
    case 5:
        cards.five_card(spacing);
        break;
    case 6:
        cards.six_card(spacing);
        break;
    case 7:
        cards.seven_card(spacing);
        break;
    case 8:
        cards.eight_card(spacing);
        break;
    case 9:
        cards.nine_card(spacing);
        break;
    case 10:
        cards.ten_card(spacing);
        break;
    case 11:
        cards.jack_card(spacing);
        break;
    case 12:
        cards.queen_card(spacing);
        break;
    case 13:
        cards.king_card(spacing);
        break;
    case 14:
        cards.a_card(spacing);
        break;
    default:
        std::cout << "Something went wrong" << std::endl;
    }
}
