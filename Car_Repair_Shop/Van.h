#pragma once
#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Date.h"

using namespace std;

class Van : public Vehicle
{
public:
    Van(string& plate, string& owner, Date& registerDate, string& color, Fuel& fuelType);
    ~Van();
    void displayDetails();
};