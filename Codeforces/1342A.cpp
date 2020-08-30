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
        ll x,y;cin>>x>>y;
        ll a,b;cin>>a>>b;

        if(a <= b/2){
            cout<<(x+y)*a<<endl;
        }else{
            cout<<min(x,y)*b + (max(x,y)-min(x,y))*a<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

