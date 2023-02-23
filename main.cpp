
//
//  Created by Eddie Ubri on 12/20/21.
//

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
#include "horserace.h"
#include "revive.h"
#include <random>

int main(int argc, const char *argv[])
{
    // This will kick off the first panel, thus starting the entire program.
    // Introduction IntroObj;
    // IntroObj.RunIntroduction();

    // Revive rObj;
    // rObj.Explanation();

    // For Testing one panel at a time
    // CasinoWar TestObj;
    // TestObj.runCasinoWar();

    HorseRace testrace;
    testrace.RunHorseRace();
}