#include "Car.h"

Car::Car(string plate, string owner, Date registerDate, string color, Fuel fuelType) : Vehicle(plate, owner, registerDate, color, fuelType)
{
}

Car::~Car()
{
}

void Car::displayDetails()
{
    cout << "Car details: " << endl;
    cout << "********************\n"
        << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}