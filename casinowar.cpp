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
    int wager;
    int playersCard;
    std::string pCard;
    int dealersCard;
    std::string dCard;
    std::string Show;
    std::string playerSpacing = "                                               ";
    std::string dealerSpacing = "                         ";

    std::cout << "\n\n\n\n\n\n\n\n                                  CASINO WAR";
    std::cout << "\n\n                                WAGER AMOUNT: ";
    std::cin >> wager;
    std::cout << "\n                              YOU WAGERED " << wager << " TOKENS \n";

    dealersCard = randomCard();
    dCard = cardDealt(dealersCard);

    std::cout << "\n\n\n                           TYPE TO SHOW DEALERS CARD: ";
    std::cin >> Show;
    system("clear");

    std::cout << "\n                       DEALERS CARD " << std::endl;
    cardBuilder(dealersCard, dealerSpacing);

    playersCard = randomCard();
    pCard = cardDealt(playersCard);
    std::cout << "\n                                               YOUR CARD " << std::endl;
    cardBuilder(playersCard, playerSpacing);

    //WinOrLoseChecker(playersCard, dealersCard);
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
void CasinoWar::cardBuilder(int card, std::string spacing)
{
    switch (card)
    {
    case 1:
        cardA(spacing);
        break;
    case 2:
        cardTwo(spacing);
        break;
    case 3:
        cardThree(spacing);
        break;
    case 4:
        cardFour(spacing);
        break;
    case 5:
        cardFive(spacing);
        break;
    case 6:
        cardSix(spacing);
        break;
    case 7:
        cardSeven(spacing);
        break;
    case 8:
        cardEight(spacing);
        break;
    case 9:
        cardNine(spacing);
        break;
    case 10:
        cardTen(spacing);
        break;
    case 11:
        cardJack(spacing);
        break;
    case 12:
        cardQueen(spacing);
        break;
    case 13:
        cardKing(spacing);
        break;
    default:
        std::cout << "Something went wrong" << std::endl;
        std::cout << card;
    }
}

void CasinoWar::cardA(std::string spacing)
{
    int time = 500;
    std::string playerSpacing = "                                     ";
    std::string dealerSpacing = "           ";

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

void CasinoWar::cardTwo(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardThree(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardFour(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardFive(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardSix(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardSeven(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardEight(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardNine(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardTen(std::string spacing)
{
    int time = 500;

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

void CasinoWar::cardJack(std::string spacing)
{
    int time = 500;

    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|J      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   J   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   A   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   C   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   K   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______J|" << std::endl;
}

void CasinoWar::cardQueen(std::string spacing)
{
    int time = 500;

    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|Q  Q   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   U   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   E   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   E   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   N   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______Q|" << std::endl;
}

void CasinoWar::cardKing(std::string spacing)
{
    int time = 500;

    std::cout << spacing << " _______" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|K      |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   K   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   I   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   N   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|   G   |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << spacing << "|______K|" << std::endl;
}
