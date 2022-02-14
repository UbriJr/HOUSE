#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include <random>
#include "gameroom.h"
#include "introduction.h"
#include "casinowar.h"
#include "visuals.h"

CasinoWar::CasinoWar(){

};

void CasinoWar::runCasinoWar()
{
    CasinoWarSelection();
}

void CasinoWar::InputValidation(int userInput)
{

    if (userInput == (1))
    {
        CasinoWarPlay();
    }
    else if (userInput == (2))
    {
        GameRoom GameRoomObj;
        GameRoomObj.ReturnToGameOptions();
    }
    else
    {
        std::cout << "\nTHIS TIME, PLEASE ENTER A VALID RESPONSE\n";
    }
}

void CasinoWar::CasinoWarSelection()
{
    int instructions = 1;
    int play = 2;
    int userInput;

    system("clear");
    std::cout << "\n\n\n\n\n\n\n                                 CASINO WAR\n"
              << std::endl;
    std::cout << "                          1: HOW TO PLAY CASINO WAR" << std::endl;
    std::cout << "                          2: PLAY CASINO WAR" << std::endl;
    std::cout << "\n                          PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    if (userInput == (instructions))
    {
        CasinoWarInstructions();
    }
    else if (userInput == (play))
    {
        CasinoWarPlay();
    }
}

// the method that plays the casino war game
void CasinoWar::CasinoWarPlay()
{
    system("clear");
    int wager;
    std::string key;

    std::cout << "\n\n\n\n\n\n                                  CASINO WAR";
    std::cout << "\n\n                                WAGER AMOUNT: ";
    std::cin >> wager;
    std::cout << "\n                              YOU WAGERED " << wager << " TOKENS \n";

    std::cout << "\n\n\n                           ENTER ANY KEY TO CONTINUE: ";
    std::cin >> key;

    ShowDealtCards();
}

// instructions for casino war
void CasinoWar::CasinoWarInstructions()
{
    system("clear");
    int userInput;
    std::string instructMessage = "\n\n\n                                  CASINO WAR\n\n -THE PLAYER AND THE DEALER ARE EACH DEALT ONE CARD.\n -IF THE PLAYER'S CARD IS HIGHER THEN THE DEALER'S,\n -THE PLAYER WINS TWICE THE WAGERED AMOUNT.\n -OTHERWISE THE PLAYER LOSES THE WAGERED AMOUNT.\n -A TIE OCCURS WHEN THE PLAYER AND THE DEALER EACH HAVE CARDS OF THE SAME RANK.\n -THE PLAYER AND DEALER ARE DEALT ANOTHER CARD TO DETERMINE THE WINNER.\n";
    std::string cardRanks = "\n             CARD RANKS (IN ORDER FROM THE HIGHEST TO LOWEST):\n             ACE, KING, QUEEN, JACK, 10, 9, 8, 7, 6, 5, 4, 3, 2 \n";

    std::cout << instructMessage;
    std::cout << cardRanks << std::endl;

    std::cout << "\n\n                          1: PLAY CASINO WAR";
    std::cout << "\n                          2: RETURN TO THE GAME FLOOR\n";
    std::cout << "\n                          PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    InputValidation(userInput);
}

// random number generated, number corresponds to a card
int CasinoWar::randomCard()
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(2, 14);
    int card = dist6(rng);
    return card;
}

std::string CasinoWar::cardDealt(int number)
{
    std::string result;

    if (number == (14))
    {
        result = "ACE";
    }
    else if (number == (13))
    {
        result = "KING";
    }
    else if (number == (12))
    {
        result = "QUEEN";
    }
    else if (number == (11))
    {
        result = "JACK";
    }
    else
    {
        result = std::to_string(number);
    }
    return result;
}

void CasinoWar::replay()
{
    int userInput;

    system("clear");
    std::cout << "\n\n\n\n\n\n\n\n                          WOULD YOU LIKE TO PLAY AGAIN?" << std::endl
              << "\n";
    std::cout << "                               1: PLAY AGAIN" << std::endl;
    std::cout << "                               2: RETURN TO GAMEROOM" << std::endl;
    std::cout << "\n                             PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    InputValidation(userInput);
}

void CasinoWar::ShowDealtCards()
{
    int playersCard;
    std::string pCard;
    std::string dCard;
    int dealersCard;
    std::string playerSpacing = "                                               ";
    std::string dealerSpacing = "                          ";

    system("clear");

    dealersCard = randomCard();
    dCard = cardDealt(dealersCard);

    std::cout << "\n\n                         DEALERS CARD " << std::endl;
    cardBuilder(dealersCard, dealerSpacing);

    playersCard = randomCard();
    pCard = cardDealt(playersCard);

    std::cout << "\n                                               YOUR CARD " << std::endl;
    cardBuilder(playersCard, playerSpacing);

    WinOrLoseChecker(playersCard, dealersCard);
}

// checked if the player won or lost the wager. Takes in the players card and the dealers card, checking which is greater.
void CasinoWar::WinOrLoseChecker(int pCard, int dCard)
{
    int timeDelay = 7000;
    int outcomeTimer = 4000;
    //int wonAmount = (2*wager);
    //int lostAmount = wager;

    if (pCard > dCard)
    {
        std::cout << "\n                                    YOU WON" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(outcomeTimer));
    }
    else if (pCard == dCard)
    {
        std::cout << "\n                                THERE WAS A TIE" << std::endl;
        std::cout << "          EACH PLAYER WILL BE DEALT ANOTHER CARD TO DETERMINE THE WINNER" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(timeDelay));
        ShowDealtCards();
    }
    else if (dCard > pCard)
    {
        std::cout << "\n                                THE DEALER WON" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(outcomeTimer));
    }
    std::cout << "\n"
              << std::endl; // remove later

    replay();
}
// thanks john wiech for the contribution
void CasinoWar::cardBuilder(int card, std::string spacing)
{
    Visuals cards;

    switch (card)
    {
    case 2:
        cards.cardTwo(spacing);
        break;
    case 3:
        cards.cardThree(spacing);
        break;
    case 4:
        cards.cardFour(spacing);
        break;
    case 5:
        cards.cardFive(spacing);
        break;
    case 6:
        cards.cardSix(spacing);
        break;
    case 7:
        cards.cardSeven(spacing);
        break;
    case 8:
        cards.cardEight(spacing);
        break;
    case 9:
        cards.cardNine(spacing);
        break;
    case 10:
        cards.cardTen(spacing);
        break;
    case 11:
        cards.cardJack(spacing);
        break;
    case 12:
        cards.cardQueen(spacing);
        break;
    case 13:
        cards.cardKing(spacing);
        break;
    case 14:
        cards.cardA(spacing);
        break;
    default:
        std::cout << "Something went wrong" << std::endl;
    }
}
