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
int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll h = n/2;
        if(h%2 == 0){
            ll i;
            cout<<"YES\n";
            ll ss = 0;
            for(i = 2;i <= n;i+=2){
                ss += i;
                cout<<i<<" ";
            }
            for(i = 1;i <= n-2;i+=2){
                ss -= i;
                cout<<i<<" ";
            }
            cout<<ss;
            cout<<endl;
        }else{
            cout<<"NO\n";
        }
    }    
    //▬▬ι═══════>
    return 0;
}

