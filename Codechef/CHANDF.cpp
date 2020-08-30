#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

string getS(ll x){
    string s;
    while(x){
        char c = x%2 == 0 ? '0':'1';
        s = c+s;
        x/=2;
    }
    while(s.length() < 25){
        s = "0"+s;
    }
    return s;
}

ll findAnsUtil(ll x,ll y,ll left,ll right){
    if(x == 0 || y == 0){return left;}
    
    ll maxprod = (left & x)*(left & y);
    ll ind = left;
    ll ans = left;

    while(ind++ < right){
        if((ind & x)*(ind & y) > maxprod){
            maxprod = (ind & x)*(ind & y);
            ans = ind;
        }
    }
    return ans;

}
ll findAnsFinal(ll x,ll y,ll left,ll right){
    if(x == 0 || y == 0){return left;}
    ll best = (x|y);
    
    if(left <= best && best <= right){return best;}

    ll minn = 0;
    ll ind1 = (ffs(x)-1);
    ll ind2 = (ffs(y)-1);
    
    if(ind1 > ind2){
        if(y & 1LL << ind1){
            minn |= 1LL << ind1;
        } else{
            minn |= 1LL << ind1;
            minn |= 1LL << ind2;
        }
    }else if(ind1 < ind2){
        if(x & 1LL << ind2){
            minn |= 1LL << ind2;
        } else{
            minn |= 1LL << ind1;
            minn |= 1LL << ind2;
        }
    }else{
        minn |= 1LL << ind1;
    }

    if(right < minn){return left;}
    if(right == minn){return right;}
    minn = minn;
    best = best;

    if(best < left){
    
        ll ans = best;
        ll leftind = log2(left);
        ll ansind = log2(ans);

        ll ind = leftind;
        ans = left;
        while(ind >= 0){
            if(!(leftind & 1LL << ind) && (best & 1LL << ind)){
                ans |= 1LL << ind;
                //ind--;
                ll mask = pow(2,ind)-1;//all ones after ind
                mask &= best;          // copies all after ind 

                ll ansZeromask = pow(2,ind)-1;
                ansZeromask = ~(ansZeromask);
                ans &= ansZeromask;
                ans |= mask;
                if(ans > right){
                    //return left;
                    break;
                }
                else{return ans;}
            }
            ind--;
        }

        if(ans > right){
            best = ans;
        }
        else {
            return left;
        }
    } 
    //best = ans;
    if(best > right){
        ll rightcopy = right;
        ll ind = log2(right);
        for(;ind >= 0;ind--){
            if(!(best & 1LL <<ind) && (right & 1LL<<ind)){
                rightcopy &= ~(1LL << ind);
                ind--;
                while(ind>=0){
                    if(best & 1ULL<<ind){
                        rightcopy |= 1LL<<ind;
                    }else{
                        rightcopy &= ~(1LL<<ind);
                    }
                    ind--;
                }
                break;
            }
        }
        ll maxAns = rightcopy;
        ll maxPro = (rightcopy & x)*(rightcopy & y);
        ll lolright = right;
        ll lolInd = log2(right);
        ind = log2(right);
        while(ind >= 0){
            if(!(rightcopy & 1LL << ind)){ind--;continue;}
            ll checkNum = rightcopy;
            ll locind = ind;
            checkNum &= ~(1LL << locind);
            locind--;
            while(locind >= 0){
                if(best & 1LL << locind){
                    checkNum |= 1LL << locind;
                }else{
                    checkNum &= ~(1LL << locind);
                }
                locind--;
            }
            ll pro = (checkNum & x)*(checkNum & y);
            if(pro > maxPro || ((pro == maxPro)) && (checkNum < maxAns)){
                maxAns = checkNum;
                maxPro = pro;
            }
            ind--;
        }
        if(maxAns < left){
            ll tillnow = 0;
            ll ind = 0;
            ll ans = maxAns;
            ll prevans = maxAns;
            while(1){
                if(prevans & 1LL << ind){
                    //bit is set
                    ind++;
                }else{
                    //unset
                    if(prevans+pow(2,ind) >= left){
                        return prevans+pow(2,ind);
                    }else if(maxAns + pow(2,ind) + tillnow >= left){
                        ans |= 1LL << ind;
                        while(ind >= 0){
                            if(ans >= left){break;}
                            if(!(prevans & 1LL << ind)){
                                ans |= 1LL << ind;
                            }
                            ind--;
                        }
                    }else{
                        tillnow |= 1LL << ind;
                    }
                    ind++;
                }
            }
        
            if(ans > right){return left;}
            return ans;
        
        }else{
            return maxAns;
        }
    }
}



int main(){
    ll num = 20;
    while(1){
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);
        
        
        ll x,y,left,right;
        left = rand()%10000;
        x = rand()%10000;
        y = rand()%10000;
        right = rand()%10000;
        if(left > right){swap(left,right);}
        //cin>>x>>y>>left>>right;
        //cout<<"Started: "<<x<<" "<<y<<" "<<left<<" "<<right<<endl;
            //cout<<findAnsUtil(x,y,left,right)<<" : "
            //<<findAns(x,y,left,right);
        
        ll noneff  = findAnsUtil(x,y,left,right);
        //ll eff = findAns(x,y,left,right);
        //ll test = findAnsTest(x,y,left,right);
        ll fina = findAnsFinal(x,y,left,right);

        if(noneff != fina){
            if(fina == -1)num--;

            cout<<"\n*************Test : "<<20-num<<"*******************\n";
            watch(x);
            watch(y);
            watch(left);
            watch(right);
            watch(x|y);
            cout<<noneff<<" : "<<fina<<endl;
            cout<<"X     :"<<getS(x)<<endl;
            cout<<"Y     :"<<getS(y)<<endl;
            cout<<"Left  :"<<getS(left)<<endl;
            cout<<"Right :"<<getS(right)<<endl;
            cout<<"X|Y   :"<<getS(x|y)<<endl;
            cout<<"crt   :"<<getS(noneff)<<endl;
            cout<<"wa    :"<<getS(fina)<<endl;
            break;
        }else{
            //cout<<"OK\n";
            //cout<<"Ended "<<endl;
            //cout<<"OK : "<<x<<" "<<y<<" "<<left<<" "<<right<<endl;
            //cout<<findAnsUtil(x,y,left,right)<<" : "
                //<<findAns(x,y,left,right)<<endl;
        }
    }
    return 0;

    //Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        
        ll x,y,left,right,i,j,k;cin>>x>>y>>left>>right;
            
        //assign random vals;

        cout<<findAns(x,y,left,right)<<endl;
        cout<<findAnsUtil(x,y,left,right)<<endl;
        
        /*
        ll ans = 0;
        for(i = 0;i <= 63;i++){
            if((x & (1LL << i)) || (y & (1LL <<i)))ans |= 1LL<<i;
        }
        
        if(x == 0 || y == 0)cout<<l<<endl;
        else cout<<ans<<endl;
        */
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

