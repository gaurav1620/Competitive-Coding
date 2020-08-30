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
    while(t--){
        ll a,b;cin>>a>>b;
    
        ll ans = 0;
        for(ll i = max(0,a);i <= min(3,b);i++){
            ans++;
        }
        cout<<ans<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

