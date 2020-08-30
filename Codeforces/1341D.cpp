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

string sarr[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
vector<string> arr;

string dp[2005][2005];

ll getDiff(string s,string querr){
    ll ans = 0;
    for(ll i = 0;i < 7;i++){
        if(querr[i] == '1' && s[i] == '0'){
            return -1;
        }else if(querr[i] == '0' && s[i] == '1'){
            ans++;
        }
    }
    return ans;
}

string findAns(ll ind,ll n,ll k){
    if(k < 0)return "-1";

    if(dp[ind][k] != "-2"){return dp[ind][k];}

    if(ind == n-1){
        for(ll i = 9;i >= 0;i--){
            ll ctf = getDiff(sarr[i],arr[ind]);
            if(k == getDiff(sarr[i],arr[ind])){
                int ct = i+'0';
                char cc = ct;
                string rets;
                rets += cc;
                dp[ind][k] = rets;
                return dp[ind][k];
            }
        }
        dp[ind][k] = "-1";
        return "-1";
    }
    for(ll i = 9;i>=0;i--){
        ll diff = getDiff(sarr[i],arr[ind]);
        if(diff != -1){
            string gg = findAns(ind+1,n,k-diff);
            if(gg != "-1"){
                char cc = i+'0';
                dp[ind][k] = cc+gg;
                return dp[ind][k];
            }
        }
    }
    dp[ind][k] = "-1";
    return "-1";
}

int main(){
   // Ninja
    //▬▬ι═══════>
    ll n,k;cin>>n>>k;
    ll i,j;
    fo(i,n){
        string s;cin>>s;arr.push_back(s);
    }
    fo(i,n+1){
        fo(j,k+1)dp[i][j] = "-2";
    }
    cout<<findAns(0,n,k)<<endl;
    //▬▬ι═══════>
    return 0;
}

