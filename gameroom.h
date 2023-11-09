#ifndef GAMEROOM_H
#define GAMEROOM_H

class Gameroom
{
public:
    Gameroom();
    void run_gameroom();
    void return_to_games_menu();

private:
    void welcome();
    void game_options();
    bool validate_input(std::string users_input);
    void direct_game_flow(std::string users_input);
};

#endif