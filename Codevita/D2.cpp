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

int min(ll a,ll b){
    return a < b ? a : b;
}

vector<ll> adj[10004];
ll n,m;
ll ind = 0;
ll comp[10004];


void findComponent(int u, int disc[], int low[], stack<int>&stk, bool stkItem[]) {
   static int time = 0;
   disc[u] = low[u] = ++time;
   stk.push(u);
   stkItem[u] = true;

   for(ll v : adj[u]) {
      if(1) {
         if(disc[v] == -1) {
            findComponent(v, disc, low, stk, stkItem);
            low[u] = min(low[u], low[v]);
         } else if(stkItem[v])
            low[u] = min(low[u], disc[v]);
      }
   }

   int poppedItem = 0;
   if(low[u] == disc[u]) {
      while(stk.top() != u) {
         poppedItem = stk.top();
         comp[poppedItem] = ind;
         stkItem[poppedItem] = false;
         stk.pop();
      }
      poppedItem = stk.top();
      comp[poppedItem] = ind++;
      stkItem[poppedItem] = false;
      stk.pop();
   }
}

void strongConComponent() {
   int disc[n], low[n];
   bool stkItem[n];
   stack<int> stk;

   for(int i = 0; i<n; i++) {    //initialize all elements
      disc[i] = low[i] = -1;
      stkItem[i] = false;
   }

   for(int i = 0; i<n; i++)    //initialize all elements
      if(disc[i] == -1)
         findComponent(i, disc, low, stk, stkItem);
}


int main(){
    Ninja
    cin>>m>>n;
    ll i;
    fo(i,m){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    strongConComponent();
    fo(i,n)cout<<comp[i]<<" ";
    cout<<endl;
    return 0;
}

