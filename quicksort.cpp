#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &a, int low, int high)
{

    int pivot = a[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (a[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (a[j] > pivot && j > low)//swapping the elements in order to get the pivot position.
        {
            j--;
        }
        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[low], a[j]);
    return j;
}

void qs(vector<int> &a, int low, int high)
{

    if (low < high)
    {
        int partition = fun(a, low, high);//found out the actual position of  pivot taken of the array.
        qs(a, low, partition - 1);
        qs(a, partition + 1, high);
    }
}
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}





int main()
{

    int n;
    cout << "Enter the no. of students:";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the percentage of marks of each student: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    qs(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}