#include <iostream>
#include <list>
#include <algorithm> // for std::find

using namespace std;

// Template class for items in the priority deque
template <typename T>
class PrioritydequeItem
{
public:
    T data;
    int priority;

    // Constructor
    PrioritydequeItem(T item, int prio)
    {
        data = item;
        priority = prio;
    }

    // Overloaded <= operator for comparing priorities
    bool operator<=(PrioritydequeItem &other) const
    {
        return priority <= other.priority;
    }
};

// Template class for the priority deque
template <typename T>
class Prioritydeque
{
private:
    list<PrioritydequeItem<T>> itemList;

public:
    // Function to insert an item with priority into the priority deque
    void insert(const T &item, int priority)
    {
        PrioritydequeItem<T> newItem(item, priority);

        // Insert at the correct position based on priority
        auto it = find_if(itemList.begin(), itemList.end(), [&newItem](const auto &elem)
                          { return !(newItem <= elem); });

        itemList.insert(it, newItem);

        cout << "Item inserted: " << item << " with priority " << priority << endl;
    }

    // Function to retrieve the highest priority item
    void getHighestPriority()
    {
        if (!itemList.empty())
        {
            cout << "Highest priority item: " << itemList.front().data << " with priority " << itemList.front().priority << endl;
        }
        else
        {
            cout << "Priority deque is empty.\n";
        }
    }

    // Function to display all items in the priority deque
    void display()
    {
        if (!itemList.empty())
        {
            cout << "Priority deque items:\n";
            for (const auto &item : itemList)
            {
                cout << item.data << " (Priority: " << item.priority << ")\n";
            }
        }
        else
        {
            cout << "Priority deque is empty.\n";
        }
    }
};

int main()
{
    // Create a priority deque of integers
    Prioritydeque<int> intPrioritydeque;

    int choice, item, priority;

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
            cout << "Enter priority: ";
            cin >> priority;
            intPrioritydeque.insert(item, priority);
            break;
        case 2:
            intPrioritydeque.getHighestPriority();
            break;
        case 3:
            intPrioritydeque.display();
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
