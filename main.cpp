
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
#include "keno.h"
#include "casinowar.h"
#include "horserace.h"
#include "revive.h"
#include <random>

int main(int argc, const char *argv[])
{
    // This will kick off the first panel, thus starting the entire program.
     Introduction introduction_obj;
     introduction_obj.run_introduction();

    //Keno keno;
    //keno.run_keno(); 

    //Revive rObj;
    //rObj.Explanation();

    // For Testing one panel at a time
    // CasinoWar TestObj;
    // TestObj.run_casino_war();

    // HorseRace testrace;
    // testrace.run_horse_race();
}