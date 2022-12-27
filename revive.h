#ifndef REVIVE_H
#define REVIVE_H

class Revive
{

public:
    Revive();
    void Explanation();

private:
    std::string RandomNumber();
    std::string generateSign();
    bool answerChecker(int userAnswer, int correctAnswer);
    void trig_function();
};

#endif