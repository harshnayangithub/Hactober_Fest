#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"ENter total number of elements :\n";
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter the array elements: \n";
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	
	for(int i=1 ; i<n ; i++)
	{
		int temp = arr[i];
		int j=i-1;
		
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		
		cout<<"the array after Pass"<<i<<"is :";
		for(int k=0 ; k<n ; k++)
		{
			cout<<arr[k]<<" ";
		}
		cout<<endl;
		
	}
	
	
	cout<<"The sorted array is : \n";
	for(int i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	cout<<endl;
	
}
