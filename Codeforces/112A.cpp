#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char a[104],b[104];
	cin>>a>>b;
	for(int i = 0;i < strlen(a);i++){
		if(a[i] >= 'A' && a[i] <= 'Z'){
			a[i] = a[i] - 'A' + 'a';
		}
		if(b[i] >= 'A' && b[i] <= 'Z'){
			b[i] = b[i] - 'A' + 'a'; 
		}
	}
	cout<<strcmp(a,b)<<endl;
	//END
	return 0;
}
