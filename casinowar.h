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
    void cardBuilder(int card, std::string spacing);
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
    std::string cardDealt(int number);
};

#endif