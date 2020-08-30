#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codeforces : gaurav1620
//codechef   : gaurav_1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;
int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll a,b,q;
        cin>>a>>b>>q;
        
        ll blockSize= (a*b)  / __gcd(a,b);
        ll remfromblock = max(a,b);
        while(q--){
            ll x,y;
            cin>>x>>y;    

            ll ans = y-x+1;
            ans -= (((y/blockSize)) - (x/blockSize+1))*remfromblock;
            ll ct = 0;
            for(ll i = (x/blockSize)*blockSize;ct <remfromblock;ct++,i++){
                if(i >= x)ans--;
            }
            ct = 0;
            for(ll i = (y/blockSize)*blockSize;ct < remfromblock;ct++,i++){
                if(i <= y)ans--;
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

