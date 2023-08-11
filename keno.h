#ifndef KENO_H
#define KENO_H

class Keno
{
public:
    Keno(); 
    void run_keno();

private:
    void keno_instructions();
    void keno_menu();
    void play_keno();
    void outcome_checker(int hits, int spots, int wager);
    int random_number_generator(); 
    bool is_digit(const std::string &str); 
    bool validate_input(int users_input);
    bool validate_wagered_numbers(std::string users_input); 
    bool validate_wager(int wager);
};

#endif