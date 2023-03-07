#ifndef CASINOWAR_H
#define CASINOWAR_H

class CasinoWar
{
public:
    CasinoWar();
    void run_casino_war();

private:
    bool validate_input(int users_input);
    void casino_war_menu();
    void play_casino_war();
    void casino_war_instructions();
    void play_again();
    void reveal_cards();
    void check_outcome(int players_card, int dealers_card);
    int random_card_generator();
    bool check_wager(int wager);
    void draw_cards(int card, std::string spacing);
};

#endif