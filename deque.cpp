#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int arr[MAX_SIZE];
int front = -1, rear = -1;

bool isFull()
{
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

bool isEmpty()
{
    return front == -1;
}

void insertFront(int value)
{
    if (isFull())
    {
        cout << "deque is full. Cannot insert at the front.\n";
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    else
    {
        front--;
    }

    arr[front] = value;
    cout << "Inserted at the front: " << value << endl;
}

void insertRear(int value)
{
    if (isFull())
    {
        cout << "deque is full. Cannot insert at the rear.\n";
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    arr[rear] = value;
    cout << "Inserted at the rear: " << value << endl;
}

void deleteFront()
{
    if (isEmpty())
    {
        cout << "deque is empty. Cannot delete from the front.\n";
        return;
    }

    cout << "Deleted from the front: " << arr[front] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        cout << "deque is empty. Cannot delete from the rear.\n";
        return;
    }

    cout << "Deleted from the rear: " << arr[rear] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "deque is empty.\n";
        return;
    }

    cout << "deque elements: ";
    int i = front;

    while (true)
    {
        cout << arr[i] << " ";

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX_SIZE;
    }

    cout << endl;
}

int main()
{
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
            insertFront(value);
            break;
        case 2:
            cout << "Enter the value to insert at the rear: ";
            cin >> value;
            insertRear(value);
            break;
        case 3:
            deleteFront();
            break;
        case 4:
            deleteRear();
            break;
        case 5:
            display();
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
