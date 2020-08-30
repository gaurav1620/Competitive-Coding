/*****************************************************************************i
  / __| __ _ _  _ _ _ __ ___ __ | |/ / |_  __ _(_)_ _ _ _  __ _ _ _ 
 | (_ -/ _` | || | '_/ _` \ V / | ' <| ' \/ _` | | '_| ' \/ _` | '_|
  \___|\__,_|\_,_|_| \__,_|\_/  |_|\_\_||_\__,_|_|_| |_||_\__,_|_| 
  ******************************************************************************
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 

# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/
#include<bits/stdc++.h>

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

#define mod 1000000007

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>inline T       min(T a,T b)        { return a<b?a:b; }
template<class T>inline T       max(T a,T b)        { return a>b?a:b; }
template<class T>inline T       fabs(T a)           { return a>0?a:-a; }
template<class T>inline T       isOdd(T a)          { return a&1; } 
template<class T>inline T       gcd(T a,T b)        { return __gcd(a,b);}
template<class T>inline T       intoTwo(T a)        { return a<<1;}
template<class T>inline ll      stringLength(T s[]) {ll i ;for(i = 0;s[i];i++);return i;}


using namespace std;

void swap(ll &x,ll &y){
    x ^= y;
    y ^= x;
    x ^= y;
}

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }return res;
}   

bool isPrime(ll n){
    if (n <= 1)return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    
    ll n;cin>>n;
    ll nn = n-2;
    ll dp[n+2];
    ll i,j;
    fo(i,n+1)dp[i] = 0;
    vector<ll> v[nn];
    fo(i,nn){
        ll a,b,c;cin>>a>>b>>c;
        v[i].push_back(a);
        v[i].push_back(b);
        v[i].push_back(c);
        dp[a]++;
        dp[b]++;
        dp[c]++;
    }

    // ll last,slast;
    // fo(i,n){
    //     if(dp[i] == 1){
    //         last = 
    //     }
    // }

    ll start = true;
    ll mmct = 0;
    for(i = 0;start;i = j){
        cout<<"ck 1"<<endl;
        if(mmct == nn)break;

        if(dp[v[i][0]] == 1){
            cout<<"ck 2"<<endl;
            cout<<v[i][0]<<" ";
            ll ctind = 0;
            dp[v[i][0]]--;
            fo(j,nn){
                cout<<"ck 3"<<endl;
                if(find(v[j].begin(), v[j].end(),v[i][1]) != v[j].end() &&  find(v[j].begin(), v[j].end(),v[i][2]) != v[j].end()){
                    ctind = j;
                    v[j][1]--;
                    v[j][2]--;
                    break;   
                }
            }
        }else if(dp[v[i][1]] == 1){
            cout<<v[i][1]<<" ";
            ll ctind = 0;
            dp[v[i][1]]--;
            fo(j,nn){
                if(find(v[j].begin(), v[j].end(),v[i][0]) != v[j].end() &&  find(v[j].begin(), v[j].end(),v[i][2]) != v[j].end()){
                    ctind = j;
                    v[j][0]--;
                    v[j][2]--;
                    break;   
                }
            }
        }else if(dp[v[i][2]] == 1){
            cout<<v[i][2]<<" ";
            ll ctind = 0;
            dp[v[i][2]]--;
            fo(j,nn){
                if(find(v[j].begin(), v[j].end(),v[i][1]) != v[j].end() &&  find(v[j].begin(), v[j].end(),v[i][0]) != v[j].end()){
                    ctind = j;
                    v[j][1]--;
                    v[j][0]--;
                    break;   
                }
            }
        }

        mmct++;

    }

    //▬▬ι═══════>
	return 0;
}


/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀:
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀ 
*/
