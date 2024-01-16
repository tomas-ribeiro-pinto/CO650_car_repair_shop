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
    void display(Repair**& repairs, int& size, void (*returnToDashboard)());
    void inputOption();
    void chooseOption(char& choice);
    void add(Repair**& repairs, int& size);
};