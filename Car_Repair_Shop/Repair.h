#pragma once
#include <iostream>
#include "Date.h"
#include <cctype>
#include <vector>
#include "Vehicle.h"

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

    // OBJECTIVE 6 - FRIENDSHIP
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
    static int getRepairSize(Repair**& repairs);

    // Static Member Functions for adding repairs menu
    static void addRepair(Repair**& repairs, int& size, void(*returnToDashboard)());
    static void inputOption(bool& isRepaired);
    static void chooseOption(bool& isRepaired, char& choice);
    static void addToList(Repair**& repairs, int& size, Repair*& repair);
};