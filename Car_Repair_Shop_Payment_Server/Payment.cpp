#include "Payment.h"

Payment::Payment()
{
}

Payment::~Payment()
{
}

string Payment::getPlate()
{
    return this->plate;
}

// Get the total cost of all repairs without discount
string Payment::getTotalCost()
{
    return this->totalCost;
}

// Get the last 4 digits of the card number used to pay the bill
string Payment::getCardNumber()
{
    return this->cardNumber;
}

void Payment::displayBill()
{
    cout << "Bill for " << getPlate() << endl;
    cout << "  Card Number: ****" << getCardNumber();
    cout << "********************\n"
        << endl;
    cout << "Total cost: " << getTotalCost() << endl;
    cout << "********************\n"
        << endl;
}