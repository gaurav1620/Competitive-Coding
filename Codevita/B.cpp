#include<iostream>
#include<map>
#include<iterator>
#include<vector>

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll long long
using namespace std;

ll testCases;
int main(){
    Ninja
    
    testCases = 1;
    while(testCases--){
        //roll
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        ll i,j;
        fo(i,n)cin>>arr[i];
        map<ll,ll> mp;
        fo(i,n)mp[arr[i]]++;

        ll ans = 0;
        fo(i,n){
            //if(mp[arr[i]] > 1)ans++;
            if(mp.upper_bound(arr[i]) != mp.end()
                    && mp.upper_bound(arr[i])->first <= arr[i]+k)ans++;
            else if(mp.lower_bound(arr[i]-k)->first != arr[i])ans++;
        }
        cout<<ans;

    }
    
    return 0;
}

