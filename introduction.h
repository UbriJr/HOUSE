#ifndef INTRODUCTION_H
#define INTRODUCTION_H

class Introduction
{

public:
    Introduction();
    void run_introduction();
    int get_tokens();
    void set_tokens(int tokens);

private:
    std::string encrypt(int tokens);
    int decrypt(std::string cipher);
    void welcome();
    bool validate_input(int users_input);
    void login();
    void reg();
    void direct_control_flow(int users_input);
    void register_or_login();
    void spacing_buffer(int spaces);
};

#endif