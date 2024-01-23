#include <iostream>
using namespace std;

void selectionSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void bubbleSort(float arr[], int n)
{
    for (int i = n - 1; i <= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j - 1] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j >= 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void displayTopFive(float arr[], int n)
{
    cout << "Top five scores: ";
    for (int i = n - 1; i >= max(0, n - 5); i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    float *percentages = new float[n];

    cout << "Enter first year percentages for each student:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> percentages[i];
    }

    while (true)
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Selection Sort & Display top five scores" << endl;
        cout << "2. Bubble Sort & Display top five scores" << endl;
        cout << "3. Insertion Sort & Display top five scores" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            selectionSort(percentages, n);
            displayTopFive(percentages, n);
            break;

        case 2:
            bubbleSort(percentages, n);
            displayTopFive(percentages, n);
            break;

        case 3:
            insertionSort(percentages, n);
            displayTopFive(percentages, n);
            break;

        case 4:
            cout << "Exiting the program. Goodbye!" << endl;
            delete[] percentages;
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    }

    return 0;
}
