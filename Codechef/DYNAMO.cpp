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

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;
    return false;
}

string getBaseString(ll n){
    string s = "";
    ll i;
    fo(i,n){
        s = s+'9';
    }
    s = "0000" + s;

    return s;
}

void printStringWithoutLeadingZeros(string s){
    ll i = 0;
    while(s[i] == '0'){
        i++;
    }
    ll len = s.length();
    for(;i < len;i++){
        cout<<s[i];
    }
    cout<<endl;
}

string getStringWithProperLength(ll n){
    string s;
    cin>>s;
    ll i = n - s.length() + 4;
    while(i--){
        s = '0'+s;
    }
    return s;
}

string findSum(string str1, string str2){
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n1; i++){
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++){
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}

string findDiff(string str1, string str2){
    if (isSmaller(str1, str2))
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i=0; i<n2; i++){
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i=n2; i<n1; i++){
        int sub = ((str1[i]-'0') - carry);
        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

int main(){
    //string a,b;
    //cin>>a>>b;
    //cout<<findDiff(a,b);
    //cout<<findSum("0000001234","00000012340");
    //cout<<getStringWithProperLength(10);
    //printStringWithoutLeadingZeros("000001234");
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll t;cin>>t;
    while(t--){
        /*ll n;
        ll a,b,d;
        ll s,e;
        scanf("%lld",&n);
        ll ct = pow(10,n)-1;
        s = ct;
        scanf("%lld",&a);
        printf("%lld\n",2*s + a);
        fflush(stdout);
        scanf("%lld",&b);
        printf("%lld\n",s - b);//c
        fflush(stdout);
        scanf("%lld",&d);
        printf("%lld\n",s - d);//e
        fflush(stdout);
        ll ck;
        scanf("%lld",&ck);
        if(ck == -1){
            return 0;
        }
        */

        ll n;
        //cout<<"ck0"<<endl;
        cin>>n;
        //cout<<"ck1"<<endl;
        string s = getBaseString(n);
        //cout<<"ck2"<<endl;
        string a = getStringWithProperLength(n);
        //cout<<"ck3"<<endl;
        printStringWithoutLeadingZeros(findSum(findSum(findSum(s,s),a), "2"));
        fflush(stdout);
        string b = getStringWithProperLength(n);
        printStringWithoutLeadingZeros(findSum(findDiff(s,b),"1"));
        fflush(stdout);
        string d = getStringWithProperLength(n);
        printStringWithoutLeadingZeros(findSum(findDiff(s,d),"1"));
        fflush(stdout);
        ll ck;
        cin>>ck;
        if(ck == -1){
            return 0;
        }
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

