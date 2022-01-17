#ifndef CASINOWAR_H
#define CASINOWAR_H

class CasinoWar{
    public: 
        CasinoWar();
        void runCasinoWar();
    private:
        void InputValidation(int userInput);
        void CasinoWarSelection();
        void CasinoWarPlay();
        void CasinoWarInstructions();
        int randomCard();
        std::string cardDealt(int number);
};

#endif