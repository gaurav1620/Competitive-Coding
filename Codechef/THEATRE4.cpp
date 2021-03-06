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
#define rfo(i,n)  for(i = n-1; i >= 0;i--)
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

bool sortcol(int *a,int *b){
    return a[0] > b[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t;cin>>t;
    ll sum = 0;
    while(t--){
        char c;
        int n,x;
    
        cin>>n;
        int arr[4][4],i,j;

        fo(i,4){
            arr[i][0] = 0;//i is abcd and i[0] for sum of all
            arr[i][1] = 0;//3pm
            arr[i][2] = 0;//6pm
            arr[i][3] = 0;//9pm
        }
        
        fo(i,n){
            cin>>c>>x;

            if(c == 'A'){
                arr[0][x/3 -1]++;
            }else if(c == 'B'){
                arr[1][x/3 -1]++;
            }else if(c == 'C'){
                arr[2][x/3 -1]++;
            }else if(c == 'D'){
                arr[3][x/3 -1]++;
            }
        }

        bool availability[4][4];
        fo(i,4){fo(j,4)availability[i][j] = true;}
        
        ll ans  = -1 * INT_MAX;
        ll k,l,m,p,q,r;
        for(i = 0;i < 4;i++){ // x1
            for(j = 0;j < 4;j++){// x2
                for(k = 0;k < 4;k++){// x3
                    for(l = 0;l < 4;l++){ // x4
                        for(m = 0;m < 4;m++){// y1
                            for(p = 0;p < 4;p++){// y2
                                for(q = 0;q < 4;q++){// y3
                                    for(r = 0;r < 4;r++){// y4
                                        if(   i != j && i!=k && i!= l && j!=k && j!= l && k!=l
                                           && m != p && m!= q && m!= r && p != q && p != r && q!=r
                                          ){
                                            ll a[4];
                                            a[1] = arr[i][m];
                                            a[2] = arr[j][p];
                                            a[3] = arr[k][q];
                                            a[0] = arr[l][r];
                                            

                                            ll currentPrice = 0;
                                            ll currentVal = 100;
                                            for(int xx = 0;xx < 4;xx++){
                                                if(a[xx]){
                                                    currentPrice += a[xx]*currentVal;
                                                    currentVal -= 25;
                                                }else{
                                                    currentPrice -=100;
                                                }
                                            }

                                            ans = max(ans,currentPrice);

                                        }
                                    } 
                                }
                            }
                        }
 
                    } 
                }
            }
        }
        cout<<ans<<endl;
        sum += ans;
    }
    cout<<sum<<endl;
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

