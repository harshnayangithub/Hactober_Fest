#include<bits/stdc++.h>
#include<cstdlib>
#include<ctime>
#define int long long 
using namespace std ;

void show(vector<int> arr){
	int n = arr.size() ;
	for(auto val : arr) cout<<val<<" ";
	cout<<endl;
}

signed main(){
	cout<<"Enter the total number of inputs\n";
	int n ;
	cin >> n ;
	vector<int> arr(n) ;
	for(int i = 0 ; i < n ; i++){
		int num = rand()%10000 ;
		arr[i] = num ;
	}
	cout<<"How would you like to sort the array\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n";
	int choice;
	cin >> choice ;	
	int cnt = 0 ;
	clock_t t1 ;
	t1 = clock() ;
	if(choice==1){
		for(int i = 0 ; i < n-1 ; i++){
			for(int j = 0 ; j < n-i-1 ; j++){
				if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]) ;
				cnt++ ;
			}
		}
		cout<<"Number of comparisons are : "<<cnt<<endl;
	}
	else if(choice==2){
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				if(arr[i]>arr[j]) swap(arr[i],arr[j]);
				cnt++ ;
			}
		}
		cout<<"Number of comparisons are : "<<cnt<<endl;
	}
	else if(choice==3){
		int temp ;
		for(int i = 1 ; i < n ; i++){
			temp = arr[i] ;
			int j = i - 1 ;
			while(j>=0 && arr[j]>temp){
				cnt++ ;
				arr[j+1] = arr[j] ;
				j-- ;
			}
			arr[j+1] = temp ;
			//cout<<"Array after pass "<<i<<" is : " ;
			//show(arr) ;
		}
		cout<<"Number of comparisons are : "<<cnt<<endl;
	}
	clock_t t2 ;
	t2 = clock() ;
	double time_taken = double(t2-t1)/double(1000000) ;
	cout<<fixed<<setprecision(10) ;
	cout<<"Time Taken is : "<<time_taken<<" seconds"<<endl;
}
