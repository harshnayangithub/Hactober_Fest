#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int low, int high, int mid)
{
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void mergesort(vector<int> &a, int low, int high)
{
    

    if (low == high)
        return;
        int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, high, mid);
}

int main()
{
    int n;
    cout << "Enter the Number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter Elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}