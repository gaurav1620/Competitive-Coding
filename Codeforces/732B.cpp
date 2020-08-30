#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define revfo(i,n) for(i = n-1;i > -1;i--)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
using namespace std;

int main(){
    
  //START
  int n,k,i;
  cin>>n>>k;
  int arr[n];
  fo(i,n)cin>>arr[i];
  int totalAdd = 0;
  revfo(i,n-1){
    int sum = arr[i] + arr[i+1];
    if(sum < k){
      arr[i] += k - sum;
      totalAdd += k-sum;
    }
  }
  cout<<totalAdd<<endl;
  fo(i,n)cout<<arr[i]<<" ";
  cout<<endl;
	//END
  return 0;

}
