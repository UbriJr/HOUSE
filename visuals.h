#ifndef VISUALS_H
#define VISUALS_H

class Visuals
{
public:
    Visuals();

private:
    friend class CasinoWar;
    friend class HorseRace;
    void standardHorse();
    void cardA(std::string spacing);
    void cardTwo(std::string spacing);
    void cardThree(std::string spacing);
    void cardFour(std::string spacing);
    void cardFive(std::string spacing);
    void cardSix(std::string spacing);
    void cardSeven(std::string spacing);
    void cardEight(std::string spacing);
    void cardNine(std::string spacing);
    void cardTen(std::string spacing);
    void cardJack(std::string spacing);
    void cardQueen(std::string spacing);
    void cardKing(std::string spacing);
};

#endif