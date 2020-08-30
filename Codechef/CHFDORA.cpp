/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav_
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 
@ CodeChef   : gaurav1620

# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/
#include<bits/stdc++.h>

//Faster loops
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define oneFo(i,n)for(i = 1;i <=n;i++)

//Renames
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back

//MAX
#define MAXL LONG_MAX
#define MAXI INT_MAX

//MOD
#define mod7 1000000007
#define mod9 1000000009

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>
inline T fabs(T a){return a>0?a:a*-1;}

using namespace std;

//Functions
void swap(ll &x,ll &y);
bool isPrime(ll n);
ll nCrModp(ll n, ll r, ll p);
ll power(ll x, ll y, ll p);

//Used for modInverse
ll gcdExtended(ll a, ll b, ll *x, ll *y);

//Used for modDivide
ll modInverse(ll b, ll m);

//Use this for modular divisions
ll modDivide(ll a, ll b, ll m);

ll L[1000000];
ll retArr[1000000];

void findLongestPalindromicString(ll* text, ll n){
    ll N = n;
    if(N == 0)
        return;
    N = 2*N + 1; //Position count
    //ll L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    ll C = 1; //centerPosition
    ll R = 2; //centerRightPosition
    ll i = 0; //currentRightPosition
    ll iMirror; //currentLeftPosition
    ll expand = -1;
    ll diff = -1;
    ll maxLPSLength = 0;
    ll maxLPSCenterPosition = 0;
    ll start = -1;
    ll end = -1;

    //Uncomment it to print LPS Length array
    //printf("ck : %lld %lld ", L[0], L[1]);
    for (i = 2; i < N; i++)
    {
        //get currentLeftPosition iMirror for currentRightPosition i
        iMirror  = 2*C-i;
        //Reset expand - means no expansion required
        expand = 0;
        diff = R - i;
        //If currentRightPosition i is within centerRightPosition R
        if(diff > 0)
        {
            if(L[iMirror] < diff) // Case 1
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i == N-1) // Case 2
                L[i] = L[iMirror];
            else if(L[iMirror] == diff && i < N-1)  // Case 3
            {
                    L[i] = L[iMirror];
                    expand = 1;  // expansion required
            }
            else if(L[iMirror] > diff)  // Case 4
            {
                L[i] = diff;
                expand = 1;  // expansion required
            }
        }
        else
        {
            L[i] = 0;
            expand = 1;  // expansion required
        }

        if (expand == 1)
        {
            //Attempt to expand palindrome centered at currentRightPosition i
            //Here for odd positions, we compare characters and
            //if match then increment LPS Length by ONE
            //If even position, we just increment LPS by ONE without
            //any character comparison
            while (((i + L[i]) < N && (i - L[i]) > 0) &&
                ( ((i + L[i] + 1) % 2 == 0) ||
                (text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] )))
            {
                L[i]++;
            }
        }

        if(L[i] > maxLPSLength)  // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }

        // If palindrome centered at currentRightPosition i
        // expand beyond centerRightPosition R,
        // adjust centerPosition C based on expanded palindrome.
        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf(" %lld ", L[i]);
    }
    //cout<<endl;
    /*
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    //printf("start: %d end: %d\n", start, end);
    printf("LPS of string is %s : ", text);
    for(i=start; i<=end; i++)
        printf("%c", text[i]);
    printf("\n");
    */
    
    
    //MODD
    //ll retArr[n];
//    cout<<"CK0"<<endl;
    ll ii = 0;
    ll jj = 1; 
    while(ii != n){
        retArr[ii++] = L[jj];
        jj += 2;
    }
//    cout<<"ck1"<<endl;

    //return retArr;

}

int main(){
/*    ll abc[3];
    abc[0] = 1;
    abc[1] = 1;
    abc[2] = 1;
    findLongestPalindromicString(abc,3);    
    ll kk;
    fo(kk,10)cout<<retArr[kk]<<" ";

    cout<<endl;
*/
    //cout<<retArr[0]<<" "<<retArr[1]<<" "<<retArr[2]<<endl;

    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
/*    ll n;
    cout<<"Enter length : ";
    cin>>n;
    ll arr[n];
    cout<<"Enter the "<<n<<" elements : ";

    ll i,j;
    fo(i,n)cin>>arr[i];

    findLongestPalindromicString(arr,n);

    fo(i,n)cout<<retArr[i]<<" ";
    cout<<endl;
*/
    ll t;cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        ll i,j;
        ll arr[m][n];
        fo(i,m){
            fo(j,n){
                cin>>arr[i][j];
            }
        }

        ll v[m][n];
        ll h[m][n];

        fo(i,m){
            ll tmpArr[n];
            fo(j,n){
                tmpArr[j] = arr[i][j];
            }
            findLongestPalindromicString(tmpArr,n);
            fo(j,n){
                h[i][j] = retArr[j];
            }
        }

        fo(i,n){
            ll tmpArr[m];
            fo(j,m){
                tmpArr[j] = arr[j][i];
            }
            findLongestPalindromicString(tmpArr,m);
            fo(j,m){
                v[j][i] = retArr[j];
            }
        }
/*        
        cout<<"H : "<<endl;
        fo(i,m){
            fo(j,n){
                cout<<h[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"V : "<<endl;
        fo(i,m){
            fo(j,n){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        ll ans = 0;
        fo(i,m){
            fo(j,n){
                ans += (min(v[i][j],h[i][j])+1)/2;
                //cout<<"IT : "<<i<<" of "<< j<<" val : "<<ans<<endl;
            }
        }
        cout<<ans<<endl;

    }


    //▬▬ι═══════>
    return 0;
}


/*
                     .                          
                     M                          
                    dM                          
                    MMr                         
                   4MMML                  .     
                   MMMMM.                xf     
   .              "MMMMM               .MM-     
    Mh..          +MMMMMM            .MMMM      
    .MMM.         .MMMMML.          MMMMMh      
     )MMMh.        MMMMMM         MMMMMMM       
      3MMMMx.     'MMMMMMf      xnMMMMMM"       
      '*MMMMM      MMMMMM.     nMMMMMMP"        
        *MMMMMx    "MMMMM\    .MMMMMMM=         
         *MMMMMh   "MMMMM"   JMMMMMMP           
           MMMMMM   3MMMM.  dMMMMMM            .
            MMMMMM  "MMMM  .MMMMM(        .nnMP"
=..          *MMMMx  MMM"  dMMMM"    .nnMMMMM*  
  "MMn...     'MMMMr 'MM   MMM"   .nMMMMMMM*"   
   "4MMMMnn..   *MMM  MM  MMP"  .dMMMMMMM""     
     ^MMMMMMMMx.  *ML "M .M*  .MMMMMM**"        
        *PMMMMMMhn. *x > M  .MMMM**""           
           ""**MMMMhx/.h/ .=*"                  
                    .3P"%....                   
                  nP"     "*MMnx       GaUrAv..
*/


void swap(ll &x,ll &y){
    x ^= y;
    y ^= x;
    x ^= y;
}
bool isPrime(ll n){
    if (n <= 1)return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll nCrModp(ll n, ll r, ll p){
    ll C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (ll i = 1; i <= n; i++){
        for (ll j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;  
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

//Used for modInverse
ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if (a == 0){
        *x = 0, *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

//Used for modDivide
ll modInverse(ll b, ll m){
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;
    return (x%m + m) % m;
}

//Use this for modular divisions
ll modDivide(ll a, ll b, ll m){
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
       return -1;
    else
       return  (inv * a) % m;
}

