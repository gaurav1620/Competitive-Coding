#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i = 0;i < n;i++)cin>>a[i];
	for(int i = 0;i < m;i++)cin>>b[i];

	int d[n];
	int cp = 0;
	map<int ,int>Map;
	for(int i = n-1;i > -1;i--){
		auto aut = Map.find(a[i]);
		if(aut == Map.end()){
			cp++;
			Map.insert(pair<int ,int >(a[i],a[i]));
		}else{
			
		}
//		cout<<"d["<<i<<"] is "<<cp<<endl;
		d[i] = cp;
	}
	for(int i = 0;i < m;i++)cout<<d[b[i]-1]<<endl;
	//END
	return 0;
}
