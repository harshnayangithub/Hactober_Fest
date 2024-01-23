#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> covidData;

    covidData["Maharashtra"] = 250000;
    covidData["Goa"] = 1200;
    covidData["J&K"] = 5000;
    covidData["Bihar"] = 3000;
    covidData["Kerala"] = 15000;
    covidData["Rajasthan"] = 8000;
    covidData["Haryana"] = 6000;
    covidData["Gujarat"] = 10000;

    string state;
    int choice;

    do
    {
        cout << "\n1. Find Covid19 patient count by state" << endl;
        cout << "2. Exit" << endl;
        cout << "Select choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter state name: ";
            cin >> state;

            if (covidData.find(state) != covidData.end())
            {
                cout << "Covid19 patient count in " << state << ": " << covidData[state] << endl;
            }
            else
            {
                cout << "State not found in the data." << endl;
            }
            break;

        case 2:
            cout << "---Exiting---" << endl;
            break;

        default:
            cout << "Enter a valid choice." << endl;
            break;
        }
    } while (choice != 2);

    return 0;
}
