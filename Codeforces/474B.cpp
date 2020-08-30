#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	long n,m;
	cin>>n;
	long f = 0;

	map<long, long> Map;

	int ck = 0;
	for(long i = 0;i < n;i++){
		f++;
		long tmp;
		cin>>tmp;
		for(long j = 0; j < tmp ;j++){
			++ck;
			Map.insert(pair<float , float>(ck,f));
		}
	}

	cin>>m;
	for(int i = 0;i < m;i++){
		int qr;
		cin>>qr;
		auto gau = Map.find(qr);
		cout<< gau->second<<endl;;

	}
	//END
	return 0;
}
