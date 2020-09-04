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
    
    ll m,n,i,j,k;
    cin>>n;
    ll arr[n];
    ll pref[n];
    

    memset(pref,0,sizeof pref);


    fo(i,n){
        cin>>arr[i];
        if(arr[i] == -1)pref[i]++;
    }
    cin>>m;
    if(arr[0] == -1 || arr[n-1] == -1){
        cout<<-1<<"\n";
        return 0;

    }

    for(i = 1;i < n;i++)pref[i] += pref[i-1];

    ll ans[n];
    
    fo(i,n)ans[i] = INT_MAX;
    ans[0] = arr[0];
    
    for(i = 1;i < n;i++){
        if(arr[i] == -1)continue;

        for(j = i-1;j >= i-m-1 && j >= 0 ;j--){
            if(arr[j]!=-1)ans[i] = min(ans[i],ans[j]+arr[i]);
        }
    }
    if(ans[n-1] == INT_MAX){
        cout<<-1<<"\n";
    }else cout<<ans[n-1]<<"\n";
    return 0;
}

