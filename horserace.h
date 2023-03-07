#ifndef HORSERACE_H
#define HORSERACE_H

class HorseRace
{
public:
    HorseRace();
    void run_horse_race();

private:
    int tie_breaker(int total_horses);
    void replay();
    int get_random_spaces();
    std::string build_racers_path();
    void check_outcome(int winning_horse);
    void animate_race();
    void instructions();
    void place_wager();
    void horse_race_menu();
};

#endif