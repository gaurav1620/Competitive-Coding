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
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    //▬▬ι═══════>
    ll t;
    cin>>t;
    while(t--){
        ll a,b;cin>>a>>b;
        ll weight = b-a;
        ll n;cin>>n;
        
        ll i,k,j;
        //fo(i,n)cin>>arr[i+1];

        ll price[n+1];
        ll wt[n+1];
        fo(i,n)cin>>price[i+1]>>wt[i+1];
        
        ll dp[weight+1];
        ll infi = 100000000000000007;

        fo(i,weight+1)dp[i] = infi;
        dp[0] = 0;
        for(i = 0;i <= weight;i++){
            for(j = 1;j <= n;j++){
                if(wt[j] <= i){
                    //ll num = (i/wt[j]);
                    ll num = 1;
                    dp[i] = min(dp[i],(num)*price[j] + dp[i-num*wt[j]]);
                }else{
                    //dp[i] = dp[]
                }
            }
        }

        //fo(i,weight+1)cout<<dp[i]<<" ";
        //cout<<endl;
        ll ans = dp[weight];
        if(ans == infi)cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<ans<<"."<<endl;

    
        
    }
    //▬▬ι═══════>
    return 0;
}

