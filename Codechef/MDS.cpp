#include<bits/stdc++.h>

#define debug true
#define lmao if(debug)
/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav_
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 
@ CodeChef   : gaurav1620

# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/

//Faster loops
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define oneFo(i,n)for(i = 1;i <=n;i++)

//Renames
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back

//MAX
#define MAXL LONG_MAX
#define MAXI INT_MAX

//MOD
#define mod7 1000000007
#define mod9 1000000009

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>
inline T fabs(T a){return a>0?a:a*-1;}

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll arr[n],i,j,k;
        fo(i,n)cin>>arr[i];
        ll q;cin>>q;
        while(q--){
            ll a,b;cin>>a>>b;
            a--;
            b--;        
            if(a == b){
                cout<<1<<endl;
            }else{

                set<ll> initSet;
                set<ll> repeatSet;

                ll ans = 0;
                for(i = a;i <=b;i++){
                    if(initSet.find(arr[i]) == initSet.end()){
                        //not found
                        initSet.insert(arr[i]);
                    }else{
                        //found 
                        if(repeatSet.find(arr[i]) == repeatSet.end()){
                            //not found 
                            repeatSet.insert(arr[i]);
                            ans += 2;
                            ans %= 998244353;
                        }else{
                            //found 
                            ans++;
                            ans %= 998244353;
                        }
                    }
                }

                if(repeatSet.size()%2 == 1){
                    cout<<ans<<endl;
                }else{
                    cout<<0<<endl;
                }
            }
        }
    }
    return 0;
}
