#include<bits/stdc++.h>
using namespace std;

long long binarySearchCount(long long arr[], long long n, long long key) 
{ 
    long long left = 0, right = n; 
  
    long long mid; 

    while (left < right) { 
        mid = (right + left) >> 1; 
  
        // Check if key is present in array 
        if (arr[mid] == key) { 
            // If duplicates are present it returns 
            // the position of last element 
            while (mid + 1 < n && arr[mid + 1] == key) 
                mid++; 
            break; 
        } 
  
        // If key is smaller, ignore right half 
        else if (arr[mid] > key) 
            right = mid; 
  
        // If key is greater, ignore left half 
        else
            left = mid + 1; 
    } 
  
    // If key is not found in array then it will be 
    // before mid 
    while (mid > -1 && arr[mid] > key) 
        mid--; 
  
    // Return mid + 1 because of 0-based indexing 
    // of array 
    return mid + 1; 
} 

int main(){
	//START
	long long n;
	cin>>n;
	long long arr[n];
	for(int i = 0;i < n; i++)cin>>arr[i];
	long long  tempN = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+tempN);
	//3 6 8 10 11
	
	long long  test;
	cin>>test;

	map<long, long>Map;
	while(test--){
		long long q;
		cin>>q;
		auto pt = Map.find(q);
	if(pt != Map.end())cout<<pt->second<<endl;
	else{
		if(q < arr[0]){cout<<0<<endl;Map.insert(pair<float ,float>(q,0));}
		else if(q >= arr[n-1]){cout<<n<<endl;Map.insert(pair<float ,float>(q,n));}
		else if(q == arr[0] && q!=arr[1]){cout<<1<<endl;Map.insert(pair<float ,float>(q,1));}
		else{
			int mam = binarySearchCount(arr, n, q);
			cout<<mam<<endl; 
			Map.insert(pair<float ,float>(q,mam));
			//long long  l = 0,r = n-1,mid = (n-1)/2,ct = 0;
			/*while(1){
//				cout<<"Check"<<endl;
				if(l < r){
					if(arr[mid] < q){
						if(arr[mid+1] == q){
							cout<<mid+2<<endl;
							break;
						}else if(arr[mid+1] > q){cout<<mid+1<<endl;break;}
						else{
							l = mid;
							mid = (l+r)/2;
						}
					}
					else if(arr[mid] > q){
						if(arr[mid-1] == q){
							cout<<mid<<endl;
							break;
						}else if(arr[mid-1] < q){cout<<mid<<endl;break;}
						else{
							r = mid;
							mid = (l+r)/2;					
						}
					}else{
						cout<<mid+1<<endl;
						break;
					}
				}else if(l == r)cout<<l+1<<endl;
				else {
					cout<<0<<endl;break;
				}
			}*/
		}}
	}
	//END
	return 0;
}
