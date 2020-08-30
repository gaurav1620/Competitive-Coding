#include<bits/stdc++.h>

#define debug true
#define lmao if(debug)
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

ll lowerIndex(ll arr[], ll n, ll x)
{
    ll l = 0, h = n - 1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

// function to find last index <= y
ll upperIndex(ll arr[], ll n, ll y)
{
    ll l = 0, h = n - 1;
    while (l <= h) {
        ll mid = (l + h) / 2;
        if (arr[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

// function to count elements within given range
ll countInRange(ll arr[], ll n, ll x, ll y)
{
    // initialize result
    ll count = 0;
    count = upperIndex(arr, n, y) - lowerIndex(arr, n, x) + 1;
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll arr[n+1];
        ll i,j;
        
        fo(i,n)cin>>arr[i];
    
        ll dp[n];
        dp[n-1] = n-1;

        ll nextNewElInd = n-1;

        for(ll i = n-2;i >= 0;i--){

            ll ell = arr[i];

            ll ii = i+1;
            while(arr[i] == ell){
                dp[i] = ii;
                i--;
            }
            i++;

        
        }
        
        //fo(i,n)cout<<dp[i]<<" ";
        //cout<<endl;
        //

        ll l = 0;
        ll r = 0;
        ll currMaxLen = 1;
        ll currNumberOfDistinctElements = 1;

        ll karr[k+1] = {0};

        set<ll> ss;
        ss.insert(arr[0]);

        for(i = 1;i < n;i++){

            if(ss.find(arr[i]) != ss.end()){
                currMaxLen = max(i-l+1, currMaxLen);
            }else{
                //Not Found
                if(currNumberOfDistinctElements < k-1){
                    currMaxLen = max(i-l+2,currMaxLen);
                    ss.insert(arr[i]);
                    currNumberOfDistinctElements++;
                }else{
                    ss.erase(arr[l]);
                    l = dp[l];
                    ss.insert(arr[i]);
                    currMaxLen = max(i-l+1,currMaxLen);
                }
            }
        }

        cout<<currMaxLen<<endl;
    
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

