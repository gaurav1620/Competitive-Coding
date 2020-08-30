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
#define lldl long long

#define vl vector<lldl>
#define vlldl vector<vector<lldl>>
#define vplldl vector<pair<lldl,lldl>>

#define plldl   pair<lldl, lldl>
#define plplldl pair< lldl, pair<lldl,lldl> >
#define plldlpl pair< pair<lldl,lldl>, lldl >

#define pb push_back

#define watch(x) cerr << (#x)<< " is : " << (x) << endl

//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;

//Generic
template <typename T> void deb(T v[],lldl n){cerr<<"ARRAY   : ";lldl i;fo(i,n)cerr<<v[i]<<" ";cerr<<endl;}
template <typename T> void deb(set<T> s)  {cerr<<"SET     : ";for(auto it:s)cerr<<it<<" ";cerr<<endl;}
template <typename T> void deb(vector<T> v){cerr<<"VECTOR : ";lldl i;fo(i,v.size())cerr<<v[i]<<" ";cerr<<endl;}
template <typename T> void deb(stack<T> s){cerr<<"STACK   : ";stack<T> st = s;while(st.size()){cerr<<st.top()<<" ";st.pop();};cerr<<endl;}
template <typename T> void deb(queue<T> q){cerr<<"Queue   : ";queue<T> qq = q;while(qq.size()){cerr<<qq.front()<<" ";qq.pop();};cerr<<endl;}

//Not generic
void deb(map<lldl,lldl> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}
void deb(unordered_map<lldl,lldl> m){cerr<<"MAP : ";for(auto it:m)cerr<<it.first<<" : "<<it.second<<endl;}

template <typename T> 
T abs(T a){return a < 0?a*-1 : a;}

//Faster Functions
void swap(lldl &x,lldl &y);
bool isPrime(lldl n);
lldl power(lldl x, lldl y, lldl p);
lldl gcdExtended(lldl a, lldl b, lldl *x, lldl *y);
lldl modInverse(lldl b, lldl m);
lldl modDivide(lldl a, lldl b, lldl m);

//Sieves
void simpleSieve(lldl N,bool[]);
void PrimeDivisorSieve(lldl N,lldl prime[]);

class nCrModPClass{
    public:
        vector<lldl> f,fi;
        lldl N;
        lldl MOD;

        lldl poww(lldl a, lldl b,lldl m){
            lldl ans=1;
            while(b){
                if(b&1)ans=(ans*a)%m;
                b/=2;
                a=(a*a)%m;
            }
            return ans;
        }
        lldl modinvv(lldl k){
            return poww(k, MOD-2,MOD);
        }
        nCrModPClass(lldl size,lldl mod){
            MOD = mod;
            N = size+10;
            f.resize(N);
            fi.resize(N);
            
            f[0] = f[1] = 1;
            for(lldl i = 2;i < N;i++)
                f[i] = (f[i-1]*i)%MOD;
            fi[N-1] = modinvv(f[N-1]);
            for(lldl i = N-2; i >= 0;i--)
                fi[i] = (fi[i+1]*(i+1))%MOD;
        }

        lldl nCrModPfromClass(lldl n,lldl r){
            if(r > n)return 0;
            lldl ret = f[n];
            ret%=MOD;
            ret *= fi[r];
            ret%=MOD;
            ret *= fi[n-r];
            ret%=MOD;
            return ret;
        }
};

lldl testCases;
#define Yess cout<<"YES\n";
#define Noo cout<<"NO\n";
#define yess cout<<"Yes\n";
#define noo cout<<"No\n";

int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    lldl i,j;
    lldl n,k;
    lldl arr[100005];
    lldl done[100005];
    while(testCases--){
        //rolldl
        cin>>n>>k;

        for(i = 0;i < n+1;i++)done[i] = 1;
        lldl g;
        for(i = 1;i <= n;i++){
            cin>>g;
            arr[i-1] = g;
        }
        sort(arr,arr+n);

        lldl tmp,ans;
        ans = tmp = 0;
        tmp = arr[n-1];
        tmp *= 2;
        watch(tmp); 
        while(tmp > k){
            tmp = (tmp+1)/2;
            ans++;
            lldl pp = lower_bound(arr,arr+n,tmp) - arr;
            watch(pp);
            if(done[pp]){
                done[pp] = 0;
                tmp = arr[pp];
            }
            watch(tmp); 
        }
        fo(i,n)ans += done[i];

        cout<<ans<<endl;
    }
    
    //▬▬ι═══════>
    return 0;
}


//Example :
// If we want primes tilldl 1043
// N = 1043
// prime[N+1];
// sieve(N,prime);
void simpleSieve(lldl N,bool prime[]){
    lldl i,j;
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
// If we want primes tilldl 1043
// N = 1043
// prime[N+1];
// sieve(N,prime);
void PrimeDivisorSieve(lldl N, lldl prime[]){
    lldl i,j;
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
void swap(lldl &x,lldl &y){
    x ^= y;
    y ^= x;
    x ^= y;
}
bool isPrime(lldl n){
    if (n <= 1)return false;
    for (lldl i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}
lldl power(lldl x, lldl y, lldl p){
    lldl res = 1;
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
lldl gcdExtended(lldl a, lldl b, lldl *x, lldl *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    lldl x1, y1;
    lldl gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
//Used for modDivide
lldl modInverse(lldl b, lldl m){
    lldl x, y;
    lldl g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}
//Use this for modular divisions
lldl modDivide(lldl a, lldl b, lldl m){
    a = a % m;
    lldl inv = modInverse(b, m);
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
