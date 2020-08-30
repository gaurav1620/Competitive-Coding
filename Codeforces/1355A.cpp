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
void printVector(ll v[],ll n){ll i;fo(i,n)cout<<v[i]<<" ";cout<<endl;}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll a,k;cin>>a>>k;
        k--;
        ll p = 0;
        ll done = false;
        while(k--){
            string s = to_string(a);
            ll minn = 0;
            ll maxx = 0;
            for(ll i = 0; i < s.length();i++){
                if(s[minn] > s[i]){
                    minn = i;
                }
                if(s[maxx] < s[i]){
                    maxx = i;
                }
            }
            p = (s[minn]-'0')*(s[maxx]-'0');
            if(p == 0){
                cout<<a<<endl;
                done = true;
                break;
            }
            a = a+p;
        }
        if(!done){
            cout<<a<<endl;
        }

    }
    //▬▬ι═══════>
    return 0;
}

