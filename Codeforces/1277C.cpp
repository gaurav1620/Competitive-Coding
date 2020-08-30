#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl
#define pb push_back
using namespace std;

void printVector(vector<ll> v){ll i;fo(i,v.size())cout<<v[i]<<" ";cout<<endl;}
void printVector(ll v[],ll n){ll i;fo(i,n)cout<<v[i]<<" ";cout<<endl;}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;
        string s;cin>>s;
        n = s.length();
        ll i,j,k;
        
        vector<ll> ans;

        fo(i,n-2){
            if(i+4 <= n-1 && s.substr(i,5) == "twone"){
                ans.pb(i+2+1);
                i+= 2;
            }
            else if(s.substr(i,3) == "one"){
                ans.pb(i+1+1);
            }else if(s.substr(i,3) == "two"){
                ans.pb(i+1+1);
            }
        }

        cout<<ans.size()<<endl;
        fo(i,ans.size())cout<<ans[i]<<" ";
        cout<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

