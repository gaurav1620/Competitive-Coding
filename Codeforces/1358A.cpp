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
        ll n,m;cin>>n>>m;
        ll ans = 0;
        if(m%2 == 0){
            ans = n*(m/2);
            cout<<ans<<endl;
        }else{
            ans = n*(m/2);
            //watch(ans);
            ans += n/2+n%2;
            //watch(ans);
            cout<<ans<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

