#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define ll long long
using namespace std;

int main(){
    //▬▬ι═══════>
    ll test;cin>>test;
    while(test--){
        ll len;cin>>len;
        ll arr[len],i,j;
        fo(i,len)cin>>arr[i];
        ll ct=0,k;cin>>k;
        fo(i,len){
            if(arr[i]<=arr[k-1])ct++;
        }
        cout<<ct<<endl;
    }
    //▬▬ι═══════>
	return 0;
}
