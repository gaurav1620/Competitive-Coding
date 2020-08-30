#include<bits/stdc++.h>
using namespace std;
int main(){
	//START
	int l;
	long long n;
	cin>>l>>n;
	long long  h = n;
	int arr[l];
	//Populate the array with the digits of the number
	for(int i =0; i < l;i++){
        // cout<<"Adding to arr[] : "<<h%10<<endl;
		arr[i] = h%10;
		h /= 10;
	}

    int sol[200];

    for(int i =0 ;i < 200;i++){
        sol[i] = -1;
    }

    // for(int i =0; i < l;i++){
        
    //     cout<<arr[i]<<endl;
    // }

    int ind = 0;
    for(int i = 0;i < l;i++){
        if(arr[i] == 2)sol[ind++] = 2;
        else if(arr[i] == 3)sol[ind++] = 3;
        else if(arr[i] == 5)sol[ind++] = 5;
        else if(arr[i] == 7)sol[ind++] = 7;
        else if(arr[i] == 4){
            // cout<<"ck"<<endl;
            sol[ind++] = 2;
            sol[ind++] = 2;
            sol[ind++] = 3;
        }
        else if(arr[i] == 6){
            // sol[ind++] = 2;
            sol[ind++] = 3;
            sol[ind++] = 5;
        }
        else if(arr[i] == 8){
            // cout<<"ck"<<endl;
            sol[ind++] = 2;
            sol[ind++] = 2;
            sol[ind++] = 2;
            sol[ind++] = 7;
        }
        else if(arr[i] == 9){
            sol[ind++] = 3;
            sol[ind++] = 3;
            sol[ind++] = 2;
            sol[ind++] = 7;
        }
    }
	
    int gg = sizeof(sol)/sizeof(sol[0]);
    sort(sol,sol+gg); 

    for(int i = 199;i >= 0;i--){
        // cout<<i<<" : ";

        if(sol[i] == -1)break;
        cout<<sol[i];

        // cout<<endl;
    }
    cout<<endl;

	//END
	return 0;
}