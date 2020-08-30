#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i =0;i < n;i++) cin>>arr[i];
	int c= 0;
	for(int i =0; i < n; i++){
		if(arr[i] >= arr[k-1] && arr[i] != 0) c++;
	}
	cout<<c<<endl;
	//END
	return 0;
}
