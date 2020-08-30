#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
int main(){
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        ll x,n,m;cin>>x>>n>>m;
        
        while(x > 20 && n>0){
            ll newx = (x/2);
            newx += 10;
            n--;
            x = newx;
        }

        while(m){
            x-=10;
            m--;
        }

        if(x <=0){
            cout<<"YES\n";
        }else {cout<<"NO\n";}

    }
    //▬▬ι═══════>
    return 0;
}

