//
//  main.cpp
//  code
//
//  Created by Eddie Ubri on 12/20/21.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>

class IntroductionClass{
    
public:
    
    // run the introduction
    void RunIntroduction(){
        Welcome();
        RegisterOrLogin();
    }
    
    // returns the number of tokens the player has
    int getTokens(){
        std::stringstream ss;
        ss<<Tokens;
        ss>>covertedTokens;
        return covertedTokens;
    }
    
private:
    
    // the number of tokens the player has
    // this number comes from txt file.
    std::string Tokens;
    int covertedTokens; 
    
    // prints a welcome banner and adds space to clear terminal window
    void Welcome(){
        
        int time = 400;
        int VisualDelay = 500;
        // clear console
        system("clear");
        
        // welcome banner
        std::cout<<"\n";
        std::cout<<"\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(VisualDelay));
        std::cout<<"   ***       ***     *******     ***         ***   **********    ************"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ***       ***  ***       ***  ***         *** ***        ***  ****"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ***       *** ***         *** ***         *** *****           ****"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ************* ***         *** ***         ***      ****       **********"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ***       *** ***         *** ***         ***           ***** ****"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ***       ***  ***       ***  ****       **** ***        ***  ****"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
        std::cout<<"   ***       ***     *******       ***********     **********    ************"<<std::endl;
        std::cout<<"\n";
        std::cout<<"\n";
        std::cout<<"\n";
    }
    
    // Validates user's input
    bool InputValidation(int userInput){
        
        // clear console
        system("clear");
        
        // Check if user even entered a digit
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"\nTHIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            return false;
        }
        
        // Check if digit is one of the available options
        if(userInput == (1) || userInput == (2)){
            return true;
        }else{
            std::cout<<"\nTHIS TIME, PLEASE ENTER A VALID RESPONSE!\n";
            return false;
        }
    }
    
    // called if the user wants to login
    void login(){
        
        // spacer
        system("clear");
        
        std::string username;
        std::string password;
        std::string CurrentLine;
        std::string NextLine;
        //std::string Tokens;
        
        std::string pleaseWait = "PLEASE WAIT WHILE WE BRING YOU TO THE GAME FLOOR\n";
        
        int WaitTime = 5000;
        
        bool InfoFound = false;
        
        std::cout<<"\nENTER YOUR USERNAME: ";
        std::cin>>username;
        std::cout<<"ENTER YOUR PASSWORD: ";
        std::cin>>password;
        
        std::ifstream readFile("data.txt");
        
        while(getline(readFile,CurrentLine)){
            
            getline(readFile,NextLine);
            getline(readFile,Tokens);
            
            if((username == CurrentLine) && (password == NextLine)){
                system("clear");
                std::cout<<"\nLOGIN SUCCESSFUL\n";
                std::cout<<"YOU HAVE "<<Tokens<<" TOKENS\n";
                std::cout<<pleaseWait;
                std::this_thread::sleep_for(std::chrono::milliseconds(WaitTime));
                
                InfoFound = true;
            }
            std::cout<<"\n";
        }
        readFile.close();
        
        if(!InfoFound){
            system("clear");
            std::cout<<"COULD NOT FIND AN ACCOUNT WITH THE GIVEN USERNAME AND PASSWORD. PLEASE REGISTER OR TRY TO LOGIN AGAIN"<< std::endl;
            RegisterOrLogin();
        }
    }
    
    // called if the user does not have a login and wants to register
    void reg(){
        system("clear");
        std::string username;
        std::string password;
        int InitTokens = 10;
        
        std::fstream dataFile;
        dataFile.open("data.txt",std::ios::out);
        
        std::cout<<"\nCREATE A USERNAME: ";
        std::cin>>username;
        std::cout<<"CREATE A PASSWORD: ";
        std::cin>>password;
        system("clear");
        std::cout<<"\nREGISTRATION COMPLETE. LOGIN TO CONTINUE \n";
        std::cout<<"\n";
        
        dataFile << username << std::endl;
        dataFile << password << std::endl;
        dataFile << InitTokens << std::endl;
        
        dataFile.close();
        
        RegisterOrLogin();
    }
    
    // direct input to either register or login method
    void InputControlFlow(int userInput){
        int LoginOption = 1;
        int RegisterOption = 2;
        
        if(userInput == (LoginOption)){
            login();
        } else if(userInput == (RegisterOption)){
            reg();
        }
    }
    
    // prompts user to register or login
    void RegisterOrLogin(){
        bool isValid;
        int userInput;
        
        do {
        std::cout << "1: LOGIN \n";
        std::cout << "2: REGISTER \n";
        std::cout << "SELECT AN OPTION: ";
        std::cin >> userInput;
        isValid = InputValidation(userInput);
        } while (!isValid);
        
        InputControlFlow(userInput);
    }
};

class GameRoom{
    
public:
    // runs game room section
    void RunGameRoom(){
        Welcome();
    }
    
private:
    // welcomes player to the game floor
    void Welcome(){
        system("clear");
        int TextTime = 125; // was 125
        int ClearWaitTime = 3000; // was 3000
        std::string welcomeText = "\n           WELCOME TO THE GAME FLOOR \nTHIS IS WHERE ALL THE GAMES ARE HELD \nHAVE FUN AND RELAX, BUT REMEMBER, THE HOUSE ALWAYS WINS.\n";
        unsigned long length = welcomeText.length();
        
        for(int i = 0; i < length; i++){
            std::cout<<welcomeText[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(TextTime));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(ClearWaitTime));
        GameOptions();
    }

    void GameOptions(){
        system("clear");
        bool isValid;
        int userInput;
        std::cout<<"                \nGAME ROOM\n";
        do {
            std::cout << "1: CASINO WAR \n";
            std::cout << "2: GAME 2 \n";
            std::cout << "3: GAME 3 \n";
            std::cout << "SELECT AN OPTION: ";
            std::cin >> userInput;
            isValid = InputValidation(userInput);
        } while (!isValid);
        InputControlFlow(userInput);
    }
    
    // validates user selected a valid option (for a game only)
    bool InputValidation(int userInput){
        
        // clear console
        system("clear");
        
        // Check if user even entered a digit
        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"\nTHIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            return false;
        }
        
        // Check if digit is one of the available options
        if(userInput == (1) || userInput == (2) || userInput == (3)){
            return true;
        }else{
            std::cout<<"\nTHIS TIME, PLEASE ENTER A VALID RESPONSE\n";
            return false;
        }
    }
    
    // once a valid input is given game branches to the correct game
    void InputControlFlow(int userInput){
        int GameOneOption = 1;
        int GameTwoOption = 2;
        int GameThreeOption = 3;
        
        if(userInput == (GameOneOption)){
            //std::cout<<"GameOne\n";
            CasinoWarSelection();
        } else if(userInput == (GameTwoOption)){
            std::cout<<"GameTwo\n";
            //GameTwo();
        } else if(userInput == GameThreeOption){
            std::cout<<"GameThree\n";
            //GameThree();
        }
    }
    // prompts user to go to game rules or the actual game (for CasinoWar only)
    void CasinoWarSelection(){
        int instructions = 1;
        int play = 2;
        int userInput; 

        system("clear");
        std::cout<<"\n                  CASINO WAR\n"<<std::endl;
        std::cout<<"1: HOW TO PLAY CASINO WAR"<<std::endl;
        std::cout<<"2: PLAY CASINO WAR"<<std::endl; 
        std::cout<<"PLEASE SELECT AN OPTION: ";
        std::cin>>userInput;

        if(userInput == (instructions)){
            CasinoWarInstructions();
        }
        else if(userInput == (play)){
            CasinoWarPlay();
        }
    }

    // the method that plays the casino war game
    void CasinoWarPlay(){

        system("clear");
        IntroductionClass tokenObj;
        int availableTokens = tokenObj.getTokens();
        int wager; 
        int playersCard;
        std::string pCard;
        int dealersCard;
        std::string dCard;
        std::string Show;

        std::cout<<"\n                                  CASINO WAR\n";
        std::cout<<"\n          PLEASE ENTER THE NUMBER OF TOKENS YOU WOULD LIKE TO WAGER: ";
        std::cin>>wager;
        std::cout<<"\n                              YOU WAGERED "<<wager<<" TOKENS \n";

        playersCard = randomCard();
        pCard = cardDealt(playersCard);

        std::cout<<"\n                                  YOUR CARD: "<<pCard<<"\n";
        std::cout<<"\nTYPE SHOW OR 1 WHEN READY TO SHOW DEALERS CARD: ";
        std::cin>>Show;

        dealersCard = randomCard();
        std::cout<<"\n Dealers Card: "<<dealersCard<<std::endl;
    }

    // instructions for casino war
    void CasinoWarInstructions(){
        system("clear");
        std::string instructMessage = "\n                                 CASINO WAR\n\n-THE PLAYER AND THE DEALER ARE EACH DEALT ONE CARD.\n-IF THE PLAYER'S CARD IS HIGHER THEN THE DEALER, HE WINS THE WAGER THEY BET.\n-OTHERWISE THE PLAYER LOSES.\n-A TIE OCCURS WHEN THE PLAYER AND THE DEALER EACH HAVE CARDS OF THE SAME RANK.\n-THE PLAYER AND DEALER ARE DEALT ANOTHER CARD TO DETERMINE THE WINNER.\n";
        std::string cardRanks = "\n             CARD RANKS (IN ORDER FROM THE HIGHEST TO LOWEST):\n           ACE, KING, QUEEN, JACK, 10, 9, 8, 7, 6, 5, 4, 3, 2 \n";

        std::cout<<instructMessage;
        std::cout<<cardRanks<<std::endl;
    }

    int randomCard(){
        srand((unsigned int) time(NULL));
        int card = rand() % 13 + 1;
        //int card = rand() % 4 + 11;
        return card;
    }

    std::string cardDealt(int number){
        std::string result;

        if(number == (14)){
            result = "ACE";
        }else if(number == (13)){
            result = "KING";
        }else if(number == (12)){
            result = "QUEEN";
        }else if(number == (11)){
            result = "JACK";
        }else {
            result = std::to_string(number);
        }
        return result; 
    }
};


int main(int argc, const char * argv[]) {
    
    // Introduction section (register, login, transfer)
    //IntroductionClass IntroObj;
    //IntroObj.RunIntroduction();
    
    // Game section (games)
    GameRoom roomObj;
    roomObj.RunGameRoom();
    
    //return 0;
}

