#include <iostream>
using namespace std;

struct Node {
    string PRN;
    string name;
    string Post;
    Node* next;
};

class PinnacleClub {
private:
    Node* president; // First node reserved for the president
    Node* secretary; // Last node reserved for the secretary
    Node* head; // Head of the linked list

public:
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
        head = nullptr;
    }

    void addMember(string post, string prn, string name) {
        Node* newNode = new Node;
        newNode->PRN = prn;
        newNode->name = name;
        newNode->Post = post;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            president = head;
            secretary = head;
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }
    }

    void deleteMember(string post, string prn) {
        Node* current = head;
        Node* prev = nullptr;

        if (current != nullptr && current->Post == post && current->PRN == prn) {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && (current->Post != post || current->PRN != prn)) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member with PRN " << prn << " and Post " << post << " not found." << endl;
            return;
        }

        prev->next = current->next;

        if (current == secretary) {
            secretary = prev;
        }

        delete current;
    }

    int totalMembers() {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void displayMembers() {
        Node* current = head;
        cout << "Members of the Club:" << endl;
        while (current != nullptr) {
            cout << "Post: " << current->Post << "\tPRN: " << current->PRN << "\tName: " << current->name << endl;
            current = current->next;
        }
    }

    void concatenateLists(PinnacleClub& otherList) {
        if (head == nullptr) {
            head = otherList.head;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = otherList.head;
        }
    }
};

int main() {
    PinnacleClub computerEngineeringClub;
    PinnacleClub otherDivisionClub;

    int choice;
    string prn, name, post;

    do {
        cout << "\nPinnacle Club Management System" << endl;
        cout << "1. Add President" << endl;
        cout << "2. Add Secretary" << endl;
        cout << "3. Add Other Member" << endl;
        cout << "4. Delete President" << endl;
        cout << "5. Delete Secretary" << endl;
        cout << "6. Delete Other Member" << endl;
        cout << "7. Total Members" << endl;
        cout << "8. Display Members" << endl;
        cout << "9. Concatenate Lists" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Add President
                cout << "Enter PRN for President: ";
                cin >> prn;
                cout << "Enter Name for President: ";
                cin.ignore();
                getline(cin, name);
                computerEngineeringClub.addMember("President", prn, name);
                break;

            case 2: // Add Secretary
                cout << "Enter PRN for Secretary: ";
                cin >> prn;
                cout << "Enter Name for Secretary: ";
                cin.ignore();
                getline(cin, name);
                computerEngineeringClub.addMember("Secretary", prn, name);
                break;

            case 3: // Add Other Member
                cout << "Enter Post for Member: ";
                cin >> post;
                cout << "Enter PRN: ";
                cin >> prn;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                computerEngineeringClub.addMember(post, prn, name);
                break;

            case 4: // Delete President
                cout << "Enter PRN for President to delete: ";
                cin >> prn;
                computerEngineeringClub.deleteMember("President", prn);
                break;

            case 5: // Delete Secretary
                cout << "Enter PRN for Secretary to delete: ";
                cin >> prn;
                computerEngineeringClub.deleteMember("Secretary", prn);
                break;

            case 6: // Delete Other Member
                cout << "Enter Post for Member to delete: ";
                cin >> post;
                cout << "Enter PRN for Member to delete: ";
                cin >> prn;
                computerEngineeringClub.deleteMember(post, prn);
                break;

            case 7: // Total Members
                cout << "Total members: " << computerEngineeringClub.totalMembers() << endl;
                break;

            case 8: // Display Members
                computerEngineeringClub.displayMembers();
                break;

            case 9: // Concatenate Lists
                cout << "Adding members to other division club for concatenation:" << endl;
                otherDivisionClub.addMember("PRN4", "Student4", "Post4");
                otherDivisionClub.addMember("PRN5", "Student5", "Post5");
                computerEngineeringClub.concatenateLists(otherDivisionClub);
                cout << "Lists concatenated." << endl;
                break;

            case 10: // Exit
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 10);

    return 0;
}
