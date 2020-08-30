#include<bits/stdc++.h>

//Gaurav Khairnar 2020
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;
int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        ll i,j,m;

        ll arr[n];
        fo(i,n)cin>>arr[i];

        bool isPeak[n];
        fo(i,n)isPeak[i] = false;

        for(i = 1;i < n-1;i++){
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i]){
                isPeak[i] = true;
            }
        }
        
        ll curParts = 1;
        ll startInd = 0;
        ll maxParts = 1;

        for(i = 1;i<k-1;i++){
            if(isPeak[i])curParts++;
        }

        maxParts = curParts;

        i = 2;
        j = k-1;

        while(j < n-1){
            if(isPeak[i-1])curParts--;
            if(isPeak[j])curParts++;

            if(curParts  > maxParts){
                maxParts = curParts;
                startInd = i-1;
                
            }

            
            i++;
            j++;
        }

        cout<<maxParts<<" "<<startInd+1<<endl;
    }
    //▬▬ι═══════>
    return 0;
}

