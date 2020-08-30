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

ll modd(ll a,ll m){
    if(a == 0){return 0;}
    if(a > 1){
        return a%m;
    }

    if((a/m)*m == a){
        return 0;
    }

    ll dd = (a/m)*(m+1);
    return a-dd;
}

ll n,i,j;
ll arr[200005];
bool ck[200005];

string findAns(){
    for(i = 0;i < n;i++){

        if(!ck[i]){
            ll ind = i;
            
            while(ck[])
        }
    }
}

int main(){
    cout<<modd(-10,3);
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        cin>>n;
        fo(i,n)cin>>arr[i];
        bool ck[n];
        fo(i,n)ck[i] = false;

        cout<<findAns()<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

