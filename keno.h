#ifndef KENO_H
#define KENO_H

class Keno
{
public:
    Keno(); 
    void run_keno();

private:
    void keno_instructions();
    void keno_menu();
    void play_keno();
    bool validate_input(int users_input);
};

#endif