#include<bits/stdc++.h>

/*  author     : Gaurav Khairnar
    codechef   : gaurav_1620
    codeforces : gaurav1620
    email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll long long


using namespace std;

ll testCases;
#define Yess cout<<"YES\n";
#define Noo cout<<"NO\n";
#define yess cout<<"Yes\n";
#define noo cout<<"No\n";

ll n;
vector<pair<ll,ll>> v;

bool sortcol(pair<ll,ll> &a,pair<ll,ll> &b){
    if(a.first != b.first)return a.first < b.first;
    return a.second < b.second;
}

bool overlaps(pair<ll,ll> a,pair<ll,ll> b){
    if(b.first <= a.second)return 1;
    return 0;
}

int main(){
    Ninja
    
    
    cin>>n;
    ll i,j,k;
    fo(i,n){
        ll x,y;cin>>x>>y;
        v.push_back({x,x+y});
    }
    sort(v.begin(),v.end(),sortcol);
    
    ll pref[172900];
    memset(pref,0,sizeof pref);

    fo(i,n){
        pref[v[i].first]++;
        pref[v[i].second+1]--;
    }

    for(i = 1; i< 172900;i++){
        pref[i] += pref[i-1];
    }
    ll ans = 0;
    fo(i,172900){
        ans = max(ans,pref[i]);
    }
    cout<<ans;

    return 0;
}

