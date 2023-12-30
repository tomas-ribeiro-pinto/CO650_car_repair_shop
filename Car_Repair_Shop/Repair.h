#pragma once
#include <string>
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
    string getPlate();
    Date getDateIssued();
    bool getIsFixed();
    void setIsFixed(bool isRepaired);
    double getCost();
    void setCost(double cost);
    void displayRepairDescription();
    Repair **searchRepairsByPlate(Repair **repairs, int &size, string plate);
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

bool Repair::getIsFixed()
{
    return this->isRepaired;
}

void Repair::setIsFixed(bool isRepaired)
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

Repair **searchRepairsByPlate(Repair **repairs, int &size, string plate)
{
    Repair **searchResults = new Repair *[size];
    int searchSize = 0;
    for (int i = 0; i < size; i++)
    {
        if (toupper(repairs[i]->getPlate()) == toupper(plate))
        {
            searchResults[searchSize] = repairs[i];
            searchSize++;
        }
    }
    return searchResults;
}