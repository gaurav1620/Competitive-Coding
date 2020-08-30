#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll unsigned long long int
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

#define MAX 87000008
bitset<MAX> bts;

ll i,j;

ll arr[5000000];
ll arInd = 0;

void sieve(){

    for(i = 2; i < MAX;i++){
        
        if(arInd >= 5000000){return;}

        if(bts[i] == 0){

            arr[arInd++] = i;
            
            for(j = i*i;j < MAX;j+=i){
                bts[j] = 1;
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    sieve();

    ll n;cin>>n;
    while(n--){
        ll k;cin>>k;
        cout<<arr[k-1]<<endl;
    }

    //▬▬ι═══════>
    return 0;
}

