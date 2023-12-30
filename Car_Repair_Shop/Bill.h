#pragma once
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Repair.h"

using namespace std;

class Bill
{
private:
    string plate;
    float cost;
    float discount;
    float totalCost;
    Repair **repairs;
    // Size of repairs array
    int rSize;
    Date dateIssued;

public:
    Bill(string plate, float cost, Repair **repairs);
    ~Bill();
    string getPlate();
    float getCost();
    float getDiscount();
    float getTotalCost();
    void setDiscount(float discount);
    void setDiscount(int discount);
    void displayBill();
    void payBill();
    void inputDiscountOption();
    void chooseDiscountOption(char &choice);
};

Bill::Bill(string plate, float cost, Repair **repairs)
{
    this->plate = plate;
    this->cost = cost;
    this->repairs = repairs;

    this->discount = 0;
    this->totalCost = cost;

    // gets the current date and assigns it to dateIssued
    time_t now = time(0);
    struct tm *currentDate = localtime(&now);
    this->dateIssued = Date(currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);

    this->rSize = Repair::getRepairSize(repairs);
}

Bill::~Bill()
{
}

string Bill::getPlate()
{
    return this->plate;
}

// Get the total cost of all repairs without discount
float Bill::getCost()
{
    return this->cost;
}

float Bill::getDiscount()
{
    return this->discount;
}

// Get the total cost with discount included
float Bill::getTotalCost()
{
    this->totalCost = this->cost - this->discount;
    return this->totalCost;
}

// Add discount to bill
void Bill::setDiscount(float discount)
{
    this->discount = discount;
}

// Add percent discount to bill
void Bill::setDiscount(int discount)
{
    if (discount > 0 && discount <= 100)
    {
        float d = discount;
        this->discount = getCost() * (d / 100);
    }
    else
        cout << "Invalid discount value" << endl;
}

void Bill::displayBill()
{
    cout << "Bill for " << getPlate() << endl;
    cout << "Date issued: ";
    this->dateIssued.display();
    cout << "********************\n"
         << endl;
    cout << "Cost | Repair Description | Employee Assigned" << endl;

    for (int i = 0; i < rSize; i++)
    {
        // Access employee using friendship access granted in Repair.h
        cout << repairs[i]->getCost() << " | " << repairs[i]->getRepairDescription() << " | " << repairs[i]->employee << endl;
        cout << endl;
    }
    cout << "Repairs Cost:" << getCost() << endl;
    cout << "Discount: " << getDiscount() << endl;
    cout << "\n********************"
         << endl;
    cout << "Total cost: " << getTotalCost() << endl;
    cout << "********************\n"
         << endl;
}

void Bill::payBill()
{
    cout << "\n\nTOTAL COST (NO DISCOUNT) IS: " << this->cost << endl;
    cout << "ADD DISCOUNT? (y/n)" << endl;
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        cout << "Enter discount mode: " << endl;
        cout << "1 - Enter discount value" << endl;
        cout << "2 - Enter discount percentage" << endl;
        inputDiscountOption();
        cout << "TOTAL COST (WITH DISCOUNT) IS: " << this->getTotalCost() << endl;
    }

    cout << endl;
    displayBill();
}

void Bill::inputDiscountOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseDiscountOption(option);
}

void Bill::chooseDiscountOption(char &choice)
{
    switch (choice)
    {
    case '1':
    {
        float discount;
        cout << "Enter discount value: " << endl;
        cin >> discount;
        this->setDiscount(discount);
        break;
    }
    case '2':
    {
        int discount;
        cout << "Enter discount percentage (Input a number between 0-100): " << endl;
        cin >> discount;
        if (discount > 0 && discount <= 100)
            this->setDiscount(discount);
        else
        {
            cout << "Invalid discount value" << endl;
            inputDiscountOption();
        }

        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputDiscountOption();
    }
    }
}