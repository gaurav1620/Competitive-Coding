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
        ll a,b;cin>>a>>b;
        if(a == b){
            cout<<0<<endl;
        }
        else if(a > b){
            if((a-b)%2 == 0){
                cout<<1<<endl;
            }else{
                cout<<2<<endl;
            }
        }else{

            if((b-a)%2 == 0){
                cout<<2<<endl;
            }else{
                cout<<1<<endl;
            }
        }
    }
    //▬▬ι═══════>
    return 0;
}

