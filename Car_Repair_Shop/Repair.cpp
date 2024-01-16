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

 //Search repairs by plate which have been completed
 //returns a vector of dynamic Repair objects
vector<Repair*> Repair::searchRepairsByPlate(Repair** repairs, int& size, string plate)
{
    vector<Repair*> searchResults{};
    searchResults.reserve(size);

    for (int i = 0; i < size; i++)
    {
        if (Vehicle::plateToUpperCase(repairs[i]->getPlate()) == Vehicle::plateToUpperCase(plate) && repairs[i]->getIsRepaired() == true)
        {
            searchResults.push_back(repairs[i]);
        }
    }

    return searchResults;
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

void Repair::addRepair(Repair**& repairs, int& size, void (*returnToDashboard)())
{
    string plate;
    string employee;
    Date dateIssued;
    string repairDescription;
    float cost;
    bool isRepaired;

    cout << "\n\nADD REPAIR" << endl;
    cout << "********************\n"
        << endl;
    cout << "Insert the vehicle plate: " << endl;
    cin >> plate;
    cout << "Insert employee name: " << endl;
    cin >> employee;
    cout << "Insert date of repair: " << endl;
    dateIssued = Date::inputDate();
    cout << "Insert the repair description:" << endl;
    cin.ignore();
    getline(cin, repairDescription);
    cout << "\nInsert the repair status: " << endl;
    cout << "1 - IN PROGRESS" << endl;
    cout << "2 - REPAIRED" << endl;
    Repair::inputOption(isRepaired);
    cout << "Insert the repair cost: " << endl;
    cin >> cost;

    Repair* repair = new Repair(plate, employee, dateIssued, repairDescription, isRepaired, cost);

    // add vehicle to vehicles array
    Repair::addToList(repairs, size, repair);

    returnToDashboard();
}

void Repair::inputOption(bool &isRepaired)
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    Repair::chooseOption(isRepaired, option);
}

void Repair::chooseOption(bool &isRepaired, char& choice)
{
    switch (choice)
    {
    case '1':
    {
        isRepaired = false;
        break;
    }
    case '2':
    {
        isRepaired = true;
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        Repair::inputOption(isRepaired);
    }
    }
}

void Repair::addToList(Repair**& repairs, int& size, Repair*& repair)
{
    Repair** temp = new Repair * [size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = repairs[i];
    }

    temp[size] = repair;
    size++;

    delete[] repairs;
    repairs = temp;

    cout << "\n\nREPAIR ADDED!" << endl;
    repair->displayRepairDescription();
}