#include<bits/stdc++.h>
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll int
#define watch(x) cerr<< (#x)<<" is : "<<(x)<<endl;
#define integer int

#ifdef ONLINE_JUDGE
#define cerr if(false)cerr

using namespace std;
ll tts;
integer qn = 1;

char qu(integer var){
    char inp;
    cout<<var<<endl;
    cin>>inp;
    qn++;
    return inp;
    watch(inp);
}
struct block{
    integer l;
    integer r;
    integer s;
};

typedef struct block block;

//GLOBALS : 
integer siz;
vector<block> v;
block createblock(integer l,integer r){
    block rr = {l,r,r-l+1};
    return rr;
}

void keepblock(block keep){
    
    integer i = 0;
    integer k = v.size();
    while((v[v.size()-1].l) >= (keep.r))v.erase(v.begin() + v.size()-1);
    while(v[0].r <= keep.l){
        v.erase(v.begin())
    }

    v[0].l = keep.l;
    v[0].s = v[0].r - v[0].l+1;
    watch(v[0].l); 
    integer sz = v.size()-1;

    v[sz].r = keep.r;
    v[sz].s = v[sz].r - v[sz].l + 1;
    watch(v[sz].l);
    siz = 0;

    for(integer i = 0;i < v.size();i++){
        siz += v[i].s;
        watch(siz);
    }

}

bool dellleteMyRange(block rem){
    
    cerr<<"Before called for : "<<rem.l<<" "<<rem.r<<endl;;
    //ll hh;
    fo(hh,v.size())cerr<<v[hh].l<<" : "<<v[hh].r<<" | ";
    cerr<<endl;
    
    integer i = 0;
    while(i < v.size()){
        if(v[i].l >=  rem.l && v[i].r <= rem.r){
            cerr<<"INSIDE 1\n";
            watch(v[0].l);
            v.erase(v.begin()+i);
        }
        else if(rem.l > v[i].l && rem.r < v[i].r){
            cerr<<"INSIDE 1\n";
            watch(v[0].l);
            //cout<<"INSIDE 2\n";
            block rr = {rem.r,v[i].r,v[i].r-rem.r+1};
            v[i].r = rem.l;
            v[i].s = v[i].r - v[i].l +1;
            v.push_back(rr);
            break;
        }else if(rem.r >= v[i].l &&
                 rem.r <= v[i].r && 
                 rem.l <= v[i].l){
            //cout<<"INSIDE 3\n";
            v[i].l = rem.r;
            v[i].s = v[i].r - v[i].l+1;
            i++;
        }else if(rem.l >= v[i].l && 
                 rem.l <= v[i].r && 
                 rem.r >= v[i].r){
            //cout<<"INSIDE 4\n";
            cerr<<"INSIDE 1\n";
            watch(v[0].l);
            v[i].r = rem.l;
            v[i].s = v[i].r - v[i].l+1;
            i++;
        }
        else{
            i++;
        }
    }
    sort(v.begin(),v.end(),sortcol);
    //cerr<<"UPDATED Rblock : ";
    //fo(hh,v.size())cout<<v[hh].l<<" : "<<v[hh].r<<" | ";
    //cout<<endl;
    integer ckj = 0;
    
    while(ckj < v.size()){
        //cout<<"CKJ : "<<ckj<<endl;
        if(v[ckj].r - v[ckj].l < 5){
            for(integer d = v[ckj].l;d <= v[ckj].r;d++){
                if(qu(d) == 'E'){
                    return true;
                }
            }
            v.erase(v.begin()+ckj);
        }else{
            ckj++;
        }
    }
    siz = 0;
    siz = 0;
    int kk;
    for(kk,v.size())siz += v[kk].s;
    
    return false;
}

block findMids(){
    integer x = 0;
    integer y = 0;
    integer ind = 0;
    
    integer lef = siz/3;
    integer rig = lef;


    while(!(x + v[ind].s >= lef)){
        x += v[ind].s;
        ind++;
    }
    block ret = {0,0,0};
    ret.l = v[ind].l + (lef-x);

    ind = v.size()-1;
    x = 0;
    while(!(x + v[ind].s >= rig)){
        x += v[ind].s;
        ind--;
    }
    ret.r = v[ind].r - (rig-x);
    cerr<<ret.l<<ret.l<<endl;
    return ret;
}

integer search(integer n){
    integer i,j;
    char s1,s2,s3,s4;
    
    int y = 10;
    while(y--){
        y++;

        if(siz < 10){
            integer h;
            fo(h,v.size()){
                integer jk;
                for(jk = v[h].l;jk <= v[h].r;jk++){
                    char c = qu(jk);
                    if(c != 'E'){

                    }else{
                        return jk;
                    }
                }
            }
        }

        block curr = findMids();

        ll bd1 = curr.l;
        ll bd2 = curr.r;

        s1 = qu(bd1);
        if(s1 != 'E'){

        }else{
            return bd1;
        }
        
        s2 = qu(bd2);
        if(s2 != 'E'){
            watch(s2);
        }else{
            return bd2;
        }

        if(s1 == 'L' && s2 == 'L'){
            block remm = {bd2,v[v.size()-1].r,0}; 
            //block.erase(block.begin() + bd2,block.end());
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            
            continue;
        }
        if(s1 == 'G' && s2 == 'G'){
            block remm = {v[0].l,bd1,0};
            
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            //block.erase(block.begin(),block.begin()+bd1);
            continue;
        }
        
        s3 = qu(bd2);
        if(s2 == 'L' && s3 == 'L'){
            block remm = {bd2,v[v.size()-1].r,0}; 
            //block.erase(block.begin() + bd2,block.end());
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            
            continue;
        }
        if(s2 == 'G' && s3 == 'G'){
        
            block remm = {v[0].l,bd2,0};
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            
            //block.erase(block.begin(),block.begin()+bd2);
            continue;
        }

        s4 = qu(bd1);
        if(s3 == 'L' && s4 =='L'){
            block remm = {bd2,v[v.size()-1].r,0}; 
            //block.erase(block.begin() + bd2,block.end());
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            continue;
        }
        if(s3 == 'G' && s4 == 'G'){
            block remm = {v[0].l,bd1,0};
            if(! dellleteMyRange(remm)){
                
            }else{
                return 0;
            }
            //block.erase(block.begin(),block.begin()+bd1);
            continue;
        }
        
        block remm = {bd1,bd2,0};
        if(! dellleteMyRange(remm)){
            
        }else{
            return 0;
        }
        //block.erase(block.begin()+bd1,block.begin()+bd2);
    }
}

void solve(){
    ll n;cin>>n;
    block r = {1,n,n};
    siz = n;
    v.clear();
    v.push_back(r);        
    search(n);
}

integer main(){
    //▬▬ι═══════>
    
    int qwerty = 1;
    while(qwerty--){
        solve();
    }
    
    //▬▬ι═══════>
    return 0;
}
