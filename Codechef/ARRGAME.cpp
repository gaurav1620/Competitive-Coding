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
        
        ll n;
        cin>>n;

        ll arr[n];
        ll i,j,k;
        fo(i,n)cin>>arr[i];

        vector<ll> vec[2];

        i = 0;
        while(i < n){
            if(arr[i] == 1){
                i++;
                continue;
            }
            ll len = 0;
            while(i < n && arr[i] == 0){
                len++;
                i++;
            }
            vec[len%2].push_back(len);
        }

        sort(vec[0].begin(),vec[0].end(), greater<ll>());
        sort(vec[1].begin(),vec[1].end(), greater<ll>());
        
        if(vec[0].size() == 0 && vec[1].size() == 0){
            cout<<"No\n";
        }else if(vec[0].size() == 0){
            
            if(vec[1].size() == 1){
                cout<<"Yes\n";
            }else if(vec[1][0] == vec[1][1]){
                cout<<"No\n";
            }else if(vec[1][0]/2+1 > vec[1][1]){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }

        }else if(vec[1].size() == 0){
            cout<<"No\n";
        }else{
            ll best = 0;
            best = vec[0][0];
            if(vec[1].size() > 1)best = max(best,vec[1][1]);

            if(best < vec[1][0]/2+1){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
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
