#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
using namespace std;

ll fact(ll i){
  if(i < 2)return 1;
  else return i*fact(i-1);
}

int main(){
	//START
  ll a,b;
  cin>>a>>b;
  a > b ? cout<<fact(b)<<endl:cout<<fact(a)<<endl;
	//END
	return 0;
}
