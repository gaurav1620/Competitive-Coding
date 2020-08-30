#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	int x = 0,y = 0,z = 0;
	while(t--){
		//START
		int a,b,c;
		cin>>a>>b>>c;
		x+=a;
		y+=b;
		z+=c;
		//END
	}
	if(x==0 && y==0 &&z==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
