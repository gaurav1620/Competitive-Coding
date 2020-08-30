#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int l,b;
	cin>>l>>b;
	if(l*b == 1)cout<<0<<endl;
	else if(l == 1)cout<<b/2<<endl;
	else if(b == 1)cout<<l/2<<endl;
	else cout<<l*b/2<<endl;
	//END
	return 0;
}
