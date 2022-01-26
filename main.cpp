
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

int main(int argc, const char * argv[]) {
    
    // Introduction section (register, login, transfer)
    //Introduction IntroObj;
    //IntroObj.RunIntroduction();
    
    // Game section (games)
    GameRoom roomObj;
    roomObj.RunGameRoom();
    
}