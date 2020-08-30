#include<bits/stdc++.h>

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl

using namespace std;
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
        return true; 
    if (n2 > n1) 
        return false; 
  
    for (int i=0; i<n1; i++) 
    { 
        if (str1[i] < str2[i]) 
            return true; 
        else if (str1[i] > str2[i]) 
            return false; 
    } 
    return false; 
} 
  
// Function for finding difference of larger numbers 
string findDiff(string str1, string str2) { 
    if (isSmaller(str1, str2))swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
    int carry = 0; 
    for (int i=n2-1; i>=0; i--) { 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - carry); 
        if (sub < 0){ sub = sub+10;carry = 1;} 
        else carry = 0; 
        str.push_back(sub + '0'); 
    } 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
    } 
    reverse(str.begin(), str.end()); 
    return str; 
} 

ll findTillNow(string s){
    if(s == "0"){return 0;}
    if(s.length() == 1){return s[0]-'0';}
    if(s.length() == 2){
        ll num = (s[0]-'0')*10 + (s[1]-'0');
        return (ll)num/11 + 9;
    }else{
        if(s[s.length()-1] < s[0]){
            //eg 64755
            ll sub = 10-(s[s.length()-1]-'0')-(10-(s[0]-'0'));
            s = findDiff(to_string(sub),s);
            //new s = 64746
            //cout<<"NEW S : "<<s<<endl;
        }else{
            s[s.length()-1] = s[0];
        }
        


        ll ans = 0;
        if(s.length() <= 2){return findTillNow(s);}
        
        //1 tp 99
        ans += 18;
        //if(s.length() > 3)ans += pow(10,s.length()-2);

        // 64746
        ll ct = 1;

        watch(s);
        ll locans = 0;


        for(ll i = s.length()-2;i >= 1;i--){
            locans += (s[i]-'0')*(ct);
            ct *=10;
        }

        // 64746
        //locans is 476
        locans++;
        ans += (s[0]-'0')*locans;
        //ans++;
        watch(locans);
        watch(ans);
        
        //

        ans += 9*pow(10,s.length()-3); 
        //if(s == "999"){return 108;}
        /*
        if(s[0] != '1'){
            ans += ((s[0]-'0')-1)*pow(10,s.length()-1);
        }
        */
        return ans;
    }
}

int main(){
///*
    while(1){
        string sss;cin>>sss;
        cout<<findTillNow(sss)<<endl;
    }
//*/
    Ninja
    //▬▬ι═══════>
    ll i,j,k;
    ll a,b;
    string sa,sb;

    cin>>a>>b;
    a--;
    sa = to_string(a);
    sb = to_string(b);

    //watch(sa);
    //watch(sb);


    //cout<<findTillNow(sa)<<endl;
    //cout<<findTillNow(sb)<<endl;
    ll ans = findTillNow(sb) - findTillNow(sa);
    
    cout<<ans<<endl;

    //▬▬ι═══════>
    return 0;
}

