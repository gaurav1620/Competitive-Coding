#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        ll k;cin>>k;
        string s;
        cin>>s;
        ll i,j;
        ll n = s.length();
        fo(i,n){
            if(s[i] == '.'){
                cout<<" ";
            }else if(s[i] >= 'a' && s[i] <= 'z'){
                if(k>=26){
                    int xx = s[i]-'a';
                    xx += k-26;
                    xx %=26;
                    char c = xx + 'A';
                    cout<<c;
                }else{
                    int xx =  s[i]-'a';
                    xx += k;
                    xx %=26;
                    char c = xx + 'a';
                    cout<<c;
                }
            }else{
                if(k>=26){
                    int xx = s[i]-'A';
                    xx += k-26;
                    xx %=26;
                    char c = xx + 'a';
                    cout<<c;
                }else{
                    int xx =  s[i]-'A';
                    xx += k;
                    xx %=26;
                    char c = xx + 'A';
                    cout<<c;
                }

            }
        }
        cout<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

