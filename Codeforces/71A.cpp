#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int t;
	cin>>t;
	while(t--){
		char s[100];
		cin>>s;
		if(strlen(s)>10)cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<endl;
		else cout<<s<<endl;
	//END
	}
	return 0;
}
