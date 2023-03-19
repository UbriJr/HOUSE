#ifndef VISUALS_H
#define VISUALS_H

class Visuals
{
public:
    Visuals();

private:
    friend class CasinoWar;
    friend class HorseRace;
    void ascii_horse();
    void a_card(const std::string &spacing);
    void two_card(const std::string &spacing);
    void three_card(const std::string &spacing);
    void four_card(const std::string &spacing);
    void five_card(const std::string &spacing);
    void six_card(const std::string &spacing);
    void seven_card(const std::string &spacing);
    void eight_card(const std::string &spacing);
    void nine_card(const std::string &spacing);
    void ten_card(const std::string &spacing);
    void jack_card(const std::string &spacing);
    void queen_card(const std::string &spacing);
    void king_card(const std::string &spacing);
};

#endif