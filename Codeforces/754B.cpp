/*****************************************************************************i
  / __| __ _ _  _ _ _ __ ___ __ | |/ / |_  __ _(_)_ _ _ _  __ _ _ _ 
 | (_ -/ _` | || | '_/ _` \ V / | ' <| ' \/ _` | | '_| ' \/ _` | '_|
  \___|\__,_|\_,_|_| \__,_|\_/  |_|\_\_||_\__,_|_|_| |_||_\__,_|_| 
  ******************************************************************************
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

//Debugging
#define watch(x) cout << (#x) << " is : " << (x) << endl

//Fast functions
template<class T>inline T       min(T a,T b)        { return a<b?a:b; }
template<class T>inline T       max(T a,T b)        { return a>b?a:b; }
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
/*
	 _ _ _ _
	|_|_|_|_|
	|_|_|_|_|
	|_|_|_|_|
	|_|_|_|_|
*/
	char arr[4][4];
	int i,j;
	fo(i,4)fo(j,4)cin>>arr[i][j];
	
	fo(i,4){
		fo(j,2){
			if(arr[i][j] == 'x' && arr[i][j+1] == 'x' && arr[i][j+2] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[i][j] == '.' && arr[i][j+1] == 'x' && arr[i][j+2] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[i][j] == 'x' && arr[i][j+1] == '.' && arr[i][j+2] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[i][j] == 'x' && arr[i][j+1] == 'x' && arr[i][j+2] == '.'){cout<<"YES"<<endl;return 0;}

			if(arr[j][i] == 'x' && arr[j+1][i] == 'x' && arr[j+2][i] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[j][i] == '.' && arr[j+1][i] == 'x' && arr[j+2][i] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[j][i] == 'x' && arr[j+1][i] == '.' && arr[j+2][i] == 'x'){cout<<"YES"<<endl;return 0;}
			if(arr[j][i] == 'x' && arr[j+1][i] == 'x' && arr[j+2][i] == '.'){cout<<"YES"<<endl;return 0;}
		}		
	}
	
	if(arr[0][1] == 'x' && arr[1][2] == 'x' && arr[2][3] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][1] == 'x' && arr[1][2] == 'x' && arr[2][3] == '.'){cout<<"YES"<<endl;return 0;}
	if(arr[0][1] == 'x' && arr[1][2] == '.' && arr[2][3] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][1] == '.' && arr[1][2] == 'x' && arr[2][3] == 'x'){cout<<"YES"<<endl;return 0;}

	if(arr[1][0] == 'x' && arr[2][1] == 'x' && arr[3][2] == 'x'){cout<<"YES"<<endl;return 0;}	
	if(arr[1][0] == 'x' && arr[2][1] == 'x' && arr[3][2] == '.'){cout<<"YES"<<endl;return 0;}
	if(arr[1][0] == 'x' && arr[2][1] == '.' && arr[3][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][0] == '.' && arr[2][1] == 'x' && arr[3][2] == 'x'){cout<<"YES"<<endl;return 0;}
	
	if(arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][0] == 'x' && arr[1][1] == 'x' && arr[2][2] == '.'){cout<<"YES"<<endl;return 0;}
	if(arr[0][0] == 'x' && arr[1][1] == '.' && arr[2][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][0] == '.' && arr[1][1] == 'x' && arr[2][2] == 'x'){cout<<"YES"<<endl;return 0;}

	if(arr[1][1] == 'x' && arr[2][2] == 'x' && arr[3][3] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][1] == 'x' && arr[2][2] == 'x' && arr[3][3] == '.'){cout<<"YES"<<endl;return 0;}
	if(arr[1][1] == 'x' && arr[2][2] == '.' && arr[3][3] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][1] == '.' && arr[2][2] == 'x' && arr[3][3] == 'x'){cout<<"YES"<<endl;return 0;}


	if(arr[3][0] == 'x' && arr[2][1] == 'x' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[3][0] == '.' && arr[2][1] == 'x' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[3][0] == 'x' && arr[2][1] == '.' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[3][0] == 'x' && arr[2][1] == 'x' && arr[1][2] == '.'){cout<<"YES"<<endl;return 0;}

	if(arr[0][3] == 'x' && arr[2][1] == 'x' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][3] == '.' && arr[2][1] == 'x' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][3] == 'x' && arr[2][1] == '.' && arr[1][2] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][3] == 'x' && arr[2][1] == 'x' && arr[1][2] == '.'){cout<<"YES"<<endl;return 0;}

	if(arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][2] == '.' && arr[1][1] == 'x' && arr[2][0] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][2] == 'x' && arr[1][1] == '.' && arr[2][0] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[0][2] == 'x' && arr[1][1] == 'x' && arr[2][0] == '.'){cout<<"YES"<<endl;return 0;}

	if(arr[1][3] == 'x' && arr[2][2] == 'x' && arr[3][1] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][3] == '.' && arr[2][2] == 'x' && arr[3][1] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][3] == 'x' && arr[2][2] == '.' && arr[3][1] == 'x'){cout<<"YES"<<endl;return 0;}
	if(arr[1][3] == 'x' && arr[2][2] == 'x' && arr[3][1] == '.'){cout<<"YES"<<endl;return 0;}


	cout<<"NO"<<endl;
    
    //▬▬ι═══════>
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
