//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/


/*  Author     : Gaurav Khairnar
    Codechef   : gaurav_1620
    Codeforces : gaurav1620
    Email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/
//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/
#include<bits/stdc++.h>
#define ll long long
#define fo(i,n) for(i = 0;i < n;i++)
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cout << (#x)<< " is : " << (x) << endl
//Removes cout on judging platforms
#ifdef ONLINE_JUDGE
#define cout if (false) cout
#endif 

using namespace std;
void deb(ll arr[],ll n);

ll n,q;
#define  MAXN 200005
ll h[MAXN];
ll b[MAXN];
ll maxIndToR[MAXN];
ll store[MAXN];
ll NGE[MAXN];//index of next greater element
ll PGE[MAXN];//index of pre  greater element
ll QRL[MAXN];//when querry is from rig to lef
ll QLR[MAXN];
ll BitQRL[MAXN];
ll BitQLR[MAXN];

//if we have a querry from rig to lef
//first check if lef is the max in the range (lef,rig)
//then we will return (QRL[rig] - QRL[lef] + b[lef])

//if we have a querry from lef to rig
//first check if rig is the max in the range(lef,rig)
//then we will return (QLR[lef] - QLR[rig] + b[rig])

//*******CAUTION CAUTION CAUTION CAUTION CAUTION**************
//Dont forget to check for other max values in the range
//other than the start polong long


//RMQ
ll lookupRL[MAXN][(ll)(log2(MAXN)+2)];
ll lookupLR[MAXN][(ll)(log2(MAXN)+2)];

void makeQRL();
void makeQLR();
void makePGE();
void makeNGE();

//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/
void buildSparseTableLR();
void buildSparseTableRL();
long long queryMAXinRange(ll L, ll R);

ll querry(ll start,ll end);




int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>q;
    ll i,j,k;
    fo(i,n)cin>>h[i];
    fo(i,n)cin>>b[i];
    
    //if(n <= 1000){
    if(false){
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
    
    makeNGE();
    cout<<"NGE : \n";
    deb(NGE,n);
    
    cout<<"Heights : \n";
    deb(h,n);

    makePGE();
    cout<<"PGE : \n";
    deb(PGE,n);
    
    makeQRL();
    cout<<"QRL : \n";
    deb(QRL,n);

    makeQLR();
    cout<<"QLR : \n";
    deb(QLR,n);
    
    buildSparseTableLR();
    buildSparseTableRL();

    while(q--){
        ll ql,qr;
        ll type;

        cin>>type>>ql>>qr;
        if(type == 2)
            cout<<querry(ql - 1,qr -1)<<endl;
        else{
            //b[ql-1] = qr;
        }
    }
    return 0;
}

ll querry(ll start,ll end){
    if(start == end){
        return b[start];
    }else if(h[start] == h[end]){
        return -1;
    }
    else if(queryMAXinRange(start,end) != start){
        return -1;
    }else if(start < end){
        //L to R
        return (ll)(QLR[end] - QLR[start] + b[start]); 
    }else if(start > end){
        //R to L
        return (ll)(QRL[end] - QRL[start] + b[start]);
    }
}
//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/
void buildSparseTableRL(){
    for (long long i = 0; i < n; i++)
        lookupRL[i][0] = i;
    for (long long j = 1; (1 << j) <= n; j++) {
        for (long long i = 0; (i + (1 << j) - 1) < n; i++) {
            if (h[lookupRL[i][j - 1]] >
                    h[lookupRL[i + (1 << (j - 1))][j - 1]])
                lookupRL[i][j] = lookupRL[i][j - 1];
            else
                lookupRL[i][j] = lookupRL[i + 
                    (1 << (j - 1))][j - 1];
        }
    }
}
//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/
void buildSparseTableLR(){
    for (long long i = 0; i < n; i++)
        lookupLR[i][0] = i;
    for (long long j = 1; (1 << j) <= n; j++) {
        for (long long i = 0; (i + (1 << j) - 1) < n; i++) {
            if (h[lookupLR[i][j - 1]] >=
                    h[lookupLR[i + (1 << (j - 1))][j - 1]])
                lookupLR[i][j] = lookupLR[i][j - 1];
            else
                lookupLR[i][j] = lookupLR[i + 
                    (1 << (j - 1))][j - 1];
        }
    }
}
//REFERENCE : https://www.geeksforgeeks.org/range-maximum-query-using-sparse-table/
long long queryMAXinRange(long long L, long long R){
    if(L < R){
        long long j = (long long)log2(R - L + 1);
        if (h[lookupRL[L][j]] > h[lookupRL[R - (1 << j) + 1][j]])
            return lookupRL[L][j];
        else
            return lookupRL[R - (1 << j) + 1][j];

    }
    swap(L,R);
    long long j = (long long)log2(R - L + 1);
    if (h[lookupLR[L][j]] >= h[lookupLR[R - (1 << j) + 1][j]])
        return lookupLR[L][j];
    else
        return lookupLR[R - (1 << j) + 1][j];
}

void makeQRL(){
    for(ll i = n-1; i >= 0; i--)
        QRL[i] = b[i] + (NGE[i] == -1 ? 0 : QRL[NGE[i]]);
}

void makeQLR(){
    for(ll i = 0; i < n; i++)
        QLR[i] = b[i] + (PGE[i] == -1 ? 0 : QLR[PGE[i]]);
}

void makeBitQRL(){

    for(ll i = n-1; i >= 0; i--){
        ll toMake = 
    }
}

void makeBitQLR(){
    for(ll i = 0; i < n; i++)
        QLR[i] = b[i] + (PGE[i] == -1 ? 0 : QLR[PGE[i]]);
}


void makeNGE(){
    stack <ll> s;
    s.push(0);
    ll i;
    for(i = 1;i < n;i++){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(!s.empty() && h[s.top()] < h[i]){
            NGE[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        NGE[s.top()] = -1;
        s.pop();
    }
}
void makePGE(){
    stack <ll> s;
    s.push(n-1);
    ll i;
    for(i = n-2;i >= 0;i--){
        if(s.empty()){
            s.push(i);
            continue;
        }
        while(!s.empty() && h[s.top()] < h[i]){
            PGE[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        PGE[s.top()] = -1;
        s.pop();
    }
}

void deb(ll arr[],ll n){
    ll i,j;
    fo(i,n)cout<<i<<" ";
    cout<<endl;
    fo(i,n)cout<<arr[i]<<" ";
    cout<<endl;
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
