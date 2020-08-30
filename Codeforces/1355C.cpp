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

ll onetoNSum(ll n){
    return (n*(n+1))/2;
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll a,b,c,d;cin>>a>>b>>c>>d;
    ll  tot = 0;
    for(ll i = d ; i>=c ;i--){
        ll z = i;
        if(b+c < z){continue;}

        if(a + b < z && b + c >= z){
            ll insidInd = z-b;
            if(insidInd <= b && insidInd >= a){

            }
        }
        else if(a + b >= z){
            tot += (b-a)*(c-b);
        }
    }
    cout<<tot<<endl;
    //▬▬ι═══════>
    return 0;
}

