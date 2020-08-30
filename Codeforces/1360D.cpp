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


ll ans (ll n,ll k){
    
    ll ans = n;

    if(k >= n)return 1;

    for(ll i = 1;i <= sqrt(n);i++){
        if(n%i == 0){
            ll x = n/i;
            if(x <= k)ans = min(ans,i);
        }
    }
    return ans;

}

int main(){

    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;

        if(k >= n){
            cout<<1<<endl;
        }else{
            cout<<ans(n,k)<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

