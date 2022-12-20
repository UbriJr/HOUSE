#ifndef REVIVE_H
#define REVIVE_H

class Revive
{

public:
    Revive();
    void Explanation();

private:
    int RandomNumber();
    char generateSign();
    bool answerChecker(int x, int y, int z, char firstSign, char secondSign, int userAnswer);
};

#endif