#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

ll sumOfDigitsFrom1ToN(ll n) 
{ 
    // base case: if n<10 return sum of 
    // first n natural numbers 
    if (n<10) 
      return n*(n+1)/2; 
  
    // d = number of digits minus one in n. For 328, d is 2 
    ll d = log10(n); 
  
    // computing sum of digits from 1 to 10^d-1, 
    // d=1 a[0]=0; 
    // d=2 a[1]=sum of digit from 1 to 9 = 45 
    // d=3 a[2]=sum of digit from 1 to 99 = a[1]*10 + 45*10^1 = 900 
    // d=4 a[3]=sum of digit from 1 to 999 = a[2]*10 + 45*10^2 = 13500 
    ll a[d+1]; 
    a[0] = 0, a[1] = 45; 
    for (int i=2; i<=d; i++) 
        a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1)); 
  
    // computing 10^d 
    ll p = ceil(pow(10, d)); 
  
    // Most significant digit (msd) of n, 
    // For 328, msd is 3 which can be obtained using 328/100 
    ll msd = n/p; 
  
    // EXPLANATION FOR FIRST and SECOND TERMS IN BELOW LINE OF CODE 
    // First two terms compute sum of digits from 1 to 299 
    // (sum of digits in range 1-99 stored in a[d]) + 
    // (sum of digits in range 100-199, can be calculated as 1*100 + a[d] 
    // (sum of digits in range 200-299, can be calculated as 2*100 + a[d] 
    //  The above sum can be written as 3*a[d] + (1+2)*100 
  
    // EXPLANATION FOR THIRD AND FOURTH TERMS IN BELOW LINE OF CODE 
    // The last two terms compute sum of digits in number from 300 to 328 
    // The third term adds 3*29 to sum as digit 3 occurs in all numbers  
    //                from 300 to 328 
    // The fourth term recursively calls for 28 
    return msd*a[d] + (msd*(msd-1)/2)*p +   
           msd*(1+n%p) + sumOfDigitsFrom1ToN(n%p); 
} 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    
    ll a,b;
    while(1){
        cin>>a>>b;
        if(a== -1){
            break;
        }
        cout<<sumOfDigitsFrom1ToN(b)-sumOfDigitsFrom1ToN(a-1)<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

