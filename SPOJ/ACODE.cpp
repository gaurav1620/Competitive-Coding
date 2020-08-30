#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long

using namespace std;

ll ans(string s){
    s = '$'+s;
    ll n = s.length()-1;

    ll dp[n+1];
    ll i,j,k;
    fo(i,n+1)dp[i] = 0;

    dp[0] = dp[1] = 1;
    for(i = 2;i <=n;i++){
        if(s[i] != '0'){
            dp[i] = dp[i-1];
        }
        ll last = 10*(s[i-1]-'0')+s[i]-'0';
        if(s[i-1]!= '0' && last >= 1 && last<=26){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    string s;
    while(1){
        cin>>s;
        if(s == "0"){
            break;
        }

        cout<<ans(s)<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

