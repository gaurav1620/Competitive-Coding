#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){ return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

bool sortcol(pair<pair<ll,ll>,ll> v1,pair<pair<ll,ll>,ll> v2){
    //if(v1.first.first != v2.first.first){
    //    return v1.first.first < v2.first.first;
    //}else{
        return v1.first.second < v2.first.second; 
    //}
}


bool overlapsWithPrevious(pair<pair<ll,ll>,ll> current,pair<pair<ll,ll>,ll> previous){
    if(current.first.first == previous.first.first){return true;}
    return (current.first.first <= previous.first.second);
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,i,j,k;cin>>n;
        vector<pair<pair<ll,ll>,ll>> v(n);
        fo(i,n){
            ll a,b,c;cin>>a>>b>>c;
            v[i].first.first = a;
            v[i].first.second = a+b;
            v[i].second = c;
        }

        sort(v.begin(),v.end(),sortcol);
        
    
        ll dp[n+1];
        dp[0] = 0;
        dp[1] = v[0].second;
        for(i = 2;i <= n;i++){
            ll ind = i-1;
            ll previous = i-2;
            while(previous >= 0 && overlapsWithPrevious(v[ind],v[previous]))previous--;

            if(previous == -1){
                dp[i] = max(v[ind].second,dp[i-1]);
            }else{
                dp[i] = max(dp[previous+1]+v[ind].second, dp[i-1]);
            }
        }
        cout<<dp[n]<<endl;
    
    }
    //▬▬ι═══════>
    return 0;
}

