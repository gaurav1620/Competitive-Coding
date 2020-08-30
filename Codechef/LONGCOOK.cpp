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

ll dayofweek(ll d, ll m, ll y)
{
    static ll t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y / 4 - y / 100 +
             y / 400 + t[m - 1] + d) % 7;
}

bool isLeapYear(ll y){
    if(y%400 == 0)return true;
    if(y%100 == 0)return false;
    if(y%4 == 0)return true;
    return false;

}


ll arr[500];

int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t,ii,ans = 0,sum = 0;cin>>t;

    //Init arr
    arr[0] = 0;
    for(ii = 1;ii <= 400;ii++){
        ans = 0;
        
        if(isLeapYear(ii)){
            if(dayofweek(1,2,ii) == 6){
                ans++;
                sum++;
            }
        }else{
            if(dayofweek(1,2,ii) == 0 || dayofweek(1,2,ii) == 6){
                ans++;
                sum++;
            }
        }

        arr[ii] = ans;
    }

    ll mm = sum;
//    fo(ii,61)cout<<arr[ii]<<endl;


    while(t--){
        ll m1,y1,m2,y2;cin>>m1>>y1>>m2>>y2;
        //cout<<getAns(m1,y1,m2,y2)<<endl;
        ll x = 0; //28 day febs till now that start with sat or sun
        ll y = 0;//29 leap years that start with sun.

        if(m1 > 2)y1++;
        if(m2 < 2)y2--;
        
        ll i,j,k;
        ans = 0;
/*
        //556
        if(y1%400 != 0){
            ans += mm - arr[y1%400];
        } 

        if(y2%400 != 0){
            ans += arr[y1%400];
        }

        ll lft,rgt;
        if(y1%400 != 0){
            lft = y1/400;
            lft++;
            lft *= 400;
        }else{
            lft = y1;
        }

        if(y2%400 != 0){
            rgt = y2/400;
            rgt *= 400;
        }else{
            rgt = y2;
        }

        ans += ((rgt - lft)/400)*mm;

        cout<<ans<<endl;
*/      
        
        ll hh = (y1/400 + 1)*400;
        ll gg = (y2/400)*400;

        for(i = y1;i != hh;i++){
            ans+=arr[i%400];
        }

        for(i = y2;i != gg;i--){
            ans+= arr[i%400];
        }

        ans += ((gg-hh)/400)*mm;

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

