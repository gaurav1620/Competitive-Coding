
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

//Gaurav Khairnar 2020
//codechef   : gaurav_1620
//codeforces : gaurav1620
//email      : gauravak007@gmail.com
//Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
//Github     : www.github.com/gaurav1620
//

#include<bits/stdc++.h>
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll long long
using namespace std;
ll tts;
struct range{
    int l;
    int r;
    int s;
};

typedef struct range range;

//GLOBALS : 
int siz;
vector<range> v;

range createRange(int l,int r){
    range rr = {l,r,r-l+1};
    return rr;
}

void keepRange(range keep){
    int i = 0;
    while(v[0].r <= keep.l)v.erase(v.begin());
    while(v[v.size()-1].l >= keep.r)v.erase(v.end());

    v[0].l = keep.l;
    v[0].s = v[0].r - v[0].l+1;
    
    int sz = v.size()-1;

    v[sz].r = keep.r;
    v[sz].s = v[sz].r - v[sz].l + 1;
    
    siz = 0;
    for(int i = 0;i < v.size();i++){
        siz += v[i].s;
    }
}

bool sortcol(range a,range b){
    return a.l < b.l;
}
void removeRange(range rem){
    int i = 0;
    while(i < v.size()){
        if(v[i].l >=  rem.l && v[i].r <= rem.r){

            v.erase(v.begin()+i);
        }
        else if(rem.l > v[i].l && rem.r < v[i].r){
            range rr = {rem.r,v[i].r,v[i].r-rem.r+1};
            v[i].r = rem.l;
            v[i].s = v[i].r - v[i].l +1;
            v.push_back(rr);
            break;
        }else if(rem.l <= v[i].r && rem.l >= v[i].l){
            v[i].r = rem.l;
            v[i].s = v[i].r - v[i].l+1;
            i++;
        }else if(rem.r <= v[i].r && rem.r >= v[i].l){
            v[i].l = rem.r;
            v[i].s = v[i].r - v[i].l+1;
            i++;
        }
        else{
            i++;
        }
    }
    sort(v.begin(),v.end(),sortcol);
}

range findBreaks(){
    int lef = siz/3;
    int rig = lef;

    int x = 0;
    int y = 0;
    int ind = 0;

    while(x + v[ind].s < lef){
        x += v[ind].s;
        ind++;
    }
    range ret = {0,0,0};
    ret.l = v[ind].l + (lef-x);

    ind = v.size()-1;
    x = 0;
    while(x + v[ind].s < rig){
        x += v[ind].s;
        ind--;
    }
    ret.r = v[ind].r - (rig-x);

    return ret;
}

int main(){
    //▬▬ι═══════>
    v.push_back({1,100,100});
    siz = 100;

    while(1){
        cout<<"1.KeepRange\n2.removeRange\n3.findBreaks\n4.printVec\n5.exit\n";

        int x;
        cin>>x;
        if(x == 1){
            int a,b;
            cout<<"Enter the range to keep : ";
            cin>>a>>b;
            range gg = {a,b,b-a+1};
            keepRange(gg);
        }
        else if(x == 2){
            int a,b;
            cout<<"Enter the range to remove : ";
            cin>>a>>b;
            range gg = {a,b,b-a+1};
            removeRange(gg);
        }
        else if(x == 3){
            range ret = findBreaks();
            cout<<ret.l<<" "<<ret.r<<endl;
        }else if(x == 4){
            int i;
            fo(i,v.size())cout<<v[i].l<<" : "<<v[i].r<<" | ";
            cout<<endl;
        }else{
            return 0;
        }
    }

    return 0;
}
