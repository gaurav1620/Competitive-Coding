#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;


ll ans;

ll findNumLeaves(vector<ll> adj[],bool vis[],ll n,ll &leafNodes,ll ind,vector<ll> &leavesInd);
int main(){
    Ninja
    //▬▬ι═══════>
    
    ll n,k;
    cin>>n>>k;
    ll i,j;
    vector<ll> adj[n];

    fo(i,n-1){
        ll a,b;cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll leafNodes = 0;
    bool vis[n];
    vector<ll> leavesInd;
    fo(i,n)vis[i] = false;

    leafNodes = findNumLeaves(adj,vis,n,leafNodes,0,leavesInd);
    
    

    //▬▬ι═══════>
    return 0;
}

ll findNumLeaves(vector<ll> adj[],bool vis[],ll n,ll &leafNodes,ll ind,vector<ll> &leavesInd){
    if(vis[ind]){return 0;}
    vis[ind] = true;

    if(adj[ind].size() == 1 && vis[adj[ind][0]]){
        leafNodes++;
        leavesInd.push_back(ind);
        return 1;
    }

    ll ans  = 0;
    for(ll i = 0;i<adj[ind].size();i++){
        ans += findNumLeaves(adj,vis,n,leafNodes,adj[ind][i],leavesInd);
    }
    return ans;

}
