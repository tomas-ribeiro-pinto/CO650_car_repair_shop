#pragma once
#include <string>
#include <iostream>

using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;

    // OBJECTIVE 8 - CONSTRUCTORS
    // non-default constructor
    Date(int day, int month, int year);
    // default constructor
    Date();
    ~Date();
    void display();

    // OBJECTIVE 7 - STATIC MEMBERS
    // Static member function
    static Date inputDate();
};