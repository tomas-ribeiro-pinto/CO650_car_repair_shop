#pragma once
#include <iostream>

using namespace std;

class Payment
{
private:
    string plate;
    float totalCost;
    string cardNumber;

public:
    Payment();
    ~Payment();
    string getPlate();
    float getTotalCost();
    string getCardNumber();
    void displayBill();
};