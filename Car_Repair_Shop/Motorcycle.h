#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

// OBJECTIVE 3 - INHERITANCE
// class deriving from Vehicle
class Motorcycle : public Vehicle
{
public:
    Motorcycle(string& plate, string& owner, Date& registerDate, string& color, Fuel& fuelType);
    ~Motorcycle();
    void displayDetails();
};