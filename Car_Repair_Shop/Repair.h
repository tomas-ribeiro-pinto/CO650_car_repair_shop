#pragma once
#include <iostream>
#include "Date.h"
#include <cctype>

using namespace std;

class Repair
{
private:
    string plate;
    string employee;
    Date dateIssued;
    string repairDescription;
    bool isRepaired;
    double cost;

public:
    Repair(string plate, string employee, Date dateIssued, string repairDescription, bool isRepaired, double cost);
    ~Repair();

    // Give access to this class to Bill class
    friend class Bill;

    string getPlate();
    Date getDateIssued();
    bool getIsRepaired();
    void setIsRepaired(bool isRepaired);
    double getCost();
    void setCost(double cost);
    string getRepairDescription();
    void displayRepairDescription();
    static Repair **searchRepairsByPlate(Repair **repairs, int &size, string plate);
    static string plateToUpperCase(string arr);
    static int getRepairSize(Repair **&repairs);
};

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
 * returns an array of Repair objects
 */
Repair **Repair::searchRepairsByPlate(Repair **repairs, int &size, string plate)
{
    Repair **searchResults = new Repair *[size];
    int searchSize = 0;

    for (int i = 0; i < size; i++)
    {
        if (Repair::plateToUpperCase(repairs[i]->getPlate()) == Repair::plateToUpperCase(plate) && repairs[i]->getIsRepaired() == true)
        {
            searchResults[searchSize] = repairs[i];
            searchSize++;
        }
    }
    return searchResults;
}

string Repair::plateToUpperCase(string arr)
{
    for (int x = 0; x < sizeof(arr); x++)
        arr[x] = toupper(arr[x]);

    return arr;
}

int Repair::getRepairSize(Repair **&repairs)
{
    int size = 0;
    while (repairs[size] != NULL)
    {
        size++;
    }
    return size;
}