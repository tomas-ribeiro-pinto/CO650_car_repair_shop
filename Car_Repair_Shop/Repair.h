#pragma once
#include <iostream>
#include "Date.h"
#include <cctype>
#include <vector>

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
    static vector<Repair*> searchRepairsByPlate(Repair** repairs, int& size, string plate);
    static string plateToUpperCase(string plate);
    static int getRepairSize(Repair**& repairs);
};