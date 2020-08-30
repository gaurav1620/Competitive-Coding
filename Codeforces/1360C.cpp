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
        ll arr[n];
        ll dp[n+1];
        ll i,j,k;
        fo(i,n)cin>>arr[i];

        sort(arr,arr+n);

        ll o,e;
        o = 0;
        e = 0;
        fo(i,n){
            if(arr[i]%2 == 0)e++;
            else o++;
        }


        bool fl = false;
        for(i = 0;i < n-1;i++){
            if(arr[i]+1 == arr[i+1])fl = true;
        }

        if( (o%2 == 0 && e%2==0)|| fl)cout<<"YES\n";
        else cout<<"NO\n";
    }
    //▬▬ι═══════>
    return 0;
}

