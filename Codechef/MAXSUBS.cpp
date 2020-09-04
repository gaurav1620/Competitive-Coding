#include<bits/stdc++.h> 
using namespace std; 
  
#define INT_BITS 32 
#define fo(i,n) for(i = 0;i < n;i++)
int maxSubarrayXOR(int arr[], int n) { 
    int ind = 0; 
    int one = 1;
    int zero = 0;

    for (int i = INT_BITS-one; i >= 0; i--){ 
        int maxEle = INT_MIN; 
        int maxInd = ind; 

        for (int j = ind; j < n; j++){ 
            if ( (arr[j] & (one << i)) != 0  
                     && arr[j] > maxEle ) 
                maxEle = arr[j], maxInd = j; 
        } 
        
        if (maxEle != INT_MIN){

        }
        else continue; 
        int temp = arr[ind];
        arr[ind ] = arr[maxInd];
        arr[maxInd] = temp;
        
        maxInd = ind; 
        for (int j=0; j<n; j++) { 
            if (j == maxInd){
            } else{
               if(arr[j] & (one << i) != 0)
                    arr[j] = arr[maxInd] ^ arr[j]; 
            }
        }
        ind = ind+one; 
    } 
  
    int res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= arr[i]; 
    return res; 
} 
int main() {
    int n;
    cin>>n;
    int arr[n];
    int i,j,k;
    fo(i,n)cin>>arr[i];
    cout << maxSubarrayXOR(arr, n)<<endl; 
    return 0; 
} 

