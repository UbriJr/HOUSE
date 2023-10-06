#ifndef REVIVE_H
#define REVIVE_H

class Revive
{

public:
    Revive();
    void Explanation();

private:
    std::string generateEquation();
    int equation_solver(const std::string& equation);
    std::string RandomNumber();
    std::string generateSign();
    bool answerChecker(int userAnswer, int correctAnswer);
};

#endif