#ifndef HORSERACE_H
#define HORSERACE_H

class HorseRace
{
public:
    HorseRace();
    void RunHorseRace();

private:
    void leaveInstructions(int userInput);
    void race();
    void instructions();
    void wager();
    void HorseRaceSelection();
};

#endif