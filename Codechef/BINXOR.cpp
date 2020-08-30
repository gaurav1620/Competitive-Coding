/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav_
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

ll modDivide(ll a, ll b){
    a = a % mod7;
    ll inv = modInverse(b, mod7);
    if (inv == -1)
       return -1;
    else
       return  (inv * a) % mod7;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    
    ll test;cin>>test;
    while(test--){
        ll n;cin>>n;
        string a,b;
        cin>>a;
        cin>>b;
        ll i,j;
        ll len = n;
        ll a0 = 0,a1 = 0,b0 = 0,b1 = 0;
        fo(i,n){
            if(a[i] == '0')a0++;
            else a1++;

            if(b[i] == '0')b0++;
            else b1++;
        }

        ll min1sforXor = len - (min(a0,b0) + min(a1,b1));
        ll max1sforXor = min(a1,b0)+min(a0,b1);

        ll ans = 0;
        map<ll,ll>m;
        ll ind = 1;
        ll num = 1;
        ll den = 1;
        
        for(i = min1sforXor;i <= max1sforXor;i+=2){
            
            if(i == min1sforXor){
                for(ll j = 0;j < i;j++){
                    num = (num*(len-j))%mod7;
                    den = (den*(j+1))%mod7;
                }
                ans = (modDivide(num,den))%mod7;
                ind = ans;
            }else{

                //The main thing that was 
                // not correct was the division 
                
                num = (num*(len-i+1))%mod7;
                num = (num*(len-i+2))%mod7;

                den = (den*(i))%mod7;
                den = (den*(i-1))%mod7;
                
                ind = (ind*(len-i+1))%mod7;
                ind = (ind*(len-i+2))%mod7;
                ind = (modDivide(ind,i))%mod7;
                ind = (modDivide(ind,(i-1)))%mod7;
                
                ans = (ans + modDivide(num,den))%mod7;
                //ans = (ans + ind)%mod7;
            }


            

            /*ll numerator = 1;
            
            ll ncr = 1;
            if(m.find(i) != m.end()){
                ncr = m.find(i)->second;
            }else{
                ncr = nCrModPFermat(len,i,mod7) %mod7;
                m.insert(pair<ll,ll>(i,ncr));
                m.insert(pair<ll,ll>(len-i,ncr));
            }
            
            ans = (ans+ncr)%mod7;
            */
            //ans = (ans+x)%mod7;
            //ans = ans%mod7;
            //ans += nCr(len,i);
            //ans = ans%mod7;
        }
        //cout<<min1sforXor<<" "<<max1sforXor<<endl;
        cout<< ans<<endl;
    }

    //▬▬ι═══════>
    return 0;
}


/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀:
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀ 
*/
