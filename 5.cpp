#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template <typename T>
void printArray(T *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int intArray[n];
    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> intArray[i];
    }

    float floatArray[n];
    cout << "Enter " << n << " floats:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> floatArray[i];
    }

    selectionSort(intArray, n);
    cout << "Sorted Integer Array: ";
    printArray(intArray, n);

    selectionSort(floatArray, n);
    cout << "Sorted Float Array: ";
    printArray(floatArray, n);

    return 0;
}
