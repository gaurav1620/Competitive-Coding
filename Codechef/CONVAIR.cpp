#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef   : gaurav_1620
//codeforces : gaurav1620
//email      : gauravak007@gmail.com
//Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
//Github     : www.github.com/gaurav1620
//
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)      for(i = 0;i < n;i++)
#define rfo(i,n)     for(i = n-1; n >= 0;i++0)
#define rep(i,l,r)   for(i = l;i <= r;i++)
#define reprev(i,r,l)for(i = r;i >= l;i--)
#define ll int

#define vl vector<ll>
#define vll vector<vector<ll>>
#define vpll vector<pair<ll,ll>>

#define pll   pair<ll, ll>
#define plpll pair< ll, pair<ll,ll> >
#define pllpl pair< pair<ll,ll>, ll >

#define pb push_back


#define watch(x) cerr << (#x)<< " is : " << (x) << endl

//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;

//Generic
template <typename T> void deb(T v[],ll n){cerr<<"ARRAY   : ";ll i;fo(i,n)cerr<<v[i]<<" ";cerr<<endl;}
template <typename T> void deb(set<T> s)  {cerr<<"SET     : ";for(auto it:s)cerr<<it<<" ";cerr<<endl;}
template <typename T> void deb(vector<T> v){cerr<<"VECTOR : ";ll i;fo(i,v.size())cerr<<v[i]<<" ";cerr<<endl;}
template <typename T> void deb(vector<T> v[],ll n){
    for(ll node = 0;node < n;node++){
        watch(node);deb(v[node]);
    }
}
template <typename T> void deb(stack<T> s){cerr<<"STACK   : ";stack<T> st = s;while(st.size()){cerr<<st.top()<<" ";st.pop();};cerr<<endl;}
template <typename T> void deb(queue<T> q){cerr<<"Queue   : ";queue<T> qq = q;while(qq.size()){cerr<<qq.front()<<" ";qq.pop();};cerr<<endl;}

//Not generic
void deb(map<ll,ll> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}
void deb(unordered_map<ll,ll> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}

template <typename T> 
T abs(T a){return a < 0?a*-1 : a;}

//Functions
void swap(ll &x,ll &y);
bool isPrime(ll n);
ll nCrModp(ll n, ll r, ll p);
ll power(ll x, ll y, ll p);
ll gcdExtended(ll a, ll b, ll *x, ll *y);
ll modInverse(ll b, ll m);
ll modDivide(ll a, ll b, ll m);

//Sieves
void simpleSieve(ll N,bool[]);
void PrimeDivisorSieve(ll N,ll prime[]);


/*
 * For fast comments 
*/

ll testCases;
#define yess cout<<"YES\n";
#define noo cout<<"NO\n";

const int N = 100005;
vl graph[N]; 
vl cycles[N]; 

int vis[N];

void dfs_cycle(int u, int p, int color[],
        int mark[], int par[], int &cycleNumber){

    watch(u);
    watch(p);
    cout<<"*******\n";
    if(color[u] == 2)return ;
    
    if(color[u] == 1){
        cycleNumber++;
        int cur = p;
        mark[cur] = cycleNumber;
        while(cur != u){
            cur = par[cur];
            mark[cur] = cycleNumber;
        }
        return;
    }

    par[u] = p;
    color[u] = 1;
    for(int v : graph[u]){
        if(v != par[u]){
            dfs_cycle(v,u,color,mark,par,cycleNumber);
        }
    }
    color[u] = 2;
    return;
}


int cycleNumber = 0;
int color[N];
int par[N];
int mark[N];


int mySelfCycleVis[N];
int countSelf(int g){

    mySelfCycleVis[g] = 1;
    
    sort(graph[g].begin(),graph[g].end());
    
    int cy = 0;
    
    for(int i = 0;i < graph[g].size()-1;i++){
        if(graph[g][i] == graph[g][i+1] && !mySelfCycleVis[graph[g][i]])
            cy++;
    }
    
    set<int> st;
    for(int i  =0;i < graph[g].size();i++)
        st.insert(graph[g][i]);
    
    graph[g].clear();
    while(!st.empty()){
        watch(st.size());
        graph[g].push_back(*st.begin());
        st.erase(st.begin());
    }

    for(int i = 0;i < graph[g].size();i++){
        if(!mySelfCycleVis[graph[g][i]]){
            cy += countSelf(graph[g][i]);
        }
    }
    return cy;
}

int countEdges(int start){
    if(mySelfCycleVis[start])return 0;
    mySelfCycleVis[start] = 1;
    int edg = graph[start].size();
    for(int i = 0; i< graph[start].size();i++){
        edg += countEdges(graph[start][i]);
    }
    return edg;
}

int countNodes(int start){
    if(vis[start])return 0;
    int ret = 1;
    vis[start] = 1;
    for(int i = 0 ; i< graph[start].size();i++){
        ret += countNodes(graph[start][i]);
    }
    return ret;
}

int countNumberOfCycles(int start,int n){
    
    int ce = countEdges(start)/2;
    int cn = countNodes(start);
    watch(ce);
    watch(cn);
    return 1+ce-cn;
    //watch(cycleNumber);
    //deb(color,6);
    //deb(par,6);
    //deb(mark,6);
    int hh = countSelf(start);
    dfs_cycle(start,0,color,mark,par,cycleNumber);

    return cycleNumber+hh;
}



int findAns(int n){
    cycleNumber  = 0;
    ll k ;
    ll singleNodes = 0;
    ll acyclic = 0;
    vector<int> cyclic;
    for(int i = 1;i <=n;i++){
        //cout<<" VIZ : ";deb(vis,6);
        if(graph[i].size() == 0){
            vis[i] = 1;
            singleNodes++;
        }else if(!vis[i]){
            watch(i);
            int ct = countNumberOfCycles(i,n);
            watch(ct);
            //watch(i);
            //watch(ct);
            
            //int self = countSelf(i);
            //if(ct == 0)acyclic++;
            if(ct){
                //has a cycle
                cyclic.push_back(ct);
            }else{
                //doesnt
                acyclic++;
            }
        }
    }
    //watch(acyclic);
    //watch(singleNodes);
    //watch(cyclic);

    //We can pair single nodes with single nodes
    //at just a cost of one
    //which is less than cost of two for pairing 
    //single node with cyclic , or acyclic.
    //
    ll ans = 0;
    
    //even after connecting two disjoint graphs
    //we need to connect it to remaining ones
    
    // we can also use a single node to connect two graphs

    //deb(cyclic);
    //watch(acyclic);
    //watch(singleNodes);

    while(acyclic + cyclic.size() +singleNodes > 1){
        if(acyclic && cyclic.size()){
            cyclic[0]--;
            if(cyclic[0] == 0){
                cyclic.erase(cyclic.begin());
            }
            else{
                acyclic--;
            }
        }
        else if(cyclic.size() > 1){
            int x = cyclic[cyclic.size()-1];

            cyclic[0] = cyclic[0] + x-1;
            cyclic.pop_back();

        }
        else if(singleNodes > 1){
            singleNodes -=2;
            acyclic++;

            ans+=2;
        }
        else if(acyclic >1){
            acyclic--;
            ans+=2;
        }else if(acyclic && singleNodes){
            ans+=2;
            singleNodes--;
        }else if(singleNodes && cyclic.size()){
            singleNodes--;
            if(cyclic[0] == 1){
                cyclic.erase(cyclic.begin());
                acyclic++;
            }else{
                // >1
                cyclic[0]--;
            }
            //cyclic--;
            //acyclic++;
            ans+=2;
        }
    }

    return ans;
}

int main(){
    
    testCases = 1;
    cin>>testCases;
    while(testCases--){

        ll n,m,i,j;
        cin>>n>>m;
        fo(i,n+1)graph[i].clear();
        fo(i,n+1)vis[i] = 0;
        fo(i,n+1){
            vis[i] = color[i] = mark[i] = par[i] = mySelfCycleVis[i] = 0;
        }
        vector<pair<ll,ll>> v;

        fo(i,m){
            ll a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        cout<<findAns(n)<<" "<<0<<endl;
        
        /*
        cout<<"Enter the number of edges : ";
        ll m;
        cin>>m;
        cout<<"Enter edges : ";
        while(m--){
            ll a,b;cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        cout<<countNumberOfCycles()<<endl;
        */
    }
    
    //▬▬ι═══════>
    return 0;
}


//Example :
// If we want primes till 1043
// N = 1043
// prime[N+1];
// sieve(N,prime);
void simpleSieve(ll N,bool prime[]){
    
    ll i,j;
    fo(i,N+1)prime[i] = true;
    for(i = 2 ;i*i <= N;i++){
        if(prime[i]){
            for(j = i*i;j <= N;j++){
                prime[j] = false;
            }
        }
    }
}

//Example :
// If we want primes till 1043
// N = 1043
// prime[N+1];
// sieve(N,prime);
void PrimeDivisorSieve(ll N, ll prime[]){
    ll i,j;

    fo(i,N+1)prime[i] = i;

    //stores the minimum Prime divisor
    for(i = 2 ;i*i <= N;i++){
        if(prime[i] == i){
            for(j = i;j <= N;j++){
                if(prime[j] == j)prime[j] = i;
            }
        }
    }
}
void swap(ll &x,ll &y){
    x ^= y;
    y ^= x;
    x ^= y;
}
bool isPrime(ll n){
    if (n <= 1)return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll nCrModp(ll n, ll r, ll p){
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

//Used for modInverse
ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

//Used for modDivide
ll modInverse(ll b, ll m){
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}

//Use this for modular divisions
ll modDivide(ll a, ll b, ll m){
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
       return  (inv * a) % m;
}

/*
  ____   ___  ____     __  __     __     _____   _     ____ __    ___
 |  _ \ / _ \|  _ \   |  \/  |   /  \   |  _  \ | |   |  __\  \  /  /
 | |_) | | | | |_) |  | \  / |  / ^  \  | |_)  || |   | |_  \  \/  /
 |  _ <| | | |  _ <   | |\/| | / /_\  \ |     / | |   |  _|  \    /
 | |_) | `-' | |_) |  | |  | |/ _____  \| |\  '-| `---| |___  |  |
 |____/ \___/|____/   |_|  |_|_/     \__|_| `.__|_____|_____| |__|
    ,         |                                     |            '
    |         .                                     ;            |
    ;          \                                   .            ;
     ;          .                                 /            /
      \          \    .-""-._           _.--""-. /            /
       \          ','`       r'-.  _.-'\        t           .'
        `.        '          \__/`| |__/                  .'
          '.                _..._7\    _,_             .'
            `'Y          ,'`     `/`"'`   `.         ,'
             /          /                   ;        L
            ;           |                   |         |mx
            |           ;                  ;          ;
             ; _ __      \                /     _ .- /
              \  \ \ `.   `.            .'    / ' / /
               '._\ `. \    `.        .'    .' / /-'
                   `._\ `.    `.    .' .-..'_.'-`
                       `-'`. /`.`. /  /  /
                            `\ _> )|  \_/
                             `'-'  `--' 
*/
