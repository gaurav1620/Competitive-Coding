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

#define mod 1000000007

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
   // ios::sync_with_stdio(false);
    //cin.tie(NULL);
	ll n;
	cin>>n;
	list<ll> in;
	list<ll> out;
	map<ll,ll> m;
	for(ll i = 0;i < n;i++){
		ll tmp;
		cin>>tmp;
		in.push_back(tmp);
		m.insert(pair<ll,ll>(tmp,tmp));
	}
	//cout<<"Check 1\n";
	for(ll i = 0;i < n;i++){
		ll tmp;cin>>tmp;
		out.push_back(tmp);
	}
	//cout<<"check 2\n";
	ll ct = 0;
	while(!in.empty()&& !out.empty()){
		//cout<<"First While : \n";
		if(m.find(in.front()) != m.end()){
			//cout<<"\tIn IF : \n";
			while(in.front() != out.front() ){
				//cout<<"\t\tSecond while popping : "<<out.front()<< "\n";
				ll ttt = out.front();	
				m.erase(ttt);
				out.pop_front();
				ct++;
			}
			ll tt = in.front();
			//cout<<"IF popping : "<<tt<<endl;
			in.pop_front();
			m.erase(tt);
			out.pop_front();
		}else{
			//cout<<"\tElse popping :"<<in.front()<<" \n";
			ll tt = in.front();
			in.pop_front();
			m.erase(tt);
		}
	}
	ct+= out.size();
	cout<<ct<<endl;

	
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
