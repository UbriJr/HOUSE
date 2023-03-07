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
    bool validate_input(int users_input);
    void direct_game_flow(int users_input);
};

#endif