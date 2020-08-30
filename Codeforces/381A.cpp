#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
using namespace std;

int main(){
	//START
    int i,n;
    cin>>n;
    int arr[n];
    fo(i,n) cin>>arr[i];
    int left = 0,right = n-1,s = 0,r = 0;
    int chance = 1;
    while(right >= left){
        if(chance){
            chance = 0;
            if(arr[left] > arr[right]){
                s += arr[left];
                left++;
            }else{
                s+= arr[right];
                right--;
            }
        }else{
            chance = 1;
            if(arr[left] > arr[right]){
                r += arr[left];
                left++;
            }else{
                r += arr[right];
                right--;
            }
        }
    }
    cout<<s<<" "<<r<<endl;
       
    
	//END
	return 0;
}
