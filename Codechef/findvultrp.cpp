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

void shuffle_array(ll arr[], ll n)
{

  // To obtain a time-based seed
  unsigned seed = 0;

  // Shuffling our array
  shuffle(arr, arr + n,
          default_random_engine(seed));

  // Printing our array
}


int main(){
    ll t;cin>>t;
    ll test = 0;
    while(t--){
        ll n,k;
        n = t+3;
        k = n;
        ll i,j;
        ll arr[n];
        
        fo(i,n)arr[i] = i;
        shuffle_array(arr,n);

        cout<<"\nTest"<<test++<<" ::  "<<endl;

        ///*
        cout<<"                 ";
        fo(i,n)cout<<i<<" ";
        cout<<endl;

        cout<<"Before sorting : ";
        fo(i,n)cout<<arr[i]<<" ";
        cout<<endl;

        //*/

        ll offset = 0;
        fo(i,n){if(arr[i] != i)offset++;}
        
        if(offset == 0){
            cout<<"n : "<<n<<" : OK No displaced element ans 0"<<endl;
        }
        else if(offset > 1 && offset%2 == 0){
            cout<<"n : "<<n<<" : OK EVEN diplaced elements ans -1"<<endl;
        }else{
            ll ct = 0;
            bool isHappy[n];
            fo(i,n)isHappy[i] = arr[i]==i;
            ll wrongTillNow = 0;
            fo(i,n)wrongTillNow += isHappy[i] ? 0:1;

            ll ind = 0;
            while(arr[ind] == ind)ind++;
            
            if(k < wrongTillNow/2){
                cout<<"n : "<<n<<" : OK K is less than 0.5n"<<endl;
            }else{
                ll val = ind;
                ll tot = wrongTillNow/2;
                ll steps = 0;
                bool wa = false;
                while(wrongTillNow){
                    steps++;
                    watch(steps);

                    cout<<"Before swap : \n";
                    fo(i,n)cout<<arr[i]<<" ";
                    cout<<endl;


                    //watch(wrongTillNow);
                    //fo(i,n)cout<<i<<" ";
                    //cout<<endl;
                    //fo(i,n)cout<<arr[i]<<" ";
                    //cout<<endl;
                    //cout<<val+1<<" ";
                    //cout<<arr[ind]+1<<" "<<arr[arr[ind]]+1<<endl; 
                    ll temp = arr[arr[arr[ind]]];
                    
                    arr[arr[arr[ind]]] = arr[arr[ind]];
                    arr[arr[ind]] = arr[ind];

                    arr[ind] = temp;
                    wrongTillNow = 0;
                    fo(i,n){
                        if(arr[i] != i){wrongTillNow++;}
                    }
                    
                    watch(wrongTillNow);
                    cout<<"After swap : \n";
                    fo(i,n)cout<<arr[i]<<" ";
                    cout<<endl;

                    if(steps > n){  
                        wa = true;
                        break;
                    }
                }
                if(wa){
                    cout<<"n : "<<n<<"************************************* : WA "
                        <<steps<<" steps"<<endl;
                }
                else cout<<"n : "<<n<<" : OK Sorted in "
                    <<steps<<" steps"<<endl;

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

