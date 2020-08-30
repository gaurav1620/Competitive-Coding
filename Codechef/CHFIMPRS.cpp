#include<bits/stdc++.h>
/*
 * author     : Gaurav Khairnar
 * github     : github.com/gaurav1620
 * codechef   : gaurav_1620
 * codeforces : gaurav1620
 *
# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define ll long long
#define pll pair<ll,ll>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define pb push_back
#define MAXL LONG_MAX
#define MAXI INT_MAX
#define mod7 1000000007
#define mod9 1000000009
#define watch(x) cout << (#x) << " is : " << (x) << endl
using namespace std;
ll abs(ll a){return a<0?a*-1:a;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

//Functions
void swap(ll &x,ll &y);
bool isPrime(ll n);
ll nCrModp(ll n, ll r, ll p);
ll power(ll x, ll y, ll p);
ll gcdExtended(ll a, ll b, ll *x, ll *y);
ll modInverse(ll b, ll m);
ll modDivide(ll a, ll b, ll m);

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll arr[n][m];
        ll i,j,k;

        unordered_map<ll,ll> mp;
        
        fo(i,n){
            fo(j,m){
                cin>>arr[i][j];
                ll x = arr[i][j];
                mp[arr[i][j]]++;
            
            }
        }
        ll passes = 0;
        if(m%2 == 1)passes+=n;
        
        ll unmatch = 0;

        for(auto it : mp){
            //watch(it.first);
            //watch(it.second);

            if(it.second %2 == 1){
                unmatch++;
            }
        }

        //watch(mp.size());

        vector<ll> vals;
        for(auto it : mp){
            if(it.second %2 == 0){
                for(i = 0; i < it.second;i++){
                    //watch(it.first);
                    vals.push_back(it.first);
                }
            }else{
                if(it.second > 2){
                    for(i = 0;i < it.second/2;i++){
                        vals.push_back(it.first);
                    }
                }
            }
        }

        for(auto it : mp){
            if(it.second %2 == 0){
            }else{
                vals.push_back(it.first);
            }
        }
        if(unmatch > passes){
            cout<<"-1"<<endl;
        }else{
            cout<<"VALS : ";
            fo(i,vals.size())cout<<vals[i]<<" ";
            cout<<endl;
            ll ans[n][m];

            ll vi = 0;
            for(i = 0;i < n ;i++){
                for(j = 0; j < m/2;j++){
                    ll cur = vals[vi];
                    vi+=2;
                    //watch(cur);
                    //watch(vi);
                    ans[i][j] = cur;
                    ans[i][m-1-j] = cur;
                    watch(ans[i][j]);
                    watch(ans[i][m-j-1]);

                }
            }
            if(m%2 == 1){
                for(i = 0;i < n;i++){
                    ans[i][m/2+1] = vals[vi++];
                    watch(ans[i][m/2+1]);
                }
            }
            watch(ans[0][0]);
            watch(ans[0][2]);
            watch(ans[1][0]);
            watch(ans[1][2]);
            watch(ans[2][1]);
            fo(i,n){
                fo(j, m){
                    cout<<ans[i][j] <<" ";
                }
                
                cout<<endl;
            }
        }
    }
    //▬▬ι═══════>
    return 0;
}


/*
                     .                          
                     M                          
                    dM                          
                    MMr                         
                   4MMML                  .     
                   MMMMM.                xf     
   .              "MMMMM               .MM-     
    Mh..          +MMMMMM            .MMMM      
    .MMM.         .MMMMML.          MMMMMh      
     )MMMh.        MMMMMM         MMMMMMM       
      3MMMMx.     'MMMMMMf      xnMMMMMM"       
      '*MMMMM      MMMMMM.     nMMMMMMP"        
        *MMMMMx    "MMMMM\    .MMMMMMM=         
         *MMMMMh   "MMMMM"   JMMMMMMP           
           MMMMMM   3MMMM.  dMMMMMM            .
            MMMMMM  "MMMM  .MMMMM(        .nnMP"
=..          *MMMMx  MMM"  dMMMM"    .nnMMMMM*  
  "MMn...     'MMMMr 'MM   MMM"   .nMMMMMMM*"   
   "4MMMMnn..   *MMM  MM  MMP"  .dMMMMMMM""     
     ^MMMMMMMMx.  *ML "M .M*  .MMMMMM**"        
        *PMMMMMMhn. *x > M  .MMMM**""           
           ""**MMMMhx/.h/ .=*"                  
                    .3P"%....                   
                  nP"     "*MMnx       GaUrAv..
*/


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

