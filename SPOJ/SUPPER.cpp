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

ll arr[100002];
bool ct[100002];
ll dp[100002];

ll uneffLisUtil(ll x){
    if(x == 0){
        return 1;
    }
    if(dp[x] != -1){
        return dp[x];
    }

    ll maxx = -1;

    for(int i = x-1;i >= 0;i--){
        if(arr[i] < arr[x]){
            maxx = max(maxx,uneffLisUtil(i)+1);
        }
    }
    dp[x] = maxx;
    return maxx;
}

ll uneffLis(ll n){
    if(n == 1){
        return 1;
    }

    ll maxx = -1;
    for(int i = n-1;i >=0;i--){
        maxx = max(maxx,uneffLisUtil(i));
    }
    return maxx;
}

ll lis(ll n){
    dp[0] = 1;
    for(ll i = 1;i < n;i++){
        for(ll j = 0;j < i;j++){
            if(dp[j] < dp[i])dp[i] = max(dp[i],dp[j+1]);
        }
    }
    ll maxx = 1;
    for(ll i = 0;i < n;i++){
        maxx = max(maxx,dp[i]);
    }
    return maxx;
}


void findAns(bool* toPrint,ll lisLen,ll n){
    
}

//2 1 4 5 3
//1 1 2 3 3
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    ll t = 10;
    while(t--){
        ll n;
        cin>>n;
        ll i,j,k;
        fo(i,n)cin>>arr[i];
        bool toPrint[n+1];
        fo(i,n+1){
            ct[i] = 0;
            dp[i] = -1;
            toPrint[i] = false;
        }
        dp[0] = 1;
        //lis(arr,n,ct);
        ll lisLen = uneffLis(n);
        fo(i,n)cout<<dp[i]<<" ";
        cout<<endl;
        findAns(toPrint,lisLen,n);
    }
    
    //▬▬ι═══════>
    return 0;
}

