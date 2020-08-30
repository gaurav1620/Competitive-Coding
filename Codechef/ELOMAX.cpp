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
        ll n,m,i,j,k;
        cin>>n>>m;
        ll store[n][m];
        ll temp[n];
        fo(i,n)cin>>temp[i];
        fo(i,n){
            fo(j,m)
                cin>>store[i][j];
        }
        //store[sudent][month]
        ll rating[m][n];
        ll ranking[m][n];
        
        //stores the month
        ll bestRat[n];
        ll bestRan[n];

        for(ll month = 0; month < m;month++){
            if(month == 0){
                fo(i,n){
                    bestRan[i] = 0;
                    bestRat[i] = 0;
                    rating[0][i] = temp[i] + store[i][0];
                }
                
                vector<pair<ll,ll>> temp_ranks;
                fo(i,n)temp_ranks.push_back({rating[0][i],i});

                sort(temp_ranks.begin(),temp_ranks.end());
                reverse(temp_ranks.begin(),temp_ranks.end());
                
                ll currank = 1;
                ll ind = 1;
                
                ranking[0][temp_ranks[0].second] = 1;
                
                while(ind < n){
                    if(temp_ranks[ind].first == temp_ranks[ind-1].first){
                        ranking[0][temp_ranks[ind].second] = currank;
                    }else{
                        ranking[0][temp_ranks[ind].second] = ind+1;
                        currank = ind+1;
                    }
                    ind++;
                }
            }else{
                fo(i,n){
                    rating[month][i] = store[i][month] + rating[month-1][i];
                    if(rating[month][i] > rating[bestRat[i]][i]){
                        bestRat[i] = month;
                    }
                }

                vector<pair<ll,ll>> temp_ranks;
                fo(i,n)temp_ranks.push_back({rating[month][i],i});
                
                sort(temp_ranks.begin(),temp_ranks.end());
                reverse(temp_ranks.begin(),temp_ranks.end());
                
                ll currank = 1;
                ll ind = 1;
                ranking[month][temp_ranks[0].second] = 1;

                while(ind < n){
                    if(temp_ranks[ind].first == temp_ranks[ind-1].first){
                        ranking[month][temp_ranks[ind].second] = currank;
                    }else{
                        ranking[month][temp_ranks[ind].second] = ind+1;
                        currank = ind+1;
                    }
                    ind++;
                }
                fo(i,n){
                    if(ranking[month][i] < ranking[bestRan[i]][i]){
                        bestRan[i] = month;
                    }
                }
            }
        }
        ll ans = 0;
        fo(i,n){
            if(bestRan[i] != bestRat[i])ans++;
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
