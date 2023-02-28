#ifndef HORSERACE_H
#define HORSERACE_H

class HorseRace
{
public:
    HorseRace();
    void RunHorseRace();

private:
    int RandomHorseWinner(int totalHorses);
    void replay();
    int HorseRunSpaces();
    std::string buildRunner();
    void winChecker(int winningHorse);
    void race();
    void instructions();
    void wager();
    void HorseRaceSelection();
};

#endif