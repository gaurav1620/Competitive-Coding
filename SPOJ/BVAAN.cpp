#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define pb push_back
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

ll dp[105][105][105];
string a,b;
ll k;

void solve(){
    ll ai,bi,ki;
    fo(ai,a.length()+1){
        fo(bi,b.length()+1){
            fo(ki,k+1){
                if(ai == 0 || bi == 0||ki==0){
                    dp[ai][bi][ki] = 0;
                }
                else if(a[ai-1] == b[bi-1]){
                    dp[ai][bi][ki] = max(
                            //Taking 
                            dp[ai-1][bi-1][ki-1]+a[ai-1],
                            //Not Taking
                            dp[ai-1][bi-1][ki]
                            );
                }else{
                    dp[ai][bi][ki] = max(dp[ai][bi-1][ki],
                                         dp[ai-1][bi][ki]);
                }
                
            }
        }
    }
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        cin>>a>>b;
        cin>>k;
        if(k > a.length() || k > b.length()){
            cout<<0<<endl;
        }else{
            solve();
            cout<<dp[a.length()][b.length()][k]<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

