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
#define watch(x) cerr << (#x)<< " is : " << (x) << endl
//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;
ll testCases;

set<ll> st;
ll arr[17000000];
ll n;
bool boo = true;
map<pair<ll,ll>,ll> mp;

ll ans(ll a,ll b){
    if(mp.find({a,b}) != mp.end())return mp[{a,b}];

    if(a == b){
        if(st.find(arr[a]) != st.end())boo = false;
        st.insert(arr[a]);
        mp[{a,b}] = arr[a];
        return arr[a];
    }
    ll pp = ans(a,b-1)|ans(a+1,b);
    if(st.find(pp) != st.end())boo = false;
    mp[{a,b}] = pp;
    st.insert(pp);
    return pp;
}

int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        st.clear();
        mp.clear();
        boo = true;
        cin>>n;
        ll i,j,k;
        fo(i,n)cin>>arr[i];
        
        if(n > 35){
            cout<<"NO\n";
            continue;
        }
        set<ll> gp;
        bool done = 1;
        for(i = 0;i < n && done;i++){
            for(j = i;j < n && done;j++){
                ll gg = 0;
                for(k = i;k <= j && done;k++){
                    gg |= arr[k];
                }
                if(gp.find(gg) != gp.end()){
                    cout<<"NO\n";
                    done = 0;
                }else{
                    gp.insert(gg);
                }
            }
        }
        if(done){
            cout<<"YES\n";
        }
    }
    
    //▬▬ι═══════>
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
