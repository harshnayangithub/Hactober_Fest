#include <bits/stdc++.h>
using namespace std;
// most important of all whenevr you are using binarysearch make sure your array is sorted.
int binarySearchRecursive(vector<pair<string, string>> &phonebook, int low, int high, string target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (phonebook[mid].first == target)
    {
        cout << "Friend found: " << phonebook[mid].first << ", Phone number: " << phonebook[mid].second << endl;
        return mid;
    }
    else if (phonebook[mid].first < target)
        return binarySearchRecursive(phonebook, mid + 1, high, target); // always return statement
    else
    {
        return binarySearchRecursive(phonebook, low, mid - 1, target);
    }
}

int binarySearchIterative(vector<pair<string, string>> &phonebook, string target)
{
    int low = 0, high = phonebook.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (phonebook[mid].first == target)
        {
            cout << "Friend found: " << phonebook[mid].first << ", Phone number: " << phonebook[mid].second << endl;
            return mid; // always return
        }
        else if (phonebook[mid].first < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // always return
}

int fibonacciSearch(vector<pair<string, string>> &phonebook, string target)
{
    int fibMMm2 = 0, fibMMm1 = 1, fibM = fibMMm1 + fibMMm2;

    while (fibM < phonebook.size())
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm1 + fibMMm2;
    }

    int offset = -1;
    int n = phonebook.size() - 1;
    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n);

        if (phonebook[i].first < target)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (phonebook[i].first > target)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            cout << "Friend found: " << phonebook[i].first << ", Phone number: " << phonebook[i].second << endl;
            return i;
        }
    }

    if (fibMMm1 && phonebook[offset + 1].first == target)
    {
        cout << "Friend found: " << phonebook[offset + 1].first << ", Phone number: " << phonebook[offset + 1].second << endl;
        return offset + 1;
    }

    return -1;
}

void insertFriend(vector<pair<string, string>> &phonebook, string &name, string &number)
{
    phonebook.push_back(make_pair(name, number));
    cout << "Friend added successfully." << endl;
}

void displayPhonebook(vector<pair<string, string>> phonebook)
{
    cout << "Phonebook:" << endl;
    for (auto &friendInfo : phonebook)
    {
        cout << friendInfo.first << ": " << friendInfo.second << endl;
    }
}

int main()
{
    vector<pair<string, string>> phonebook = {{"Alice", "123456789"}, {"Bob", "987654321"}, {"Charlie", "555555555"}};
    sort(phonebook.begin(), phonebook.end());
    while (true)
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Search friend using Binary Search (Recursive)" << endl;
        cout << "2. Search friend using Binary Search (Iterative)" << endl;
        cout << "3. Search friend using Fibonacci Search" << endl;
        cout << "4. Insert friend in phonebook" << endl;
        cout << "5. Display phonebook" << endl;
        cout << "6. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (choice == 1)
        {
            string nameToSearch;
            cout << "Enter the name to search: ";
            cin >> nameToSearch;
            int result = binarySearchRecursive(phonebook, 0, phonebook.size() - 1, nameToSearch);
            if (result == -1)
            {
                cout << "Not Present in Phonebook But don't worry add it." << endl;
                string nameToInsert, numberToInsert;
                cout << "Enter the name to insert: ";
                cin >> nameToInsert;
                cout << "Enter the number to insert: ";
                cin >> numberToInsert;
                insertFriend(phonebook, nameToInsert, numberToInsert);
                // cout << nameToSearch << " not found in phonebook" << endl;
            }
        }
        else if (choice == 2)
        {
            string nameToSearch;
            cout << "Enter the name to search: ";
            cin >> nameToSearch;
            int result = binarySearchIterative(phonebook, nameToSearch);
            if (result == -1)
            {
                cout << "Not Present in Phonebook But don't worry add it." << endl;
                string nameToInsert, numberToInsert;
                cout << "Enter the name to insert: ";
                cin >> nameToInsert;
                cout << "Enter the number to insert: ";
                cin >> numberToInsert;
                insertFriend(phonebook, nameToInsert, numberToInsert);
                // cout << nameToSearch << " not found in phonebook" << endl;
            }
        }
        else if (choice == 3)
        {
            string nameToSearch;
            cout << "Enter the name to search: ";
            cin >> nameToSearch;
            int result = fibonacciSearch(phonebook, nameToSearch);
            if (result == -1)
            {
                cout << "Not Present in Phonebook But don't worry add it." << endl;
                string nameToInsert, numberToInsert;
                cout << "Enter the name to insert: ";
                cin >> nameToInsert;
                cout << "Enter the number to insert: ";
                cin >> numberToInsert;
                insertFriend(phonebook, nameToInsert, numberToInsert);
                // cout << nameToSearch << " not found in phonebook" << endl;
            }
        }
        else if (choice == 4)
        {
            string nameToInsert, numberToInsert;
            cout << "Enter the name to insert: ";
            cin >> nameToInsert;
            cout << "Enter the number to insert: ";
            cin >> numberToInsert;
            insertFriend(phonebook, nameToInsert, numberToInsert);
        }
        else if (choice == 5)
        {
            displayPhonebook(phonebook);
        }
        else if (choice == 6)
        {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}
