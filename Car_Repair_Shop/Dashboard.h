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
    Vehicle** vehicles;
    int vSize;
    Repair** repairs;
    int rSize;

    // create a pointer to a function that returns void
    void (*returnToDashboard)();
    static void promptToDashboard();

    char option;
    Dashboard();
    ~Dashboard();
    void display();
    void inputOption();
    void chooseOption(char& option);
};