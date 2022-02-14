#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "visuals.h"
#define time 450

Visuals::Visuals()
{
}

void Visuals::cardA(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|A      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   A   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______A|" << std::endl;
}

void Visuals::cardTwo(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|2      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______2|" << std::endl;
}

void Visuals::cardThree(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|3      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______3|" << std::endl;
}

void Visuals::cardFour(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|4      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______4|" << std::endl;
}

void Visuals::cardFive(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|5      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______5|" << std::endl;
}

void Visuals::cardSix(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|6      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______6|" << std::endl;
}

void Visuals::cardSeven(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|7      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______7|" << std::endl;
}

void Visuals::cardEight(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|8      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______8|" << std::endl;
}

void Visuals::cardNine(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|9      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| * * * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______9|" << std::endl;
}

void Visuals::cardTen(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|10     |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| * * * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "| * * * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|_____10|" << std::endl;
}

void Visuals::cardJack(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|J      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   J   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______J|" << std::endl;
}

void Visuals::cardQueen(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|Q      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   Q   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______Q|" << std::endl;
}

void Visuals::cardKing(std::string spacing)
{
    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|K      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   K   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______K|" << std::endl;
}
