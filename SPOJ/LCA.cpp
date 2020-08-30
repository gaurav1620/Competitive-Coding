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


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    ll t;cin>>t;
    for(ll casee = 1;casee <= t;casee++){
        ll n;cin>>n;
        vector<vector<ll>> v(n);
        ll i,k,j;
        fo(i,n){
            ll x;cin>>x;
            while(x--){
                ll a;cin>>a;
                a--;
                v[a].push_back(i);
            }
        }
        ll q;cin>>q;
        vector<ll> answers;
        fo(k,q){
            //cout<<"ENTER VALUES\n";
            ll a,b;cin>>a>>b;
            a--;b--;
            bool vis[n];
            fo(i,n)vis[i] = false;
            vis[a] = true;
            while(v[a].size() != 0){
                a = v[a][0];
                vis[a] = true;
            }
            bool done = false;
            while(v[b].size() != 0){
                if(vis[b]){
                    answers.push_back(b);
                    //cout<<"Found anser : "<<b<<endl;
                    done = true;
                    break;
                }else{
                    vis[b] = true;
                    b = v[b][0];
                }
            }
            if(!done){
                answers.push_back(b);
            }
        }
        cout<<"Case "<<casee<<":"<<endl;
        for(i = 0;i < answers.size();i++){
            cout<<answers[i]+1<<endl;
        }
    }
    //▬▬ι═══════>
    return 0;
}

