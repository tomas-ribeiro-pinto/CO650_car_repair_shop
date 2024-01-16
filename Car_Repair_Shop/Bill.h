#pragma once
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Repair.h"
#include <vector>

using namespace std;

class Bill
{
private:
    string plate;
    float cost;
    float discount;
    float totalCost;
    vector<Repair*> repairs;
    string cardNumber;
    Date dateIssued;

public:
    Bill(string plate, float cost, vector<Repair*> repairs);
    ~Bill();
    string getPlate();
    float getCost();
    float getDiscount();
    float getTotalCost();
    void getDateIssued();
    string getCardNumber();
    bool isPayed();
    void setDiscount(float discount);
    void setDiscount(int discount);
    void setCardNumber(char *cardNumber);
    void displayBill();
    bool payBill();
    void inputDiscountOption();
    void chooseDiscountOption(char& choice);
    void add(Bill**& bills, int &Size);
    static vector<Bill*> searchBillsByPlate(Bill**& bills, int& size, string plate);
};