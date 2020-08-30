#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char s[101];
	cin>>s;
	int l = strlen(s);
	if(l > 1){
		int a;
		if(l%2)a = l/2 +1;
		else a = l/2;
		int arr[a];
		for(int i = 0;i < a;i++){
			arr[i] = s[i*2] - '0';
		}
		int sze = sizeof(arr)/sizeof(arr[0]);
		sort(arr,arr+sze);
		
		for(int i = 0;i < a-1;i++){
			cout<<arr[i]<<"+";
		}
		cout<<arr[a-1]<<endl;
	}
	else{cout<<s[0]<<endl;}
	//END
	return 0;
}
