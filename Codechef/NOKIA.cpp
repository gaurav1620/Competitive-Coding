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

ll ans(ll n){
    if(n == 0)return 0;
    if(n == 1)return 2;
    if(n%2)return n+1 + ans(n/2) + ans(n/2);
    return n+1 + ans(n/2-1) + ans(n/2);
}

int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        ll n,m;
        cin>>n>>m;
        
        ll minn = ans(n);
        ll maxx = ((n+2)*(n+1))/2 - 1;
        watch(minn);    
        watch(maxx);    
        if(m >= minn && m <= maxx)cout<<0<<endl;
        else if(m > maxx)cout<<m-maxx<<endl;
        else cout<<-1<<endl;
        //else cout<<m-gg<<endl;
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
