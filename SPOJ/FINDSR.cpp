#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){ return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

bool possible(string s,ll step){
    ll i,j,k;
    for(i = 0;i<step;i++){
        for(j = i+step;j < s.length();j+=step){
            if(s[j] != s[i]){return false;}
        }
    }
    return true;
}
int main(){
    Ninja
    //▬▬ι═══════>
    while(1){
        string  s;cin>>s;
        if(s == "*"){return 0;}
        ll n = s.length();
        ll lps[n+1];
        lps[0] = 0;
        ll len = 0;
        ll i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        if(lps[n-1] >= n/2+n%2 && n%(n-lps[n-1]) == 0){
            cout<<n/(n-lps[n-1])<<endl; 
        }else{
            cout<<1<<endl;
        }
    
    }
    //▬▬ι═══════>
    return 0;
}

