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
    Date(int day, int month, int year);
    Date();
    ~Date();
    void display();
};

Date::Date()
{
}

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::~Date()
{
}

void Date::display()
{
    cout << this->day << "/" << this->month << "/" << this->year << endl;
}

// Static function to input the date of vehicle registration
Date inputDate()
{
    int day;
    int month;
    int year;

    cout << " >Insert the day: " << endl;
    cin >> day;
    cout << " >Insert the month: " << endl;
    cin >> month;
    cout << " >Insert the year: " << endl;
    cin >> year;

    return Date(day, month, year);
}