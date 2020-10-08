#include<bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    long long ans = 0;
    long long mm = m;
    long long nn = n;
    for(int i = 0;i < 32;i++){
        if(m & (1<<i)){
            unsigned long long int lp = 1<<(i+1);
            lp--;
            lp = m|lp;
            //finds pos of rightmost unset bit
            lp = (long long )log2((~lp) & (-(~lp)));
            //finds next no. that will 
            //have this bit set
            lp = (mm | 1LL<<lp) & ~((1LL<<lp) - 1);
            
            if(lp > n)
                ans|=1<<i;
        }
    }
    int rt = ans;
    return rt;
}

int main(){
    cout<<rangeBitwiseAnd(1248234,1248334)<<endl;
    return 0;
}
