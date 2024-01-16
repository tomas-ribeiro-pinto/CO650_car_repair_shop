#include <iostream>
#include <exception>
using namespace std;

class IOException : public exception
{
public:
    // IO exception for invalid input
    virtual const char* what() const throw()
    {
        return "Invalid Input Exception!";
    }
};