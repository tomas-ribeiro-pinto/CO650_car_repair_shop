#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Exception.h"

// OBJECTIVE 2 - ENCAPSULATION
// Initialise vehcile object with given details
Vehicle::Vehicle(string plate, string owner, Date registerDate, string color, Fuel fuelType)
{
    Vehicle::vehicleCount++;

    this->plate = plate;
    this->owner = owner;
    this->registerDate = registerDate;
    this->color = color;
    this->fuelType = fuelType;

    this->fuelMap[PETROL] = "Petrol";
    this->fuelMap[DIESEL] = "Diesel";
    this->fuelMap[ELECTRIC] = "Electric";
    this->fuelMap[HYBRID] = "Hybrid";
}

// decreases static variable for vehicle count on vehicle delete
Vehicle::~Vehicle()
{
    Vehicle::vehicleCount--;
}

void Vehicle::setPlate(string& plate)
{
    this->plate = plate;
}

string Vehicle::getPlate()
{
    return this->plate;
}

void Vehicle::setOwner(string& owner)
{
    this->owner = owner;
}

string Vehicle::getOwner()
{
    return this->owner;
}

void Vehicle::setRegisterDate(Date& date)
{
    this->registerDate = date;
}

Date Vehicle::getRegisterDate()
{
    return this->registerDate;
}

void Vehicle::setColor(string& color)
{
    this->color = color;
}

string Vehicle::getColor()
{
    return this->color;
}

void Vehicle::setFuelType(Fuel& fuel)
{
    this->fuelType = fuel;
}

Fuel Vehicle::getFuelType()
{
    return this->fuelType;
}

void Vehicle::displayDetails()
{
    cout << "Vehicle details: " << endl;
    cout << "********************\n"
        << endl;
    cout << "Plate: " << this->getPlate() << endl;
    cout << "Owner: " << this->getOwner() << endl;
    cout << "Date of Vehicle Registration: ";
    this->getRegisterDate().display();
    cout << "Color: " << this->getColor() << endl;
    cout << "Fuel Type: " << this->fuelMap[this->getFuelType()] << endl;
}

string Vehicle::plateToUpperCase(string plate)
{
    const int length = plate.length();
    char* str = new char[length + 1];
    strcpy(str, plate.c_str());
    for (int x = 0; x < length; x++)
        str[x] = toupper(str[x]);

    return str;
}

// Register Vehicle menu
void Vehicle::registerVehicle(Vehicle**& vehicles, int& size, void (*returnToDashboard)())
{
    string plate;
    string owner;
    Date registerDate;
    string color;
    Fuel fuelType;

    cout << "\n\nREGISTER VEHICLE" << endl;
    cout << "********************\n"
        << endl;
    cout << "Insert the plate: " << endl;
    cin >> plate;
    cout << "Insert the owner: " << endl;
    cin.ignore();
    getline(cin, owner);
    cout << "Insert the date of vehicle registration: " << endl;
    registerDate = Date::inputDate();
    cout << "Insert the vehicle color: " << endl;
    cin >> color;
    cout << "Insert the fuel type: " << endl;
    cout << "1 - Petrol" << endl;
    cout << "2 - Diesel" << endl;
    cout << "3 - Electric" << endl;
    cout << "4 - Hybrid\n"
        << endl;
    Vehicle::inputFuelOption(fuelType);

    // create and add vehicle to vehicles array
    Vehicle vehicle = Vehicle(plate, owner, registerDate, color, fuelType);
    Vehicle::addToList(vehicles, size, vehicle);

    // return to dashboard using a function pointer
    returnToDashboard();
}

void Vehicle::inputFuelOption(Fuel &fuelType)
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    Vehicle::chooseFuelOption(fuelType, option);
}

void Vehicle::chooseFuelOption(Fuel &fuelType, char& choice)
{
    switch (choice)
    {
        case '1':
        {
            fuelType = PETROL;
            break;
        }
        case '2':
        {
            fuelType = DIESEL;
            break;
        }
        case '3':
        {
            fuelType = ELECTRIC;
            break;
        }
        case '4':
        {
            fuelType = HYBRID;
            break;
        }
        default:
        {
            cout << "Invalid option" << endl;
            Vehicle::inputFuelOption(fuelType);
        }
    }
}

Vehicle* Vehicle::inputVehicleOption(Vehicle**& temp, int& size, Vehicle &vehicle)
{
    try
    {
        char option = '0';
        cout << "\n Choose an option: " << endl;
        cin >> option;
        if (option != '1' && option != '2')
        {
            // Throws custom exception when input is not valid
            IOException ioException;
            throw ioException;
        }

        Vehicle::chooseVehicleOption(option, temp, size, vehicle);
    }
    catch (exception& e)
    {
        cerr << e.what() << '\n';
        exit;
    }

    return temp[size];
}

void Vehicle::chooseVehicleOption(char& choice, Vehicle**& temp, int& size, Vehicle& vehicle)
{
    switch (choice)
    {
        // User chooses a car
    case '1':
    {
        // Create car
        Car* car = new Car(vehicle.plate, vehicle.owner, vehicle.registerDate, vehicle.color, vehicle.fuelType);
        temp[size] = car;
        cout << "\n\nCAR REGISTERED!" << endl;
        break;
    }
    // User chooses a motorcycle
    case '2':
    {
        // Create motorcycle
        Motorcycle* motorcycle = new Motorcycle(vehicle.plate, vehicle.owner, vehicle.registerDate, vehicle.color, vehicle.fuelType);
        temp[size] = motorcycle;
        cout << "\n\nMOTORCYCLE REGISTERED!" << endl;

        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        Vehicle::inputVehicleOption(temp, size, vehicle);
    }
    }
}

// Changes dynamic array by creating a new one with a size incremented by one
void Vehicle::addToList(Vehicle**& vehicles, int& size, Vehicle& vehicle)
{
    Vehicle** temp = new Vehicle * [size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = vehicles[i];
    }

    cout << "Choose type of vehicle:" << endl;
    cout << "1 - Car" << endl;
    cout << "2 - Motorcycle" << endl;

    cin.ignore();
    Vehicle* nvehicle = Vehicle::inputVehicleOption(temp, size, vehicle);
    size++;

    // delete old array
    delete[] vehicles;
    // assigns pointer with new array of vehicles
    vehicles = temp;

    nvehicle->displayDetails();
}