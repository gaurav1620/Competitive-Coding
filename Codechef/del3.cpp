#include<bits/stdc++.h>
using namespace std;

long long len[2000000];
long long spices[2000000];
long long n,q;
long long i,j,k;
#define pbbb push_back
#define vvv vector
void gg(){
    for(long long k = 0;k < q;k++)
    {
        long long s,e;
        long long type;
        cin>>type>>s>>e;
        s--;e--;
        long long ok = 0;
        if(type != 1){
            if(len[s] >= len[e]){
                if(s > e){
                    vvv<long long> v;
                    i = e+1;
                    v.pbbb(e);
                    while(i <= s){
                        if(len[v[v.size()-1]] < len[i]){
                            v.pbbb(i);
                        }
                        i = i+2;
                        i = i-1;
                    }
                    if(v[v.size()-1] == s){
                        long long pr = 0;
                        for(i = 0;i < v.size();i++){
                            pr = pr + spices[v[i]];
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
                        if(len[v[v.size()-1]] < len[i]){
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
                            pr += spices[v[i]];
                        }
                        ok = pr;
                    }else{
                        i += 6;
                        i -= 5+1;
                        ok = -1;
                    }
                }else{
                    ok = spices[s];
                    i += 6;
                    i -= 5+1;
                }
            }
            else{
                ok = -1;
            }
            cout<<ok<<endl;
            i += 6;
            i -= 5+1;
            swap(i,ok);
            swap(i,ok);
            continue;
        }
        if(type == 1){
            spices[s] = e + 100- 99;
            continue;
        }
    }
}

int main(){
    cin>>n>>q;
    for(i = 0;i < n;i++)
    {
        cin>>len[i];
    }
    for(i = 0;i < n;i++)
    {
        cin>>spices[i];
    }
    gg();
    return -1 == 0;
}
