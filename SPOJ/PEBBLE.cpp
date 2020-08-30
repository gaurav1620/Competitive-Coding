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
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    
    string s;
    ll t = 0;
    while(cin>>s){
        t++;
        ll n = s.length();
        ll curr = 0;
        ll ans = 0;
        for(ll i = 0;i < n;i++){
            if((s[i] - '0')!=curr){
                ans++;
                curr = !curr;
            }
        }
        cout<<"Game #"<<t<<": ";
        cout<<ans<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

