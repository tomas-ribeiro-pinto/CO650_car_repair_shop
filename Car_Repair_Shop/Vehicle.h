#pragma once
#include <string>
#include <iostream>
#include <map>
#include "Date.h"

using namespace std;

enum Fuel
{
    PETROL,
    DIESEL,
    ELECTRIC,
    HYBRID
};

class Vehicle
{
protected:
    map<Fuel, string> fuelMap;
    string plate;
    string owner;
    // Date of plate registration
    Date registerDate;
    string color;
    // Type of fuel: petrol, diesel, electric or hybrid
    Fuel fuelType;

public:
    Vehicle(string plate, string owner, Date registerDate, string color, Fuel fuelType);
    ~Vehicle();
    void setPlate(string &plate);
    string getPlate();
    void setOwner(string &owner);
    string getOwner();
    void setRegisterDate(Date &date);
    Date getRegisterDate();
    void setColor(string &color);
    string getColor();
    void setFuelType(Fuel &fuel);
    Fuel getFuelType();
    virtual void displayDetails() = 0;
};

Vehicle::Vehicle(string plate, string owner, Date registerDate, string color, Fuel fuelType)
{
    this->plate = plate;
    this->owner = owner;
    this->registerDate = registerDate;
    this->color = color;
    this->fuelType = fuelType;

    this->fuelMap[PETROL] = "Petrol";
    this->fuelMap[DIESEL] = "Diesel";
    this->fuelMap[ELECTRIC] = "Electric";
    this->fuelMap[HYBRID] = "Hybrid";
}

Vehicle::~Vehicle()
{
}

void Vehicle::setPlate(string &plate)
{
    this->plate = plate;
}

string Vehicle::getPlate()
{
    return this->plate;
}

void Vehicle::setOwner(string &owner)
{
    this->owner = owner;
}

string Vehicle::getOwner()
{
    return this->owner;
}

void Vehicle::setRegisterDate(Date &date)
{
    this->registerDate = date;
}

Date Vehicle::getRegisterDate()
{
    return this->registerDate;
}

void Vehicle::setColor(string &color)
{
    this->color = color;
}

string Vehicle::getColor()
{
    return this->color;
}

void Vehicle::setFuelType(Fuel &fuel)
{
    this->fuelType = fuel;
}

Fuel Vehicle::getFuelType()
{
    return this->fuelType;
}