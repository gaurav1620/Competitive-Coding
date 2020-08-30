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

ll v[100000];


int main(){

    ll i;    
    //v.push_back(0);//0th ind
    
    //v.push_back(2);// height = 1
    //v.push_back(7);//height = 2
    
    v[0] = 0;
    v[1] = 2;
    v[2] = 7;
    for(i = 3;;i++){
        
        v[i] = i*2;
        ll dd = i*(i-1);
        dd /=2;
        v[i] += dd*3;
             
        if(v[i] > 1000000000){
            break;
        }
    }
    Ninja
    //▬▬ι═══════>
    
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;

        if(n < 2){cout<<"0\n";continue;}

        for(i = 1;i < n;i++){
            if(n < v[i]){
                i--;
                ll ans = n/v[i];
                ll temp = n/v[i];
                n -= temp*v[i];
                i--;
                while(n > 0 && i > 0){
                    temp = n/v[i];
                    ans += temp;
                    n -= temp*v[i];
                    i--;
                }
                cout<<ans<<endl;
                break;
            }else if(v[i] == n){
                cout<<1<<endl;
                break;
            }
        }
    }
    return 0;
}

