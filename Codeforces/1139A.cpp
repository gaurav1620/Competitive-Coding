#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	long long l,n;
	cin>>l>>n;
	int ct = 0;
	long long lcp = l;
	while(lcp--){
//		cout<<"check : "<<n%10<<endl;
		int e = n%10;
		n/=10;
		if(e%2 == 0){
			ct += lcp+1;
//			cout<<e<<" : "<<lcp+1<<" : "<<ct<<endl;
		
		}
	}
	cout<<ct<<endl;
	//END
	return 0;
}
