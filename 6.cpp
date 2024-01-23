#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Item {
public:
    int code;
    string name;
    double cost;
    int quantity;
    Item() : code(0), name(""), cost(0.0), quantity(0) {}

    Item(int c, const string& n, double co, int q)
        : code(c), name(n), cost(co), quantity(q) {}

    void display() const {
        cout << "Code: " << code << "\tName: " << name
             << "\tCost: " << cost << "\tQuantity: " << quantity << endl;
    }
};

class Record {
private:
    vector<Item> items;

public:
    void insertAndSortItem() {
        Item newItem;
        cout << "Enter Item Code: ";
        cin >> newItem.code;
        cout << "Enter Item Name: ";
        cin >> newItem.name;
        cout << "Enter Item Cost: ";
        cin >> newItem.cost;
        cout << "Enter Item Quantity: ";
        cin >> newItem.quantity;

        items.push_back(newItem);

        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.code < b.code;
        });

        cout << "Item inserted and sorted successfully.\n";
    }

    void searchItemByName() const {
        string searchName;
        cout << "Enter Item Name to search: ";
        cin >> searchName;

        auto it = find_if(items.begin(), items.end(), [&searchName](const Item& item) {
            return item.name == searchName;
        });

        if (it != items.end()) {
            cout << "Item found:\n";
            it->display();
        } else {
            cout << "Item not found.\n";
        }
    }

    void searchItemByCode() const {
        int searchCode;
        cout << "Enter Item Code to search: ";
        cin >> searchCode;

        auto it = lower_bound(items.begin(), items.end(), searchCode, [](const Item& a, int value) {
            return a.code < value;
        });

        if (it != items.end() && it->code == searchCode) {
            cout << "Item found:\n";
            it->display();
        } else {
            cout << "Item not found.\n";
        }
    }

    void displayAllItems() const {
        cout << "All Items:\n";
        for (const auto& item : items) {
            item.display();
        }
    }
};

int main() {
    Record record;
    int choice;
    do {
        cout << "\nMenu:\n"
             << "1. Insert & Sort Item\n"
             << "2. Search Item By Name\n"
             << "3. Search Item By Code\n"
             << "4. Display All Items\n"
             << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                record.insertAndSortItem();
                break;
            case 2:
                record.searchItemByName();
                break;
            case 3:
                record.searchItemByCode();
                break;
            case 4:
                record.displayAllItems();
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
