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

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll i,j,k,n,m,len;
        cin>>len>>n;
        string s;cin>>s;
        ll arr[n];
        fo(i,n)cin>>arr[i];
        fo(i,n)arr[i]--;

        sort(arr,arr+n);

        ll ct[26];
        fo(i,26)ct[i] = 0;

        ll dp[len];
        fo(i,len)dp[i] = 0;
        
        fo(i,n)dp[arr[i]]++;


        for(i = len-1;i > 0;i--){
            dp[i-1] += dp[i];
        }
        for(i = 0;i < len;i++){
            ct[s[i]-'a'] += dp[i];
        }
        fo(i,len)ct[s[i]-'a']++;

        fo(i,26)cout<<ct[i]<<" ";
        cout<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

