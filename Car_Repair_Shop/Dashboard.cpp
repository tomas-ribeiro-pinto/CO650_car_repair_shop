#include "Dashboard.h"

Dashboard::Dashboard()
{
    this->option = '0';
    // vehicles dynamic array size
    this->vSize = 1;
    // repairs dynamic array size
    this->rSize = 1;
    // bills dynamic array size
    this->bSize = 0;

    vehicles = new Vehicle * [vSize];
    vehicles[0] = new Car("ABC123", "John Doe", Date(01, 01, 2020), "Red", PETROL);

    repairs = new Repair * [rSize];
    repairs[0] = new Repair("ABC123", "Mark Sanderson", Date(27, 01, 2020), "Front Wheels to be replaced", true, 340.65);

    bills = new Bill *[bSize];

    // OBJECTIVE 10 - FUNCTIONAL POINTERS
    // assigns the function pointer to the return to dashboard function
    returnToDashboard = &Dashboard::promptToDashboard;
}

Dashboard::~Dashboard()
{
    // Delete array of vehicles, repairs and bills
    for (int n = 0; n < this->vSize; n++)
    {
        delete vehicles[n];
    }
    delete vehicles;

    for (int n = 0; n < this->rSize; n++)
    {
        delete repairs[n];
    }
    delete repairs;

    for (int n = 0; n < this->bSize; n++)
    {
        delete bills[n];
    }
    delete bills;
}

// Displays the home dashboard
void Dashboard::display()
{
    while (option != '8')
    {
        cout << "CAR REPAIR SHOP" << endl;
        cout << "********************\n"
            << endl;
        cout << "Vehicles registered for repair: " << Vehicle::vehicleCount << endl;
        cout << "********************\n"
            << endl;
        cout << "DASHBOARD" << endl;
        cout << "********************\n"
            << endl;
        cout << "1. Register a new vehicle for repair" << endl;
        cout << "2. Display all vehicles" << endl;
        cout << "3. Add repair" << endl;
        cout << "4. Display all repairs" << endl;
        cout << "5. Display repairs by plate" << endl;
        cout << "6. Pay repair bill" << endl;
        cout << "7. Display all bills" << endl;
        cout << "8. Exit" << endl;
        inputOption();
    }
}

void Dashboard::inputOption()
{
    cout << "\n Choose an option: " << endl;
    cin >> option;
    chooseOption(option);
}

// switch statement with all 8 menu options
void Dashboard::chooseOption(char& option)
{
    switch (option)
    {
    case '1':
    {
        registerVehicle();
        break;
    }
    case '2':
    {
        displayVehicles();
        break;
    }
    case '3':
    {
        addRepair();
        break;
    }
    case '4':
    {
        displayRepairs();
        break;
    }
    case '5':
    {
        displayRepairByPlate();
        break;
    }
    case '6':
    {
        payBill();
        break;
    }
    case '7':
    {
        displayBill();
        break;
    }
    case '8':
    {
        cout << "Exiting..." << endl;
        break;
    }
    default:
    {
        cout << "Invalid option" << endl;
        inputOption();
    }
    }
}

void Dashboard::promptToDashboard()
{
    cout << "\n\nPress any key to return to the dashboard..." << endl;
    cin.get();
    cin.ignore();
}

void Dashboard::registerVehicle() {
    Vehicle::registerVehicle(vehicles, vSize, returnToDashboard);
}

void Dashboard::displayVehicles() {
    cout << "All vehicles" << endl;
    cout << "********************\n"
        << endl;
    cout << "Total vehicles: " << vSize << endl;
    cout << endl;
    cout << "********************\n"
        << endl;
    cout << "Plate      | Owner" << endl;
    cout << "===================" << endl;

    // runs loop through vehicles array
    for (int i = 0; i < vSize; i++)
    {
        cout << vehicles[i]->getPlate() << "        " << vehicles[i]->getOwner() << endl;
    }

    returnToDashboard();
}

void Dashboard::addRepair() 
{
    Repair::addRepair(repairs, rSize, returnToDashboard);
}

void Dashboard::displayRepairs() 
{
    cout << "\n\nAll Repairs: \n\n"
        << endl;

    // runs loop through repairs array and displays each repair description
    for (int i = 0; i < rSize; i++)
    {
        repairs[i]->displayRepairDescription();
        cout << endl;
    }

    returnToDashboard();
}

void Dashboard::displayRepairByPlate() 
{
    string searchPlate;
    cout << "Display repairs by plate" << endl;
    cout << "Insert plate number:" << endl;
    cin.ignore();
    getline(cin, searchPlate);
    cout << "\n\nSearch results by:" << Vehicle::plateToUpperCase(searchPlate) << "\n\n"
        << endl;

    vector<Repair*> searchResults = Repair::searchRepairsByPlate(repairs, rSize, searchPlate);

    // Loops through the vector of dynamic Repair objects
    for (int i = 0; i < searchResults.size(); i++)
    {
        searchResults.at(i)->displayRepairDescription();
        cout << endl;
    }

    returnToDashboard();
}
void Dashboard::payBill() 
{
    string searchPlate;
    cout << "Pay repair bill" << endl;
    cout << "Insert plate number:" << endl;
    cin.ignore();
    getline(cin, searchPlate);

    vector<Repair*> searchResults = Repair::searchRepairsByPlate(repairs, rSize, searchPlate);

    if (searchResults.size() == 0)
    {
        cout << "No repairs found for plate: " << searchPlate << endl;
    }
    else
    {
        cout << "Repairs with outstanding payment for: " << Vehicle::plateToUpperCase(searchPlate) << endl;
        double tCost = 0;
        cout << "Cost | Repair Description" << endl;
        for (int i = 0; i < searchResults.size(); i++)
        {
            cout << searchResults.at(i)->getCost() << " | " << searchResults.at(i)->getRepairDescription() << endl;
            cout << endl;

            // increase total cost
            tCost += searchResults.at(i)->getCost();
        }
        cout << "Total cost:" << tCost << endl;

        // pay bill
        cout << "Pay bill? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            // Creates bill and attempts to pay the bill
            Bill* bill = new Bill(searchPlate, tCost, searchResults);
            if (bill->payBill() == 0)
            {
                // if transaction is cancelled by the user
                cout << "Bill not paid!" << endl;
            }
            else
            {
                // add bill to list of paid bills
                bill->add(bills, bSize);
            }
        }
        else
        {
            cout << "Bill not paid!" << endl;
        }
    }

    returnToDashboard();
}

void Dashboard::displayBill() 
{
    string searchPlate;
    cout << "Display previous bills" << endl;
    cout << "Insert plate number:" << endl;
    cin.ignore();
    getline(cin, searchPlate);

    vector<Bill*> searchResults = Bill::searchBillsByPlate(bills, bSize, searchPlate);

    if (searchResults.size() == 0)
    {
        cout << "\nNo bills found for plate: " << searchPlate << endl;
        cout << endl;
    }
    else
    {
        cout << "Previous bills : " << Vehicle::plateToUpperCase(searchPlate) << endl;
        cout << "Cost | Date issued" << endl;

        for (int i = 0; i < searchResults.size(); i++)
        {
            cout << searchResults.at(i)->getCost() << " | ";
            searchResults.at(i)->getDateIssued();
            cout << endl;
        }
    }
    returnToDashboard();
}