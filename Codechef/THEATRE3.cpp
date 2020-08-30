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

ll findAns(ll arr[4][4],bool canTake[4][4],ll num,ll currentAns, ll currentPrice){
    if(num == 0)return 0;

    bool origCanTake[4][4];

    ll chh = -1;


    ll i,j,mm,maxi,maxj,ans = 0,amt;
    fo(i,4){
        fo(j,4){
            if(arr[i][j] > chh && canTake[i][j])chh = arr[i][j];
            origCanTake[i][j] = canTake[i][j];
        }
    }
    if(chh == 0 || chh == -1){
        return -100 + findAns(arr,canTake,num-1,0,currentPrice);
    }
    mm = 0;
    fo(i,4){
        fo(j,4){
            if(canTake[i][j] && arr[i][j] > mm){
                maxi = i;
                maxj = j;
                mm = arr[i][j];
            }else if(canTake[i][j] && arr[i][j] == mm){
                //TODO: erdtfyghjgfdsdfghfgjhgfddfgshfjh
            }
        }
    }
    

    bool notIntialized = true;
    vector<pair<ll,ll>>v;
    fo(i,4){
        fo(j,4){
            if((arr[i][j] == mm) && canTake[i][j] == true){
                v.push_back(pair<ll,ll>(i,j));
            } 
        }
    }
    
    //cout<<"*Found max for "<<num<<" of "<<mm<<endl;
/*
    fo(i,4){
        fo(j,4)cout<<canTake[i][j];
        cout<<endl;
    }
*/
    ll localMax = INT_MAX*-1;
    for(int xx = 0;xx < v.size();xx++){
        bool cpCanTake[4][4];
        fo(i,4){
            fo(j,4){
                cpCanTake[i][j] = canTake[i][j];
            }
        }
        fo(i,4)cpCanTake[v[xx].first][i] = false;
        fo(i,4)cpCanTake[i][v[xx].second] = false;
        
        
        //cout<<"Going in to find "<<num-1<<" elements."; 
        if(findAns(arr,cpCanTake,num-1,0,currentPrice-25) > localMax){
            //cout<<"\tYup Greater";
            localMax = findAns(arr,cpCanTake,num-1,0,currentPrice-25);
            maxi = v[xx].first;
            maxj = v[xx].second;
        }
    }
    ll y;
    fo(y,4)canTake[maxi][y] = false;
    fo(y,4)canTake[y][maxj] = false;

//      cout<<v+1<<". "<<maxi<<" "<<maxj<<" "<<mm<<endl;
    if(arr[maxi][maxj] == 0)ans -= 100;
    else {
        ans = arr[maxi][maxj]*currentPrice;
    }
    //cout<<"Returning for "<<num<<" "<<ans<<endl;
    return max(ans+findAns(arr,canTake,num-1,0,currentPrice-25), findAns(arr,origCanTake,num-1,0,currentPrice) -100);
 }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t;cin>>t;
    ll fin = 0;
    while(t--){
        ll n;cin>>n;
        char x;
        ll v,i,j,k,u,y,z,maxi,maxj,mm,ans = 0,amt = 100;
        ll arr[4][4];
        bool canTake[4][4];

        fo(i,4)fo(j,4)canTake[i][j] = true;
        fo(i,4)fo(j,4)arr[i][j] = 0;

        fo(i,n){
            cin>>x>>u;
            arr[x-'A'][(u/3)%4]++;
        }
/*
        fo(i,4){
            fo(j,4){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        
        ans = findAns(arr,canTake,4,0,100);

        cout<<ans<<endl;
        fin += ans;
    }
    cout<<fin<<endl;
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

