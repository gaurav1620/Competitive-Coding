/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 

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

#define mod7 1000000007

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>inline T       fabs(T a)           { return a>0?a:-a; }
template<class T>inline T       isOdd(T a)          { return a&1; } 
//template<class T>inline T       gcd(T a,T b)        { return __gcd(a,b);}
template<class T>inline T       intoTwo(T a)        { return a<<1;}
template<class T>inline ll      stringLength(T s[]) {ll i ;for(i = 0;s[i];i++);return i;}


using namespace std;

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

ll nCrModp(ll n, ll r, ll p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    ll C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (ll i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (ll j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

/*
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

ll nCrModPFermat(ll n, ll r, ll p)
{
   // Base case
   if (r==0)
      return 1;
    if(n == r)return 1;
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n+1];
    fac[0] = 1;
    for (int i=1 ; i<=n; i++)
        fac[i] = fac[i-1]*i%p;

    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}
*/

ll myFastestnCr(ll n,ll r){
    r = min(r,n-r);
    if(r == 0)return 1;
    if(r == 1)return n;
    ll numerator = 1;
    ll denominator = 1;
    ll ans = 1;
    for(ll i = 0;i < r;i++ ){
        numerator = (numerator*(n-i))%mod7;
        denominator = (denominator*(r-i))%mod7;
    
        ll Gcd = __gcd(numerator,denominator);
        numerator = numerator/Gcd;
        denominator = denominator/Gcd;
    }
    ans = (numerator/denominator)%mod7;
    return ans;
}

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

ll modDivide(ll a, ll b, ll m){
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
       return  (inv * a) % m;
}

#define modd 998244353

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    
    ll test;cin>>test;
    while(test--){
        ll n,p,r;cin>>n>>p>>r;

        ll ans = 0;
        ll num = 1;
        ll den = 1;

        for(ll i = 0;i <= n;i++){
            ll pp = power(p,i,modd);
            if(pp >= r){
                num = 1;

                for(ll j = 0;j < min(r,pp-r);j++){
                    num = (num*(pp-j))%modd;
                    num = (modDivide(num,j+1,modd))%modd;
                }
                ans = (ans+num)%modd;
            }

        }
        cout<<ans<<endl;

    }

}
