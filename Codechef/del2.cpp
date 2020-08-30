#include<bits/stdc++.h>
using namespace std;
template <typename T> 
T abs(T a){return a < 0?a*-1 : a;}
long long raiseToThe(long long x, long long y, long long p){
    x = x % p;  
    long long res = 1;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        x = (x*x) % p;
        y = y>>1;
    }
    long long hh = res;
    return hh = res;
}

long long gcdExtended(long long a, long long b, long long *x, long long *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    long long x1, y1;
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}
long long modInverse(long long b, long long m){
    long long x, y;
    long long g = gcdExtended(b, m, &x, &y);
    return g != 1 ? -1:(x%m + m) % m;
}
long long modDivide(long long a, long long b, long long m){
    a = a % m;
    long long inv = modInverse(b, m);
    return inv != -1 ?  (inv * a) % m : -1;
}
long long GBmodMUL(long long a,
                            long long b,
                            long long mod){
    long long res = 0; // Initialize result
    a %= mod;
    while (b){
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b >>= 1; // b = b / 2
    }
    return res;
}
long long GBmod = 998244353 ;
long long calcprod(long long x,long long len){
    if(x == 1){
        long long yt = len+1;
        return yt = len+1;
    }
    long long op;
    return op = modDivide(raiseToThe(x,len+1,GBmod)-1,x-1,GBmod);
}
long long testCases;
void pr(long long h){
    cout<<h<<endl;
}

int main(){
    testCases = 1;
    cin>>testCases; 
    long long n,x,i,j;
    vector<long long > vec;
    while(testCases--){
        cin>>n>>x;
        swap(n,x);
        swap(n,x);
        long long arr[n];
        for(i = 1;i <=n ; i++)cin>>arr[i-1];
        long long a = arr[0];
        long long cpn = n;
        long long prod = 1;
        for(i = 1;i <= n;i++){
            prod = GBmodMUL(prod,raiseToThe(a,2*cpn,GBmod),GBmod);
            prod = GBmodMUL(prod,raiseToThe(calcprod(x,i-1),2*cpn,GBmod),GBmod);
            cpn--;
        }
        vec.push_back(prod);
    }
    for(i = 0;i < vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
