
#include <bits/stdc++.h>
using namespace std;


//int min(int x, int y) { return (x <= y) ? x : y; }


int fibonaccianSearch(int arr[], int x, int n)
{
	
	int fibk2 = 0; 
	int fibk1 = 1; 
	int fibk= fibk2 + fibk1; 

	
	while (fibk < n) {
		fibk2 = fibk1;
		fibk1 = fibk;
		fibk = fibk2 + fibk1;
	}

	int offset = -1;

	
	while (fibk > 1) {
		
		int i = min(offset + fibk2, n - 1);

		if (arr[i] < x) {
			fibk = fibk1;
			fibk1 = fibk2;
			fibk2 = fibk - fibk1;
			offset = i;
		}

		
		else if (arr[i] > x) {
			fibk = fibk2;
			fibk1 = fibk1 - fibk2;
			fibk2 = fibk - fibk1;
		}

		
		else
			return i;
	}

	
	if (fibk1 && arr[offset + 1] == x)
		return offset + 1;

	
	return -1;
}


int main()
{	
	int n; 
	cout<<"Enter number of elements in array :"<<endl;
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter elements in the array"<<endl;
	
	for(int i=0 ; i<n ;i++)
	{
		cin>>arr[i];
	}
	//int n = sizeof(arr) / sizeof(arr[0]);
	int x ;

	cout<<"--------------------------------------------------------------------"<<endl;
	
	int y=0;
	
	while(y==0)
	{
		cout<<"Enter the target element:"<<endl;
		cin>>x;
		int ind = fibonaccianSearch(arr, x, n);
		if(ind>=0)
			cout << "Found at index: " << ind<<endl;
		else
			cout << x << " is not present in the array"<<endl;
		
		cout<<"Enter 1 to Quit (or) 0 to continue"<<endl;
		cin>>y;
	
	}
	return 0;
}



