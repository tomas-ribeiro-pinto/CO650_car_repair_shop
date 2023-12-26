#pragma once
#include <string>
#include <iostream>
#include "RegisterVehicle.h"

using namespace std;

class Dashboard
{
public:
    Dashboard();
    ~Dashboard();
    void display();
    void inputOption();
    void chooseOption(char &choice);
};

Dashboard::Dashboard()
{
}

Dashboard::~Dashboard()
{
}

void Dashboard::display()
{
    cout << "CAR REPAIR SHOP" << endl;
    cout << "DASHBOARD" << endl;
    cout << "********************\n"
         << endl;
    cout << "1. Register a new vehicle for repair" << endl;
    cout << "2. Display all vehicles" << endl;
    cout << "3. Display all vehicles needing service" << endl;
    cout << "4. Add repair" << endl;
    cout << "5. Pay repair bill" << endl;
    cout << "6. Display all bills" << endl;
    cout << "7. Display outsanding bills by plate" << endl;
    cout << "8. Exit" << endl;

    inputOption();
}

void Dashboard::inputOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseOption(option);
}

void Dashboard::chooseOption(char &choice)
{
    switch (choice)
    {
    case '1':
    {
        RegisterVehicle *registerVehicle = new RegisterVehicle();
        registerVehicle->display();
        break;
    }
    case '2':
    {
        cout << "Display all vehicles" << endl;
        break;
    }
    case '3':
    {
        cout << "Display all vehicles by owner" << endl;
        break;
    }
    case '4':
    {
        cout << "Display all vehicles by fuel type" << endl;
        break;
    }
    case '5':
    {
        cout << "Display all vehicles by register date" << endl;
        break;
    }
    case '6':
    {
        cout << "Display all vehicles by color" << endl;
        break;
    }
    case '7':
    {
        cout << "Display all vehicles by color" << endl;
        break;
    }
    case '8':
    {
        cout << "Exiting..." << endl;
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputOption();
    }
    }
}