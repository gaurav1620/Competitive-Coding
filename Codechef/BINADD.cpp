/*
© GAURAV KHAIRNAR 2019 

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 

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

#define mod 1000000007

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>inline T       fabs(T a)           { return a>0?a:-a; }
template<class T>inline T       isOdd(T a)          { return a&1; } 
template<class T>inline T       gcd(T a,T b)        { return __gcd(a,b);}
template<class T>inline T       intoTwo(T a)        { return a<<1;}
template<class T>inline ll      stringLength(T s[]) {ll i ;for(i = 0;s[i];i++);return i;}


using namespace std;

void swap(ll &x,ll &y){
    x ^= y;
    y ^= x;
    x ^= y;
}

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }return res;
}   

bool isPrime(ll n){
    if (n <= 1)return false;
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

void bin(ll n){
    if(n == 0)return;
    bin(n/2);
    cout<<n%2;
}

void binaryOfSize8(ll num){
    ll n = 8;
    ll x = ceil(log2(num));
    n -= x;
    while(n > 0){
        n--;
        cout<<0;
    }
    bin(num);
}

void printA(ll a){
    cout<<"A is : \n"<<"\tDec : "<<a<<"\n\tBin : ";
    binaryOfSize8(a);
    cout<<endl;
}
void printB(ll b){
    cout<<"B is : \n"<<"\tDec : "<<b<<"\n\tBin : ";
    binaryOfSize8(b);
    cout<<endl;
}

ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    ll base = 1;

    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}

string XOR(string a , string b, ll len){
    string s = "";
    for(ll i = 0;i < len;i++){
        if(a[i] == b[i])s.push_back('0');
        else s.push_back('1');
    }
    return s;
}

string AND(string a,string b, ll len){
    string s = "";
    for(ll i = 0;i < len;i++){
        if(a[i] == '1' && b[i] == '1')s.push_back('1');
        else s.push_back('0');
    }
    return s;
}

ll countOnes(string s,ll n){
    ll i = 0;
    ll ct = 0;
    for(;i < n;i++){
        if(s[i] == '1')ct++;
    }
    return ct;
}

string leftShift(string s,ll n){
    for(ll i = 0;i < n-1;i++){
        s[i] = s[i+1];
    }
    s[n-1] = '0';
    return s;
}

ll getAns(string a,string b){
    ll n = a.length();
    ll i = 0;
    ll extra = 0;
    ll currentMax = 0;
    ll ct = 0;
    cout<<a<<endl<<b<<endl;
    for(i = n-1;i >= 0;i--){
        if(b[i] == '1'){
            ct++;
            while(a[i-extra] != '0'){
                extra++;
                ct++;
            }
            
            currentMax = max(currentMax,ct+extra);
            ct = 0;
        }
    }
    return extra;
}

ll newAns(string a,string b){
    ll maxx = 0;
    cout<<"\tStrings : \n\t"<<a<<"\n\t"<<b<<endl;
    ll i;
    for(ll i = b.length() - 1;i >= 0;i--){
        ll cutt = i;
        if(b[cutt] == '1'){
            while(a[cutt]!='0'){
                cutt--;
            }
            maxx = max(i-cutt+1,maxx);
        }
            
    }
    
    ll maxx2 = 0;
    ll kk = 0;
    while(b[kk] == '0'){
        kk++;
    }
    for(ll i = b.length() - 1;i >= kk;i--){
        ll cutt = i;
        if(b[cutt] == '0'){
            while(a[cutt]!='1'){
                cutt--;
            }
            maxx2 = max(i-cutt+1,maxx2);
        }
    }


    cout<<"B finds in a :\n";
    cout<<"  find 0 for 1 : "<<maxx<<endl;
    cout<<"  find 1 for 0 : "<<maxx2<<endl;

    for(ll i = a.length() - 1;i >= 0;i--){
        ll cutt = i;
        if(a[cutt] == '1'){
            while(b[cutt]!='0'){
                cutt--;
            }
            maxx = max(cutt-i+1,maxx);
        }
        
    }

    return maxx;
}

ll finalAnswer(string a,string b){
    ll ind = 0;
    bool AisGreater;
    while(1){
        if(a[ind] == '1'){
            AisGreater = true;
            break;
        }
        if(b[ind] == '1'){
            AisGreater = false;
            break;
        }
    
        ind++;
    }

    if(!AisGreater){
        string s = a;
        a = b;
        b = s;
    }
    ll maxx = 0;
    for(ll i = ind; i<= a.length()-1;i++){
        ll cur = i;
        if(a[i] == '0'){
            while(b[cur]!='1' && i <= a.length()-1){
                cur++;
            }
            maxx = max(maxx,cur-i+1);
        }
    }
    return maxx;
}

ll lastTry(string a,string b){
    ll ans = 0;
    ll ct = 0;
    ll ind = 0;
    for(ll i = a.length()-1;i >=0;i--){

    }
}

ll getFinalAnswer(string a,string b){
//    cout<<"ct\n"<<a<<endl<<b<<endl;
    ll ans = 0;
    ll ct = 0;
    bool start = false;

    for(ll i = a.length()-1;i >= 0;){
        if(a[i] == b[i] && b[i] == '1'){
            start = true;
            i--;
            ct++;
            while(a[i] != b[i] && i>=0){
                i--;
                ct++;
            }
            ans = max(ans,ct);
            ct = 0;        
        }
        if(start == true){
            start = false;

        }else{
            i--;
        }

    }

    return ans;
}

int main(){
    //UNCOMMENT THIS
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        // we just want ot find the max dist betwn the  1 made by and with the xor
        while(a.length() != b.length()){
            if(a.length() > b.length()){
                b = '0'+b;
            }else{
                a = '0'+a;
            }
        }
        a = '0'+a;
        b = '0'+b;

        ll ffff = getFinalAnswer(a,b);
        ll n = a.length();
        ll ct = 0;
        ll gg = countOnes(b,b.length());
/*
        while(countOnes(b,n) > 0){
            string u = XOR(a,b,n);
            string v = AND(a,b,n);
            a = u;
            b = leftShift(v,n);
            ct++;
        }        
        cout<<ct<<" ";
*/
        if(gg){
            cout<<ffff+1<<endl;
        }else{
            cout<<0<<endl;
        }
    }

	return 0;
}
/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀:
⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀ 
*/

