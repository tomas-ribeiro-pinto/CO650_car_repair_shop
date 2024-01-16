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
    Payment(string plate, string totalCost, string cardNumber);
    ~Payment();
    string getPlate();
    string getTotalCost();
    string getCardNumber();
    void displayBill();
};