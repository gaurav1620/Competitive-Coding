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

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
       
        ll i,j,k,m,n;
        cin>>n>>m;
        ll arr[n];
        ll p[n];
        fo(i,n)p[i] = 0;
        fo(i,n)cin>>arr[i];
        fo(i,m){
            ll x;cin>>x;
            p[x-1] = 1;
        }

        for(i = 0;i < n;i++){
            j = i;
            while(j < n && p[j])j++;
            sort(arr+i,arr+j+1);
            i = j;
        }
        bool ok = true;
        for(i = 0;i < n-1;i++){
            ok &= arr[i+1]>=arr[i];
        }
        if(ok)cout<<"YES\n";
        else cout<<"NO\n";

    }
    //▬▬ι═══════>
    return 0;
}

