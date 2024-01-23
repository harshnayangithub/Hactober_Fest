#include <iostream>
#include <deque>

using namespace std;

int main() {
    priority_deque<int> pq;
    int choice, element;

    do {
        cout << "Priority deque Operations:" << endl;
        cout << "1. Insert Element" << endl;
        cout << "2. Delete Element" << endl;
        cout << "3. Display Highest Priority Element" << endl;
        cout << "4. Display Size of Priority deque" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                pq.push(element);
                break;
            case 2:
                if (pq.empty()) {
                    cout << "Priority deque is empty" << endl;
                } else {
                    cout << "Element deleted: " << pq.top() << endl;
                    pq.pop();
                }
                break;
            case 3:
                if (pq.empty()) {
                    cout << "Priority deque is empty" << endl;
                } else {
                    cout << "Highest priority element: " << pq.top() << endl;
                }
                break;
            case 4:
                cout << "Size of Priority deque: " << pq.size() << endl;
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please enter a valid option." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}