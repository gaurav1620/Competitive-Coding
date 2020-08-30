#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		//START
		long long n,a,b;
		cin>>n>>a>>b;

		//Even 
		if(n%2 == 0){
			if(2*a < b)cout<<n*a<<endl;
			else cout<<(n/2)*b<<endl;
		}
		//Odd
		else{
			if(2*a < b)cout<<n*a<<endl;
			else cout<<(n/2)*b + a<<endl;

		}
		//END
	}
	return 0;
}
