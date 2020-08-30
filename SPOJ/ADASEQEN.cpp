#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long

using namespace std;

ll max(ll a,ll b){return a>b?a:b;}

ll getAns(string a,string b,ll n,ll m,ll arr[]){
    if(n == 0 || m == 0){return 0;}
    if(a[n-1] == b[m-1]){return arr[a[n-1] - 'a'] + getAns(a,b,n-1,m-1,arr);}
    return max(getAns(a,b,n-1,m,arr),getAns(a,b,n,m-1,arr));
}

ll getAnsUsingDp(string a,string b,ll n,ll m,ll arr[]){
    ll dp[n+1][m+1];
    ll i,j,k;
    fo(i,n+1){
        fo(j,m+1){
            if(i == 0|| j == 0){dp[i][j] = 0;}
            else if(a[i-1] == b[j-1]){dp[i][j] = arr[a[i-1]-'a'] + dp[i-1][j-1];}
            else {dp[i][j] = max(dp[i-1][j],dp[i][j-1]);}
        }
    }
    return dp[n][m];

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    
    ll n,m;cin>>n>>m;
    ll arr[26];
    ll i,j,k;
    fo(i,26)cin>>arr[i];
    string a,b;
    cin>>a;
    cin>>b;
    cout<<getAnsUsingDp(a,b,n,m,arr)<<endl;
    //▬▬ι═══════>
    return 0;
}

