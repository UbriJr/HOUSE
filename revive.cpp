#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <regex>
#include <random>
#include <stdio.h>
#include "tinyexpr.h"
#include "introduction.h"
#include "revive.h"

Revive::Revive(){

};

// Dialgue and explanation
void Revive::Explanation()
{
    // time delay for the dialog
    int timeDelay = 1000;

    // random numbers that make up the equation
    int x = RandomNumber();
    int y = RandomNumber();
    int z = RandomNumber();
    int userAnswer;

    // random sign (+ or -)
    char firstSign = generateSign();
    char secondSign = generateSign();

    // clear the console
    system("clear");

    // print dialog to the console
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
    std::cout << "                  IT LOOKS LIKE YOU HAVE RUN OUT OF TOKENS" << std::endl;
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
    std::cout << "                     SOLVE THIS PROBLEM TO GET 3 TOKENS" << std::endl;
    std::cout << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
    std::cout << "                              " << x << " " << firstSign << " " << y << " " << secondSign << " " << z << " = ?";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "                               YOUR ANSWER: ";
    std::cin >> userAnswer;

    // pass in the vars that make up the equation and the users answer
    answerChecker(x, y, x, firstSign, secondSign, userAnswer);
}

// This function generates a random number, this is later used for the equations
int Revive::RandomNumber()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);
    int number = dist6(rng);
    return number;
}

// radnomly generates plus or minus signs for the equation
char Revive::generateSign()
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 1);
    int number = dist6(rng);
    char sign;

    if (number == 0)
    {
        sign = '-';
        return (sign);
    }

    sign = '+';
    return (sign);
}

// validates user's answer, returns true if valide and correct, false otherwise
bool Revive::answerChecker(int x, int y, int z, char firstSign, char secondSign, int userAnswer)
{

    // clear console
    system("clear");

    // time delay
    int time = 3000;

    // temp var used for conversion
    std::string tmp = std::to_string(x) + std::to_string(firstSign);

    std::cout << tmp << std::endl;

    // extra tokens earned for solving the equation
    int extraTokens = 3;

    // answer to the original equation  **** TO DO ******
    int trueAnswer;

    std::cout << trueAnswer;
    std::this_thread::sleep_for(std::chrono::milliseconds(time * 2));

    // Check if user even entered a digit
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "                   THIS TIME, PLEASE ENTER A VALID RESPONSE\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }

    // Introduction revivalTokensObj;
    // revivalTokensObj.setTokens(extraTokens);
}