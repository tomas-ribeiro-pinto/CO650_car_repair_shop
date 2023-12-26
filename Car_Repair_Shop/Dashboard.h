#pragma once
#include <string>
#include <iostream>
#include "RegisterVehicle.h"

using namespace std;

struct Dashboard
{
    char option;
    Dashboard();
    ~Dashboard();
    void display();
    void inputOption();
    void chooseOption(char &option);
};

Dashboard::Dashboard()
{
    this->option = '0';
}

Dashboard::~Dashboard()
{
}

void Dashboard::display()
{
    while (option != '8')
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
}

void Dashboard::inputOption()
{
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseOption(option);
}

void Dashboard::chooseOption(char &option)
{
    switch (option)
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