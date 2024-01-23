#include<iostream>
using namespace std;

void BubbleSort(int arr[],int n)
{	
	int cnt=0;
	cout<<"-------------------BUBBLE SORT-----------------------"<<endl;
	for(int i=0 ; i<n-1 ; i++)
	{
		for(int j=0 ; j<n-i-1 ; j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
			cnt++;
		}
		
		cout<<"Array after Pass"<<i+1<<endl;
		for(int i=0 ; i<n ; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
		cout<<"Total numbetr of comparisions are :"<<cnt<<endl;
		
	}
	
}

void SelectionSort(int arr[],int n)
{	
	int cnt1=0;
	cout<<"-------------------SELECTION SORT --------------------"<<endl;
	int min_index=0;
	
	for(int i=0 ; i<n-1; i++)
	{
		min_index=i;
		
		for(int j=i+1; j<n;j++)
		{
			if(arr[j]<arr[min_index])
			{
				min_index=j;
			}
			cnt1++;
		}
		
		if(min_index != i)
		{
			swap(arr[min_index],arr[i]);
		}
		
		cout<<"Array after Pass"<<i+1<<endl;
		for(int i=0 ; i<n ; i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		
		cout<<"Total numbetr of comparisions are :"<<cnt1<<endl;
	}
	
}

void InsertionSort(int arr[],int n)
{	
	cout<<"------------------INSERTION SORT --------------------"<<endl;
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
	
}

void printArray(int arr[],int n)
{
	for(int i=0 ; i<n ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n ;
	cout<<"Enter the total number of elements:"<<endl;
	cin>>n;
	
	int arr[n];
	
	cout<<"Enter elements of the array:"<<endl;
	
	for(int i=0 ; i<n ; i++)
	{
		cin>>arr[i];
	}
	
	bool ans = false;
	
	for(int i=0 ; i<n ; i++)
	{
		if(arr[i] > arr[i+1])
		{
			ans=true;
			break;
		}
	}
	
	if(ans==true)
	{
		int choice;
		
		cout<<"------------------------MENU----------------------------"<<endl;
		cout<<"1.Bubble sort"<<endl;
		cout<<"2.Selection sort"<<endl;
		cout<<"3.Insertion sort"<<endl;
		
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		
		if(choice ==  1)
		{
			BubbleSort(arr,n);
			cout<<"The Sorted Array is:";
			printArray(arr,n);
		}
		else if(choice==2)
		{
			SelectionSort(arr,n);
			cout<<"The Sorted Array is:";
			printArray(arr,n);
		}
		else
		{
			InsertionSort(arr,n);
			cout<<"The sorted array is:";
			printArray(arr,n);
		}
	}
	else
	{
		cout<<"The Sorted Array is:";
		printArray(arr,n);
	}
	
}
