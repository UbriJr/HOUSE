
//
//  Created by Eddie Ubri on 12/20/21.
//

// Includes
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "gameroom.h"
#include "introduction.h"

// remove after testing
#include "casinowar.h"

int main(int argc, const char *argv[])
{
    //Introduction IntroObj;
    //IntroObj.RunIntroduction();

    //GameRoom roomObj;
    //roomObj.RunGameRoom();

    CasinoWar TestObj;
    TestObj.runCasinoWar();

    /*
    while (true)
    {
        srand((unsigned int)time(NULL));
        int card = rand() % 13 + 1;
        std::cout << card << std::endl;
    }
    */
}