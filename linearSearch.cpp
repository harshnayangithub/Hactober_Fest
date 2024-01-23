#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of elements of array:"<<endl;
	 cin>>n;
	int arr[n];
	
	cout<<"Enter element of array:"<<endl;
	for(int i=0 ; i<n ; i++)
	{
		
		cin>>arr[i];
	}
	
	int b;
	cout<<"Enter element for searching:"<<endl;
	cin>>b;
	
	int flag=0;
	
	
	
	for(int i=0 ; i<n ; i++)
	{
		if(arr[i]==b)
		{
			cout<<"Element Found"<<endl;
			cout<<"Position of Element is:"<<i<<endl;
			flag=1;
			break;
		}
	}
	
	if(flag==0)
	{
		cout<<"Element not fouond"<<endl;
	}
}
