#include <iostream>
using namespace std;

class convert {
protected:
    double val1, val2;
public:
    double getInit() const {
        return val1;
    }
    double getConv() const {
        return val2;
    }
    virtual void compute() = 0;
    convert(double initval) : val1(initval), val2(0){};
};

class distanceconvertor : public convert {
public:
    distanceconvertor(double initval) : convert(initval){};
    void compute() override {
        val2 = val1 * 3.28084;
    }
};

class tempconvertor : public convert {
public:
    tempconvertor(double initval) : convert(initval){};
    void compute() override {
        val2 = (val1 * 9 / 5) + 32;
    }
};

int main() {
    double initval1;
    double initval2;
    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Convert distance\n";
        cout << "2. Convert temperature\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Enter the initial value:-- ";
            cin >> initval1;
            distanceconvertor distance(initval1);
            distance.compute();
            cout << "Initial Value: " << distance.getInit() << " meters" << endl;
            cout << "Converted Value: " << distance.getConv() << " feet" << endl;
            break;
        }
        case 2: {
            cout << "Enter the initial value:-- ";
            cin >> initval2;
            tempconvertor temp(initval2);
            temp.compute();
            cout << "Initial Value: " << temp.getInit() << " F" << endl;
            cout << "Converted Value: " << temp.getConv() << " C" << endl;
            break;
        }
        case 3:
            cout << "-----Exiting program-----\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}
