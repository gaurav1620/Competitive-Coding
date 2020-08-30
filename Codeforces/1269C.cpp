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
    ll n,k;cin>>n>>k;
    string s = to_string(n);
    ll len = s.length();

    bool done = false;
    ll ind  = -1;
    for(i = 0;i < len-k;i++){
        if(s[i] == s[i+k]){
            continue;
        }else if(s[i] < s[i+k]){
            
            ll carry = 1;
            ll indd = i+k-1;
            s[i+k] = s[i];
            while(carry && ind >= 0){
                if(s[indd] != '9'){
                    s[indd]++;
                    break;
                }else{
                    if(indd - k < 0){s[indd] = '0';}
                    //INcomplete ?? !!!!
                }

            }

            done = 1;
            break;
        }else{
            
            s[i+k] = s[i];

            for(j = i;j < len-k;j++){
                s[j+k] = s[j];
            }
            done = 1;
            cout<<s<<endl;            
            break;
        }
    }

    //▬▬ι═══════>
    return 0;
}

