#include<bits/stdc++.h>
/*
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
        ll r,c;cin>>r>>c;
        char arr[r+1][c+1];

        ll i,j,k;
        fo(i,r){
            string s;cin>>s;
            fo(j,c){
                arr[i][j] = s[j];
            }
        }

        map<ll,ll> m[r][c];
        fo(i,r){
            fo(j,c){
                ll ind = 1;
                ll ii = i;
                ll  jj = j;
                if(arr[i][j] == 'L'){
                    j--;
                    while(j >= 0 && arr[i][j] != '#'){
                        m[i][j][ind++]++;
                        j--;
                    }
                }
                else if(arr[i][j] == 'R'){
                    j++;
                    while(j < c && arr[i][j] != '#'){
                        m[i][j][ind++]++;
                        j++;
                    }   
                }
                else if(arr[i][j] == 'U'){
                    i--;
                    while(i >= 0 && arr[i][j] != '#'){
                        m[i][j][ind++]++;
                        i--;
                    }
                }
                else if(arr[i][j] == 'D'){
                    i++;
                    while(i < r && arr[i][j] != '#'){
                        m[i][j][ind++]++;
                        i++;
                    }
                }
                //COpy back
                j = jj;
                i = ii;
            }
        }

        ll ans = 0;
        fo(i,r){
            fo(j,c){
                
                for(auto itr = m[i][j].begin(); itr != m[i][j].end();itr++)
                if(itr->second > 1)ans += nCrModp(itr->second,2,mod9);
            }
        }
        cout<<ans<<endl;

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

