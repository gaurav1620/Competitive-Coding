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

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        set<ll> st;
        ll i,j,k;
        fo(i,n){
            ll x;cin>>x;
            st.insert(x);
        }
        ll ans = 0;
        set<ll> done;
        for(auto itr = st.begin();itr!=st.end();++itr){
            ll loc = 0;
            ll num = *itr;
            while(!(num&1) && done.find(num) == done.end()){
                done.insert(num);
                num /=2;
                loc++;
            }
            ans += loc;
        }
        cout<<ans<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

