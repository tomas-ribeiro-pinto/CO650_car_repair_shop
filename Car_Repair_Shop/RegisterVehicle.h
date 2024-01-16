#pragma once
#include <string>
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Van.h"
#include "Date.h"
#include "Exception.h"

using namespace std;

class RegisterVehicle
{
private:
    string plate;
    string owner;
    Date registerDate;
    string color;
    Fuel fuelType;

public:
    RegisterVehicle();
    ~RegisterVehicle();
    void display(Vehicle**& vehicles, int& size, void (*returnToDashboard)());
    void inputFuelOption();
    void chooseFuelOption(char& choice);
    Vehicle* inputVehicleOption(Vehicle**& temp, int& size);
    void chooseVehicleOption(char& choice, Vehicle**& temp, int& size);
    void addVehicle(Vehicle**& vehicles, int& size);
};