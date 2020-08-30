#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long

using namespace std;

map<ll,ll> m;

ll ans(ll n){
    if(n < 4){
        return n;
    }
    
    if(m.find(n) != m.end()){
        auto xx = m.find(n);
        return xx->second;
    }

    ll gg = max(n,ans(n/2)+ans(n/3)+ans(n/4));
    m.insert({n,gg});
    return gg;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll n;
    while(cin>>n){
        cout<<ans(n)<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

