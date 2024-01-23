#include <iostream>
#include <deque>

using namespace std;

int main()
{
    priority_queue<int> pq;

    int choice, item;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Insert item\n2. Get highest priority item\n3. Display items\n4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter item: ";
            cin >> item;
            pq.push(item);
            cout << "Item inserted: " << item << endl;
            int p;
            cout << "Enter the Priority: ";
            cin >> p;
            break;
        case 2:
            if (!pq.empty())
            {
                cout << "Highest priority item: " << pq.top() << endl;
            }
            else
            {
                cout << "Priority deque is empty.\n";
            }
            break;
        case 3:
            if (!pq.empty())
            {
                cout << "Priority deque items:\n";
                // Use an iterator to traverse and display the elements
                priority_queue<int> copydeque = pq; // Create a copy as priority_deque doesn't provide iterators
                while (!copydeque.empty())
                {
                    cout << copydeque.top() << " ";
                    copydeque.pop();
                }
                cout << endl;
            }
            else
            {
                cout << "Priority deque is empty.\n";
            }
            break;

        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}
