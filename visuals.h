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
    void cardA(const std::string &spacing);
    void cardTwo(const std::string &spacing);
    void cardThree(const std::string &spacing);
    void cardFour(const std::string &spacing);
    void cardFive(const std::string &spacing);
    void cardSix(const std::string &spacing);
    void cardSeven(const std::string &spacing);
    void cardEight(const std::string &spacing);
    void cardNine(const std::string &spacing);
    void cardTen(const std::string &spacing);
    void cardJack(const std::string &spacing);
    void cardQueen(const std::string &spacing);
    void cardKing(const std::string &spacing);
};

#endif