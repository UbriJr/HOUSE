#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <regex>
#include <random>
#include "introduction.h"
#include "revive.h"

Revive::Revive(){

};

// Dialgue and explanation
void Revive::Explanation()
{

    // time delay for the dialog
    int timeDelay = 1000;

    // users answer and the correct answer to the equation
    int userAnswer;
    int correctAnswer;

    // varaible to check if user answerwed correctly
    bool answeredCorrectly;

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

    do
    {
        // random numbers that make up the equation
        std::string equationString = generateEquation();

        std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
        std::cout << "                     SOLVE THIS PROBLEM TO GET 3 TOKENS" << std::endl;
        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
        std::cout << "                              " << equationString << " = ?";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "\n";
        std::cout << "                               YOUR ANSWER: ";
        std::cin >> userAnswer;

        // pass in the vars that make up the equation and the users answer
        answeredCorrectly = answerChecker(0, 9);

    } while (!answeredCorrectly);
}

// this function generates the equation using the other helper functions
std::string Revive::generateEquation()
{

    std::string stringRandomNumber = RandomNumber();

    stringRandomNumber.append(" ");
    stringRandomNumber.append(generateSign());
    stringRandomNumber.append(" ");
    stringRandomNumber.append(RandomNumber());

    stringRandomNumber.append(" ");
    stringRandomNumber.append(generateSign());
    stringRandomNumber.append(" ");
    stringRandomNumber.append(RandomNumber());

    return stringRandomNumber;
}

// This function generates a random number, this is later used for the equations
std::string Revive::RandomNumber()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);
    std::string number = std::to_string(dist6(rng));
    return number;
}

// radnomly generates plus or minus signs for the equation
std::string Revive::generateSign()
{

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 1);
    int number = dist6(rng);
    std::string sign;

    if (number == 0)
    {
        sign = "-";
        return (sign);
    }

    sign = "+";
    return (sign);
}

// validates user's answer, returns true if valide and correct, false otherwise
bool Revive::answerChecker(int userAnswer, int correctAnswer)
{
    // clear console
    system("clear");

    // time delay
    int time = 3000;

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
        std::cout << "                   THIS TIME, PLEASE ENTER A VALID RESPONSE\n\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        return false;
    }

    // if user answers currently add token to account and break out of loop
    if (userAnswer == correctAnswer)
    {
        // extra tokens earned for solving the equation
        int extraTokens = 3;

        std::cout << "\n\n\n\n\n\n\n            YOUR ANSWER WAS CORRECT, ADDING TOKENS TO YOUR ACCOUNT \n";
        std::this_thread::sleep_for(std::chrono::milliseconds(time - 1000));
        Introduction revivalTokensObj;
        revivalTokensObj.set_tokens(revivalTokensObj.get_tokens() + extraTokens);
        return true;
    }

    // if the user answers incorrectly, return false to restart the loop
    std::cout << "\n\n\n\n\n\n\n                    YOUR ANSWER WAS INCORRECT, PLEASE TRY AGAIN\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    return false;
}