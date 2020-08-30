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

bool sortcol(pair<ll,pair<ll,ll>> &a , pair<ll,pair<ll,ll>> &b){
    if(a.first == b.first){
        if(a.second.first == b.second.first){
            return a.second.second > b.second.second;
        }else{
            return a.second.first > b.second.first;
        }
    }else{
        return a < b;
    }
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vector<pair<ll,pair<ll,ll>>>v;
        ll quant[m],i,j,k;
        fo(i,m)cin>>quant[i];
        fo(i,n){
            ll f,a,b;
            cin>>f>>a>>b;
            f--;
            v.push_back({f,{a,b}});
        }
        //sort(v.begin(),v.end(),sortcol);

        //fo(i,n)cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        ll ans = 0;
        vector<ll> pr(n);
        ll req = 0;
        for(i = 0 ;i < n;i++){
            if(quant[v[i].first] > 0){
                pr[i] = v[i].first+1;
                ans += v[i].second.first;
                quant[v[i].first]--;
            }else{
                req++;
                pr[i] = -1;
                ans += v[i].second.second;
            }
        }
        
        //fo(i,n)if(quant[i] > 0)rem.push_back()
        vector<ll> rem;
        fo(i,n){
            if(quant[i] > 0){

                while(quant[i] > 0 && req){
                    req--;
                    quant[i]--;
                    rem.push_back(i+1);
                }
            }
        }
        ll ind = 0;
        for(i = 0;i < n;i++){
            if(pr[i] == -1){
                pr[i] = rem[0];
                rem.erase(rem.begin());
            }
        }
        cout<<ans<<endl;
        fo(i,n)cout<<pr[i]<<" ";
        cout<<endl;
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

