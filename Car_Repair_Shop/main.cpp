#include <string>
#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Login.h"
#include "Dashboard.h"

using namespace std;

int main()
{
    // Creates a new Login object and displays the
    // login screen for authentication purposes
    Login *login = new Login();
    login->display();
    Dashboard *dashboard = new Dashboard();
    dashboard->display();
    return 0;
}