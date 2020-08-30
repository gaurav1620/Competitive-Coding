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
int main(){
    Ninja
    //▬▬ι═══════>
    ll n,m;cin>>n>>m;
    ll arr[n][2],i,j,k;

    fo(i,n)cin>>arr[i][0];
    fo(i,n)cin>>arr[i][1];

    map<ll,ll> ma,mb;
    
    fo(i,n)ma[arr[i][0]]++;
    fo(i,n)mb[arr[i][1]]++;

    ll ans = 0;

    ll ansisZero = true;
    for(auto itr : mb){
        if(itr.second != ma[itr.first]){
            ansisZero = false;
            break;
        }
    } 

    if(ansisZero){
        cout<<0<<endl;
    }else{
        set<ll> sett;
        fo(i,n){
            ll a = arr[i][0];
            ll b = arr[0][1];
            sett.insert(a > b 
                        ? m-a+b:b-a);
        }
        ll nas = m+1;
        for(auto it : sett){
            bool isans= 1;
            for(auto mpaitr : ma){
                if(mpaitr.second != mb[(mpaitr.first+it)%m]){
                    isans = 0;break;
                }
            }
            if(isans){
                nas = min(nas,it);
            }
        }
        cout<<nas<<endl;
    }


    //▬▬ι═══════>
    return 0;
}

