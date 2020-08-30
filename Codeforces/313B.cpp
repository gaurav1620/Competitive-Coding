#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char s[100000];
	int t;
	cin>>s>>t;

	int arr[strlen(s)];
	int ct = 0;
	int len = strlen(s);
	arr[0] = 0;
	for(int i = 1;i < len;i++){
		if(s[i-1] == s[i])arr[i] = ++ct;
		else arr[i] = ct;
	}

//	for(int i = 0; i < len;i++)cout<<arr[i]<<endl;

	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<arr[r-1]-arr[l-1]<<endl;	
	}
	//END
	return 0;
}
