#include "Repair.h"

Repair::Repair(string plate, string employee, Date dateIssued, string repairDescription, bool isRepaired, double cost)
{
    this->plate = plate;
    this->employee = employee;
    this->dateIssued = dateIssued;
    this->repairDescription = repairDescription;
    this->isRepaired = isRepaired;
    this->cost = cost;
}

Repair::~Repair()
{
}

string Repair::getPlate()
{
    return this->plate;
}

Date Repair::getDateIssued()
{
    return this->dateIssued;
}

bool Repair::getIsRepaired()
{
    return this->isRepaired;
}

void Repair::setIsRepaired(bool isRepaired)
{
    this->isRepaired = isRepaired;
}

double Repair::getCost()
{
    return this->cost;
}

void Repair::setCost(double cost)
{
    this->cost = cost;
}

string Repair::getRepairDescription()
{
    return this->repairDescription;
}

void Repair::displayRepairDescription()
{
    cout << "Repair description: " << endl;
    cout << "********************\n"
        << endl;
    cout << "Plate: " << this->plate;
    if (this->isRepaired == false)
        cout << " STATUS: "
        << "In Progress" << endl;
    else
        cout << " STATUS: "
        << "Repaired" << endl;
    cout << "Employee Assigned: " << this->employee << endl;
    cout << "Date Issued: ";
    this->getDateIssued().display();
    cout << "Cost: " << this->cost << endl;
    cout << "Repair Description: \n"
        << " >> "
        << this->repairDescription << endl;
}

/**
 * Search repairs by plate which have been completed
 * returns a vector of dynamic Repair objects
 */
vector<Repair*> Repair::searchRepairsByPlate(Repair** repairs, int& size, string plate)
{
    vector<Repair*> searchResults{};
    searchResults.reserve(size);

    for (int i = 0; i < size; i++)
    {
        if (Repair::plateToUpperCase(repairs[i]->getPlate()) == Repair::plateToUpperCase(plate) && repairs[i]->getIsRepaired() == true)
        {
            searchResults.push_back(repairs[i]);
        }
    }

    return searchResults;
}

string Repair::plateToUpperCase(string plate)
{
    const int length = plate.length();
    char* str = new char[length + 1];
    strcpy(str, plate.c_str());
    for (int x = 0; x < length; x++)
        str[x] = toupper(str[x]);

    return str;
}

int Repair::getRepairSize(Repair**& repairs)
{
    int size = 0;
    while (repairs[size] != NULL)
    {
        size++;
    }
    return size;
}