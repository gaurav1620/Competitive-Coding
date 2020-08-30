#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;

void printVector(vector<ll> v){ll i;fo(i,v.size())cout<<v[i]<<" ";cout<<endl;}
void printVector(ll v[],ll n){ll i;fo(i,n)cout<<v[i]<<" ";cout<<endl;}


unordered_map<ll,ll> fact;

ll max(ll a,ll b){
    return a > b ? a:b;
}


ll printNcR(ll  n, ll r){
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}

long long C(ll n, ll r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1 == x2 || y1 == y2){
            cout<<1<<endl;
        }else{
            ll x = x2-x1;
            ll y = y2-y1;
            ll ss = x+y;
            ll ans = 1;
          
            /*
            for(ll i = ss;i > max(x,y);i--){
                ans *= i;
            }
            ll den = 1;
            for(ll i = 1;i <= min(x,y);i++){
                den*=i;
            }
            ans /= den;
            */
            cout<<C(ss,x)<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

