#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

// OBJECTIVE 3 - INHERITANCE
// Car class deriving from Vehicle
class Car : public Vehicle
{
public:
    Car(string plate, string owner, Date registerDate, string color, Fuel fuelType);
    ~Car();
    void displayDetails();
};