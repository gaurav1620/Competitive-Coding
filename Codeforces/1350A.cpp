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

ll prime[1000006];
int main(){
    ll i,j;

    bool done[1000006];
    fo(i,1000006)done[i] = false;
    
    prime[2] = 2;
    for(i = 2;i*i < 1000006;i++){
        if(!done[i]){
            //done[i] = true;
            for(j = i;j < 1000006;j+=i){
                if(!done[j]){
                    done[j] = true;
                    prime[j] = i; 
                }
            }
        }
    }
    for(;i < 1000006;i++){
        if(prime[i] == 0){
            prime[i] = i;
        }
    }

    
    //Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        cout<<n+prime[n]+(k-1)*2<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

