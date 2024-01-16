#pragma once
#include <iostream>

using namespace std;

class Payment
{
private:
    string plate;
    string totalCost;
    string cardNumber;

public:
    Payment();
    ~Payment();
    string getPlate();
    string getTotalCost();
    string getCardNumber();
    void displayBill();
};