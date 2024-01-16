#include "Motorcycle.h"

Motorcycle::Motorcycle(string& plate, string& owner, Date& registerDate, string& color, Fuel& fuelType) : Vehicle(plate, owner, registerDate, color, fuelType)
{
}

Motorcycle::~Motorcycle()
{
}

void Motorcycle::displayDetails()
{
    cout << "Motorcycle details: " << endl;
    cout << "********************\n"
        << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}