#pragma once
#include <string>
#include <iostream>
#include "Car.h"
#include "Date.h"

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
    void display();
    void inputFuelOption();
    void chooseOption(char &choice);
};

RegisterVehicle::RegisterVehicle()
{
}

RegisterVehicle::~RegisterVehicle()
{
}

void RegisterVehicle::display()
{
    cout << "\n\nREGISTER VEHICLE" << endl;
    cout << "********************\n"
         << endl;
    cout << "Insert the plate: " << endl;
    cin >> this->plate;
    cout << "Insert the owner: " << endl;
    cin >> this->owner;
    cout << "Insert the date of vehicle registration: " << endl;
    this->registerDate = inputDate();
    cout << "Insert the vehicle color: " << endl;
    cin >> this->color;
    cout << "Insert the fuel type: " << endl;
    cout << "1 - Petrol" << endl;
    cout << "2 - Diesel" << endl;
    cout << "3 - Electric" << endl;
    cout << "4 - Hybrid\n"
         << endl;
    inputFuelOption();

    Car *car = new Car(this->plate, this->owner, this->registerDate, this->color, this->fuelType);

    cout << "\n\nCAR REGISTERED!" << endl;
    car->displayDetails();

    // return to dashboard
    cout << "\n\nPress any key to return to the dashboard..." << endl;
    cin.get();
    cin.ignore();
}

void RegisterVehicle::inputFuelOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseOption(option);
}

void RegisterVehicle::chooseOption(char &choice)
{
    switch (choice)
    {
    case '1':
    {
        this->fuelType = PETROL;
        break;
    }
    case '2':
    {
        this->fuelType = DIESEL;
        break;
    }
    case '3':
    {
        this->fuelType = ELECTRIC;
        break;
    }
    case '4':
    {
        this->fuelType = HYBRID;
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputFuelOption();
    }
    }
}