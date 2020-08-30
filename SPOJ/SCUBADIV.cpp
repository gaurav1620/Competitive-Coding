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

ll dp[1005][23][100];

ll findAns(ll arr[][3],ll n,ll i,ll reqO,ll reqN){

    cout<<"Called for : "<<i<<"req oxy "<<reqO<<" req nit "<<reqN<<endl;

    if(i == n){
        cout<<"Returning INF for "<<i<<endl;
        return 1000000000;

    }
    if(reqO == reqN && reqN == 0){
        cout<<"Rturning 0 for : "<<i<<endl;
        return 0;
    }

    if(dp[i][reqO][reqN] != -1){
        cout<<"Returning precal : "<<i<<endl;
        return dp[i][reqO][reqN];
    }

    ll prevO = reqO;
    ll prevN = reqN;

    ll wt = 0;
    if(reqO > 0 || reqN > 0){
        wt += arr[i][2];
        reqO -= arr[i][0];
        reqN -= arr[i][1];
        cout<<"Check"<<endl;
    }
    if(reqN < 0){reqN=0;}
    if(reqO < 0){reqO=0;}
    cout<<reqO<<" : "<<reqN<<endl;
    
    ll aa = wt+findAns(arr,n,i+1,reqO,reqN);
    ll bb = findAns(arr,n,i+1,prevO,prevN);

    dp[i][prevO][prevN]  = min(aa,bb);


    cout<<"RETurning : "<<dp[i][prevO][prevN]<<"for "<<i<<endl;
    return dp[i][prevO][prevN]; 
}


ll inf = 1000000007;
ll findAns2(ll arr[][3],ll n,ll i,ll oo,ll nn){
    if(i == n){
        return inf;
    }

    if(oo == 0 && nn == 0){
        return 0;
    }

    if(dp[i][oo][nn] != -1){
        return dp[i][oo][nn];
    }
    ll ans = 0;
    if(oo - arr[i][0] >= 0){
        if(nn - arr[i][1] >=0){
            ans = min(arr[i][2] + findAns2(arr,n,i+1,oo-arr[i][0],nn-arr[i][1]) ,findAns2(arr,n,i+1,oo,nn));
        }else{
            ans = min(arr[i][2] + findAns2(arr,n,i+1,oo-arr[i][0],0) ,findAns2(arr,n,i+1,oo,nn));
        }
    }else{
        if(n - arr[i][1] >= 0){
            ans = min(arr[i][2] + findAns2(arr,n,i+1,0,nn-arr[i][1]) ,findAns2(arr,n,i+1,oo,nn));
        }else{
            ans = min(arr[i][2] + findAns2(arr,n,i+1,0,0) ,findAns2(arr,n,i+1,oo,nn));
        }
    }
    dp[i][oo][nn] = ans;
    return ans;
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    
    ll test;cin>>test;
    while(test--){

        ll i,j,k;

        ll reqO,reqN;cin>>reqO>>reqN;
        ll n;cin>>n;
        ll arr[n][3];
        fo(i,n)cin>>arr[i][0]>>arr[i][1]>>arr[i][2];


        fo(i,n+1){
            fo(j,23){
                fo(k,80){
                    dp[i][j][k] = -1;
                }
            }
        }
        cout<<findAns2(arr,n,0,reqO,reqN)<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

