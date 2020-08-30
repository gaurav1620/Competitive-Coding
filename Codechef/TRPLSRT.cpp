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

ll arr[200005];
bool todo[200005];
ll n,i,j,k,len,ind,sum,ct,tot;
vector<ll> v;
vector<ll> even;

string findAns(){
    even.clear();

    ct = 0;
    fo(i,n){
        todo[i] = arr[i]!=i;
        if(todo[i])ct++;
    }
    if(ct == 0){return "0\n";}

    tot = 0;//Count of ops
    len = 0;
    v.clear();
    
    ind = 0;
    string ans;

    while(ct){

        //if(ind > n){return "ERR";}
        if(!todo[ind]){ind++;continue;}
        
        ll cpind = ind;

        ll nextind = arr[ind];
        todo[ind] = false;

        v.clear();
        v.push_back(ind);
        while(todo[nextind]){
            v.push_back(nextind);
            todo[nextind] = false;
            nextind = arr[nextind];
        }

        ct -= v.size();   
        tot += v.size()/2;
        watch(v.size());
        if(v.size()%2 == 0){
            watch(even.size());
            if(even.size() > 1){
                cout<<"V : ";
                fo(i,v.size())cout<<v[i]<<" ";
                cout<<endl;
                cout<<"EVEN : ";
                fo(i,even.size())cout<<even[i]<<" ";
                cout<<endl;
                watch(ans);

                /*
                cout<<"EVEN : ";
                fo(i,even.size())cout<<even[i]<<" ";
                cout<<endl;
                cout<<"V :    ";
                fo(i,v.size())cout<<v[i]<<" ";
                cout<<endl;
                */
                ll gg = arr[v[0]];
                ans += to_string(v[0]+1)+" "+to_string(even[0]+1)
                        +" "+to_string(v[v.size()-1]+1)+"\n";
                
                watch(ans);
                ll a = arr[v[0]];
                ll b = arr[even[0]];
                ll c = arr[v[v.size()-1]];

                arr[even[0]] = arr[v[0]];
                arr[v[0]] = v[0];
                arr[v[v.size()-1]] = b;

                fo(i,n)cout<<arr[i]<<" ";
                cout<<endl;
                //remove the first elements
                v.erase(v.begin());

                ll newind = arr[v[0]];
                ll noice = v[0];
                watch(newind);
                cout<<v[0]<<endl;                
                //todo[noice] = false;
            
                while(newind != noice){
                    watch(newind);
                    ans += to_string(noice+1)+" "+to_string(newind+1)
                            +" "+to_string(arr[newind]+1)+"\n";
                            
                    todo[newind] = todo[arr[newind]] = false;
                    newind = arr[arr[newind]];
                }
                even.clear();
            }else{
                even.clear();
                for(i = 0;i < v.size();i++){
                    even.push_back(v[i]);
                }
            }
        }else{
            ll gg = v.size()/2;
            todo[v[0]] = false;
            ll lmoind = arr[v[0]];
            while(gg--){
                ans += to_string(v[0]+1)+" ";
                ans += to_string(lmoind+1)+" ";
                ans += to_string(arr[lmoind]+1)+"\n";
                todo[lmoind] = todo[arr[lmoind]] = false;
                lmoind = arr[arr[lmoind]];
            }
        }
        ind = cpind;   
    }
    if(even.size() > 1 || tot > k){return "-1\n";}
    ans = to_string(tot)+"\n"+ans;
    return ans;
}


int main(){
/*
    srand(time(NULL));

    while(1){
        n = rand()%10;
        fo(i,n)arr[i] = i;
        random_shuffle(arr,arr+n);

        watch(n);
        fo(i,n)cout<<arr[i]+1<<" ";
        cout<<endl;
        string s = findAns();
        if(s == "ERR"){break;}
        cout<<s<<endl;
    }
    */
    Ninja
    //▬▬ι═══════>
    ///*
    ll t;cin>>t;
    while(t--){
        cin>>n>>k;
        fo(i,n)cin>>arr[i];
        fo(i,n)arr[i]--;
        cout<<findAns();
    }
    //▬▬ι═══════>
    //*/
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

