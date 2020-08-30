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


bool isPerfectSquare(ll x)
{
  // Find floating point value of
  // square root of x.
  long double sr = sqrt(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}

ll findYCor(ll x1,ll x2){
    if(isPerfectSquare(x1*x2)){
        return sqrt(x1*x2);
    }else{
        return -1;
    }
}
void pV(vector<ll> g1){
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " ";
    cout<<endl;
    return;
}
int main(){
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm

    ll t;cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll i,j,a[n],b[m];
        fo(i,n)cin>>a[i];
        fo(i,m)cin>>b[i];

        vector<ll> u,d,l,r;
        ll mu[100000] = {0};
        ll md[100000] = {0};
        ll ml[100000] = {0};
        ll mr[100000] = {0};
        
        bool xhas = false,yhas = false;

        fo(i,m){
            ll e = b[i];
            if(e > 0){
                u.push_back(e);
                mu[e]++;
            }else if(e < 0){
                d.push_back(e*-1);
                md[e*-1]++;
            }else{
                yhas = true;
            }
        }
       
        fo(i,n){
            ll e = a[i];
            if(e > 0){
                r.push_back(e);
                mr[e]++;
            }else if(e < 0){
                l.push_back(e*-1);
                ml[e*-1]++;
            }else{
                xhas = true;
            }
        }
/*
        pV(r); 
        pV(u); 
        pV(l); 
        pV(d); 
 */
        ll ct = 0;
        ll mm = max(n,m);

        for(i = 0;i < d.size();i++){
            for(j= 0;j < u.size();j++){
                /*
                if(!(d[i] == u[j] && u[j] == 0)){

                    if(d[i] == 0 || u[j] == 0){
                        ct++;
                        continue;
                    }
                */
                    //cout<<"Check"<<ct<<endl;
                    //Then only find
                    //this is to check if both zeros do not overlap
                    ll y1 = findYCor(d[i],u[j]);

                    if(y1 != -1 && ml[y1] != 0){
                        ct++;
   //                     cout<<"Found69 : "<<u[j]<<" "<<d[i]<<" "<<y1<<endl;
                    }
                    if(y1 != -1 && mr[y1] != 0){
                        ct++;
     //                   cout<<"Found69 : "<<u[j]<<" "<<d[i]<<" "<<y1<<endl;
                    }
               // }

            }
        }

        for(i = 0;i < l.size();i++){
            for(j= 0;j < r.size();j++){
                /*
                if(!(l[i] == r[j] && r[j] == 0)){
                    if(l[i] == 0 || r[j] == 0){
                        ct++;
                        continue;
                    }
                    //Then only find
                    //this is to check if both zeros do not overlap
                */
                    ll y1 = findYCor(l[i],r[j]);
                
                    if(y1 != -1 && mu[y1] != 0){
                        ct++;
       //                 cout<<"Found : "<<r[j]<<" "<<l[i]<<" "<<y1<<endl;
                    }
                    if(y1 != -1 && md[y1] != 0){
                        ct++;
         //               cout<<"Found : "<<r[j]<<" "<<l[i]<<" "<<y1<<endl;
                    }

                //}
            }
        }

        if(xhas || yhas){
            ct += (mr.size()*mu.size())+(mu.size()*ml.size());
            ct += (ml.size()*md.size())+(md.size()*mu.size());
        }
        cout<<ct<<endl;

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

