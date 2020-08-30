#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int ct = 0;
	while(t--){
		//START
		int a,b,c;
		cin>>a>>b>>c;
		if((a && b)||(b && c)||(a&&c)){
			ct++;
		}
		//END
	}
	cout<<ct<<endl;
	return 0;
}
