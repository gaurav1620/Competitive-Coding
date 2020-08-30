#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int n,m;
	cin>>n>>m;
	
	map<string ,string>Map;
	for(int i = 0; i < m;i++){
		char a[11],b[11];
		cin>>a>>b;
		if(strlen(a) > strlen(b))Map.insert(pair<string ,string>(a,b));
		else Map.insert(pair<string ,string>(b,a));
		
	}
	for(int i =0;i < n;i++){
		char s[11];
		cin>>s;
		auto aut = Map.find(s);
		if(aut == Map.end())cout<<s<<" ";
		else cout<< aut->second<<" " ;
	}
	cout<<endl;
	//END
	return 0;
}
