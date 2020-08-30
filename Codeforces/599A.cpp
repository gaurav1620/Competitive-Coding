#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	long long  d1,d2,d3,min;
	cin>>d1>>d2>>d3;
	long long  arr[4];
	arr[0] = (d1+d2)*2;
	arr[1] = (d1+d3)*2;
	arr[2] = (d2+d3)*2;
	arr[3] = (d1+d2+d3);
	min = arr[0];

	for(int i =0;i < 4;i++){
		if(arr[i] < min)min = arr[i];
	}
	cout<<min<<endl;
	//END
	return 0;
}
