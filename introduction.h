#ifndef INTRODUCTION_H
#define INTRODUCTION_H

class Introduction{

    public:
        Introduction();
        void RunIntroduction();
        int getTokens();
    private:
        std::string Tokens;
        int covertedTokens; 
        
        void Welcome();
        bool InputValidation(int userInput);
        void login();
        void reg();
        void InputControlFlow(int userInput);
        void RegisterOrLogin();
        void spacingBuffer(int spaces);
};

#endif