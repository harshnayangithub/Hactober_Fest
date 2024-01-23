#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of elements:"<<endl;
	cin>>n;
	
	
	
	vector<pair<int,string>>v;
	cout<<"Enter Roll  number and Name"<<endl;
	for(int i=0 ; i<n ; i++)
	{
		int roll; cin>>roll;
		string name;
		cin>>name;
		v.push_back({roll,name});
	}
	
	sort(v.begin(),v.end());
	
	int key; 
	
	cout<<"Enter key for searching"<<endl;
	cin>>key;
	
	int low=0,up=n-1,mid=0,flag=0;
	
	while(low<=up)
	{

		
		mid = (low+up)/2;
		
		if(v[mid].first==key)
		{
		
			cout<<"The Roll no is : "<<v[mid].first<<endl;
			cout<<"The name of the student is:"<<v[mid].second<<endl;
			flag=1;
			break;
		
		}
		else if(key<v[mid].first)
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
