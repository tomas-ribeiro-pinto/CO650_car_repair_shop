#include "Vehicle.h"

Vehicle::Vehicle(string plate, string owner, Date registerDate, string color, Fuel fuelType)
{
    Vehicle::vehicleCount++;

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
    Vehicle::vehicleCount--;
}

void Vehicle::setPlate(string& plate)
{
    this->plate = plate;
}

string Vehicle::getPlate()
{
    return this->plate;
}

void Vehicle::setOwner(string& owner)
{
    this->owner = owner;
}

string Vehicle::getOwner()
{
    return this->owner;
}

void Vehicle::setRegisterDate(Date& date)
{
    this->registerDate = date;
}

Date Vehicle::getRegisterDate()
{
    return this->registerDate;
}

void Vehicle::setColor(string& color)
{
    this->color = color;
}

string Vehicle::getColor()
{
    return this->color;
}

void Vehicle::setFuelType(Fuel& fuel)
{
    this->fuelType = fuel;
}

Fuel Vehicle::getFuelType()
{
    return this->fuelType;
}

void Vehicle::displayDetails()
{
}