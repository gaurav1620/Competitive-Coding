#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

ll findAns(ll arr[],ll target, ll ind, ll ans){
    if(ind == 0 || target == 0){return 0;}
    if(arr[ind-1] == -1 || ind > target){return findAns(arr,target,ind-1,ans);}

    ll mm = (target/ind)*ind;
    ll price = (target/ind)*arr[ind-1];
    return max(findAns(arr,target,ind-1,ans),price + findAns(arr,target - mm,ind-1,ans));
}

ll findAnsUsingDp(ll arr[],ll k){
    ll dp[k+1][k+1];
    for(ll i = 0;i <= k;i++){
        ll pre = 1001;
        for(ll j = 0;j <= k;j++){
            if(i == 0|| j ==0 ){
                dp[i][j] = 0;
            }else{
                if(arr[j] == -1 || i<j){
                    dp[i][j] = pre;
                }else{
                    ll q = i/j;
                    ll r = i%j;
                    dp[i][j] = min(pre,q*arr[j]+dp[r][j]);
                    pre = dp[i][j];
                }
            }
        }
    }
    return dp[k][k];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll arr[k+1];
        arr[0] = -1;
        ll i,j;
        
        fo(i,k){
            cin>>arr[i+1];
        }
        cout<<(findAnsUsingDp(arr,k) == 1001 ? -1:findAnsUsingDp(arr,k))<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

