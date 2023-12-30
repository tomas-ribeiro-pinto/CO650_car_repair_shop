#pragma once
#include <string>
#include <iostream>
#include "RegisterVehicle.h"
#include "Repair.h"
#include "AddRepair.h"

using namespace std;

struct Dashboard
{
    // create a pointer to array of vehicles
    Vehicle **vehicles;
    int vSize;
    Repair **repairs;
    int rSize;

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
    this->vSize = 1;
    this->rSize = 1;

    vehicles = new Vehicle *[vSize];
    vehicles[0] = new Car("ABC123", "John Doe", Date(01, 01, 2020), "Red", PETROL);

    repairs = new Repair *[rSize];
    repairs[0] = new Repair("ABC123", "Mark Sanderson", Date(27, 01, 2020), "Front Wheels to be replaced", true, 340.65);
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
        cout << "3. Add repair" << endl;
        cout << "4. Display all repairs" << endl;
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
        registerVehicle->display(vehicles, vSize);
        break;
    }
    case '2':
    {
        cout << "All vehicles" << endl;
        cout << "********************\n"
             << endl;
        cout << "Total vehicles: " << vSize << endl;
        cout << endl;
        cout << "********************\n"
             << endl;
        cout << "Plate      | Owner" << endl;
        cout << "===================" << endl;
        for (int i = 0; i < vSize; i++)
        {
            cout << vehicles[i]->getPlate() << "        " << vehicles[i]->getOwner() << endl;
        }

        // return to dashboard
        cout << "\n\nPress any key to return to the dashboard..." << endl;
        cin.get();
        cin.ignore();
        break;
    }
    case '3':
    {
        AddRepair *addRepair = new AddRepair();
        addRepair->display(repairs, rSize);
        break;
    }
    case '4':
    {
        cout << "\n\nAll Repairs: \n\n"
             << endl;

        for (int i = 0; i < rSize; i++)
        {
            repairs[i]->displayRepairDescription();
            cout << endl;
        }

        // return to dashboard
        cout << "\n\nPress any key to return to the dashboard..." << endl;
        cin.get();
        cin.ignore();
        break;
    }
    case '5':
    {
        cout << "Pay repair bill" << endl;
        break;
    }
    case '6':
    {
        cout << "Display all bills" << endl;

        break;
    }
    case '7':
    {
        string searchPlate;
        cout << "Display outsanding bills by plate" << endl;
        cout << "Insert plate number:" << endl;
        cin.ignore();
        getline(cin, searchPlate);
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