#include<bits/stdc++.h>

using namespace std;

#define fo(i,n) for(i= 0;i < n;i++)
#define ll long long 

int main(){
    vector<bool> dp(134217728/2);
    ll i = 1;
    dp[0] = false;
    bool flag = false;
    while(i <= 134217728/4){
        flag = !flag;
        ll hh = i;
        for(ll r = 0;r < hh;r++){
            if(flag)dp[i] = !dp[hh-r-1];
            else dp[i] = dp[hh-r-1];

            i++;
        }
    }

    ll t;cin>>t;
    while(t--){
        ll n,q,j,k;cin>>n>>q;
        ll arr[n];
        ll test = 0;
        fo(i,n){
            cin>>arr[i];
            if(dp[arr[i]])test++;
        }

        fo(i,q){
            ll ans = test;
            ll x;cin>>x;

            if(x < 134217728/2){
                if(dp[x])ans = n-ans;
            }else{

                if(flag && !dp[134217728/2 - 2*x])ans = n-ans; 
                if(!flag && dp[134217728/2 - 2*x])ans = n-ans; 
            }

            cout<<n-ans<<" "<<ans<<endl;
        }
    }
    return 0;
}
