/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav_
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 
@ CodeChef   : gaurav1620

# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/
#include<bits/stdc++.h>

//Faster loops
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define oneFo(i,n)for(i = 1;i <=n;i++)

//Renames
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back

//MAX
#define MAXL LONG_MAX
#define MAXI INT_MAX

//MOD
#define mod7 1000000007
#define mod9 1000000009

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>
inline T fabs(T a){return a>0?a:a*-1;}

using namespace std;

//Functions
void swap(ll &x,ll &y);
bool isPrime(ll n);
ll nCrModp(ll n, ll r, ll p);
ll power(ll x, ll y, ll p);

//Used for modInverse
ll gcdExtended(ll a, ll b, ll *x, ll *y);

//Used for modDivide
ll modInverse(ll b, ll m);

//Use this for modular divisions
ll modDivide(ll a, ll b, ll m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t;cin>>t;
    while(t--){
        ll n,p;cin>>n>>p;
        ll arr[n],i,j,k;
        fo(i,n)cin>>arr[i];
        
        bool hasGreaterCurrency = false;
        fo(i,n){
            if(arr[i] > p){
                hasGreaterCurrency = true;
                break;
            }
        }
        
        if(hasGreaterCurrency){
            bool cmplt = false;
            cout<<"YES ";
            for(i = 0; i < n;i++){
                if(!cmplt && arr[i] > p){
                    cout<<"1 ";
                    cmplt = true;
                }else{
                    cout<<"0 ";
                }
            }
            cout<<endl;
        }else{
            ll ct = 0;
            bool has = false;
            fo(i,n){
                if(p%arr[i] != 0){
                    has = true;
                }
            }

            ll leftMostIndex;
            fo(i,n){
                if(p%arr[i] != 0){
                    leftMostIndex = i;
                    break;
                }
            }

            bool notDone = true;
            if(!has)cout<<"NO"<<endl;
            else{
                cout<<"YES ";
                ll rem = p;
                vector<ll> v;
                for(i = n-1;i>=0;i--){
                    //cout<<"ck : "<<i<<" : arr[i]"<<arr[i]<<" rem : "<<rem<<endl;
                    if(i == leftMostIndex){
                        v.push_back(rem/arr[i]+1);
                        rem = 0;
                    }else if(rem%arr[i] != 0){
                        v.push_back(rem/arr[i]);
                        rem -= (rem/arr[i])*arr[i];
                    }else{
                        v.push_back(0);
                    }
                }

                for(i = v.size()-1;i >=0;i--){
                    cout<<v[i]<<" ";
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

