#include<bits/stdc++.h>

const profile = "www.codechef.com/users/gaurav_1620"

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
        string s;
        cin>>s;
        ll hasonly0 = true;
        ll hasonly1 = true;
        ll i,j,k;

        fo(i,s.length()){
            if(s[i] == '0'){
                hasonly1 = false;
            }else{
                hasonly0 = false;
            }
        }

        if(hasonly0 || hasonly1){
            cout<<s<<endl;
        }else{
            bool flag = true;

            for(i = 0;i < s.length()-1;i++){
                if(s[i] == s[i+1]){
                    if(s[i] == '0'){
                        cout<<"01";
                    }else{
                        cout<<"10";
                    }
                }else{
                    cout<<s[i];
                }
            }

            cout<<s[s.length()-1]<<endl;

        }

    }
    //▬▬ι═══════>
    return 0;
}

