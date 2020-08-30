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
int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        ll n,d;
        cin>>n>>d;
        map<ll,ll> mp;
        ll arr[n];
        ll i,j,k;
        fo(i,n)cin>>arr[i];
        
        sort(arr,arr+n);
        
        vector<pair<ll,ll>> v;
        i = 0;

        while(i < n){
            ll temp = arr[i];
            ll ct = 0;
            while(temp == arr[i]){
                i++;
                ct++;
            }
            v.push_back({temp,ct});
        }
        
        for(i = 0;i < v.size();i++){
            cout<<v[i].first<<" : "<<v[i].second<<endl;
        }

        double ans = INT_MAX;
        
        if(v[0].first > 1){
            ll cools = v[0].first -1;
            double gp = (double)d/(double)cools;
            if(gp < ans)ans = gp;
        }
        
        for(i = 1;i < v.size();i++){
            ll cools = v[i].first;
            ll tim = v[i].second - v[i-].second;
            
            if(v[i-1].second + d > v[i-1].second){

                tim = (v[i].second + d) - (v[i-1].second - d);
            
            }
            ll gp = (double)tim/(double)cools;
            if(gp < ans)ans = gp;
        }

        cout<<ans<<endl;
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
