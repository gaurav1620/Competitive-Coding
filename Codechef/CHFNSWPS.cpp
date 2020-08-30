/*  Author     : Gaurav Khairnar
    Codechef   : gaurav_1620
    Codeforces : gaurav1620
    Email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/

#include<bits/stdc++.h>
#define ll long long int
#define fo(i,n) for(i = 0;i < n;i++)
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cerr << (#x)<< " is : " << (x) << endl

//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;

int main(){
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n],b[n];
        ll i,j;
        
        fo(i,n)cin>>a[i];
        fo(i,n)cin>>b[i];
        
        sort(a,a + n);
        sort(b,b + n);
        
        ll best = min(a[0], b[0]);
        ll ans = 0;

        unordered_map<ll,ll> mpA,mpB;
    
        fo(i,n)mpA[a[i]]++;
        fo(i,n)mpB[b[i]]++;
        
        bool gd = true;
        for(auto it = mpA.begin();it != mpA.end();it++){
            gd &= (mpA[it->first] + mpB[it->first])%2 == 0;
        }

        for(auto it = mpB.begin();it != mpB.end();it++){
            gd &= (mpA[it->first] + mpB[it->first])%2 == 0;
        }
        if(!gd){
            cout<<-1<<endl;
            continue;
        }
        //va contains the vals A wants to give to B
        vector<ll> va;
        vector<ll> vb;
        set<ll> sa;
        set<ll> sb;

        fo(i,n)sa.insert(a[i]);
        fo(i,n)sb.insert(b[i]);
        for(int f : sa){
            if(mpA[f] > mpB[f]){
                ll ct = (mpA[f] - mpB[f])/2;
                while(ct--){
                    va.push_back(f);
                }
            }
        }
        for(int f : sb){
            if(mpA[f] < mpB[f]){
                ll ct = (mpB[f] - mpA[f])/2;
                while(ct--){
                    vb.push_back(f);
                }
            }
        }
        sort(va.begin(),va.end());
        sort(vb.begin(),vb.end(),greater<ll>());

        for(i = 0;i < va.size();i++){
            ans += min(2*best, min(va[i],vb[i]));
        }
        cout<<ans<<endl;
    
    }

    return 0;
}
/*
  ____   ___  ____     __  __     __     _____   _     ____ __    ___
 |  _ \ / _ \|  _ \   |  \/  |   /  \   |  _  \ | |   |  __\  \  /  /
 | |_) | | | | |_) |  | \  / |  / ^  \  | |_)  || |   | |_  \  \/  /
 |  _ <| | | |  _ <   | |\/| | / /_\  \ |     / | |   |  _|  \    /
 | |_) | `-' | |_) |  | |  | |/ _____  \| |\  '-| `---| |___  |  |
 |____/ \___/|____/   |_|  |_|_/     \__|_| `.__|_____|_____| |__|
    ,         |                                     |            '
    |         .                                     ;            |
    ;          \                                   .            ;
     ;          .                                 /            /
      \          \    .-""-._           _.--""-. /            /
       \          ','`       r'-.  _.-'\        t           .'
        `.        '          \__/`| |__/                  .'
          '.                _..._7\    _,_             .'
            `'Y          ,'`     `/`"'`   `.         ,'
             /          /                   ;        L
            ;           |                   |         |mx
            |           ;                  ;          ;
             ; _ __      \                /     _ .- /
              \  \ \ `.   `.            .'    / ' / /
               '._\ `. \    `.        .'    .' / /-'
                   `._\ `.    `.    .' .-..'_.'-`
                       `-'`. /`.`. /  /  /
                            `\ _> )|  \_/
                             `'-'  `--' 
*/
