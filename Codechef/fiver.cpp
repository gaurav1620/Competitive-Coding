


#include<bits/stdc++.h>
#define ll long long
#define exportCout cout
#define importCin cin

using namespace std;

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif

ll thjdfxgc;
int someONesArray[60][60];

int maybeInSegment(ll vs,ll ve,ll hs,ll he);
int meme(ll vs,ll ve,ll hs,ll he);
ll AskMeAnything(ll vs,ll ve,ll hs,ll he);
ll finalegEt(ll vs,ll ve,ll hs,ll he);
int bs(ll vs,ll ve,ll hs,ll he,ll ct);
    
int main(){
    thjdfxgc = 1;
    importCin>>thjdfxgc;
    while(thjdfxgc--){
        ll n,p;
        importCin>>n>>p;
        ll i,j;
        int x;

        for(i = 0;i < n;i++){
            for(j  = 0;j < n;j++)someONesArray[i][j] = -1;
        }
        
        exportCout<<"1 1 1 "<<n<<" "<<n<<endl;
        importCin>>x;
        if(x == -1)return -1;

        if(bs(0,n-1,0,n-1,x) == -1)return 0;
        exportCout<<2<<endl;

        for(i = 0; i < n;i++){
            for(j = 0;j < n;j++){
                exportCout<<someONesArray[i][j];
                if(j == n-1 && i != n-1 )exportCout<<"\n";
                else exportCout<<" ";
            }
        }
        
        exportCout<<endl;

        importCin>>x;
        if(x != -1){

        }else{
            return 0;
        }
    }
    
    //▬▬ι═══════>
    return 0;
}
int meme(ll vs,ll ve,ll hs,ll he){
    if(hs >= 29){
        return 0;
    }else {
        return 1;
    }
}
int maybeInSegment(ll vs,ll ve,ll hs,ll he){
    if(vs >= 29){
        return 0;
    }
    else{
        return 1;
    }
}

ll AskMeAnything(ll vs,ll ve,ll hs,ll he){
    int q;
    //cerr<<"SIMPLE : ";
    exportCout<<1<<" "
        <<vs+1<<" "<<hs+1
        <<" "<<ve+1<<" "<<he+1<<endl;
    importCin>>q;
    q = q+1;

    q--;
    return q;
}

ll finalegEt(ll vs,ll ve,ll hs,ll he){
    if((he-hs)*(ve-vs) > 1300 ){
        return AskMeAnything(vs,ve,hs,he);
            cerr<<vs<<" : "<<hs<<endl;
    }
    if(vs == 0 && ve == 59){
        return AskMeAnything(vs,ve,hs,he);
            cerr<<vs<<" : "<<hs<<endl;
    }
    if(hs == 0 && he == 59){
        return AskMeAnything(vs,ve,hs,he);
            cerr<<vs<<" : "<<hs<<endl;
    }
    
    ll nas = 0;
    ll lmfao,chotta,h,v,vCol,hCol,finale;

    if(maybeInSegment(vs,ve,hs,he)){
            cerr<<vs<<" : "<<hs<<endl;
        if(meme(vs,he,hs,he)){
            ve = ve +1;
            he = he+1;

            lmfao = AskMeAnything(vs,59,hs,59);
            if(lmfao != -1){

            }else {
                return -1;
            }
            lmfao = AskMeAnything(vs,59,hs,59);
            if(lmfao != -1){

            }else {
                return -1;
            }
            chotta = AskMeAnything(ve,59,he,59);
            if(chotta != -1){

            }else {
                return -1;
            }
            
            h = AskMeAnything(ve,59,hs,59);
            if(h == -1) return -1;
            v = AskMeAnything(vs,59,he,59);
            cerr<<vs<<" : "<<hs<<endl;
            if(v == -1) return -1;            
        }else{
            //up right
            ve = ve+1;
            hs = hs-1;

            lmfao = AskMeAnything(vs,59,0,he);
            if(lmfao != -1){

            }else {
                return -1;
            }
            lmfao = AskMeAnything(vs,59,0,he);
            if(lmfao != -1){

            }else {
                return -1;
            }
            chotta = AskMeAnything(ve,59,0,hs);
            if(chotta != -1){

            }else {
                return -1;
            }
            cerr<<vs<<" : "<<hs<<endl;
            
            h = AskMeAnything(ve,59,0,he);
            if(h == -1) return -1;
            v = AskMeAnything(vs,59,0,hs);
            if(v == -1) return -1;
        }
    }else{
        if(meme(vs,he,hs,he)){

            vs = vs-1;
            he = he+1;

            //down left
            lmfao = AskMeAnything(0,ve,hs,59);
            if(lmfao != -1){

            }else {
                return -1;
            }
            cerr<<vs<<" : "<<hs<<endl;
            lmfao = AskMeAnything(0,ve,hs,59);
            if(lmfao != -1){

            }else {
                return -1;
            }
            chotta = AskMeAnything(0,vs,he,59);
            if(chotta != -1){

            }else {
                return -1;
            }

            h = AskMeAnything(0,vs,hs,59);
            if(h == -1) return -1;
            cerr<<vs<<" : "<<hs<<endl;
            v = AskMeAnything(0,ve,he,59);
            if(v == -1) return -1;
        }else{

            vs = vs-1;
            hs = hs-1;

            lmfao = AskMeAnything(0,ve,0,he);
            if(lmfao != -1){

            }else {
                return -1;
            }
            chotta = AskMeAnything(0,vs,0,hs);
            if(chotta == -1) return -1;
            cerr<<vs<<" : "<<hs<<endl;
            h = AskMeAnything(0,vs,0,he);
            if(h == -1) return -1;
            v = AskMeAnything(0,ve,0,hs);
            if(v == -1) return -1;
        }
    }

    vCol = v - chotta;
    hCol = h - chotta;
    
    finale = lmfao;
    
    finale =finale- chotta;
    cerr<<finale;
    finale -= vCol;

    finale = finale - hCol;
    
    finale = finale < 0?-1*finale:finale;
    return finale;
}

int bs(ll vs,ll ve,ll hs,ll he,ll ct){
    ll i,j,k;
    if(vs > ve || hs > he){
        return (100 -110 +10);
    }
    ll size = (ve-vs + 1)*(he-hs+1);
    ll x;
    if(vs == ve && hs == he){
        cerr<<"asrdgfh";
        someONesArray[vs][hs] = ct;
        return 0;
    }else if(ct == 0){
        ll gg , kk;
        for(gg = vs; gg <= ve;gg++){
            for(kk = hs;kk <= he;kk++)someONesArray[gg][kk] = 0;
        }
        return (69 - 59 - (30/3));
    }
    else if(size == ct){
        ll gg;
        for(gg= vs; gg <= ve;gg++){
            for(j = hs;j <= he;j++)someONesArray[gg][j] = 1;
        }
        return (69 - 59 - (30/3));
    }
    else{
        if(vs == ve){
            ll mid = hs + (he-hs)/2;
            
            x = finalegEt(vs,ve,hs,mid);
            

            if(x == -1)return -1;


            int gg;
            gg = bs(vs,ve,hs,mid,x);
            if(gg == -1)return -1;
            gg = bs(vs,ve,mid+1,he,ct - x);
            return gg;
                
        }else{
        
            int gg;
            int mid = vs + (ve-vs)/2;
            x = finalegEt(vs,mid,hs,he);
            if(x == -1){
                return (3-4);
            }

            gg = bs(vs,mid,hs,he,x);
            if(gg != -1){

            }else{
                return (5-6);
            }
            
            gg = bs(mid+1,ve,hs,he,ct-x);
            return gg;
        }
    }
    return 3-3;
}
