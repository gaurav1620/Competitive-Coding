#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef   : gaurav_1620
//codeforces : gaurav1620  
//github     : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll int
using namespace std;
ll abs(ll x){ return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

bitset<1> arr[200][200];
int store[200][200];
queue<pair<ll,ll>> v;
int n,m;

int ck = 0;
ll findAns(){
    ll val = 0;
    while(v.size() != 0){
        ll sizz = v.size();
        while(sizz--){
            pair<ll,ll> gg = v.front();
            v.pop();
            ll i = gg.first; 
            ll j = gg.second;

            //cout<<"CHECK"<<ck++<<" i : "<<i<<"  , j: "<<j<<endl;
            store[i][j] = val;
            if(i+1 < n && store[i+1][j] == -1){
                v.push({i+1,j});
                store[i+1][j] = -2;
            }
            if(j+1 < m && store[i][j+1] == -1){
                v.push({i,j+1});
                store[i][j+1] = -2;
            }
            if(i-1 >= 0 && store[i-1][j] == -1){
                v.push({i-1,j});
                store[i-1][j] = -2;
            }
            if(j-1 >= 0 && store[i][j-1] == -1){
                v.push({i,j-1});
                store[i][j-1] = -2;
            }
        }
        val++;
    }
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        cin>>n>>m;
        ll i,j,k;
        
        fo(i,n)fo(j,m)store[i][j] = -1;
        
        fo(i,n){
            string s;cin>>s;
            fo(j,m){
                arr[i][j] = s[j]-'0';
                if(arr[i][j] == 1){
                    v.push({i,j});
                    store[i][j] = 0;
                }            
            }
        }
        
        findAns();
        fo(i,n){
            fo(j,m)cout<<store[i][j]<<" ";
            cout<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

