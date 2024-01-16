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

    // static member variable to keep track of vehicle count
    static int vehicleCount;

    void setPlate(string& plate);
    string getPlate();
    void setOwner(string& owner);
    string getOwner();
    void setRegisterDate(Date& date);
    Date getRegisterDate();
    void setColor(string& color);
    string getColor();
    void setFuelType(Fuel& fuel);
    Fuel getFuelType();
    virtual void displayDetails();
};