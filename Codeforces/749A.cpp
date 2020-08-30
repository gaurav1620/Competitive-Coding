#include<bits/stdc++.h>
using namespace std;
int main(){
	//START
	int n;
	cin>>n;

	int ct = 0;
	vector <int > v;
	while(n > 0){
		++ct;
		if(n%2 == 0){
//			cout<<"Pushed 2"<<endl;
			v.push_back(2);
			n -= 2;
		}
		else {
//			cout<<"Pushed 3"<<endl;
			v.push_back(3);
			n -= 3;
		}
	}
	cout<<ct<<endl;

	for(auto x = v.begin();x !=  v.end() ;++x ){
		cout<<*x<<" ";
	}
	cout<<endl;

	//END
	return 0;
}
