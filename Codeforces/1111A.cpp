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

bool findAns(string s,string t){
    if(s.length() != t.length())return false;
    ll i,j,k;
    vector<char> v = {'a','e','i','o','u'};
    for(i = 0 ;i < t.length();i++){
        if(s[i] != t[i]){
            if(find(v.begin(),v.end(),s[i]) != v.end() && find(v.begin(),v.end(),t[i]) != v.end()){

            }else if(find(v.begin(),v.end(),s[i]) == v.end() && find(v.begin(),v.end(),t[i]) == v.end()){

            }else{
                return false;
            }

        }
    }
    return true;
}

int main(){
    Ninja
    //▬▬ι═══════>
    string s,t;cin>>s>>t;
    ll i,j,k;
    cout<<(findAns(s,t)? "Yes":"No")<<endl;
    //▬▬ι═══════>
    return 0;
}

