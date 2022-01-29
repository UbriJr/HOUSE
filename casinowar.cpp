#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "gameroom.h"
#include "introduction.h"
#include "casinowar.h"

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
    Introduction tokenObj;
    int availableTokens = tokenObj.getTokens();
    int wager;
    int playersCard;
    std::string pCard;
    int dealersCard;
    std::string dCard;
    std::string Show;

    std::cout << "\n                                  CASINO WAR\n";
    std::cout << "\n          PLEASE ENTER THE NUMBER OF TOKENS YOU WOULD LIKE TO WAGER: ";
    std::cin >> wager;
    std::cout << "\n                              YOU WAGERED " << wager << " TOKENS \n";

    playersCard = randomCard();
    pCard = cardDealt(playersCard);

    cardBuilder(playersCard);

    std::cout << "\n                                  YOUR CARD: " << pCard << "\n";

    std::cout << "\n\n\n\n\n                TYPE SHOW OR 1 WHEN READY TO SHOW DEALERS CARD: ";
    std::cin >> Show;

    dealersCard = randomCard();
    std::cout << "\n                              DEALERS CARD: " << dealersCard << std::endl;
    WinOrLoseChecker(playersCard, dealersCard);
}

// instructions for casino war
void CasinoWar::CasinoWarInstructions()
{
    system("clear");
    int userInput;
    std::string instructMessage = "\n\n\n                                  CASINO WAR\n\n -THE PLAYER AND THE DEALER ARE EACH DEALT ONE CARD.\n -IF THE PLAYER'S CARD IS HIGHER THEN THE DEALER, HE WINS THE WAGER THEY BET.\n -OTHERWISE THE PLAYER LOSES.\n -A TIE OCCURS WHEN THE PLAYER AND THE DEALER EACH HAVE CARDS OF THE SAME RANK.\n -THE PLAYER AND DEALER ARE DEALT ANOTHER CARD TO DETERMINE THE WINNER.\n";
    std::string cardRanks = "\n             CARD RANKS (IN ORDER FROM THE HIGHEST TO LOWEST):\n             ACE, KING, QUEEN, JACK, 10, 9, 8, 7, 6, 5, 4, 3, 2 \n";

    std::cout << instructMessage;
    std::cout << cardRanks << std::endl;

    std::cout << "\n\n                          1: PLAY CASINO WAR";
    std::cout << "\n                          2: RETURN TO THE GAME FLOOR";
    std::cout << "\n                          PLEASE SELECT AN OPTION: ";
    std::cin >> userInput;

    InputValidation(userInput);
}
// random number generated, number corresponds to a card
int CasinoWar::randomCard()
{
    srand((unsigned int)time(NULL));
    int card = rand() % 13 + 1;
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
    std::cout << "\n                          WOULD YOU LIKE TO PLAY AGAIN?" << std::endl
              << "\n";
    std::cout << "                                1: PLAY AGAIN" << std::endl;
    std::cout << "                                2: RETURN TO GAMEROOM" << std::endl;
    std::cin >> userInput;

    InputValidation(userInput);
}

// checked if the player won or lost the wager. Takes in the players card and the dealers card, checking which is greater.
void CasinoWar::WinOrLoseChecker(int pCard, int dCard)
{
    if (pCard > dCard)
    {
        std::cout << "            THE PLAYER WON";
    }
    else if (pCard == dCard)
    {
        std::cout << "            THERE WAS A TIE";
    }
    else if (dCard > pCard)
    {
        std::cout << "            THE DEALER WON";
    }
    replay();
}
// thanks john wiech for the contribution
void CasinoWar::cardBuilder(int card)
{
    switch (card)
    {
    case 2:
        cardTwo();
        break;
    case 3:
        cardThree();
        break;
    case 4:
        cardFour();
        break;
    case 5:
        cardFive();
        break;
    case 6:
        cardSix();
        break;
    case 7:
        cardSeven();
        break;
    case 8:
        cardEight();
        break;
    case 9:
        cardNine();
        break;
    case 10:
        cardTen();
        break;
    case 11:
        cardJack();
        break;
    case 12:
        cardQueen();
        break;
    case 13:
        cardKing();
        break;
    case 14:
        cardA();
        break;

    default:
        std::cout << "Something went wrong" << std::endl;
    }
}

void CasinoWar::cardA()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |A      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |   *   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______A|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardTwo()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |2      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______2|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardThree()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |3      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______3|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardFour()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |4      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______4|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardFive()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |5      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______5|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardSix()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |6      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______6|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardSeven()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |7      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______7|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardEight()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |8      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______8|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardNine()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |9      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______9|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardTen()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |10     |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    | * * * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    | *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    | *   * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    | * * * |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |_____10|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardJack()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |J      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______J|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardQueen()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |Q      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______Q|" << std::endl;
    std::cout << "\n";
}

void CasinoWar::cardKing()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |K      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |       |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |______K|" << std::endl;

    std::cout << "\n";
}
