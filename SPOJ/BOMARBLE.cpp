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

ll arr[1002];

ll findans(ll n){
    if(n == 1){
        return 5;
    }
    if(arr[n] != -1){
        return arr[n];
    }

    arr[n] =  n*5 + findans(n-1) - 2*(n)+1;

    return arr[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    ll i,j,k;
    fo(i,1002)arr[i] = -1;

    while(1){
        ll n;cin>>n;
        if(n == 0){
            break;
        }
        cout<<findans(n)<<endl;
    }


    //▬▬ι═══════>
    return 0;
}

