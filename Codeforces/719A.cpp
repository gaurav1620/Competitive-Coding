#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int A[30] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i < n;i++)cin>>arr[i];

	if(n > 1){
		//last is greater than second last
		if(arr[n-1] > arr[n-2]){
			if(arr[n-1] != 15)cout<<"UP"<<endl;
			else cout<<"DOWN"<<endl;
		}
		//last is lesser than second last
		else if(arr[n-1] < arr[n-2]){
			if(arr[n-1] != 0)cout<<"DOWN"<<endl;
			else cout<<"UP"<<endl;
		}
	}
	else if(n == 1 && arr[0] == 15)cout<<"DOWN"<<endl;
	else if(n == 1 && arr[0] == 0)cout<<"UP"<<endl;
	else cout<<-1<<endl;
	//END
	return 0;
}
