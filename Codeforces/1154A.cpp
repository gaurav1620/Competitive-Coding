#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int a,b,c;
	int w,x,y,z;
	int arr[4];
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	int nnn = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+nnn);
	x = arr[0];y = arr[1];w = arr[2];
	cout<<(x-y+w)/2<<" "<<(w-x+y)/2<<" "<<(-w+x+y)/2<<endl;
	//END
	return 0;
}
