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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        ll arr[n];
        ll logArr[n];

        ll i,j,k;
        fo(i,n)cin>>arr[i];

        sort(arr,arr+n);
        ll ans = 0;
        for(i = 0;i<n;i++){
            for(j = 0;j<n;j++){
                if(i!=j && arr[i]!=-1 && arr[i] !=-1 && arr[i]==2*arr[j]){
                    arr[i] = -1;
                    arr[j] = -1;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

