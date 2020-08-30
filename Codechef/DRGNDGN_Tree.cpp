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
ll BITRL[2*MAXN];
ll BITLR[2*MAXN];

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

#define pbbb push_back
#define vvv vector

long long gg(long long type,long long s,long long e);

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
    
    
    fo(i,n)cout<<enterRL[i]<<" ";
    cout<<endl;
    fo(i,n)cout<<leaveRL[i]<<" ";
    cout<<endl;

    fo(i,2*n + 2)cout<<FlatTreeRL[i]<<" ";
    cout<<endl;
    
    fo(i,2*n + 2)cout<<FlatTreeLR[i]<<" ";
    cout<<endl;

    constructBIT(BITLR,FlatTreeLR,2*n+2);
    constructBIT(BITRL,FlatTreeRL,2*n+2);
   
    /*
    while(1){
        ll la;
        cin>>la;
        cout<<getSumTill(BITRL,la)<<endl;
    }
    */

    /*
    fo(i,n)cout<<enterLR[i]<<" ";
    cout<<endl;
    fo(i,n)cout<<leaveLR[i]<<" ";
    cout<<endl;
    */
    /* 

    fo(i,n)cout<<QRL[i]<<" ";
    cout<<endl;
    fo(i,n)cout<<QLR[i]<<" ";
    cout<<endl;

    fo(i,n)cout<<NGE[i]<<" ";
    cout<<endl;
    fo(i,n)cout<<PGE[i]<<" ";
    cout<<endl;
    */

    //*
    for(long long i = 0;i < n;i++){
        for(long long j= 0;j < n;j++){
            if(Noice(2,i+1,j+1) != gg(2,i+1,j+1)){
                cout<<"\n WA : \n";
                cout<<i<<" : "<<j<<endl;
                cout<<Noice(2,i+1,j+1)<<" : "<<gg(2,i+1,j+1)<<endl;
            }else{
                cerr<<" OK ";
            }
        }
    }
    //*/
    
    Noice(1,4,100);
    Noice(1,3,130);
    Noice(1,2,120);
    
    for(long long i = 0;i < n;i++){
        for(long long j= 0;j < n;j++){
            if(Noice(2,i+1,j+1) != gg(2,i+1,j+1)){
                cout<<"\n WA : \n";
                cout<<i<<" : "<<j<<endl;
                cout<<Noice(2,i+1,j+1)<<" : "<<gg(2,i+1,j+1)<<endl;
            }else{
                cerr<<" OK ";
            }
        }
    }

    while(q--){
        ll start,end;
        ll op;
        cin>>op>>start>>end;
        cout<<Noice(op,start,end)<<endl;
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
long long gg(long long type,long long s,long long e){
    ll i;
    for(long long k = 0;k < q;k++){
        s--;e--;
        long long ok = 0;
        if(type != 1){
            if(h[s] >= h[e]){
                if(s > e){
                    vvv<long long> v;
                    i = e+1;
                    v.pbbb(e);
                    while(i <= s){
                        if(h[v[v.size()-1]] < h[i]){
                            v.pbbb(i);
                        }
                        i = i+2;
                        i = i-1;
                    }
                    if(v[v.size()-1] == s){
                        long long pr = 0;
                        for(i = 0;i < v.size();i++){
                            pr = pr + b[v[i]];
                        }
                        ok = pr;
                    }else{
                        ok = -1;
                    }
                }else if(s < e){
                    vvv<long long> v;
                    v.pbbb(e);
                    i = e-1;
                    while(i >= s){
                        i += 6;
                        i -= 5+1;
                        if(h[v[v.size()-1]] < h[i]){
                            v.pbbb(i);
                        }
                        i += 2;
                        i -= 3;
                    }
                    if(v[v.size()-1] == s){
                        long long pr = 0;
                        i += 6;
                        i -= 5+1;
                        for(i = 0;i < v.size();i++){
                        i += 6;
                        i -= 5+1;
                            pr += b[v[i]];
                        }
                        ok = pr;
                    }else{
                        i += 6;
                        i -= 5+1;
                        ok = -1;
                    }
                }else{
                    ok = b[s];
                    i += 6;
                    i -= 5+1;
                }
            }
            else{
                ok = -1;
            }
            return ok;
            i += 6;
            i -= 5+1;
            swap(i,ok);
            swap(i,ok);
            continue;
        }
        if(type == 1){
            b[s] = e + 100- 99;
            continue;
        }
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
