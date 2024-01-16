#include <iostream>
#include <exception>

using namespace std;

// OBJECTIVE 11 - EXCEPTION HANDLING
class IOException : public exception
{
public:
    // IO exception for invalid input
    virtual const char* what() const throw()
    {
        return "Invalid Input Exception!";
    }
};

class PaymentException : public exception
{
public:
    float cost;
    PaymentException(float c) :cost(c) {}
    // Exception for payment failure
    virtual const char* what() const throw()
    {
        return "--## PAYMENT DECLINED/FAILED ##--";
    }
};