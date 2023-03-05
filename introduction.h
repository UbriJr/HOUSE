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
    void welcome();
    bool input_validation(int users_input);
    void login();
    void reg();
    void direct_control_flow(int users_input);
    void register_or_login();
    void spacing_buffer(int spaces);
};

#endif