#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

class Motorcyle : public Vehicle
{
public:
    Motorcyle(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType);
    ~Motorcyle();
    void displayDetails();
};

Motorcyle::Motorcyle(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType) : Vehicle(plate, owner, registerDate, color, fuelType)
{
}

Motorcyle::~Motorcyle()
{
}

void Motorcyle::displayDetails()
{
    cout << "Motorcyle details: " << endl;
    cout << "********************\n"
         << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}