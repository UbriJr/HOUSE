#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <thread>
#include "introduction.h"
#include "gameroom.h"
#include <map>
#include <vector>

std::vector<int> encryptionKey = {862442, 421612, 916945, 148275}; // Longer key for added complexity

// constructor
Introduction::Introduction(){

};

// runs the introduction
void Introduction::run_introduction()
{
    welcome();
    register_or_login();
}

// reads & returns the number of tokens the player has
int Introduction::get_tokens()
{
    std::ifstream read_file("data.txt");
    std::string current_line;
    std::string tmp;
    std::stringstream string_stream;
    int tokens;
    int current_position = 0; 
    int token_position_in_file = 2;
    std::string ciphertext;  

    while (getline(read_file, current_line))
    {
        if (current_position == token_position_in_file)
        {
            tmp = current_line;
        }
        current_position = current_position + 1; 
    }

    ciphertext = tmp;

    // decrypt ciphertext to get token amount
    tokens = decrypt(ciphertext);

    return tokens;
}

// adjust and set new token amount in the file
void Introduction::set_tokens(int tokens)
{
    std::ifstream data_file;
    data_file.open("data.txt");

    std::fstream tmp("test.txt", std::ios::out);

    std::string current_line;
    std::string line;
    int current_position = 0; 
    int token_position_in_file = 2;

    while (getline(data_file, current_line))
    {
        tmp << current_line << std::endl;
    }

    tmp.close();
    data_file.close();

    std::ifstream test_file("test.txt");
    std::fstream data;
    data.open("data.txt", std::ios::out);

    // encrypt tokens before writing to file
    std::string ciphertext = encrypt(tokens); 

    while (getline(test_file, line))
    {
        if (current_position != token_position_in_file)
        {
            data << line << std::endl;
        }
        else if (current_position == token_position_in_file)
        {
            data << ciphertext << std::endl;
        }

        current_position = current_position + 1; 
    }

    test_file.close();
    remove("test.txt");
    data.close();
}

std::string Introduction::encrypt(int tokens){ 
    int encryptedValue = tokens;
    for (size_t i = 0; i < encryptionKey.size(); ++i) {
        encryptedValue ^= encryptionKey[i]; // XOR with each byte of the key
    }

    std::stringstream stream;
    stream << std::hex << encryptedValue;
    
    return (stream).str(); 
}

int Introduction::decrypt(std::string cipher){

    int decryptedValue = std::stoi(cipher, 0, 16);

    for (size_t i = 0; i < encryptionKey.size(); ++i) {
        decryptedValue ^= encryptionKey[i]; // XOR with each byte of the key to reverse encryption
    }

    return decryptedValue;
}


// displays a welcome banner to the terminal window
void Introduction::welcome()
{
    // clear console
    system("clear");

    const int time = 400;

    // welcome banner
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "\n\n";
    std::cout << "    ***       ***     *******     ***         ***   **********    ************" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ***       ***  ***       ***  ***         *** ***        ***  ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ***       *** ***         *** ***         *** *****           ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ************* ***         *** ***         ***      ****       **********" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ***       *** ***         *** ***         ***           ***** ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ***       ***  ***       ***  ****       **** ***        ***  ****" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "    ***       ***     *******       ***********     **********    ************" << std::endl;
}

// validates the user's input in this panel
bool Introduction::validate_input(int users_input)
{
    // clear console
    system("clear");

    const int time = 3000;

    // Check if user even entered a digit
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                         PLEASE ENTER A VALID RESPONSE";
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }

    // Check if digit is one of the available options
    if (users_input == (1) || users_input == (2))
    {
        return true;
    }
    else
    {
        std::cout << "\n\n\n\n\n\n\n\n\n\n";
        std::cout << "                         PLEASE ENTER A VALID RESPONSE";
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }
}

// prompts user to login if this option is selected
void Introduction::login()
{

    system("clear");
    std::string username;
    std::string password;
    std::string current_line;
    std::string next_line;
    std::cout << "\n";

    const int time = 5000;

    bool user_info_found = false;

    std::cout << "\n\n\n\n\n\n\n\n";
    std::cout << "                                   LOGIN MENU";
    std::cout << "\n\n";
    std::cout << "                              ENTER YOUR USERNAME: ";
    std::cin >> username;
    std::cout << "\n";
    std::cout << "                              ENTER YOUR PASSWORD: ";
    std::cin >> password;

    std::ifstream read_file("data.txt");

    while (getline(read_file, current_line))
    {

        getline(read_file, next_line);

        if ((username == current_line) && (password == next_line))
        {
            system("clear");
            std::cout << "\n\n\n\n\n\n\n\n\n";
            std::cout << "                                LOGIN SUCCESSFUL" << std::endl;
            std::cout << "                               YOU HAVE " << (get_tokens()) << " TOKENS" << std::endl;
            std::cout << "                PLEASE WAIT WHILE WE BRING YOU TO THE GAME FLOOR" << std::endl;
            std::cout << "";
            std::this_thread::sleep_for(std::chrono::milliseconds(time));

            user_info_found = true;
        }
        std::cout << "\n";
    }

    read_file.close();

    if (!user_info_found)
    {
        system("clear");
        int needed_spaces = 11;

        spacing_buffer(needed_spaces);
        std::cout << "        COULD NOT FIND AN ACCOUNT WITH THE GIVEN USERNAME AND PASSWORD" << std::endl;
        std::cout << "                     PLEASE REGISTER OR TRY TO LOGIN AGAIN"
                  << std::endl;
        register_or_login();
    }

    Gameroom game_floor_obj;
    game_floor_obj.run_gameroom();
}

// prompts user to register if that option is selected
void Introduction::reg()
{
    system("clear");
    const int time = 4000;
    const int initial_tokens = 10;

    std::string username;
    std::string password;

    // encrypt token amount 
    std::string ciphertext = encrypt(initial_tokens);

    int temp = decrypt(ciphertext);
    
    std::fstream data_file;
    data_file.open("data.txt", std::ios::out);

    std::cout << "\n\n\n\n\n\n\n\n";
    std::cout << "                               REGISTRATION MENU";
    std::cout << "\n\n";
    std::cout << "                              CREATE A USERNAME: ";
    std::cin >> username;
    std::cout << "\n";
    std::cout << "                              CREATE A PASSWORD: ";
    std::cin >> password;

    system("clear");

    std::cout << "\n\n\n\n\n\n\n\n\n\n";
    std::cout << "                             REGISTRATION COMPLETE" << std::endl;
    std::cout << "                               LOGIN TO CONTINUE";
    std::cout << "\n\n";
    

    data_file << username << std::endl;
    data_file << password << std::endl;
    data_file << ciphertext << std::endl;

    data_file.close();
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    login();
}

// direct programs control to either register or login method
void Introduction::direct_control_flow(int users_input)
{
    int login_option = 1;
    int register_option = 2;

    if (users_input == (login_option))
    {
        login();
    }
    else if (users_input == (register_option))
    {
        reg();
    }
}

// prompts user to register or login during menu screen
void Introduction::register_or_login()
{
    bool is_valid;
    int users_input;

    do
    {
        std::cout << "\n\n\n\n\n";
        std::cout << "                                    1: LOGIN";
        std::cout << "\n";
        std::cout << "                                   2: REGISTER";
        std::cout << "\n\n";
        std::cout << "                                 SELECT AN OPTION: ";
        std::cin >> users_input;
        is_valid = validate_input(users_input);

        system("clear");
        std::cout << "\n\n\n\n";

    } while (!is_valid);

    direct_control_flow(users_input);
}

// added white space to make program more visually appealing
void Introduction::spacing_buffer(int spaces)
{
    for (int i = 0; i < spaces; i++)
    {
        std::cout << "\n";
    };
}
