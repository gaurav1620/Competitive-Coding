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

int main(){
    Ninja
    
    ll m,n,i,j,k;
    cin>>m>>n;
    ll edges[m][2];

    fo(i,m)cin>>edges[i][0]>>edges[i][1];

    set<ll> st;

    fo(i,m){
        vector<ll> adj[n];

        for(j = 0;j < m;j++){
            if(i != j){
                adj[edges[j][0]].push_back(edges[j][1]);
                adj[edges[j][1]].push_back(edges[j][0]);
            }
        }
        bool vis[n];
        memset(vis,0,sizeof vis);
        
        queue<ll> q;
        q.push(0);
        ll ct = 0;

        vis[0] = 1;
        while(q.size() > 0){
            ct++;
            ll ind = q.front();
            q.pop();
            for(ll ver : adj[ind]){
                if(!vis[ver]){
                    q.push(ver);
                    vis[ver] = 1;    
                }
            }
        }
        if(ct != n){
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
        }
    }
    vector<ll> v;
    for(auto it = st.begin();it != st.end();it++){
        v.push_back(*it);
    }

    sort(v.begin(),v.end());
    if(v.size() == 0){
        cout<<-1<<endl;
    }else{
        for(ll ver : v){
            cout<<ver<<endl;
        }
    }


    return 0;
}

