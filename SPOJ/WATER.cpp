#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef   : gaurav_1620
//codeforces : gaurav1620  
//github     : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){ return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

bool isOuterEdge(ll i,ll j,ll n,ll m){
    if(i == 0 || i == n-1 || j == 0|| j == m-1){return true;}
    return false;
}

bool sortcol(pair<ll,pair<ll,ll>> v1, pair<ll,pair<ll,ll>> v2){
    return v1.first < v2.first;
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<pair<ll,ll>> adj[n][m];
        ll arr[n][m],i,j,k;
        
        fo(i,n)
            fo(j,m)
                cin>>arr[i][j];

        fo(i,n)
            fo(j,m){
                if(i+1 <  n)adj[i][j].push_back(pair<ll,ll>(i+1,j));
                if(i-1 >= 0)adj[i][j].push_back(pair<ll,ll>(i-1,j));
                if(j+1 <  m)adj[i][j].push_back(pair<ll,ll>(i,j+1));
                if(j-1 >= 0)adj[i][j].push_back(pair<ll,ll>(i,j-1));
            }
        

        fo(i,n){
            fo(j,m)
                cout<<adj[i][j].size()<<" ";
            cout<<endl;
        }
        
        
        bool visited[n][m];
        fo(i,n)
            fo(j,m)
                visited[i][j] = false;
        
        vector< pair< ll ,pair<ll,ll> > > v;
        fo(i,n)
            fo(j,m)
                if(!isOuterEdge(i,j,n,m))
                    v.push_back(pair<ll,pair<ll,ll>>(arr[i][j],pair<ll,ll>(i,j)));
        
        sort(v.begin(),v.end(),sortcol);
        
        fo(i,v.size())cout<<v[i].first<<"     "
                          <<v[i].second.first<<" : "<<v[i].second.second<<endl;

        ll maxWaterCap[n][m];

        for(i,v.size()){
            ll height = v[i].first;
            ll x = v[i].second.first;
            ll y = v[i].second.second;
            if(!visited[x][y]){
                //visited[x][y] = true;
                queue<pair<ll,ll>> q;
                q.push_back(pair<ll,ll>(x,y));
                while(!q.empty()){
                    
                }
            }
        }        

    }
    //▬▬ι═══════>
    return 0;
}

