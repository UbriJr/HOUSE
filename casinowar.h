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
    void WinOrLoseChecker(int pCard, int dCard);
    int randomCard();
    void cardBuilder(int card);
    void cardA();
    void cardTwo();
    void cardThree();
    void cardFour();
    void cardFive();
    void cardSix();
    void cardSeven();
    void cardEight();
    void cardNine();
    void cardTen();
    void cardJack();
    void cardQueen();
    void cardKing();
    std::string cardDealt(int number);
};

#endif