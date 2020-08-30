#include<bits/stdc++.h>
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
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    

    while(1){
        ll m,n,i,k,j;
        cin>>m>>n;
        if(m == 0 && n == 0){
            break;
        }

        ll arr[m+1][2];
        fo(i,m)cin>>arr[i+1][0]>>arr[i+1][1];
        
        ll dp[m+1][n+1];

        fo(i,m+1){fo(j,n+1){dp[i][j] = 0;}}
        
        for(i = 1;i <=m;i++){
            for(j = 1; j <= n;j++){
                if(j-1 >= arr[i][0] && j-1 <= arr[i][1]){
                    //dp[i][j] = 1+dp[i][j-1]+dp[i-1][m+1-j]; 
                    dp[i][j] = dp[i][j-1]+dp[i-1][m-j]+1;
                }else{
                    dp[i][j] = dp[i-1][j];                    
                }
            }
        }


        /*        
        for(i = 0;i <=m;i++){
            for(j = 0; j <= n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        
        cout<<dp[m][n]<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

