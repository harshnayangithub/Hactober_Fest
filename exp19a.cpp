#include <iostream>
#include <deque>

using namespace std;

void insertFront(deque<int> &dq, int value)
{
    dq.push_front(value);
    cout << "Inserted at the front: " << value << endl;
}

void insertRear(deque<int> &dq, int value)
{
    dq.push_back(value);
    cout << "Inserted at the rear: " << value << endl;
}

void deleteFront(deque<int> &dq)
{
    if (!dq.empty())
    {
        cout << "Deleted from the front: " << dq.front() << endl;
        dq.pop_front();
    }
    else
    {
        cout << "deque is empty. Cannot delete from the front.\n";
    }
}

void deleteRear(deque<int> &dq)
{
    if (!dq.empty())
    {
        cout << "Deleted from the rear: " << dq.back() << endl;
        dq.pop_back();
    }
    else
    {
        cout << "deque is empty. Cannot delete from the rear.\n";
    }
}

void display(const deque<int> &dq)
{
    if (!dq.empty())
    {
        cout << "deque elements: ";
        for (int num : dq)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "deque is empty.\n";
    }
}

int main()
{
    deque<int> dq;

    int choice, value;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Insert at Front\n2. Insert at Rear\n3. Delete from Front\n4. Delete from Rear\n5. Display\n6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert at the front: ";
            cin >> value;
            insertFront(dq, value);
            break;
        case 2:
            cout << "Enter the value to insert at the rear: ";
            cin >> value;
            insertRear(dq, value);
            break;
        case 3:
            deleteFront(dq);
            break;
        case 4:
            deleteRear(dq);
            break;
        case 5:
            display(dq);
            break;
        case 6:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }

    } while (choice != 6);

    return 0;
}
