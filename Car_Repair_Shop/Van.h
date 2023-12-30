#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

class Van : public Vehicle
{
public:
    Van(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType);
    ~Van();
    void displayDetails();
};

Van::Van(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType) : Vehicle(plate, owner, registerDate, color, fuelType)
{
}

Van::~Van()
{
}

void Van::displayDetails()
{
    cout << "Van details: " << endl;
    cout << "********************\n"
         << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}