#include<bits/stdc++.h>
/*
 * author     : Gaurav Khairnar
 * github     : github.com/gaurav1620
 * codechef   : gaurav_1620
 * codeforces : gaurav1620
 *
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

ll t,n,m,i,j,k;
ll arr[20];
ll grpInd[20];
vector<ll> adj[20];
vector<set<ll>> groups;


ll findAns(ll inp[]){
    ll ind;
    bool ret = true;
    fo(i,n){
        if(inp[i] != i){
            ret = false;
            break;
        }
    }
    if(ret){
        return 0;
    }
    ll ans = 1000;
    fo(ind,n){
        if(inp[ind] != ind){
            //now we have to put proper value for ind ie. ind
            ll localAns = 1000;
            
            if(groups[grpInd[ind]].size() == 1){
                ll copyArr[n];
                fo(i,n)copyArr[i] = inp[i];
                ll ff;
                for(ff = 0;ff < n;ff++){
                    //watch(ff);
                    //watch(ind);
                    if(ind == inp[ff]){
                        swap(copyArr[ind],copyArr[ff]);
                        break;
                    }
                }
                localAns = 1 + findAns(copyArr);
            }else{
                ll copyArr[n];
                fo(i,n)copyArr[i] = inp[i];
                localAns = 0;
                ll ff;
                for(ff = 0;ff < n;ff++){
                    if(ind == inp[ff]){
                        
                        if(grpInd[ind] != grpInd[ff]){localAns++;}
                        
                        swap(copyArr[ind],copyArr[ff]);
                        break;
                    }
                }
                localAns += findAns(copyArr);
                
            }
            ans = min(ans,localAns);
        }
    }
    return ans;
}
int main(){
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        cin>>n>>m;
        fo(i,n)cin>>arr[i];
        fo(i,n)arr[i]--;
        fo(i,n)adj[i].clear();
        groups.clear();

        if(m == 0){
            ll ans = 0;
            fo(i,n){
                if(arr[i] != i){
                    fo(j,n){if(arr[j] == i)break;}
                    ans++;
                    arr[j] = arr[i];
                    arr[i] = i;
                }
            }
            cout<<ans<<endl;
            continue;
        }
        fo(i,m){
            ll x,y;cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool visited[n];
        fo(i,n)visited[i] = false;
         
        for(i = 0;i < n;i++){
            if(!visited[i]){
                if(adj[i].size() == 0){
                    visited[i] = true;
                    set<ll> sett;
                    sett.insert(i);
                    groups.push_back(sett);
                    grpInd[i] = groups.size()-1;
                }else{
                    queue<ll> q;
                    q.push(i);
                    set<ll> sett;
                    
                    while(!q.empty()){
                        ll tt = q.front();
                        q.pop();
                        sett.insert(tt);
                        visited[tt]  = true;
                        grpInd[tt] = groups.size();

                        fo(j,adj[tt].size()){
                            if(!visited[adj[tt][j]]){
                                q.push(adj[tt][j]);
                            }
                        }
                    }
                    groups.push_back(sett);
                }
            }
        }
        cout<<findAns(arr)<<endl;
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

