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

ll oneDigit(ll num)
{
    // comparison operation is faster than division operation.
    // So using following instead of "return num / 10 == 0;"
    return (num >= 0 && num < 10);
}


bool isPalUtil(ll num, ll* dupNum)
{
    // Base case (needed for recursion termination): This statement
    // mainly compares the first digit with the last digit
    if (oneDigit(num))
        return (num == (*dupNum) % 10);

    // This is the key line in this method. Note that all recursive
    // calls have a separate copy of num, but they all share same copy
    // of *dupNum. We divide num while moving up the recursion tree
    if (!isPalUtil(num/10, dupNum))
        return false;

    // The following statements are executed when we move up the
    // recursion call tree
    *dupNum /= 10;

    // At this point, if num%10 contains i'th digit from beiginning,
    // then (*dupNum)%10 contains i'th digit from end
    return (num % 10 == (*dupNum) % 10);
}

// The main function that uses recursive function isPalUtil() to
// find out whether num is palindrome or not
bool isPal(ll num)
{
    // If num is negative, make it positive
    if (num < 0)
       num = -num;

    // Create a separate copy of num, so that modifications made
    // to address dupNum don't change the input number.
    ll *dupNum = new long long (num); // *dupNum = num

    return isPalUtil(num, dupNum);
}

ll findSum(ll x){
    ll ans = 0;
    while(x){
        ans += x%10;
        x /= 10;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    vector<ll> primes;
    bool isPrime[500];
    ll i,k,j;
    fo(i,500)isPrime[i] = true;

    vector<ll> ppnums;
    for(i = 2;i*i <500;i++){
        if(isPrime[i]){
            if(isPal(i)){
                ppnums.push_back(i);
            }
            if(ppnums.size() >= 114){
                break;
            }
            primes.push_back(i);
            for(j = i*i;j < 700;j+=i){
                primes[j] = false;
            }
        }
    }

    ll t;cin>>t;
    while(t--){
        ll x;
        cin>>x;
        cout<<ppnums[x]<<" "<<primes[findSum(ppnums[x])]<<endl;
    }

    //▬▬ι═══════>
    return 0;
}

