#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Repair.h"
#include "Bill.h"
#include "Car.h"

using namespace std;

// structure as all members are public
struct Dashboard
{
    // OBJECTIVE 9 - POINTERS
    // create a pointer to array of vehicles
    Vehicle** vehicles;
    int vSize;
    Repair** repairs;
    int rSize;
    Bill** bills;
    int bSize;

    // OBJECTIVE 10 - FUNCTIONAL POINTER
    // create a pointer to a function that returns void
    void (*returnToDashboard)();
    static void promptToDashboard();

    char option;
    Dashboard();
    ~Dashboard();
    void display();
    void inputOption();
    void chooseOption(char& option);
    void registerVehicle();
    void displayVehicles();
    void addRepair();
    void displayRepairs();
    void displayRepairByPlate();
    void payBill();
    void displayBill();
};