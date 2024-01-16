#pragma once
#include <string>
#include <iostream>

using namespace std;

class Login
{
private:
    string username;
    string password;

public:
    string currentUser;

    Login();
    ~Login();
    void display();
    void resetInput();
    bool validateLogin();
};

