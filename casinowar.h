#ifndef CASINOWAR_H
#define CASINOWAR_H

class CasinoWar
{
public:
    CasinoWar();
    void runCasinoWar();

private:
    bool InputValidation(int userInput);
    void CasinoWarSelection();
    void CasinoWarPlay();
    void CasinoWarInstructions();
    void replay();
    void ShowDealtCards();
    void WinOrLoseChecker(int pCard, int dCard);
    int randomCard();
    bool WagerChecker(int wager);
    void cardBuilder(int card, std::string spacing);
};

#endif