#include <bits/stdc++.h>
using namespace std;


// 1 1 2 2 3 3 4 4
// 0 1 2 3 4 5 6 7
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
	    int rev = l-1;
	    int locS = arr[i];
	    int increment = 0;
	    int flag = 0;
//	    cout<<"For : "<<i<<endl;
	    while(locS <= 4 && i < l && rev >= i){
//		cout<<"\tBeg While : i :"<<i<<" LocS "<<locS <<"rev"<<rev<<endl;
	        if(locS + arr[rev] > 4){
	            //rev--;
	        }
	        else if(locS+ arr[rev] > 0){
		    flag = 1;
	            locS += arr[rev];
	            arr[rev] = 0;
	            increment++;
	            //rev--;
	        }
		if(locS)flag = 1;
		rev--;
//		cout<<"\tEnd While : i :"<<i<<" LocS "<<locS <<"rev"<<rev<<endl;
	    }
	    if(flag)ans++;
//	   cout<<"i : "<<i<<" ans : "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
