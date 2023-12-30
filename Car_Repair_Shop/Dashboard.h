#pragma once
#include <string>
#include <iostream>
#include "RegisterVehicle.h"
#include "Repair.h"
#include "AddRepair.h"
#include "Bill.h"

using namespace std;

struct Dashboard
{
    // create a pointer to array of vehicles
    Vehicle **vehicles;
    int vSize;
    Repair **repairs;
    int rSize;

    // create a pointer to a function that returns void
    void (*returnToDashboard)();
    static void promptToDashboard();

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

    // assigns the function pointer to the return to dashboard function
    returnToDashboard = &Dashboard::promptToDashboard;
}

Dashboard::~Dashboard()
{
}

void Dashboard::display()
{
    while (option != '8')
    {
        cout << "CAR REPAIR SHOP" << endl;
        cout << "********************\n"
             << endl;
        cout << "Vehicles registered for repair: " << Vehicle::vehicleCount << endl;
        cout << "********************\n"
             << endl;
        cout << "DASHBOARD" << endl;
        cout << "********************\n"
             << endl;
        cout << "1. Register a new vehicle for repair" << endl;
        cout << "2. Display all vehicles" << endl;
        cout << "3. Add repair" << endl;
        cout << "4. Display all repairs" << endl;
        cout << "5. Display repairs by plate" << endl;
        cout << "6. Pay repair bill" << endl;
        cout << "7. Display all bills" << endl;
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
        registerVehicle->display(vehicles, vSize, returnToDashboard);
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

        returnToDashboard();
        break;
    }
    case '3':
    {
        AddRepair *addRepair = new AddRepair();
        addRepair->display(repairs, rSize, returnToDashboard);
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

        returnToDashboard();
        break;
    }
    case '5':
    {
        string searchPlate;
        cout << "Display repairs by plate" << endl;
        cout << "Insert plate number:" << endl;
        cin.ignore();
        getline(cin, searchPlate);
        cout << "\n\nSearch results by:" << Repair::plateToUpperCase(searchPlate) << "\n\n"
             << endl;

        Repair **searchResults = Repair::searchRepairsByPlate(repairs, rSize, searchPlate);
        // search array size
        int sSize = Repair::getRepairSize(searchResults);

        for (int i = 0; i < sSize; i++)
        {
            searchResults[i]->displayRepairDescription();
            cout << endl;
        }

        returnToDashboard();
        break;
    }
    case '6':
    {
        string searchPlate;
        cout << "Pay repair bill" << endl;
        cout << "Insert plate number:" << endl;
        cin.ignore();
        getline(cin, searchPlate);

        Repair **searchResults = Repair::searchRepairsByPlate(repairs, rSize, searchPlate);
        // search array size
        int sSize = Repair::getRepairSize(searchResults);

        if (sSize == 0)
        {
            cout << "No repairs found for plate: " << searchPlate << endl;
        }
        else
        {
            cout << "Repairs with outstanding payment for: " << Repair::plateToUpperCase(searchPlate) << endl;
            int tCost = 0;
            cout << "Cost | Repair Description" << endl;
            for (int i = 0; i < sSize; i++)
            {
                cout << searchResults[i]->getCost() << " | " << searchResults[i]->getRepairDescription() << endl;
                cout << endl;

                // increase total cost
                tCost += searchResults[i]->getCost();
            }
            cout << "Total cost:" << tCost << endl;

            // pay bill
            cout << "Pay bill? (y/n)" << endl;
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                Bill *bill = new Bill(searchPlate, tCost, searchResults);
                bill->payBill();
            }
            else
            {
                cout << "Bill not paid!" << endl;
            }
        }

        returnToDashboard();
        break;
    }
    case '7':
    {
        string searchPlate;
        cout << "Display previous bills" << endl;
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

void Dashboard::promptToDashboard()
{
    cout << "\n\nPress any key to return to the dashboard..." << endl;
    cin.get();
    cin.ignore();
}