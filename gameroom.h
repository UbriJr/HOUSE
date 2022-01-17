#ifndef GAMEROOM_H 
#define GAMEROOM_H

class GameRoom{
    public: 
        GameRoom();
        void RunGameRoom();
        void ReturnToGameOptions();
    private:
        void Welcome();
        void GameOptions();
        bool InputValidation(int userInput);
        void InputControlFlow(int userInput);
};

#endif