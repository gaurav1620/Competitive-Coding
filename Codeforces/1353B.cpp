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
        ll n,k;cin>>n>>k;
        ll a[n],b[n],i,j;
        fo(i,n)cin>>a[i];
        fo(i,n)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        ll ind = 0;
        ll sum = 0;
        while(k-- && ind < n && a[ind] < b[ind] ){
            sum += b[ind];
            ind++;
        }
        while(ind < n){
            sum += a[ind];
            ind++;
        }
        cout<<sum<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

