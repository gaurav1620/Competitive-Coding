#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int f = 0;
	while(t--){
		//START
		char arr[10];
		cin>>arr;
		if(arr[1] == '-'){f--;}
		else {f++;}
		//END
	}
	cout<<f<<endl;
	return 0;
}
