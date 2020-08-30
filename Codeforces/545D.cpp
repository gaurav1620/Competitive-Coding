#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int l;
	cin>>l;
	int arr[l];
	for(int i =0;i < l;i++)cin>>arr[i];

	int n =sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	int count = 0;
	int sum = 0;
	for(int i = 0;i <l ;i++){
		if(sum > arr[i]){
			count++;
		}
		sum+=arr[i];
	}
	cout<<l-count<<endl;
	//END
	return 0;
}
