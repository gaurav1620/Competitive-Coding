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
    ll i,j,k;
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n+1];
        fo(i,n)cin>>arr[i+1];

        ll ans = 0;
        ll longarr[n+1];
        fo(i,n)longarr[i+1] = 1;

        for(i = 1;i <= n;i++){
            for(j = i*2;j <= n;j+=i){
                if(arr[i] < arr[j])longarr[j] = max(longarr[j],longarr[i]+1);
            }
        }
        fo(i,n)ans = max(longarr[i+1],ans);
        cout<<ans<<endl;

    }

    //▬▬ι═══════>
    return 0;
}

