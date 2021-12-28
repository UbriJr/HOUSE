//
//  main.cpp
//  code
//
//  Created by Eddie Ubri on 12/20/21.
//

#include <iostream>
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
    
    // returns the number of tokens the player has (type string)
    std::string getTokens(){
        return Tokens;
    }
    
private:
    
    // the number of tokens the player has
    // this number comes from txt file.
    std::string Tokens;
    
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
        
        int WaitTime = 10000;
        
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
        int TextTime = 125;
        int ClearWaitTime = 1500;
        std::string welcomeText = "WELCOME TO THE GAME FLOOR \nTHIS IS WHERE ALL THE GAMES ARE HELD \nHAVE FUN AND RELAX, BUT REMEMBER, THE HOUSE ALWAYS WINS.\n";
        unsigned long length = welcomeText.length();
        
        for(int i = 0; i < length; i++){
            std::cout<<welcomeText[i];
            std::this_thread::sleep_for(std::chrono::milliseconds(TextTime));
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(ClearWaitTime));
        GameOptions();
    }
    
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
    
    // direct input to either register or login method
    void InputControlFlow(int userInput){
        int GameOne = 1;
        int GameTwo = 2;
        int GameThree = 3;
        
        if(userInput == (GameOne)){
            std::cout<<"GameOne\n";
            //GameOne();
        } else if(userInput == (GameTwo)){
            std::cout<<"GameTwo\n";
            //GameTwo();
        } else if(userInput == GameThree){
            std::cout<<"GameThree\n";
            //GameThree();
        }
    }
    
    void GameOne(){
        
    }
    
    void GameTwo(){
        
    }
    
    void GameThree(){
        
    }
    
    void GameOptions(){
        system("clear");
        bool isValid;
        int userInput;
        std::cout<<"                GAME ROOM\n";
        do {
            std::cout << "1: GAME 1 \n";
            std::cout << "2: GAME 2 \n";
            std::cout << "3: GAME 3 \n";
            std::cout << "SELECT AN OPTION: ";
            std::cin >> userInput;
            isValid = InputValidation(userInput);
        } while (!isValid);
        
        InputControlFlow(userInput);
    }
};


int main(int argc, const char * argv[]) {
    
    // Introduction section (register, login, transfer)
    IntroductionClass IntroObj;
    IntroObj.RunIntroduction();
    
    // Game section (games)
    //GameRoom roomObj;
    //roomObj.RunGameRoom();
    
    //return 0;
}

