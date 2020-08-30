#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
ll abs(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

// function to convert decimal to binary 
void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

string toBinAndAddone(string s){
    string ans;
    while(s.length() > 0){
        int n = s[s.length()-1] - '0';
        if(n&1){
            ans = '1'+ans;
        }else{
            ans = '0'+ans;
        }

        bool carry = false;
        string newS;
        for(ll i = 0;i<s.length();i++){
            if(carry){
                int x = (s[i]-'0')+10;
                x/=2;
                char c = x+'0';
                newS = newS + c;
            }else{
                int x = (s[i]-'0')/2;
                char c = x+'0';
                newS = newS+c;
            }

            int xx = s[i]-'0';
            if(xx&1)carry = true;
            else carry = false;
        }
        if(newS[0] == '0')s = newS.substr(1,newS.length()-1);
        else s = newS;
    }
    
    bool noZero = true;
    for(ll i = 0;i<ans.length();i++){
        if(ans[i] == '0'){noZero = false;break;}
    }

    if(noZero){
        for(ll i = 0;i<ans.length();i++){
            ans[i] = '0';
        }
        ans = '1'+ans;
    }else{
        ll i = 0;
        while(ans[ans.length()-1-i] != '0'){
            ans[ans.length()-1-i] = '0';
            i++;
        }
        ans[ans.length()-1-i] = '1';
    }
    return ans;
}


int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        string bin = toBinAndAddone(s);
        
        if(s == "1"){
            cout<<"5"<<endl;
        }else if(s == "2"){
            cout<<"6"<<endl;
        }else{
            for(ll i = 1;i<bin.length();i++){
                if(bin[i] == '0')cout<<'5';
                else cout<<'6';
            }
            cout<<endl;
        }
        
    
    }
    //▬▬ι═══════>
    return 0;
}

