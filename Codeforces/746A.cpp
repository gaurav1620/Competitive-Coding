#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int a,b,c;
	cin>>a>>b>>c;
	if(a > 0 && b > 1 && c > 3){
		int x,y,z;
		x = 4*a;
		y = 2*b;
		z = c;

		// 8 10 7

		if(x <= y && x <= z){
			int dd = x/4;
			int ans = dd + dd*2 + dd*4;
			cout<<ans<<endl;
		}
		else if(y <= x && y <= z){
			int dd = y/4;
			int ans = dd + dd*2 + dd*4;
			cout<<ans<<endl;
		}
		else{
			int dd = z/4;
			int ans = dd + dd*2 + dd*4;	
			cout<<ans<<endl;
		}
	}
	else cout<<0<<endl;
	//END
	return 0;
}
