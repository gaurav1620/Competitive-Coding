#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codeforces : gaurav1620
//codechef : gaurav_1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;
int main(){
    Ninja
    //▬▬ι═══════>
    ll n,i,j,k;
    cin>>n;
    
    set<ll> sett;
    fo(i,n){ll x;cin>>x;sett.insert(x);}
    vector<ll> v;

    for(auto itr : sett){
        v.push_back(itr);
    }

    ll q;cin>>q;
    while(q--){
        ll left,right;cin>>left>>right;
        ll sizz = right-left;
        
        ll ans = sizz+1;

        for(i = 1;i< v.size();i++){
            ans += min(v[i]-v[i-1],sizz+1);
        }
        cout<<ans<<" ";
    }
    cout<<endl;

    //▬▬ι═══════>
    return 0;
}

