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
#define ll long long
#define fo(i,n) for(i = 0;i < n;i++)
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cerr << (#x)<< " is : " << (x) << endl
//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;
void deb(ll arr[], ll n){
    ll i;
    fo(i,n)cout<<arr[i]<<" ";
    cout<<endl;
}

#define MAXN 200005
ll h[MAXN];
ll b[MAXN];
ll NGE[MAXN];
ll PGE[MAXN];
ll QLR[MAXN];
ll QRL[MAXN];
ll enterRL[MAXN];
ll leaveRL[MAXN];
ll enterLR[MAXN];
ll leaveLR[MAXN];
ll FlatTreeRL[2*MAXN];
ll FlatTreeLR[2*MAXN];
ll BITRL[2*MAXN];//Segment Rl
ll BITLR[2*MAXN];    //LR

ll timeRL = 0;
ll timeLR = 0;

ll indFlatTreeLR = 0;
ll indFlatTreeRL = 0;

bool visRL[MAXN];
bool visLR[MAXN];

#define root 200002
vector<ll> adjRL[MAXN];
vector<ll> adjLR[MAXN];

ll n,q;

ll getSumTill(ll BIT[],ll ind){
    ll sum = 0;
    ind++;
    while(ind > 0){
        sum += BIT[ind];
        ind -= ind&(-ind);
    }
    return sum;
}
void update(ll BIT[],ll ind,ll val,ll nn){
    ++ind;
    while(ind <= nn){
        BIT[ind] += val;
        ind += ind&(-ind);
    }
}
ll constructBIT(ll BIT[],ll arr[],ll nn){
    ll i,j;
    fo(i,nn)BIT[i] = 0;
    fo(i,nn)update(BIT,i,arr[i],nn);
}

void constrGrphAndTimes();
void makeNGE();
void makePGE();

long long Noice(long long op,long long start,long long end){
        if(op == 1){
            //Update both trees !!!!!
            update(BITRL,enterRL[start-1]
                    ,end - b[start-1],2*n+2);
            update(BITRL,leaveRL[start-1],
                    b[start-1] - end,2*n+2);
            
            update(BITLR,enterLR[start-1]
                    ,end - b[start-1],2*n+2);
            update(BITLR,leaveLR[start-1],
                    b[start-1] - end,2*n+2);
            b[start-1] = end;
            return -69;
        }else{
            start--;
            end--;
            if(start == end){
                return b[start];
            }else if(h[start] == h[end]){
                return -1;
            }else if(start > end){
                // RL
                /*
                watch(enterRL[start]);
                watch(enterRL[end]);
                watch(leaveRL[start]);
                watch(leaveRL[end]);
                */
                if(enterRL[start] < enterRL[end] && leaveRL[start] > leaveRL[end]){
                    return (ll)(getSumTill(BITRL,enterRL[end]) 
                                - getSumTill(BITRL,enterRL[start]) + b[start]); 
                }else{
                    return -1;
                }
            }else{
                // LR
                if(enterLR[start] < enterLR[end] && leaveLR[start] > leaveLR[end]){
                    return (ll)(getSumTill(BITLR,enterLR[end]) 
                                - getSumTill(BITLR,enterLR[start]) + b[start]); 
                    
                }else{
                    return -1;
                }
            }
        }
}

int main(){

    memset(visRL,false,sizeof(visRL));
    memset(visLR,false,sizeof(visLR));

    cin>>n>>q;

    ll i,j,k;
    fo(i,n)cin>>h[i];
    fo(i,n)cin>>b[i];
    
    makeNGE();
    makePGE();
    constrGrphAndTimes();

    constructBIT(BITLR,FlatTreeLR,2*n+2);
    constructBIT(BITRL,FlatTreeRL,2*n+2);
    
    cout<<"Height    : ";deb(h,n);
    cout<<"NGE       : ";deb(NGE,n);
    cout<<"EnterRL   : ";deb(enterRL,n);
    cout<<"LeavdRL   : ";deb(leaveRL,n);
    cout<<"FlattenRL : ";deb(FlatTreeRL, 2*n+2);

    while(q--){
        ll start,end;
        ll op;
        cin>>op>>start>>end;
        ll tp = Noice(op,start,end);
        if(op == 2)cout<<tp<<endl;
    }
    return 0;
}
void DFSRL(long long ind){
    visRL[ind] = 1;
    enterRL[ind] = timeRL++;
    
    FlatTreeRL[indFlatTreeRL++] = b[ind];

    for(long long v : adjRL[ind]){
        if(!visRL[v]){
            DFSRL(v);
        }
    }
    FlatTreeRL[indFlatTreeRL++] = -b[ind];
    leaveRL[ind] = timeRL++;
}

void DFSLR(long long ind){
    visLR[ind] = 1;
    enterLR[ind] = timeLR++;

    FlatTreeLR[indFlatTreeLR++] = b[ind];
    for(long long v : adjLR[ind]){
        if(!visLR[v]){
            DFSLR(v);
        }
    }
    FlatTreeLR[indFlatTreeLR++] = -b[ind];
    leaveLR[ind] = timeLR++;
}
void constrGrphAndTimes(){
    for(long long i = 0;i < n;i++){
        QLR[i] = b[i] + (PGE[i] == -1 ? 0 : QLR[PGE[i]]);
        if(NGE[i] == -1){
            adjRL[root].push_back(i);
        }else{
            adjRL[NGE[i]].push_back(i);
        }
        if(PGE[i] == -1){
            adjLR[root].push_back(i);
        }else{
            adjLR[PGE[i]].push_back(i);
        }
    }
    DFSRL(root);
    DFSLR(root);
    for(long long i = n-1;i >= 0;i--){
        QRL[i] = b[i] + (NGE[i] == -1 ? 0 : QRL[NGE[i]]);
    }
    

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
