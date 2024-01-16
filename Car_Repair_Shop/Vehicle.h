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
    // OBJECTIVE 8 - CONSTRUCTORS
    // Parent Constructor of any car or motorcycle
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

    // OBJECTIVE 1 - ABSTRACTION
    // abstract method for vehicle's description
    virtual void displayDetails();
    static string plateToUpperCase(string plate);

    // Static Member Functions for adding vehicles menu
    static void registerVehicle(Vehicle**& vehicles, int& size, void(*returnToDashboard)());
    static void inputFuelOption(Fuel& fuelType);
    static void chooseFuelOption(Fuel& fuelType, char& choice);
    static Vehicle* inputVehicleOption(Vehicle**& temp, int& size, Vehicle& vehicle);
    static void chooseVehicleOption(char& choice, Vehicle**& temp, int& size, Vehicle& vehicle);
    static void addToList(Vehicle**& vehicles, int& size, Vehicle& vehicle);
};