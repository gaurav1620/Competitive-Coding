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
#define mod9 1000000009

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>inline T       fabs(T a)           { return a>0?a:-a; }

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


class R{
public:
    ll start;
    ll end;
    ll size;
    R(){
        start = 0;
        end = 0;
        size = 0;
    }
    R(ll s,ll e){
        start = s;
        end = e;
        size = e-s+1;
    }
};

bool myFunc(R a,R b){
    if(a.start < b.start){
        return true;
    }else if(a.start > b.start){
        return false;
    }else {
        return a.end < b.end;
    }
}

bool overlap(R x,R y){
    if(x.start == y.start)return true;
    else if(x.start < y.start)return x.end >= y.start;
    else return y.end >= x.start;
}

ll isSubsetSum(ll set[], ll n, ll sum){
   // Base Cases
   if (sum == 0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;

   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) ||
                        isSubsetSum(set, n-1, sum-set[n-1]);
}

bool hasOverlappingRange(vector<R> v,R x){
    for(auto& it:v){
        if(overlap(it,x))return true;
    }
    return false;
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
        ll n,i,j;cin>>n;
        R arr[n];
        fo(i,n){
            ll s,e;cin>>s>>e;
            
            R r(min(s,e),max(s,e));
            arr[i] = r;
        }
        ll nn = sizeof(arr)/sizeof(arr[0]);
        sort(arr, arr + nn , myFunc);

        vector<R> A,B,Abackup,Bbackup;

        bool chanceA = true;
        fo(i,n){
            
            //Current element
            R el = arr[i];

            if(chanceA){
                if(hasOverlappingRange(B,el)){
                    Bbackup.push_back(el);
                }else{
                    chanceA = false;
                    A.push_back(el);
                }
            }else{
                if(hasOverlappingRange(A,el)){
                    Abackup.push_back(el);
                }else{
                    chanceA = true;
                    B.push_back(el);
                }
            }
        }
        
        for(auto& it:Abackup){
            bool pp = true;
            for(auto& bb:B){
                if(overlap(it,bb)){
                    pp = false;
                    break;
                }
            }
            if(pp){
                A.push_back(it);
            }
        }

        for(auto& it:Bbackup){
            bool pp = true;
            for(auto& aa:A){
                if(overlap(aa,it)){
                    pp = false;
                    break;
                }
            }
            if(pp)B.push_back(it);
        }
        
        if(min(A.size(),B.size()) != 0)cout<<n - (min(A.size(),B.size())*2)<<endl;
        else cout<<-1<<endl;
        
    }

}

