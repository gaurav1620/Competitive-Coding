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

ll findAns(ll n){
    string s = to_string(n);
    if(s.length() == 1){return n;}
    ll num = 0;
    ll i,j,k;
    fo(i,s.length()){
        num += pow(10,i)*(s[0]-'0');
    }
    ll ans = (s.length()-1)*9;
    if(num > n){
        ans += s[0]-'0'-1;
    }else{
        ans += s[0]-'0';
    }
    return ans;
}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        cout<<findAns(n)<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

