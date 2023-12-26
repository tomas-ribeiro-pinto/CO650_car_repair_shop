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

Login::Login()
{
    resetInput();
    this->currentUser = "";
}

Login::~Login()
{
}

// Displays Login Screen while Login is not validated
void Login::display()
{
    while (!validateLogin())
    {
        cout << "CAR REPAIR SHOP" << endl;
        cout << "LOGIN" << endl;
        cout << "********************\n"
             << endl;
        cout << "Insert your Username: " << endl;
        cin >> this->username;
        cout << "Insert your Password: " << endl;
        cin >> this->password;
    }
}

// Validates Login against inputed username and password
bool Login::validateLogin()
{
    if (this->username != "" || this->password != "")
    {
        if (this->username == "admin" && this->password == "admin")
        {
            cout << "\n*** Login Successful! ***\n"
                 << endl;
            this->currentUser = this->username;
            resetInput();
            return true;
        }
        else
        {
            cout << "\n**!! Login Failed! **!!\n"
                 << endl;
            resetInput();
            return false;
        }
    }
    return false;
}

void Login::resetInput()
{
    this->username = "";
    this->password = "";
}