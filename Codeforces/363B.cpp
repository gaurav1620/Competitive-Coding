#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define deb(x) cout<<"DEBUG : "<<x<<endl;
using namespace std;

int main(){
	//START
	ll n,k;
	cin>>n>>k;
	int arr[n];
	int i;

	int min = INT_MAX,minInd = 0;
	int sum = 0;
	fo(i,n){
		cin>>arr[i];
		if(i > k-1){
			sum = sum+arr[i]-arr[i-k];
//			deb(sum);
			if(sum < min){
				minInd = i-k+1;
				min = sum;
//				cout<<" :: "<<minInd<<" :: "<<min<<endl;
			}
		}
		else{
			sum+=arr[i];
//			deb(sum);
			min = sum;
		}
	}
	cout<<minInd+1<<endl;
	//END
	return 0;
}
