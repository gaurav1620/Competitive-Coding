#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int l;
	cin>>l;
	int arr[l];
	for(int i = 0;i < l;i++){
		cin>>arr[i];
	}

	if(l < 3){cout<<0<<endl;}
	else {
		int tmpN = sizeof(arr)/sizeof(arr[0]);
		sort(arr,arr+tmpN);

		//ENTER CODE HERE 
		//REMAINING

	}
	//END
	return 0;
}
