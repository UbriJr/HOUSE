#ifndef KENO_H
#define KENO_H

#include <string>
#include <vector>
#include <set>
#include <random>

class Keno
{
public:
    Keno(); 
    void run_keno();

private:
    void keno_instructions();
    void keno_menu();
    void play_keno();
    void play_again(); 
    void outcome_checker(int hits, int spots, int wager);
    int random_number_generator(); 
    bool is_digit(const std::string &str); 
    bool validate_input(int users_input);
    bool validate_wagered_numbers(const std::string &users_input); 
    bool validate_wager(int wager);

    // Helper functions
    std::set<int> draw_winning_numbers();
    void display_keno_board(const std::set<int>& winning_numbers = {});
    std::vector<int> parse_wagered_numbers(const std::string &input);
    int count_hits(const std::vector<int> &wagered_numbers, const std::set<int> &winning_numbers);

    // Random number generator
    std::mt19937 rng;
};

#endif
