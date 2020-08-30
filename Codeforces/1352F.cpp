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
        ll n0,n1,n2,i,j,k;
        cin>>n0>>n1>>n2;

        if(n0 == 0 && n1 == 0){
            cout<<"11";
            fo(i,n2-1){
                cout<<"1";
            }
            cout<<endl;
            continue;
        }
        if(n2 == 0 && n1 == 0){
            cout<<"00";
            fo(i,n0-1){
                cout<<"0";
            }
            cout<<endl;
            continue;
        }
        if(n2 == 0 && n0 == 0){
            cout<<"01";
            fo(i,n1-1){
                cout<<(i%2 == 0 ? "0":"1");
            }
            cout<<endl;
            continue;
        }

        if(n1%2 == 0){
            cout<<"0";
            fo(i,n0)cout<<"0";
            cout<<"1";
            fo(i,n2)cout<<"1";
            n1--;
            fo(i,n1)cout<<i%2;
            cout<<endl;
            continue;
        }

        fo(i,n0)cout<<"0";
        
        cout<<"01";

        fo(i,n1-1){
            cout<<(i%2 == 0 ? "0":"1");
        }
        fo(i,n2)cout<<"1";
        cout<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

