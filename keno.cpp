#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include <cstdlib>
#include <regex>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cmath>
#include <set>
#include <limits>
#include "introduction.h"
#include "gameroom.h"
#include "keno.h"
#include "revive.h"

// Constants
const int MAX_NUMBER = 80;
const int MIN_NUMBER = 1;
const int MAX_SELECTIONS = 10;
const int MIN_SELECTIONS = 2;
const int DRAW_COUNT = 20;
const int CLEAR_SLEEP_TIME = 3;
const int SLEEP_TIME = 3000; // milliseconds

// Constructor
Keno::Keno() : rng(std::random_device{}()) {}

// Kicks off the Keno game
void Keno::run_keno() {
    keno_menu();
}

void Keno::clear_screen() {
#ifdef _WIN32
    std::this_thread::sleep_for(std::chrono::milliseconds(CLEAR_SLEEP_TIME));
    system("cls");
#else
    std::this_thread::sleep_for(std::chrono::milliseconds(CLEAR_SLEEP_TIME));
    system("clear");
#endif
}

// Keno instructions
void Keno::keno_instructions() { 
    int users_input;
    bool valid_input;

    do {
        clear_screen();  
        std::cout << "\n\n                                      KENO\n\n\n"
                  << "   -THE PLAYER SELECTS BETWEEN 2-10 NUMBERS RANGING FROM 1 TO 80 AND PLACES A\n"
                  << "                         WAGER ON THAT POOL OF NUMBERS\n\n"
                  << "                     -THEN, 20 NUMBERS ARE DRAWN AT RANDOM\n\n"
                  << "     -THE PLAYER WINS BASED ON MATCHING SELECTED NUMBERS TO THE DRAWN ONES\n\n"
                  << "        -THE PAYOUTS VARY BASED ON THE TOTAL NUMBER OF SELECTED NUMBERS\n"
                  << "                        (SEE GITHUB README FOR DETAILS)\n\n"
                  << "      -IF NONE OF THE SELECTED NUMBERS MATCH, THEY LOSE THE WAGERED AMOUNT\n\n\n"
                  << "                                  1: PLAY KENO\n"
                  << "                          2: RETURN TO THE GAME FLOOR\n\n"
                  << "                           PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;
        valid_input = validate_input(users_input);

    } while (!valid_input);

    if (users_input == 1) {
        play_keno();
    } else if (users_input == 2) {

        // it is possible to go into other panels with failed cin
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        Gameroom game_room_obj;
        game_room_obj.return_to_games_menu();
    }
}

// Prompt user with the Keno menu to either play or display instructions
void Keno::keno_menu() {
    int users_input;
    bool valid_input;

    do {
        clear_screen(); 
        std::cout << "\n\n\n\n\n\n\n\n\n                                      KENO\n\n"
                  << "                              1: HOW TO PLAY KENO\n"
                  << "                                  2: PLAY KENO\n\n"
                  << "                            PLEASE SELECT AN OPTION: ";
        std::cin >> users_input;
        valid_input = validate_input(users_input);

    } while (!valid_input);

    if (users_input == 1) {
        keno_instructions();
    } else if (users_input == 2) {
        play_keno();
    }
}

void Keno::play_keno() {
    bool are_valid_numbers;
    bool is_valid_wager = false;
    int wagered_amount;

    const int TERMINAL_WIDTH = 80; // Default terminal width for Linux

    do {
        clear_screen();
        std::cout << "\n\n                                      KENO\n\n\n";
        display_keno_board();

        std::string wagered_numbers;
        std::cout << "\n\n                     SELECT BETWEEN 2-10 NUMBERS TO BET ON:\n"
                  << "                                ";
        std::getline(std::cin >> std::ws, wagered_numbers);
        are_valid_numbers = validate_wagered_numbers(wagered_numbers);

        std::cout << "\n                                 WAGER AMOUNT: ";
        std::cin >> wagered_amount;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            clear_screen();
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                         PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
            continue;
        }

        is_valid_wager = validate_wager(wagered_amount);

        if (!are_valid_numbers || !is_valid_wager) {
            clear_screen();
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n                         PLEASE ENTER A VALID RESPONSE\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
        } else {
            std::set<int> winning_numbers = draw_winning_numbers();
            clear_screen();
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME / 3));
            std::cout << "\n\n                            THE WINNING NUMBERS ARE:\n\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
            display_keno_board(winning_numbers);

            std::vector<int> wagered_numbers_vector = parse_wagered_numbers(wagered_numbers);
            int hits = count_hits(wagered_numbers_vector, winning_numbers);

            // Build the output strings
            std::string numbers_text = "YOUR NUMBERS: ";
            for (int num : wagered_numbers_vector) {
                numbers_text += std::to_string(num) + " ";
            }

            std::string hits_text = "HITS: " + std::to_string(hits);

            // Calculate padding for centering
            int padding_numbers = (TERMINAL_WIDTH - numbers_text.length()) / 2;
            int padding_hits = (TERMINAL_WIDTH - hits_text.length()) / 2;

            // Print centered text
            std::cout <<  "\n\n";
            std::cout << std::string(padding_numbers, ' ') << numbers_text << "\n";
            std::cout <<  "\n";
            std::cout << std::string(padding_hits, ' ') << hits_text << "\n\n\n";

            outcome_checker(hits, wagered_numbers_vector.size(), wagered_amount);
            std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME * 2));
        }

    } while (!are_valid_numbers || !is_valid_wager);

    // User is out of tokens
    Introduction token_access_obj;
    if (token_access_obj.get_tokens() < 1) {
        Revive revive_obj;
        revive_obj.Explanation();
        Gameroom gameroom_obj;
        gameroom_obj.return_to_games_menu();
    } else {
        play_again();
    }
}

// Asks the user if they want to play again
void Keno::play_again() {
    int input;
    bool outcome = false;

    do {
        clear_screen(); 
        std::cout << "\n\n\n\n\n\n\n\n\n                         WOULD YOU LIKE TO PLAY AGAIN?\n\n"
                  << "                                 1: PLAY AGAIN\n"
                  << "                             2: RETURN TO GAMEROOM\n\n"
                  << "                            PLEASE SELECT AN OPTION: ";
        std::cin >> input;
        outcome = validate_input(input);

        if (input == 1) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            play_keno();
        } else if (input == 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            Gameroom game_room;
            game_room.return_to_games_menu();
        }

    } while (!outcome);
}

// Validates that the user wagered a valid amount
bool Keno::validate_wager(int wager) {
    Introduction account_checker;
    return wager > 0 && wager <= account_checker.get_tokens();
}

// Validates that the string of wagered numbers is valid
bool Keno::validate_wagered_numbers(const std::string& users_input) {
    std::string input = users_input;
    input.erase(std::remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (!is_digit(input)) {
        return false;
    }

    std::vector<int> numbers = parse_wagered_numbers(users_input);
    if (numbers.size() < MIN_SELECTIONS || numbers.size() > MAX_SELECTIONS) {
        return false;
    }

    for (int num : numbers) {
        if (num < MIN_NUMBER || num > MAX_NUMBER) {
            return false;
        }
    }

    return true;
}

// Checks if input is only digits
bool Keno::is_digit(const std::string& str) {
    return str.find_first_not_of("0123456789 ") == std::string::npos;
}

// Validates the user's input for the main menu
bool Keno::validate_input(int users_input) {
    clear_screen();  
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n                         PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
        clear_screen();  
        return false;
    }

    if (users_input == 1 || users_input == 2) {
        return true;
    } else {
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n                         PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
        clear_screen();  
        return false;
    }
}

// Generates a random number between 1 and 80
int Keno::random_number_generator() {
    std::uniform_int_distribution<std::mt19937::result_type> dist(MIN_NUMBER, MAX_NUMBER);
    return dist(rng);
}

// Draws 20 unique winning numbers
std::set<int> Keno::draw_winning_numbers() {
    std::set<int> winning_numbers;
    while (winning_numbers.size() < DRAW_COUNT) {
        winning_numbers.insert(random_number_generator());
    }
    return winning_numbers;
}

// Displays the Keno board
void Keno::display_keno_board(const std::set<int>& winning_numbers) {
    int counter = 0;
    std::string add_space = "               ";
    for (int x = 1; x <= MAX_NUMBER; x++) {
        if (counter == 0) {
            std::cout << add_space;
        }
        if (winning_numbers.count(x)) {
            std::cout << " [XX]";
        } else {
            std::cout << " [" << (x < 10 ? "0" : "") << x << "]";
        }
        counter++;
        if (counter >= 10) {
            std::cout << std::endl;
            counter = 0;
        }
    }
}

// Parses the wagered numbers from a string to a vector of integers
std::vector<int> Keno::parse_wagered_numbers(const std::string& input) {
    std::vector<int> numbers;
    std::stringstream ss(input);
    int number;
    while (ss >> number) {
        numbers.push_back(number);
    }
    return numbers;
}

// Counts how many numbers match between the wagered numbers and the winning numbers
int Keno::count_hits(const std::vector<int>& wagered_numbers, const std::set<int>& winning_numbers) {
    int hits = 0;
    for (int num : wagered_numbers) {
        if (winning_numbers.count(num)) {
            hits++;
        }
    }
    return hits;
}

// Checks the outcome of the game and updates the token balance
void Keno::outcome_checker(int hits, int spots, int wager) {
    int won_tokens = 0;

    switch (spots) {
        case 2: if (hits == 2) won_tokens = wager * 15; break;
        case 3: if (hits == 2) won_tokens = wager; else if (hits == 3) won_tokens = wager * 16; break;
        case 4: if (hits == 2) won_tokens = wager; else if (hits == 3) won_tokens = wager * 2; else if (hits == 4) won_tokens = wager * 25; break;
        case 5: if (hits == 3) won_tokens = wager; else if (hits == 4) won_tokens = wager * 3; else if (hits == 5) won_tokens = wager * 160; break;
        case 6: if (hits == 3) won_tokens = wager; else if (hits == 4) won_tokens = wager; else if (hits == 5) won_tokens = wager * 15; else if (hits == 6) won_tokens = wager * 270; break;
        case 7: if (hits == 3) won_tokens = wager; else if (hits == 4) won_tokens = wager * 2; else if (hits == 5) won_tokens = wager * 4; else if (hits == 6) won_tokens = wager * 70; else if (hits == 7) won_tokens = wager * 1000; break;
        case 8: if (hits == 4) won_tokens = wager * 2; else if (hits == 5) won_tokens = wager * 3; else if (hits == 6) won_tokens = wager * 16; else if (hits == 7) won_tokens = wager * 240; else if (hits == 8) won_tokens = wager * 1250; break;
        case 9: if (hits == 4) won_tokens = wager; else if (hits == 5) won_tokens = wager * 5; else if (hits == 6) won_tokens = wager * 7; else if (hits == 7) won_tokens = wager * 50; else if (hits == 8) won_tokens = wager * 580; else if (hits == 9) won_tokens = wager * 1111; break;
        case 10: if (hits == 5) won_tokens = wager * 3; else if (hits == 6) won_tokens = wager * 4; else if (hits == 7) won_tokens = wager * 20; else if (hits == 8) won_tokens = wager * 125; else if (hits == 9) won_tokens = wager * 600; else if (hits == 10) won_tokens = wager * 1500; break;
        default: std::cout << "Something went wrong\n"; break;
    }

    Introduction token_access;
    if (won_tokens == 0) {
        std::cout << "                               YOU LOST " << wager << " TOKENS\n\n";
        token_access.set_tokens(token_access.get_tokens() - wager);
    } else {
        std::cout << "                                YOU WON " << won_tokens << " TOKENS\n\n";
        token_access.set_tokens(token_access.get_tokens() + won_tokens);
    }
}