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



//************************************************

void printArr(ll* arr,ll n){
    ll i;
    fo(i,n)cout<<arr[i]<<" ";
    cout<<endl;
}

void printBoolArr(bool* b , ll n){
    ll i;
    fo(i,n){
        if(b[i])cout<<"T ";
        else cout<<"F ";
    }
    cout<<endl;
}



void getBadArray(ll* arr,bool *b,ll n){
    ll i;
    fo(i,n)b[i] = false;
    for(i = 0 ;i < n-1 ;i++){
        if(arr[i] == arr[i+1]){
            b[i] = true;
            b[i+1] = true;
        }
    }
}

//This is the array where if 
//the starting index ie p 
//if p is bad but as it is starting index
//so we dont consider it bad
//but if it is previously in a series 
//dont consider it 
//but if not then use it
void getStartPossibleArray(ll *arr, ll *addArr, bool * badArr, ll n){
    ll i;

    if(n < 3)return;

    fo(i,n)addArr[i] = 0;
    for(i = 0;i < n-2;i++){
        if(badArr[i] && (arr[i+1] > arr[i] ) && (arr[i+2] < arr[i+1])) {
            addArr[i] = 1;
        }       
    }
    if(badArr[n-2] && arr[n-1] > arr[n-2]){
        addArr[n-2] = 1;
    }
}

void getEndPossibleArray(ll *arr,ll *addArr, bool *badArr, ll n){
    if(n < 3) return;

    ll i;
    fo(i,n)addArr[i] = 0;

    if(badArr[1] && (arr[0] > arr[1])){
        addArr[1] = 1;
    }

    for(i = 0;i < n-2;i++){
        if(badArr[i+2] && (arr[i+1] > arr[i]) && (arr[i+2] > arr[i+1])){
            addArr[i+2] = 1;
        }
    }
}

bool isIncreasing(ll *arr, ll i){
    return arr[i+1] > arr[i]; 
}
bool isDecreasing(ll *arr, ll i){
    return arr[i+1] < arr[i];
}

vector<ll> getIncreasingSizeVector(ll *arr, bool *isBad, ll n){
    vector<ll> increasingSizeVector;
    ll size = 0;

    for(ll i = 0; i < n-1; i++){
        size = 0;
        while(isIncreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            size ++;
            i++;
        }
        if(size > 0){
            i--;
            increasingSizeVector.push_back(size);
        }
    }
    return increasingSizeVector;
}

vector<ll> getDecreasingSizeVector(ll *arr, bool *isBad, ll n){
    vector<ll> decreasingSizeVector;
    ll size = 0;

    for(ll i = 0; i < n-1; i++){
        size = 0;
        while(isDecreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            size ++;
            i++;
        }
        if(size > 0){
            i--;
            decreasingSizeVector.push_back(size);
        }
    }
    return decreasingSizeVector;
}



void getPIandQI(ll *arr,ll *PI,ll *QI, bool *isBad,ll totalIncresingSequences, ll n){
    ll i ,j,k;
    fo(i,n) PI[i] = 0;
    fo(i,n) QI[i] = 0;
    ll copyTis = totalIncresingSequences;
    for(i = 0; i < n-1;i++){
        if(isIncreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            while(isIncreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
                PI[i] = totalIncresingSequences;
                i++;
            }
            i--;
            totalIncresingSequences--;
        }else{
            PI[i] = totalIncresingSequences;
        }
    }
    PI[n-1] = 0;

    totalIncresingSequences = copyTis;
    for(i = 0;i < n-1;i++){
        if(isIncreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            QI[i] = totalIncresingSequences;
            while(isIncreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
                i++;
                QI[i] = totalIncresingSequences-1;
            }
            i--;
            totalIncresingSequences--;
        }else{
            QI[i] = totalIncresingSequences;
        }
    }
    QI[n-1] = 0;
    
}

void getPDandQD(ll *arr,ll *PD,ll *QD, bool *isBad,ll totalDecreasingSequences, ll n){
    ll i ,j,k;
    fo(i,n) PD[i] = 0;
    fo(i,n) QD[i] = 0;
    ll copyTis = totalDecreasingSequences;
    for(i = 0; i < n-1;i++){
        if(isDecreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            while(isDecreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
                PD[i] = totalDecreasingSequences;
                i++;
            }
            i--;
            totalDecreasingSequences--;
        }else{
            PD[i] = totalDecreasingSequences;
        }
    }
    PD[n-1] = 0;

    totalDecreasingSequences = copyTis;
    for(i = 0;i < n-1;i++){
        if(isDecreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
            QD[i] = totalDecreasingSequences;
            while(isDecreasing(arr,i) && !isBad[i] && !isBad[i+1] && i < n-1){
                i++;
                QD[i] = totalDecreasingSequences-1;
            }
            i--;
            totalDecreasingSequences--;
        }else{
            QD[i] = totalDecreasingSequences;
        }
    }
    QD[n-1] = 0;   
}


void getIncreasingDecreasingIndexArray(ll *arr,ll* dpI,ll* dpD,bool* isBad, ll n){  
    //ll dpI[n+2];
    bool isI;

    //ll dpD[n+2];
    bool isD;


    dpI[0] = 0;
    dpD[0] = 0;
    if(arr[1] > arr[0]){
        dpI[1] = 1;
        dpD[1] = 0;
        isI = true;
        isD = false;
    }else if(arr[1] < arr[0]){
        dpI[1] = 0;
        dpD[1] = 1;
        isI = false;
        isD = true;
    }else{
        dpI[1] = 0;
        dpD[1] = 0;
        isI = false;
        isD = false;
    }
    ll i;    
    for(i = 2;i < n;i++){
        if(isBad[i-1]){
            isI = false;
            while(isBad[i-1] && i < n){
                dpI[i] = dpI[i-1];
                i++;
            }
            i--;
        }else if(isBad[i]){
            isI = false;
            while(isBad[i] && i < n){
                dpI[i] = dpI[i-1];
                //cout<<"Ck i : "<<i<<endl;
                i++;
            }
            dpI[i] = dpI[i-1];
            //i++ from for loop
        }else if(arr[i-1] < arr[i]){
            if(isI)dpI[i] = dpI[i-1];
            else {
                dpI[i] = dpI[i-1]+1;
                isI = true;
            }
        }else if(arr[i-1] > arr[i]){
            if(isI){
                isI = false;
                dpI[i] = dpI[i-1];
            }else{
                dpI[i] = dpI[i-1]; 
            }
        }
    }
    
    for(i = 2;i < n;i++){
        if(isBad[i-1]){
            isD = false;
            while(isBad[i-1] && i < n){
                dpD[i] = dpD[i-1];
                i++;
            }
            i--;
        }else if(isBad[i]){
            isD = false;
            while(isBad[i] && i < n){
                dpD[i] = dpD[i-1];
                //cout<<"Ck i : "<<i<<endl;
                i++;
            }
            dpD[i] = dpD[i-1];
            //i++ from for loop
        }else if(arr[i-1] > arr[i]){
            if(isD)dpD[i] = dpD[i-1];
            else {
                dpD[i] = dpD[i-1]+1;
                isD = true;
            }
        }else if(arr[i-1] < arr[i]){
            if(isD){
                isD = false;
                dpD[i] = dpD[i-1];
            }else{
                dpD[i] = dpD[i-1]; 
            }
        }
        /*else{//EQUAL
            dpD[i] = dpD[i-1];
            isD = false;
        }*/
    }
} 

void getRandom(ll* arr,ll n){
    ll i;
    fo(i,n)arr[i] = rand()%(7);
}

int main(){
    ll n,q;
    cin>>n>>q;
    ll i;
    ll arr[n],dpI[n],dpD[n],pAdd[n],qAdd[n];
    ll PI[n],QI[n],PD[n],QD[n];
    bool isBad[n];
    
    fo(i,n)cin>>arr[i];
    
    //DEBUG
    //srand(time(NULL));
    //getRandom(arr,n);
    getBadArray(arr,isBad,n);
    getStartPossibleArray(arr,pAdd,isBad,n);
    getEndPossibleArray(arr,qAdd,isBad,n);
    getIncreasingDecreasingIndexArray(arr,dpI,dpD,isBad,n);
    vector<ll> increasingSizeVector = getIncreasingSizeVector(arr,isBad,n);
    vector<ll> decreasingSizeVector = getDecreasingSizeVector(arr,isBad,n);
    getPIandQI(arr,PI,QI,isBad,increasingSizeVector.size(),n);
    getPDandQD(arr,PD,QD,isBad,decreasingSizeVector.size(),n);
/*
    cout<<"Start pos "<<endl;
    printArr(pAdd,n);

    cout<<"End pos"<<endl;
    printArr(qAdd,n);

    cout<<"PI : ";
    printArr(PI,n);

    cout<<"QI : ";
    printArr(QI,n);
     
    cout<<"PD : ";
    printArr(PD,n);

    cout<<"QD : ";
    printArr(QD,n);
*/


/*
    printArr(arr,n);
    printArr(dpI,n);
    printArr(pAdd,n);
    printArr(qAdd,n);
*/    
    fo(i,q){
        ll l,r;
        cin>>l>>r;
        l--;r--;
        
        if(l-r == 1){
            if(arr[l] == arr[r])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;

            continue;
        }

        ll lhs = PI[l] - QI[r];
        ll rhs = PD[l] - QD[r];
        //cout<<lhs<<" : "<<rhs<<endl;
        
        if(isBad[l] && arr[l+1] > arr[l] && arr[i+2] < arr[i+1])lhs++;
        if(isBad[r] && arr[r-1] < arr[r] && arr[r-2] > arr[r-1])lhs++;
        
        if(isBad[l] && arr[l+1] < arr[l] && arr[l+2] > arr[l+1])rhs++;
        if(isBad[r] && arr[r-1] > arr[r] && arr[r-2] < arr[r-1])rhs++;

        if(lhs == rhs)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

/*
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    //Dont forget to use 
    //map , vector, list
    //log ,gcd,lcm
    ll n,q;
    cin>>n>>q;
    ll arr[n];
    ll i,j,k;
    fo(i,n)cin>>arr[i];
    
    ll dpI[n+2];
    bool isI;

    ll dpD[n+2];
    bool isD;


    dpI[0] = 0;
    dpD[0] = 0;
    if(arr[1] > arr[0]){
        dpI[1] = 1;
        dpD[1] = 0;
        isI = true;
        isD = false;

    }else if(arr[1] < arr[0]){
        dpI[1] = 0;
        dpD[1] = 1;
        isI = false;
        isD = true;
    }else{
        dpI[1] = 0;
        dpD[1] = 0;
        isI = false;
        isD = false;
    }

    bool isBad[n] = {false};

    for(ll i = 0; i < n-1;i++){
        if(arr[i] == arr[i+1]){
            isBad[i] = true;
            isBad[i+1] = true;
        }
    }
    
    for(i = 2;i < n;i++){
        if(isBad[i-1]){
            isI = false;
            while(isBad[i-1] && i < n){
                dpI[i] = dpI[i-1];
                i++;
            }
            i--;
        }else if(isBad[i]){
            isI = false;
            while(isBad[i] && i < n){
                dpI[i] = dpI[i-1];
                //cout<<"Ck i : "<<i<<endl;
                i++;
            }
            dpI[i] = dpI[i-1];
            //i++ from for loop
        }else if(arr[i-1] < arr[i]){
            if(isI)dpI[i] = dpI[i-1];
            else {
                dpI[i] = dpI[i-1]+1;
                isI = true;
            }
        }else if(arr[i-1] > arr[i]){
            if(isI){
                isI = false;
                dpI[i] = dpI[i-1];
            }else{
                dpI[i] = dpI[i-1]; 
            }
        }
    }
    
    for(i = 2;i < n;i++){
        if(isBad[i-1]){
            isD = false;
            while(isBad[i-1] && i < n){
                dpD[i] = dpD[i-1];
                i++;
            }
            i--;
        }else if(isBad[i]){
            isD = false;
            while(isBad[i] && i < n){
                dpD[i] = dpD[i-1];
                //cout<<"Ck i : "<<i<<endl;
                i++;
            }
            dpD[i] = dpD[i-1];
            //i++ from for loop
        }else if(arr[i-1] > arr[i]){
            if(isD)dpD[i] = dpD[i-1];
            else {
                dpD[i] = dpD[i-1]+1;
                isD = true;
            }
        }else if(arr[i-1] < arr[i]){
            if(isD){
                isD = false;
                dpD[i] = dpD[i-1];
            }else{
                dpD[i] = dpD[i-1]; 
            }
        }
        else{//EQUAL
            dpD[i] = dpD[i-1];
            isD = false;
        }
    }

    ******* GFG **********
    ll len = 1;
    ll cnt = 0;
    for (int i=0; i < n-1; ++i)
    {
        // If arr[i+1] is greater than arr[i],
        // then increment length
        if (arr[i + 1] > arr[i]){
            len++;
        }
        // Else Update count and reset length
        else
        {
            cnt += (((len - 1) * len) / 2);
            len = 1;
        }

        dpI[i] = cnt;
    }

    
    dpI[n-1] = len > 1 ? cnt + (((len - 1)*len)/2) : cnt;
    

    cout<<"dpI : ";
    fo(i,n)cout<<dpI[i]<<" ";
    cout<<endl;
 
    cout<<"dpD : ";
    fo(i,n)cout<<dpD[i]<<" ";
    cout<<endl;
   
    fo(i,q){
        ll l,r;
        cin>>l>>r;
        l = l - 1;
        r = r - 1;
        
        //watch(l);
        //watch(r);

        if((dpI[r] - dpI[l]) == (dpD[r] - dpD[l])){
            cout<<"YES"<<endl;
        }
        else{ 
            cout<<"NO"<<endl;
        }
    }
    
    //▬▬ι═══════>
    return 0;
}
*/

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

