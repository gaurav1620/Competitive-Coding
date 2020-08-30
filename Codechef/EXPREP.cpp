/*  Author     : Gaurav Khairnar
    Codechef   : gaurav_1620
    Codeforces : gaurav1620
    Email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/

#include<bits/stdc++.h>
#define ll long long int
#define fo(i,n) for(i = 0;i < n;i++)
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cerr << (#x)<< " is : " << (x) << endl

//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;
#define MOD 998244353

ll wt[26];

vector<string> findTheRepeatedStr(string s){
    vector<string> v;
    ll i = 1;
    while(i <= s.length()){
        string loc = s.substr(0,i);
        bool gd = true;
        for(int j = 0;j < s.length();j++){
            gd &= s[j] == loc[j%i];
        }
        if(gd){
            v.push_back(loc);
        }
        i++;
    }
    return v;
}

vector<string> findRightFit(string Sl,string Sr){
    vector<string> prevAn = findTheRepeatedStr(Sl);
    vector<string> currA;

    for(string r : prevAn){
        ll i = 0;
        while(i <= r.length()){
            if(Sr == r.substr(0,i)){
                currA.push_back(r);
                break;
            }
            i++;
        }
    }
    return currA;
}

ll addUp(string s){
    set<string> x;
    ll n = s.length();
    for(int i = (n/2)+n%2;i <= n;i++){
        string Sl = s.substr(0,i);
        string Sr = s.substr(i,s.length()-i);
        vector<string> r = findRightFit(Sl,Sr);
        if(r.size()){
            for(string st : r){
                x.insert(st);
            }
        }
    }
    ll ans = 0;
    //watch(x.size());
    for(string p : x){
        for(char j : p){
            ans += wt[j-'a'];
            ans %= MOD;

        }
    }
    return ans%MOD;
}

//REFERENCE : https://www.geeksforgeeks.org/multiply-large-integers-under-large-modulo/
ll moduloMultiplication(ll a,ll b){
    ll mod = MOD;
    ll res = 0;
    a %= mod;
    while (b){
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1;
    }
    return res;
}

// REFERENCE :  https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
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
ll modInverse(ll b){
    ll x, y;
    ll m = MOD;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}
int main(){
    Ninja
    ll t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll i,j,k;
        ll nc = s.length();
        ll n = s.length();
        fo(i,26)cin>>wt[i];
        fo(i,26)wt[i]%=MOD;

        i = j = 0;
        ll ans = 0;
        while(i < n){
            j = i+1;
            while(j < n+1){
                ll pp = addUp(s.substr(i,j-i))%MOD;
                ans += pp;
                ans %= MOD;
                j++;
            }
            i++;
        }
        ll finalAns = moduloMultiplication(ans,
                modInverse((ll) ((n*(n+1))/2)%MOD))%MOD;
        cout<<finalAns<<endl;
    }
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
