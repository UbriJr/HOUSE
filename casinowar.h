#ifndef CASINOWAR_H
#define CASINOWAR_H

class CasinoWar
{
public:
    CasinoWar();
    void runCasinoWar();

private:
    void InputValidation(int userInput);
    void CasinoWarSelection();
    void CasinoWarPlay();
    void CasinoWarInstructions();
    void replay();
    void ShowDealtCards();
    void WinOrLoseChecker(int pCard, int dCard);
    int randomCard();
    void WagerChecker(int wager);
    void cardBuilder(int card, std::string spacing);
    std::string cardDealt(int number);
};

#endif