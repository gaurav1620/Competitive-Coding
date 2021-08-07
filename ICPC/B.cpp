#include<bits/stdc++.h>
#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)      for(i = 0;i < n;i++)
#define ll long long
#define watch(x) cerr << (#x)<< " is : " << (x) << endl
//Removes cerr on judging platforms
#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif 

using namespace std;
ll testCases;


//    1,3,5,7
//    2,8,32, 128
int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        ll n,k;
        cin>>n>>k; 
        
        int ans = 0;

        while(n){
            if(n <= k){
                n = 0;
                ans ++;
            }
            if(n < 2)break;
            ll ap = log2(n);
            if(ap%2 == 0)ap--;
            n -= pow(2,ap);
            //watch(n);
            //watch(ap);
            //watch(pow(2,ap));
            //cout<<"\n\n";
            ans++;
            /*
            if(n <= k || n < 2)break;
            ll ap = log2(n);
            if(!ap&1)ap--;
            ap = min(mx, ap);
            mx = ap;
            mx -= 2;
            n -= pow(2,ap);
            ans ++;
            if(mx < 0)break;
            */
        }
        if(n == 0)cout<<ans<<endl;
        else cout<<-1<<endl;

    }
    
    //▬▬ι═══════>
    return 0;
}
