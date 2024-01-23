#include <iostream>
#include <cstring>
using namespace std;

// Node structure for singly linked list
struct Node
{
    int prn;
    string name;
    Node *next;
};

// Singly linked list class
class ClubList
{
public:
    Node *head;

public:
    ClubList()
    {
        head = nullptr;
    }

    // Function to add a member at the end
    void addMember(int prn, const string &name)
    {
        Node *newNode = new Node();
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr)
        {
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
        }
        cout << "Member added successfully.\n";
    }

    // Function to delete a member by PRN
    void deleteMember(int prn)
    {
        if (head == nullptr)
        {
            cout << "Club is empty. Cannot delete member.\n";
            return;
        }

        if (head->prn == prn)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Member deleted successfully.\n";
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;

        while (temp != nullptr && temp->prn != prn)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Member with PRN " << prn << " not found.\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Member deleted successfully.\n";
    }

    // Function to compute the total number of members
    int getTotalMembers()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Function to display members
    void displayMembers()
    {
        if (head == nullptr)
        {
            cout << "Club is empty.\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    // Function to display list in reverse order using recursion
    void displayReverse(Node *temp)
    {
        if (temp == nullptr)
        {
            return;
        }
        displayReverse(temp->next);
        cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
    }

    // Function to concatenate two lists
    void concatenateLists(ClubList &otherList)
    {
        if (otherList.head == nullptr)
        {
            cout << "Second list is empty. Nothing to concatenate.\n";
            return;
        }

        if (head == nullptr)
        {
            head = otherList.head;
            cout << "Lists concatenated successfully.\n";
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = otherList.head;

        cout << "Lists concatenated successfully.\n";
    }
};

int main()
{
    ClubList clubList1, clubList2;
    int choice;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Add Member\n2. Delete Member\n3. Total Members\n4. Display Members\n5. Display Reverse\n";
        cout << "6. Concatenate Lists\n7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int prn;
            string name;
            cout << "Enter PRN: ";
            cin >> prn;
            cin.ignore(); // Clear the newline character from the buffer
            cout << "Enter Name: ";
            getline(cin, name);
            clubList1.addMember(prn, name);
            break;
        }
        case 2:
        {
            int prn;
            cout << "Enter PRN to delete: ";
            cin >> prn;
            clubList1.deleteMember(prn);
            break;
        }
        case 3:
            cout << "Total Members: " << clubList1.getTotalMembers() << endl;
            break;
        case 4:
            cout << "Members of the Club:\n";
            clubList1.displayMembers();
            break;
        case 5:
            cout << "Members of the Club in Reverse Order:\n";
            clubList1.displayReverse(clubList1.head);
            break;
        case 6:
            cout << "Enter members for the second list:\n";
            int members;
            cout << "Enter the number of members: ";
            cin >> members;
            for (int i = 0; i < members; i++)
            {
                int prn;
                string name;
                cout << "Enter PRN: ";
                cin >> prn;
                cin.ignore(); // Clear the newline character from the buffer
                cout << "Enter Name: ";
                getline(cin, name);
                clubList2.addMember(prn, name);
            }
            clubList1.concatenateLists(clubList2);
            break;
        case 7:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

    } while (choice != 7);

    return 0;
}
