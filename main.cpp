
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

int main(int argc, const char *argv[])
{
    // This will kick off the first panel, thus starting the entire program.
    Introduction introduction_obj;
    introduction_obj.run_introduction();
}