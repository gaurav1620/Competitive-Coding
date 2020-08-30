
//Reference : 
//https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-in-a-subarray-set-2/
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

vector<int> adj[200005];
bool vis[200005];
int arr[200005];

set<int> st;

void find(ll node,ll dist){
    /*
    watch(node);
    watch(dist);
    watch(arr[node]);
    */
    vis[node] = true;
    if(dist == 0){
        st.insert(arr[node]);
    }
    else{
        st.insert(arr[node]);
        for(int i = 0 ; i < adj[node].size();i++){
            
            if(!vis[adj[node][i]]){
                find(adj[node][i],dist-1);
            }
        }
    }
}

//Reference : 
//https://apps.topcoder.com/forums/?module=RevisionHistory&messageID=1369039


//Segree Start
const int MAXN = 200005;
const int MAXLGN = 18;
//number of nodes and querries
int N,Q;
map<int,int> pos;
int greenTree[MAXN];
int dont;

struct node{
    int val,L,R,size;
}cache[2*MAXN*MAXLGN];

int makeTree( int lo, int hi ) {
	watch(lo);
    if ( lo <= hi ){ 

    }else{
        return 0;

    }
	int idx = ++dont;
	int mid = ( lo + hi ) / 2;
	cache[idx] = (node)
                 { mid, makeTree( lo, mid - 1 )
                     , makeTree( mid + 1, hi ), 0 };
	watch(idx);
	return idx;
}

int checkChange( int x, int val, int amount ) {
	watch(val);
    if ( x != 0 ){

    }else{
        return 0;
    }
	int idx = ++dont;
	int L = cache[x].L;
	int R = cache[x].R;
	watch(cache[x].val);
	if ( val < cache[x].val ){
        L = checkChange( L, val, amount );
    }
	if ( val > cache[x].val ) {
        R = checkChange( R, val, amount );
    }
	cache[idx] = (node){ cache[x].val, L, R, cache[x].size + amount };
	watch(cache[idx].val);
	return idx;
}
int askTheRes( int x, int val ) {
	if ( val < cache[x].val ){
        watch(cache[x].val);
		return askTheRes( cache[x].L, val ) 
                + cache[x].size - cache[ cache[x].L ].size;
    }
	if ( val > cache[x].val ){
        watch(cache[x].val);
		return askTheRes( cache[x].R, val );
    }
	int ret  = cache[x].size - cache[ cache[x].L ].size;
    watch(ret);
    return ret;
}

//Reference : 
//https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-in-a-subarray-set-2/
set<int>* segment;

void makeTheSeg(int i, int s, int e, int arr[]){
    if (s == e) {
        segment[i].insert(arr[s]);
        return;
    }
    makeTheSeg(2 * i, s, (s + e) / 2, arr);
    makeTheSeg(1 + 2 * i, 1 + (s + e) / 2, e, arr);
    segment[i].insert(segment[2 * i].begin(),
                      segment[2 * i].end());

    segment[i].insert(segment[2 * i + 1].begin(),
                      segment[2 * i + 1].end());
}

//Reference : 
//https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-in-a-subarray-set-2/
set<int> qqqqwewere(int node, int l, int r, int a, int b){
    set<int> left, right, report;
    if (b < l || a > r)
        return report;

    if (a <= l && r <= b)
        return segment[node];

    left = qqqqwewere(2 * node, l, (l + r) / 2, a, b);
    report.insert(left.begin(), left.end());
    right = qqqqwewere(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    report.insert(right.begin(), right.end());
    return report;
}
//Reference : 
//https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-in-a-subarray-set-2/

void init(int n){
    int h = (int)ceil(log2(n));
    h = (2 * (pow(2, h))) - 1;
    segment = new set<int>[h];
}

//Reference : 
//https://www.geeksforgeeks.org/queries-for-number-of-distinct-elements-in-a-subarray-set-2/
int getAnsss(int l, int r, int n){
    set<int> ans = qqqqwewere(1, 0, n - 1, l, r);
    return ans.size();
}

int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases;
    while(testCases--){
        cin>>N;
        ll n = N;

        if(n < 1001){
            ll i,j,k;
            fo(i,n)adj[i].clear();
            fo(i,n)vis[i] = false;

            for(i = 0;i < n-1;i++){
                ll x;cin>>x;
                x--;
                adj[x].push_back(i+1);
            }
            fo(i,n)cin>>arr[i];


            ll q;cin>>q;
            ll ans= 0;
            while(q--){
                fo(i,n)vis[i] = false;
                ll node,dist;
                cin>>node>>dist;
                //node--;
                node = node^ans;
                node--;
                dist = dist^ans;
                //dist--;
                st.clear();
                find(node,dist);
                /*
                cout<<"ARR : ";
                fo(i,n)cout<<arr[i]<<" ";
                cout<<endl;
                cout<<"SET \n";
                for(auto it = st.begin();it!=st.end();it++){
                    cout<<*it<<endl;
                }
                */
                ans = st.size();
                cout<<ans<<endl;       
            }

        }else{
            ll i,j,k;
            fo(i,n-1)cin>>j;
            fo(i,n)cin>>arr[i];

            init(n);            
            makeTheSeg(1, 0, n - 1, arr);
            
            ll q;cin>>q;

            ll ans = 0;
            
            while(q--){
                ll node,dist;
                cin>>node>>dist;
                node = node^ans;
                node--;
                dist = node + dist^ans;
                ans = getAnsss(node,dist,n);
                cout<<ans<<endl;       
            }
        }
    }
    
    //▬▬ι═══════>
    return 0;
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

