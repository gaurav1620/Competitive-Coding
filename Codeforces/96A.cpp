#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char s[101];
	cin>>s;
	int c = 0;
	if(strlen(s) <= 7){cout<<"NO"<<endl;return 0;}
	for(int i = 0;i < strlen(s)-6;i++){
		int f = 0;
		char d = s[i];
		for(int j = i; j < i+7;j++){
			if(d != s[j])f=1;
		}
		if(!f)c=1;
	}
	if(c)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	//END
	return 0;
}
