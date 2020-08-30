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
        ll n;cin>>n;
        ll arr[n],i,j,k;
        ll a,b;
        fo(i,n)cin>>arr[i];
        
        a = 0;
        b = n-1;
        ll moves = 0;
        bool chanceA = true;
        ll candA,candB;
        ll totA,totB;
        totA = totB = 0;

        if(n == 1){
            cout<<1<<" "<<arr[0]<<" 0\n";
            continue;
        }

        while(a <= b){
            if(chanceA){
                if(a == 0){
                    candA = arr[a];
                }else{
                    ll cc = arr[a];
                    while(a != b && cc <= candB){
                        a++;
                        cc+=arr[a];
                    }
                    candA = cc;
                }
                totA += candA;
                a++;
            }else{
                ll cc = arr[b];
                while(a != b && cc <= candA){
                    b--;
                    cc += arr[b];
                }
                b--;
                candB = cc;
                totB += candB;
            }
            moves++;
            chanceA = !chanceA;
        }
        cout<<moves<<" "<<totA<<" "<<totB<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

