#include "Bill.h"


Bill::Bill(string plate, float cost, vector<Repair*> repairs)
{
    this->plate = Vehicle::plateToUpperCase(plate);
    this->cost = cost;
    this->repairs = repairs;

    this->discount = 0;
    this->totalCost = cost;
    this->cardNumber = "";

    // gets the current date and assigns it to dateIssued
    time_t now = time(0);
    struct tm* currentDate = localtime(&now);
    this->dateIssued = Date(currentDate->tm_mday, currentDate->tm_mon + 1, currentDate->tm_year + 1900);
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

// Get date issued
void Bill::getDateIssued()
{
    this->dateIssued.display();
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

// Get the last 4 digits of the card number used to pay the bill
string Bill::getCardNumber()
{
    return this->cardNumber;
}

// Set card number's 4 last digits used to pay
void Bill::setCardNumber(char *cardNumber)
{
    char cardEnd[5];
    for (int i = 0; i < 5; i++)
        cardEnd[i] = cardNumber[i + 12];
    this->cardNumber = cardEnd;
}

bool Bill::isPayed()
{
    if (this->getCardNumber() != "")
        return 1;
    return 0;
}


void Bill::displayBill()
{
    cout << "Bill for " << getPlate() << endl;
    cout << "Date issued: ";
    this->dateIssued.display();
    cout << "  Card Number: ****" << getCardNumber() << endl;;
    cout << "********************\n"
        << endl;
    cout << "Cost | Repair Description | Employee Assigned" << endl;

    for (int i = 0; i < repairs.size(); i++)
    {
        // OBJECTIVE 6 - FRIENDSHIP
        // Access employee using friendship access granted in Repair.h
        cout << repairs.at(i)->getCost() << " | " << repairs.at(i)->getRepairDescription() << " | " << repairs.at(i)->employee << endl;
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

bool Bill::payBill()
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

    cin.ignore();
    cin.clear();

    // OBJECTIVE 12 - WINSOCK CLIENT
    // Creates an object of PaymentGateway and initialises paymentGateway
    PaymentGateway paymentGateway = PaymentGateway();
    paymentGateway.initialise();
    if (paymentGateway.payBill(this))
    {
        cout << "##PAYMENT ACCEPTED!##\n" << endl;
        displayBill();
        return 1;
    }
    else
    {
        cout << "--## PAYMENT DECLINED/FAILED ##--" << endl;
        return 0;
    }
    return 0;
}

void Bill::inputDiscountOption()
{
    char option = '0';
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseDiscountOption(option);
}

void Bill::chooseDiscountOption(char& choice)
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

void Bill::add(Bill**& bills, int& size)
{
    Bill** temp = new Bill * [size + 1];
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            temp[i] = bills[i];
        }
    }

    temp[size] = this;
    size++;

    delete[] bills;
    bills = temp;
}

vector<Bill*> Bill::searchBillsByPlate(Bill**& bills, int& size, string plate)
{
    vector<Bill*> searchResults{};
    searchResults.reserve(size);

    for (int i = 0; i < size; i++)
    {
        if (Vehicle::plateToUpperCase(bills[i]->getPlate()) == Vehicle::plateToUpperCase(plate) && bills[i]->isPayed() == true)
        {
            searchResults.push_back(bills[i]);
        }
    }

    return searchResults;
}