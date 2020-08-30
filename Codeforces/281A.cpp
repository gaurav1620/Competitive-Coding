#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char a[1001];
	cin>>a;
	if(!(a[0] >= 'A' && a[0] <= 'Z'))a[0] = a[0] - 'a' +'A';
	cout<<a<<endl;
	//END
	return 0;
}
