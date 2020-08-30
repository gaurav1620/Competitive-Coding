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
    ll t;t = 1;
    while(t--){
        ll n,s;cin>>n>>s;
        ll leftsum = n-1;
        ll rightsum = s-leftsum;
        if(!(leftsum +1 < rightsum)){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            n--;
            while(n--){
                cout<<"1 ";
            }
            cout<<rightsum<<endl;
            cout<<leftsum+1<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}
