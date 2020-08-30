#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int n;
	cin>>n;
	int cp = n;
	int ct = 0;
	while(cp){
		ct += cp+ (cp-1)*(n-cp);
		cp--;
	}
	cout<<ct<<endl;

	//cout<<ans(n)<<endl;
	/*int h;
	cin>>h;
	int s = 0;
	for(int i = h;i > 0;i--){
		s += i;
	}
	cout<<s+h<<endl;
	*/
	//END
	return 0;
}
