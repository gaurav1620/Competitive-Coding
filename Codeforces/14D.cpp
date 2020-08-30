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
#define rfo(i,n)     for(i = n-1; n >= 0;i++0)
#define rep(i,l,r)   for(i = l;i <= r;i++)
#define reprev(i,r,l)for(i = r;i >= l;i--)
#define ll long long

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
template <typename T> void deb(stack<T> s){cerr<<"STACK   : ";stack<T> st = s;while(st.size()){cerr<<st.top()<<" ";st.pop();};cerr<<endl;}
template <typename T> void deb(queue<T> q){cerr<<"Queue   : ";queue<T> qq = q;while(qq.size()){cerr<<qq.front()<<" ";qq.pop();};cerr<<endl;}

//Not generic
void deb(map<ll,ll> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}
void deb(unordered_map<ll,ll> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}

template <typename T> 
T abs(T a){return a < 0?a*-1 : a;}

//Faster Functions
void swap(ll &x,ll &y);
bool isPrime(ll n);
ll power(ll x, ll y, ll p);
ll gcdExtended(ll a, ll b, ll *x, ll *y);
ll modInverse(ll b, ll m);
ll modDivide(ll a, ll b, ll m);

//Sieves
void simpleSieve(ll N,bool[]);
void PrimeDivisorSieve(ll N,ll prime[]);

class nCrModPClass{
    public:
        vector<ll> f,fi;
        ll N;
        ll MOD;

        ll poww(ll a, ll b,ll m){
            ll ans=1;
            while(b){
                if(b&1)ans=(ans*a)%m;
                b/=2;
                a=(a*a)%m;
            }
            return ans;
        }
        ll modinvv(ll k){
            return poww(k, MOD-2,MOD);
        }
        nCrModPClass(ll size,ll mod){
            MOD = mod;
            N = size+10;
            f.resize(N);
            fi.resize(N);
            
            f[0] = f[1] = 1;
            for(ll i = 2;i < N;i++)
                f[i] = (f[i-1]*i)%MOD;
            fi[N-1] = modinvv(f[N-1]);
            for(ll i = N-2; i >= 0;i--)
                fi[i] = (fi[i+1]*(i+1))%MOD;
        }

        ll nCrModPfromClass(ll n,ll r){
            if(r > n)return 0;
            ll ret = f[n];
            ret%=MOD;
            ret *= fi[r];
            ret%=MOD;
            ret *= fi[n-r];
            ret%=MOD;
            return ret;
        }
};

ll testCases;
#define Yess cout<<"YES\n";
#define Noo cout<<"NO\n";
#define yess cout<<"Yes\n";
#define noo cout<<"No\n";

vector<ll> adj[250];
ll n;
void fil(set<ll> &v,ll ind,bool* vis){
    v.insert(ind);
    vis[ind] = 1;
    for(ll j : adj[ind]){
        if(!vis[j])fil(v,j,vis);
    }
}
ll dfs(ll ind,bool *vis){
    vis[ind] = 1;
    ll ret = 0;
    for(ll h : adj[ind]){
        if(!vis[h])ret = max(ret,1+dfs(h,vis));
    }
    return ret;
}
ll getAns(ll x,ll y){
    bool vis[n];
    memset(vis,0,sizeof vis);
    vis[y] = 1;
    set<ll> a,b;
    fil(a,x,vis);
    memset(vis,0,sizeof vis);
    vis[x] = 1;
    fil(b,y,vis);
    

    //
    memset(vis,0,sizeof vis);
    for(auto p : a){
        vis[p] = 1;
    }
    ll i;
    ll best_b = 0;
    bool vis2[n];
    fo(i,n)vis2[i] = vis[i];
    for(auto p : b){
        fo(i,n)vis2[i] = vis[i];
        best_b = max(best_b,dfs(p,vis2));    
    }

    //
    memset(vis,0,sizeof vis);
    for(auto p : b){
        vis[p] = 1;
    }
    ll best_a = 0;
    fo(i,n)vis2[i] = vis[i];
    for(auto p : a){
        fo(i,n)vis2[i] = vis[i];
        best_a = max(best_a,dfs(p,vis2));
    }
    /*
    watch(x);
    watch(y);
    deb(a);
    deb(b);
    watch(best_b);
    watch(best_a);
    */

    return best_b*best_a;

    //return 1;
}

int main(){
    Ninja
    //▬▬ι═══════>
    cin>>n;
    ll i;
    ll edges[n-1][2];

    fo(i,n-1){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i][0] = a;
        edges[i][1] = b;
    }
    /*
    while(1){
        ll a,b;
        cin>>a>>b;
        cout<<getAns(a,b)<<endl;
    }
    */

    ll ans = 0;

    fo(i,n-1){
        ans = max(ans,getAns(edges[i][1],edges[i][0]));
    }

    cout<<ans<<endl;

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
            for(j = i*i;j <= N;j+=i){
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
            for(j = i;j <= N;j+=i){
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
