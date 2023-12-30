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
    void display(Vehicle **&vehicles, int &size);
    void inputFuelOption();
    void chooseOption(char &choice);
    void addVehicle(Vehicle **&vehicles, int &size);
};

RegisterVehicle::RegisterVehicle()
{
}

RegisterVehicle::~RegisterVehicle()
{
}

void RegisterVehicle::display(Vehicle **&vehicles, int &size)
{
    cout << "\n\nREGISTER VEHICLE" << endl;
    cout << "********************\n"
         << endl;
    cout << "Insert the plate: " << endl;
    cin >> this->plate;
    cout << "Insert the owner: " << endl;
    cin.ignore();
    getline(cin, this->owner);
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

    // add vehicle to vehicles array
    addVehicle(vehicles, size);

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

void RegisterVehicle::addVehicle(Vehicle **&vehicles, int &size)
{
    Vehicle **temp = new Vehicle *[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = vehicles[i];
    }

    Car *car = new Car(this->plate, this->owner, this->registerDate, this->color, this->fuelType);
    temp[size] = car;
    size++;

    delete[] vehicles;
    vehicles = temp;

    cout << "\n\nCAR REGISTERED!" << endl;
    car->displayDetails();
}