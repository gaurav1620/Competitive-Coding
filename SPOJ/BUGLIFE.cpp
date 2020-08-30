#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}



bool dfs(vector<vector<ll>> &v,ll n,ll gender[],ll ind,bool visited[],ll curGender){
    for(ll i = 0;i < v[ind].size();i++){
        ll check = v[ind][i];
        if(visited[check] == true){
            if(gender[check] == curGender){
                return false;
            }
        }else{
            visited[check] = true;
            gender[check] = !curGender;
            if(dfs(v,n,gender,check,visited,!curGender) == false){
                return false;
            }
        }
    }
    return true;
}


bool ansUtil(vector<vector<ll>> &v,ll n){
    bool visited[n];
    ll i,j,k;
    fo(i,n)visited[i] = false;
    ll gender[n];
    fo(i,n)gender[i] = -1;

    for(i = 0;i < n;i++){
        if(!visited[i]){
            visited[i] = 1;
            gender[i] = 1;
            if(dfs(v,n,gender,i,visited,1) == false){
                return false;
            } 
        }else{
            //if(dfs(v,n,gender,i,visited,gender[i]) == false){
            //    return false;
            //}
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    ll x;cin>>x;
    for(ll t= 1;t <=x;t++){

        ll n,k;cin>>n>>k;
        vector<vector<ll>> v(n);
        ll i,j;
        fo(i,k){
            ll a,b;cin>>a>>b;
            a--;b--;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        ll gender[n];
        fo(i,n)gender[i] = -1;

        cout<<"Scenario #"<<t<<":"<<endl;
        if(ansUtil(v,n))cout<<"No suspicious bugs found!"<<endl;
        else cout<<"Suspicious bugs found!"<<endl;
    }

    //▬▬ι═══════>
    return 0;
}

