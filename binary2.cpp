#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	
	
	
	vector<int>v;
	for(int i=1 ; i<n ; i++)
	{
		
		v.push_back(i);
	}
	
	sort(v.begin(),v.end());
	
	int key; 
	
	cout<<"Enter key for searching"<<endl;
	cin>>key;
	
	int low=0,up=n-1,mid=0,flag=0,cnt=0;
	
	while(low<=up)
	{

		cnt++;
		mid = (low+up)/2;
		
		if(v[mid]==key)
		{
			cout<<"Element Found"<<endl;
			cout<<"Number of comparisions:"<<cnt<<endl;
			flag=1;
			break;
		
		}
		else if(key<v[mid])
		{
			up=mid-1;
		}
		else
		{
			low=mid+1;
		}
		
	}
	
	if(flag==0)
	{
		cout<<"Key value not found"<<endl;
	}
	
}
