#include <bits/stdc++.h> 
using namespace std;
int main(){
	long long l,b,a;
	cin>>l>>b>>a;
	long long q = l%a == 0 ? l/a:l/a +1;
	long long w = b%a == 0 ? b/a:b/a +1;
	cout<<q*w<<endl;

	return 0;
}
