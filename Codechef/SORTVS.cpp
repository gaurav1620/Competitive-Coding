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

typedef struct container{
    set<ll> indexes;
    set<ll> values;
} container;


vector<container> conts;
vector<ll> adj[20];
ll n,m,i,j,k,x,y,arr[20];
bool containerVisited[20];
bool vis[20];
unordered_map<ll,ll> inWhichContIsIndex;//this store the key as the array 
unordered_map<ll,ll> inWhichContIsValue;
                                    //elements and values as the index
                                    //of the vector that conains its 
                                    //value

void createContainer(ll ind){
    if(adj[ind].size() == 0){
        if(arr[ind] != ind){
            containerVisited[ind] = true;
            container newc;

            //Insert the indexes and vals
            newc.indexes.insert(ind);
            newc.values.insert(arr[ind]);
            
            conts.push_back(newc);
            inWhichContIsValue[arr[ind]] = conts.size()-1;
            inWhichContIsIndex[ind] = conts.size()-1;
        }
    }else{
        stack<ll> st;
        st.push(ind);

        container newc;

        while(!st.empty()){
            ind = st.top();
            st.pop();
            containerVisited[ind] = true;
            
            newc.indexes.insert(ind);
            newc.values.insert(arr[ind]);
            fo(i,adj[ind].size()){
                if(!containerVisited[adj[ind][i]]){
                    st.push(adj[ind][i]);
                }
            }
        }
        vector<ll> rem;
        //remove if the graph contains the values of the indices needed
        for(auto itr = newc.indexes.begin();itr != newc.indexes.end();itr++){
            if(newc.values.find(*itr) != newc.values.end()){
                rem.push_back(*itr);
            }
        }
        //rem contains the indexes to remove

        fo(i,rem.size()){
            newc.indexes.erase(newc.indexes.find(rem[i]));
            newc.values.erase(newc.values.find(arr[rem[i]]));
        }
        if((newc.indexes.size() != 0) && (newc.values.size() != 0)){
            conts.push_back(newc);
            
            for(auto itr = newc.values.begin();itr != newc.values.end();itr++)
            inWhichContIsValue[*itr] = conts.size()-1;

            for(auto itr = newc.indexes.begin();itr != newc.indexes.end();itr++)
            inWhichContIsIndex[*itr] = conts.size()-1;
        }
    }
}

ll findAns(){
    fo(i,n)containerVisited[i] = false;

    fo(i,n){
        if(!containerVisited[i])createContainer(i);
    }

    ///*/DEB
    fo(i,conts.size()){
        cout<<"ind : "<<i<<endl;
        container newc = conts[i];
        cout<<"Indexes : ";
        for(auto itr = newc.indexes.begin();itr != newc.indexes.end();itr++)
        cout<<*itr<<" ";
        cout<<endl;

        cout<<"Values  : ";
        for(auto itr = newc.values.begin();itr != newc.values.end();itr++)
        cout<<*itr<<" ";
        cout<<endl;
    }
    //*///DEB END
    //fo(i,n)cout<<inWhichContIsValue[i]<<" ";
    //cout<<endl;
    //fo(i,n)cout<<inWhichContIsIndex[i]<<" ";
    
    ll ans = 0;
    ll doneTillNow = 0;
    bool done[n];
    fo(i,n){
        done[i] = arr[i] == i;
        if(done[i])doneTillNow++;
    }

    //remember we now only have unmatching indices and their vals stored in the conts
    while(doneTillNow < n){
        
        ll minSizeInd;
        bool init = true;
    
        fo(i,conts.size()){
            if(init && conts[i].indexes.size() > 0){
                init = false;
                minSizeInd = i;
            }
            else if(!init   && conts[minSizeInd].indexes.size() > conts[i].indexes.size()){
                minSizeInd = i;
            }
        }
        
        //Current container
        container crC = conts[minSizeInd];

        auto gg = crC.values.begin();
        //valuew to send 
        ll valueToSend = *gg;
        ll currentContainer = minSizeInd;
        ll containerToSend = inWhichContIsValue[valueToSend];
        
        //Watch
        watch(valueToSend);
        watch(currentContainer);
        watch(containerToSend);

        //As values in the conttosend may have indexes of current container
        bool hasUsableVal = false;
        ll usableVal;

        //iterate over the send containers values
        set<ll>::iterator itr,itr2; 
        for( itr = conts[containerToSend].values.begin();itr != conts[containerToSend].values.end();++itr){

            for(itr2 = conts[currentContainer].indexes.begin();itr2 != conts[currentContainer].indexes.end();++itr2){
                if(*itr2 == *itr){
                    hasUsableVal = true;
                    usableVal = *itr;
                    break;
                }
            }
        }

        conts[containerToSend].indexes.erase(conts[containerToSend].indexes.find(valueToSend));
        if(hasUsableVal){
            doneTillNow++;
            //erase the from send container
            //usable val is current containers ind;
            conts[containerToSend].values.erase(conts[containerToSend].values.find(usableVal));
            conts[currentContainer].indexes.erase(conts[currentContainer].indexes.find(usableVal));
        }else{
            auto kk = conts[containerToSend].values.begin();
            conts[containerToSend].values.erase(conts[containerToSend].values.begin());
            conts[currentContainer].values.insert(*kk);
        }

        ans++;
        doneTillNow++;
    }
    return ans;
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        conts.clear();
        cin>>n>>m;
        fo(i,n)cin>>arr[i];
        fo(i,n)arr[i]--;
        
        //Clearing !!!!!!!!!!!
        fo(i,n)vis[i] = false;
        fo(i,n)adj[i].clear();
        
        while(m--){
            ll x,y;
            cin>>x>>y;
            x--;y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        cout<<findAns()<<endl;
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

