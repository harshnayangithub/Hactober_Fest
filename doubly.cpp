#include <iostream>
#include <cmath>
using namespace std;

// Node structure for doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Doubly linked list class
class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = nullptr;
    }

    // Function to insert a binary digit at the end
    void insertEnd(int digit)
    {
        Node *newNode = new Node();
        newNode->data = digit;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            newNode->prev = nullptr;
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to display the binary number
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            temp->data = 1 - temp->data;
            temp = temp->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement()
    {
        onesComplement();
        Node *temp = head;
        int carry = 1;

        while (temp != nullptr)
        {
            temp->data += carry;
            if (temp->data == 2)
            {
                temp->data = 0;
            }
            else
            {
                carry = 0;
            }
            temp = temp->next;
        }

        if (carry == 1)
        {
            // If there is a carry after the addition, insert a new node with carry at the end
            insertEnd(1);
        }
    }

    // Function to add two binary numbers
    DoublyLinkedList addBinary(DoublyLinkedList &binaryNumber)
    {
        DoublyLinkedList result;
        int carry = 0;

        Node *num1 = head;
        Node *num2 = binaryNumber.head;

        while (num1 != nullptr || num2 != nullptr)
        {
            int sum = carry + (num1 ? num1->data : 0) + (num2 ? num2->data : 0);
            carry = sum / 2;
            result.insertEnd(sum % 2);

            if (num1)
                num1 = num1->next;
            if (num2)
                num2 = num2->next;
        }

        if (carry > 0)
        {
            // If there is a carry after addition, insert a new node with carry at the end
            result.insertEnd(carry);
        }

        return result;
    }
};

int main()
{
    DoublyLinkedList binaryNumber1, binaryNumber2;

    // Input binary numbers
    cout << "Enter the first binary number: ";
    string binary1;
    cin >> binary1;

    cout << "Enter the second binary number: ";
    string binary2;
    cin >> binary2;

    // Convert input strings to doubly linked lists
    for (char digit : binary1)
    {
        binaryNumber1.insertEnd(digit - '0');
    }

    for (char digit : binary2)
    {
        binaryNumber2.insertEnd(digit - '0');
    }

    // Display the input binary numbers
    cout << "Binary Number 1: ";
    binaryNumber1.display();

    cout << "Binary Number 2: ";
    binaryNumber2.display();

    // Compute 1's complement and display
    cout << "\n1's Complement of Binary Number 1: ";
    binaryNumber1.onesComplement();
    binaryNumber1.display();

    cout << "1's Complement of Binary Number 2: ";
    binaryNumber2.onesComplement();
    binaryNumber2.display();

    // Compute 2's complement and display
    cout << "\n2's Complement of Binary Number 1: ";
    binaryNumber1.twosComplement();
    binaryNumber1.display();

    cout << "2's Complement of Binary Number 2: ";
    binaryNumber2.twosComplement();
    binaryNumber2.display();

    // Add two binary numbers and display the result
    cout << "\nSum of Binary Numbers: ";
    DoublyLinkedList result = binaryNumber1.addBinary(binaryNumber2);
    result.display();

    return 0;
}
