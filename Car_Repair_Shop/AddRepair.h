#pragma once
#include <string>
#include <iostream>
#include "Car.h"
#include "Date.h"
#include "Repair.h"

using namespace std;

class AddRepair
{
private:
    string plate;
    string employee;
    Date dateIssued;
    string repairDescription;
    bool isRepaired;
    double cost;

public:
    AddRepair();
    ~AddRepair();
    void display(Repair **&repairs, int &size, void (*returnToDashboard)());
    void inputOption();
    void chooseOption(char &choice);
    void add(Repair **&repairs, int &size);
};

AddRepair::AddRepair()
{
}

AddRepair::~AddRepair()
{
}

void AddRepair::display(Repair **&repairs, int &size, void (*returnToDashboard)())
{
    cout << "\n\nADD REPAIR" << endl;
    cout << "********************\n"
         << endl;
    cout << "Insert the vehicle plate: " << endl;
    cin >> this->plate;
    cout << "Insert employee name: " << endl;
    cin >> this->employee;
    cout << "Insert date of repair: " << endl;
    this->dateIssued = inputDate();
    cout << "Insert the repair description:" << endl;
    cin.ignore();
    getline(cin, this->repairDescription);
    cout << "\nInsert the repair status: " << endl;
    cout << "1 - IN PROGRESS" << endl;
    cout << "2 - REPAIRED" << endl;
    inputOption();
    cout << "Insert the repair cost: " << endl;
    cin >> this->cost;

    // add vehicle to vehicles array
    add(repairs, size);

    returnToDashboard();
}

void AddRepair::inputOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseOption(option);
}

void AddRepair::chooseOption(char &choice)
{
    switch (choice)
    {
    case '1':
    {
        this->isRepaired = false;
        break;
    }
    case '2':
    {
        this->isRepaired = true;
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputOption();
    }
    }
}

void AddRepair::add(Repair **&repairs, int &size)
{
    Repair **temp = new Repair *[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = repairs[i];
    }

    Repair *repair = new Repair(this->plate, this->employee, this->dateIssued, this->repairDescription, this->isRepaired, this->cost);
    temp[size] = repair;
    size++;

    delete[] repairs;
    repairs = temp;

    cout << "\n\nREPAIR ADDED!" << endl;
    repair->displayRepairDescription();
}