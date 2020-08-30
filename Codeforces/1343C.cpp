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

bool isPos(ll n){
    return n >0?true:false;
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n],i,j,k;
        fo(i,n)cin>>arr[i];

        ll st = 0;
        i = 0;
        vector<ll> v; 
        while(i < n){
            st = i;
            i++;
            ll maxx = arr[st];
            while(i < n && isPos(arr[st]) == isPos(arr[i])){
                maxx = max(maxx,arr[i]);
                i++;
            }
            v.push_back(maxx);
        }

        ll summ = 0;
        for(i = 0;i < v.size();i++){
            summ += v[i];
        }
        cout<<summ<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

