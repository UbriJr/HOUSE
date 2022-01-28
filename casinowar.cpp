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
    std::cout << "                          PLEASE SELECT AN OPTION: ";
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

    displayA();

    std::cout << "\n                                  YOUR CARD: " << pCard << "\n";

    //displayA();

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
void CasinoWar::displayA()
{
    int time = 500;

    std::cout << "\n";
    std::cout << "                                     _____" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |A _  |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    | ( ) |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |(_'_)|" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |  |  |" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::cout << "                                    |____V|" << std::endl;
    std::cout << "\n";
}
