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

//M????U
//U???M
//   M??U    U??M
//   M???U
//
int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        string s;
        cin>>s;

        ll i = 0;
        bool ans = false;

        while(i < s.length()){
            if(s[i] == 'M'){
                i++;
                while(i < s.length() && (s[i]=='M' || s[i] == '?')){
                    i++;
                }
                if(i < s.length())ans = true;

            }else if(s[i] == 'U'){
                while(i < s.length() && (s[i]=='U' || s[i] == '?')){
                    i++;
                }
            }else{
                i++;
            }
        }
        if(ans )cout<<"Yes\n";
        else cout<<"No\n";

    }
    
    //▬▬ι═══════>
    return 0;
}
