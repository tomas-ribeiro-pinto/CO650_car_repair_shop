#include <string>
#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Login.h"
#include "Dashboard.h"

using namespace std;

// Static variable to keep track of the number of vehicles registered
int Vehicle::vehicleCount = 0;

int main()
{
    // Creates a new Login object and displays the
    // login screen for authentication purposes
    Login* login = new Login();
    login->display();

    // Creates a list of vehicles
    // list<Vehicle> vehicles = {};

    Dashboard* dashboard = new Dashboard();
    dashboard->display();
    return 0;
}