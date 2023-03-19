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

void Visuals::ascii_horse()
{
    std::cout << "              ,--," << std::endl;
    std::cout << "        _ ___/ /\\|" << std::endl;
    std::cout << "       ;( )__, )" << std::endl;
    std::cout << "      ; //   '--;" << std::endl;
    std::cout << "        \\      |" << std::endl;
    std::cout << "        ^     ^" << std::endl;
}

void Visuals::a_card(const std::string &spacing)
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

void Visuals::two_card(const std::string &spacing)
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

void Visuals::three_card(const std::string &spacing)
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

void Visuals::four_card(const std::string &spacing)
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

void Visuals::five_card(const std::string &spacing)
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

void Visuals::six_card(const std::string &spacing)
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

void Visuals::seven_card(const std::string &spacing)
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

void Visuals::eight_card(const std::string &spacing)
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

void Visuals::nine_card(const std::string &spacing)
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

void Visuals::ten_card(const std::string &spacing)
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

void Visuals::jack_card(const std::string &spacing)
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

void Visuals::queen_card(const std::string &spacing)
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

void Visuals::king_card(const std::string &spacing)
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
