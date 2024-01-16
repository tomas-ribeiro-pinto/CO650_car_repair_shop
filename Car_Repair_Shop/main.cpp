#include <string>
#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Dashboard.h"

using namespace std;

// OBJECTIVE 7 - STATIC MEMBERS
// Static variable to keep track of the number of vehicles registered
int Vehicle::vehicleCount = 0;

int main()
{
    // Creates a new Dashboard object and displays the home screen
    Dashboard* dashboard = new Dashboard();
    dashboard->display();
    return 0;
}