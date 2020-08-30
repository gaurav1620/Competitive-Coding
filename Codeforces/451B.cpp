#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
using namespace std;

int main(){
	//START
	int n,i;
	cin>>n;
	int beg = -1,end = -1,arr[n];
	fo(i,n){
		cin>>arr[i];
		if(i!=0){
			if(arr[i-1] > arr[i]){
				if(beg == -1) {
					beg = i-1;
					end = i;
				}else if(end == i-1) end++;
				else{
					cout<<"no"<<endl;return 0;
				}
			}
			else{
				
			}			
		}
		
	}
	//for(int i = 0;i < n;i++)cout<<arr[i]<<" | ";
	//cout<<endl;
	
	int Cbeg = beg,Cend = end;	
	while(Cend > Cbeg){
		int ff = arr[Cend];
		arr[Cend] = arr[Cbeg];
		arr[Cbeg] = ff;
		Cend--;Cbeg++;
	}
	
	//for(int i = 0;i < n;i++)cout<<arr[i]<<" | ";
	//cout<<endl;

	int tmpn = sizeof(arr)/sizeof(arr[0]);
	//sort(arr + beg*sizeof(arr[0]),arr+(end+1)*sizeof(arr[0]));
	if(is_sorted(arr,arr+tmpn) && beg != -1){
		cout<<"yes"<<endl<<beg+1<<" "<<end+1<<endl;
	}else{
		if(beg == -1)cout<<"yes"<<endl<<1<<" "<<1<<endl;
		else cout<<"no"<<endl;
	}
	//END
	return 0;
}
