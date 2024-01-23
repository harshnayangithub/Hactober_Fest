#include <bits/stdc++.h>
using namespace std;

const int maxi = 10;
int arr[maxi];
int front = -1, rear = -1;

bool isfull()
{
    if (front > rear || (front == 0 && rear == (maxi - 1)))
        {
            return true;
        }
        return false;
}
bool isempty()
{
    if (front == -1)
       {
        return true;
       }
       return false;
}
void add_front(int value)
{

    if (isfull())
    {
        cout << "Deque is full" << endl;
        return;
    }
    else
    {
        if (isempty())
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = maxi - 1;
        }
        else
        {
            front--;
        }
        arr[front] = value;
        cout << "Inserted at the front: " << value << endl;
    }
}
void add_rear(int value)
{
    if (isfull())
    {
        cout << "Deque is full" << endl;
        return;
    }
    else
    {
        if (isempty())
        {
            front = rear = 0;
        }
        else if (rear == maxi - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
            ;
        }
        arr[rear] = value;
        cout << "Inserted at the rear: " << value << endl;
    }
}
void delete_front()
{
    if (isempty())
    {
        cout << "Deque is empty." << endl;
        return;
    }
    else
    {
        if (front == rear)
        { // only one element is present.
            front = rear = -1;
        }
        else if (front == maxi - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
}
void delete_back()
{
    if (isempty())
    {
        cout << "Deque is empty." << endl;
        return;
    }
    else
    {
        if (front == rear)
        { // only one element is present.
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = maxi - 1;
        }
        else
        {
            rear--;
        }
    }
}
void display()
{
    if (isempty())
    {
        cout << "nothing";
    }
    else
    {
        int i = front;
        cout << "deque elements: ";
        while (true)
        {
            cout << arr[i] << " ";//you know mistake it is.
            if (i == rear)
                break;
            i = (i + 1) % maxi;
        }
    }
}
int main()
{
    int value, choice;
    while (true)
    {
        cout << "\nMenu:\n1.Insert at Front\n2.Insert at Rear\n3.Delete from Front\n4.Deletefrom rear\5.Exit";
        cout << "enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "enter the value to be inserted at first: ";
            cin >> value;
            add_front(value);
        }
        else if (choice == 2)
        {
            cout << "enter the value to be inserted at last: ";
            cin >> value;
            add_rear(value);
        }
        else if (choice == 3)
        {
            cout << "enter the value to be deleted at first: ";

            delete_front();
        }
        else if (choice == 4)
        {
            cout << "enter the value to be deleted at last: ";

            delete_back();
        }
        else
        {
            cout << "exiting the program" << endl;
            break;
        }
    }
}