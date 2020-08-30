#include <bits/stdc++.h>
using namespace std;

int main(){
	int l;
	cin>>l;
	int arr[l];
	for(int i =0; i < l; i++){
		cin>>arr[i];
	}
	sort(arr,arr+l);
	int ans = 0;
	for(int i = 0;i < l;i++){
		int locA = 0;
		while(locA <= 4 && i < l){
			if(locA + arr[i] > 4){
				i--;
				//cout<<"Break!"<<endl;
				break;
			}
			//cout<<"Added!";
			locA += arr[i];
			i++;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
