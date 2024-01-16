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
    static Date inputDate();
};