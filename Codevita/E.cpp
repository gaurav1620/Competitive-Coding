#include<bits/stdc++.h>

/*  author     : Gaurav Khairnar
    codechef   : gaurav_1620
    codeforces : gaurav1620
    email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll long long
using namespace std;
ll testCases;
#define Yess cout<<"YES\n";
#define Noo cout<<"NO\n";
#define yess cout<<"Yes\n";
#define noo cout<<"No\n";

int main(){
    Ninja
    
    ll m,n,i,j,k;
    
    cin>>n;
    ll arr[n];
    ll ctn = 0;
    fo(i,n){
        cin>>arr[i];
        if(arr[i] == -1)ctn++;
    }
    ll skip = 0;
    cin>>skip;
    if(ctn > skip || arr[0] == -1 || arr[n-1] == -1) {
        cout<<-1<<endl;
        return 0;
    }

    vector<ll> v;
    fo(i,n){
        if(arr[i] != -1 && i != 0)v.push_back(arr[i]);
    }

    sort(v.begin(),v.end(),greater<ll>());

    ll rem = skip - ctn;
    
    ll totValSkip = 0;
    i = 0;
    while(rem-- && i < n){
        totValSkip += v[i++];  
    }

    ll sum = 0;
    fo(i,n){
        if(arr[i] != -1)sum += arr[i];
    }

    cout<<sum - totValSkip<<endl;
    return 0;
}

