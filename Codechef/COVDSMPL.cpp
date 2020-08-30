//Gaurav Khairnar 2020
//codechef   : gaurav_1620
//codeforces : gaurav1620
//email      : gauravak007@gmail.com
//Linedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
//Github     : www.github.com/gaurav1620
//

#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll testCases;
int store[60][60];

bool isInUpperHalf(ll vs,ll ve,ll hs,ll he){
    if(vs < 29)return true;
    return false;
}
bool isInLeftHalf(ll vs,ll ve,ll hs,ll he){
    if(hs < 29)return true;
    return false;
}

ll simpleQuerry(ll vs,ll ve,ll hs,ll he){
    int q;
    //cerr<<"SIMPLE : ";
    cout<<1<<" "<<vs+1<<" "<<hs+1<<" "<<ve+1<<" "<<he+1<<endl;
    cin>>q;
    return q;
}

ll getAns(ll vs,ll ve,ll hs,ll he){
    if(vs == 0 && ve == 59)return simpleQuerry(vs,ve,hs,he);
    if(hs == 0 && he == 59)return simpleQuerry(vs,ve,hs,he);
    if((he-hs)*(ve-vs) > 1300 )return simpleQuerry(vs,ve,hs,he);
    
    ll nas = 0;
    ll big,small,h,v,vCol,hCol,ans;

    if(isInUpperHalf(vs,ve,hs,he)){
        if(isInLeftHalf(vs,he,hs,he)){
            ve++;
            he++;

            big = simpleQuerry(vs,59,hs,59);
            if(big == -1) return -1;
            small = simpleQuerry(ve,59,he,59);
            if(small == -1) return -1;
            
            h = simpleQuerry(ve,59,hs,59);
            if(h == -1) return -1;
            v = simpleQuerry(vs,59,he,59);
            if(v == -1) return -1;

            
        }else{
            //up right
            ve++;
            hs--;
            big = simpleQuerry(vs,59,0,he);
            if(big == -1) return -1;
            small = simpleQuerry(ve,59,0,hs);
            if(small == -1) return -1;
            
            h = simpleQuerry(ve,59,0,he);
            if(h == -1) return -1;
            v = simpleQuerry(vs,59,0,hs);
            if(v == -1) return -1;
        }
    }else{
        if(isInLeftHalf(vs,he,hs,he)){

            vs--;
            he++;

            //down left
            big = simpleQuerry(0,ve,hs,59);
            if(big == -1) return -1;
            small = simpleQuerry(0,vs,he,59);
            if(small == -1) return -1;

            h = simpleQuerry(0,vs,hs,59);
            if(h == -1) return -1;
            v = simpleQuerry(0,ve,he,59);
            if(v == -1) return -1;
        }else{

            vs--;
            hs--;

            big = simpleQuerry(0,ve,0,he);
            if(big == -1) return -1;
            small = simpleQuerry(0,vs,0,hs);
            if(small == -1) return -1;

            h = simpleQuerry(0,vs,0,he);
            if(h == -1) return -1;
            v = simpleQuerry(0,ve,0,hs);
            if(v == -1) return -1;
        }
    }

    vCol = v - small;
    hCol = h - small;
    
    ans = big;
    ans -= small;
    ans -= vCol;
    ans -= hCol;
    
    ans = ans < 0?-1*ans:ans;
    return ans;
}

int bs(ll vs,ll ve,ll hs,ll he,ll ct){
    ll i,j,k;
    if(vs > ve || hs > he)return 0;
    ll size = (ve-vs + 1)*(he-hs+1);
    ll x;
    if(vs == ve && hs == he){
        store[vs][hs] = ct;
        return 0;
    }else if(ct == 0){
        for(i = vs; i <= ve;i++){
            for(j = hs;j <= he;j++){
                store[i][j] = 0;
            }
        }
        return 0;
    }
    else if(size == ct){
        for(i = vs; i <= ve;i++){
            for(j = hs;j <= he;j++){
                store[i][j] = 1;
            }
        }
        return 0;
    }
    else{
        if(vs == ve){
            ll mid = hs + (he-hs)/2;
            x = getAns(vs,ve,hs,mid);
            if(x == -1)return -1;


            int gg;
            gg = bs(vs,ve,hs,mid,x);
            if(gg == -1)return -1;
            gg = bs(vs,ve,mid+1,he,ct - x);
            return gg;
                
        }else{
        
            int gg;
            int mid = vs + (ve-vs)/2;
            x = getAns(vs,mid,hs,he);
            if(x == -1)return -1;

            gg = bs(vs,mid,hs,he,x);
            if(gg == -1)return -1;
            
            gg = bs(mid+1,ve,hs,he,ct-x);
            return gg;
        }
    }
    return 0;
}
int main(){
    testCases = 1;
    cin>>testCases;
    while(testCases--){
        ll n,p;
        cin>>n>>p;
        ll i,j;
        int x;

        for(i = 0;i < n;i++){
            for(j  = 0;j < n;j++){
                store[i][j] = -1;
            }
        }
        
        cout<<"1 1 1 "<<n<<" "<<n<<endl;
        cin>>x;
        if(x == -1)return -1;

        if(bs(0,n-1,0,n-1,x) == -1)return 0;
        cout<<2<<endl;
        for(i = 0; i < n;i++){
            for(j = 0;j < n;j++){
                cout<<store[i][j];
                if(j == n-1 && i != n-1 )cout<<"\n";
                else cout<<" ";
            }
        }
        cout<<endl;

        cin>>x;
        if(x == -1)return 0;
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
