#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

class Car : public Vehicle
{
public:
    Car(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType);
    ~Car();
    void displayDetails();
};

Car::Car(string &plate, string &owner, Date &registerDate, string &color, Fuel &fuelType) : Vehicle(plate, owner, registerDate, color, fuelType)
{
}

Car::~Car()
{
}

void Car::displayDetails()
{
    cout << "Car details: " << endl;
    cout << "********************\n"
         << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}