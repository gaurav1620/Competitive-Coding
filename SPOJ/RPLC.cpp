#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    
    ll t;cin>>t;
    ll tt = t;
    while(t--){
        ll n;cin>>n;
        ll arr[n+1];
        ll i,j,k;
        fo(i,n)cin>>arr[i];

        ll minn = 1;

        ll sum = 1;
        for(i = 0;i < n;i++){
            if(sum+arr[i] <= 0){
//                cout<<sum+arr[i]<<" : "<<minn<<endl;
                minn += (sum+arr[i])*-1;
                minn++;
//                cout<<"Check : "<<minn<<endl;
                sum = 1;
            }else{
                sum+=arr[i];
            }
        }
        cout<<"Scenario #"<<tt-t<<": "<<minn<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

