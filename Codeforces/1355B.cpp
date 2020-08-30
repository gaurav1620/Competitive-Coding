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
        ll n;cin>>n;
        ll arr[n],i,j,k;
        fo(i,n)cin>>arr[i];
        sort(arr,arr+n);
        ll grps = 0;
        ll ind = 0;
        while(ind < n){
            ll sizz = arr[ind];
            sizz--;
            if(ind+sizz >= n){
                break;
            }
            if(arr[ind+sizz] > sizz+1){
                while(ind+sizz < n && arr[ind+sizz] > sizz+1){
                    sizz++;
                }
                if(ind+sizz >= n){
                break;
                }
            }
            while(ind < n && sizz--){
                ind++;
            }
            ind++;
            grps++;
        }
        cout<<grps<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

