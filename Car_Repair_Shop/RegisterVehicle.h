#pragma once
#include <string>
#include <iostream>
#include "Car.h"
#include "Motorcycle.h"
#include "Van.h"
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
    void display(Vehicle **&vehicles, int &size, void (*returnToDashboard)());
    void inputFuelOption();
    void chooseFuelOption(char &choice);
    Vehicle *inputVehicleOption(Vehicle **&temp, int &size);
    void chooseVehicleOption(char &choice, Vehicle **&temp, int &size);
    void addVehicle(Vehicle **&vehicles, int &size);
};

RegisterVehicle::RegisterVehicle()
{
}

RegisterVehicle::~RegisterVehicle()
{
}

void RegisterVehicle::display(Vehicle **&vehicles, int &size, void (*returnToDashboard)())
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

    // return to dashboard using a function pointer
    returnToDashboard();
}

void RegisterVehicle::inputFuelOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseFuelOption(option);
}

void RegisterVehicle::chooseFuelOption(char &choice)
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

Vehicle *RegisterVehicle::inputVehicleOption(Vehicle **&temp, int &size)
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseVehicleOption(option, temp, size);

    return temp[size];
}

void RegisterVehicle::chooseVehicleOption(char &choice, Vehicle **&temp, int &size)
{
    switch (choice)
    {
        // User chooses a car
    case '1':
    {
        Car *car = new Car(this->plate, this->owner, this->registerDate, this->color, this->fuelType);
        temp[size] = car;
        cout << "\n\nCAR REGISTERED!" << endl;
        break;
    }
        // User chooses a motorcycle
    case '2':
    {
        Motorcycle *motorcycle = new Motorcycle(this->plate, this->owner, this->registerDate, this->color, this->fuelType);
        temp[size] = motorcycle;
        cout << "\n\nMOTORCYCLE REGISTERED!" << endl;

        break;
    }
        // User chooses a van
    case '3':
    {
        Van *van = new Van(this->plate, this->owner, this->registerDate, this->color, this->fuelType);
        temp[size] = van;
        cout << "\n\nVAN REGISTERED!" << endl;

        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputVehicleOption(temp, size);
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

    cout << "Choose type of vehicle:" << endl;
    cout << "1 - Car" << endl;
    cout << "2 - Motorcycle" << endl;
    cout << "3 - Van" << endl;

    cin.ignore();
    Vehicle *vehicle = inputVehicleOption(temp, size);
    size++;

    delete[] vehicles;
    vehicles = temp;

    vehicle->displayDetails();
}