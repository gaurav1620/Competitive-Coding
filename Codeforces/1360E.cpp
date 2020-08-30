#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;

void printVector(vector<ll> v){ll i;fo(i,v.size())cout<<v[i]<<" ";cout<<endl;}
void printVector(ll v[],ll n){ll i;fo(i,n)cout<<v[i]<<" ";cout<<endl;}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll i,j,k;
        ll arr[n][n];
        ll dp[n+1][n+1];

        fo(i,n){
            string s;cin>>s;

            fo(j,n)
                arr[i][j] = s[j]=='0' ? 0:1;
        }

        bool ans= true;


        for(i = n;i >=0;i--){
            for(j = n;j >=0;j--){
                if(i == n || j == n)dp[i][j] = 1;
                else{
                    if(arr[i][j] == 1){
                        if(dp[i+1][j] || dp[i][j+1]){
                            dp[i][j] = 1;
                        }else{
                            ans = false;
                            break;
                        }
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
            if(ans == false){
                break;
            }
        }
        if(ans)cout<<"YES\n";
        else cout<<"NO\n";
    }
    //▬▬ι═══════>
    return 0;
}

