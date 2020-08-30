#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
using namespace std;

int main(){
	//START
    int n,i;
    cin>>n;
    string s;
    cin>>s;
    map<string ,int>Map;
    fo(i,n-1){
        string ss(s,i,2);
        auto it = Map.find(ss);
        if(it == Map.end()){
//            cout<<"Inserting : "<<ss<<" "<<0<<endl;
            Map.insert(pair<string ,int>(ss,0));
        }else{
//            cout<<"Increasing : "<<it->first<<"  "<<it->second+1<<endl;
            it->second++;
        }
    }
    int maxI = Map.begin()->second;
    string maxS = Map.begin()->first;
    for(auto it = Map.begin();it != Map.end();it++){
//        cout<<it->first<<"  "<<it->second<<endl;
        if(maxI < it->second){
            maxI = it->second;
            maxS = it->first;
        }
    }

    cout<<maxS<<endl;
    

	//END
	return 0;
}
