#pragma once
#include <iostream>
#include <ctime>
#include "Date.h"
#include "Repair.h"
#include <vector>
#include "PaymentGateway.h"

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

    //OBJECTIVE 5 - OVERLOADING
    // User can input a discount eiter with a float type value or
    // a percentage by inputing a integer number between 0 and 100
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