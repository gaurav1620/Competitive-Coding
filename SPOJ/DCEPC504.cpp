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

bool isMale(ll k){
    //cout<<"CK : "<<k<<endl;
    if(k == 1){
        return true;
    }
    if(k == 2){
        return false;
    }
    

    ll lloh = log2(k);
    if(k == pow(2,lloh)){
        if(lloh&1){
            return false;
        }else{
            return true;
        }
    }

    bool ans =  isMale(1+(pow(2,lloh+1) - k));
    if(lloh%2 == 1){
        return ans;
    }else{
        return !ans;
    }
}


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        if(isMale(k))cout<<"Male\n";
        else cout<<"Female\n";
    }
    //▬▬ι═══════>
    return 0;
}

