#include<bits/stdc++.h>
using namespace std;
int mod(int x){return x<0 ?-x:x;}
int main(){
	//START
	int arr[5][5];
	int f[2];
	for(int i = 0;i < 5; i++){
		for(int j =0; j < 5;j++){
			int h;
			cin>>h;
			arr[i][j] = h;
			if(h == 1){
				f[0] = i;
				f[1] = j;
			}
		}
	}
	cout<<mod(f[0]-2)+mod(f[1]-2)<<endl;
	//END
	return 0;
}


