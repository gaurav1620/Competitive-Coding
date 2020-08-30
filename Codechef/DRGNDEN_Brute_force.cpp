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
    ll n,q;
    cin>>n>>q;
    ll h[n];
    ll b[n];

    ll i,j,k;
    fo(i,n)cin>>h[i];
    fo(i,n)cin>>b[i];
    
    while(q--){
        ll s,e;
        ll type;
        cin>>type>>s>>e;
        s--;e--;

        if(type == 1){
            b[s] = e+1;
            continue;
        }

        if(h[s] < h[e]){
            cout<<-1<<endl;
        }else{
            if(s > e){
                watch(s);
                vector<ll> v;
                v.push_back(e);

                i = e+1;
                while(i <= s){
                    if(h[v[v.size()-1]] < h[i]){
                        v.push_back(i);
                        watch(i);
                    }
                    i++;
                }

                if(v[v.size()-1] == s){
                    ll pr = 0;
                    fo(i,v.size())pr += b[v[i]];
                    cout<<pr<<endl;
                }else{
                    cout<<-1<<endl;
                }
                
            }else if(s < e){
                watch(e);
                vector<ll> v;
                v.push_back(e);
                i = e-1;
                while(i >= s){
                    if(h[v[v.size()-1]] < h[i]){
                        v.push_back(i);
                    }
                    i--;
                }

                if(v[v.size()-1] == s){
                    ll pr = 0;
                    fo(i,v.size())pr += b[v[i]];
                    cout<<pr<<endl;
                }else{
                    cout<<-1<<endl;
                }
            }else{
                cout<<b[s]<<endl;
            }
        }

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
