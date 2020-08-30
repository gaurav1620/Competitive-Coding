#include<bits/stdc++.h>

//Gaurav Khairnar 2019
//codechef,codeforces : gaurav1620
//email : gauravak007@gmail.com

#define fo(i,n)   for(i = 0;i < n;i++)
#define rfo(i,n)  for(i = n-1; n >= 0;i++0)
#define ll long long
using namespace std;
//ll abss(ll x){return x<0?x*-1:x;}
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

string abss(string a,string b){
    if(a > b){
        return findDiff(a,b);
    }
    return findDiff(b,a);
}

bool isSmaller(string str1, string str2);
string findSum(string str1, string str2);
string findDiff(string str1, string str2) ;

string arr[50005];

string getDisorder(ll n){
    string ans;
    for(ll i = 0;i < n-1;i++){
        ans = findSum(abss(arr[i],arr[i+1]),ans);
    }
    return ans;
}

string getabssDiff(ll a,ll b){
    return abss(arr[a],arr[b]);
}

string ifChanged(ll i,ll j,ll n){
    //to put val of arr[j] in arr[i];

    if (n < 3){
        return 0;
    }

    if(i == 0){
        if(j == 1){
            ll prevv = getabssDiff(1,2);
            return getabssDiff(0,2) - prevv; 
        }else{
            ll prevv = getabssDiff(0,1);
            ll neww = getabssDiff(j,1);
            if(j == n-1){
                prevv += getabssDiff(n-1,n-2);
                neww += getabssDiff(0,n-2);
            }else{
                prevv += getabssDiff(j,j+1);
                prevv += getabssDiff(j,j-1);
                neww += getabssDiff(i,j+1);
                neww += getabssDiff(i,j-1);
            }
            return neww - prevv;
        }

    }else if(i == n-1){
        if(j == 0){
            ll prevv = getabssDiff(0,1) + getabssDiff(n-1,n-2);
            ll neww = getabssDiff(1,j)+getabssDiff(n-2,0);
            return neww - prevv;
        }else if(j == n-2){
            ll prevv = getabssDiff(n-2,n-3);
            ll neww = getabssDiff(n-1,n-3);
            return neww - prevv;
        }else{
            ll prevv = getabssDiff(n-1,n-2);
            ll neww = getabssDiff(j,n-2);
            prevv += getabssDiff(j-1,j);
            prevv += getabssDiff(j+1,j);
            neww += getabssDiff(j-1,n-1);
            neww+= getabssDiff(j+1,n-1);
            return neww - prevv;
        }
    }else if(abss(i-j) == 1){
        
        if(j == 0){
            return getabssDiff(2,1) - getabssDiff(2,0);
        }else if(j == n-1){
            return getabssDiff(n-3,n-2) - getabssDiff(n-1,n-3);
        }
        else{
            if(i > j){
                ll prevv = getabssDiff(i+1,i);
                prevv += getabssDiff(j-1,j);
                ll neww = getabssDiff(i+1,j);
                neww += getabssDiff(i,j-1);
                return neww - prevv;
            }else{
                ll prevv = getabssDiff(j+1,j);
                prevv += getabssDiff(i-1,i);
                ll neww = getabssDiff(j+1,i);
                neww += getabssDiff(j,i-1);
                return neww - prevv;
            }
        }
    }else{

        if(j == 0){
            ll prevv = getabssDiff(0,1);
            ll neww = getabssDiff(i,1);
            prevv += getabssDiff(i,i+1);
            prevv += getabssDiff(i,i-1);
            neww += getabssDiff(j,i+1);
            neww += getabssDiff(j,i-1);
            return neww - prevv;
        }else if(j == n-1){
            ll prevv = getabssDiff(n-1,n-2);
            ll neww = getabssDiff(n-2,i);
            prevv += getabssDiff(i-1,i);
            prevv += getabssDiff(i+1,i);
            neww += getabssDiff(j,i-1);
            neww += getabssDiff(j,i+1);
            return neww - prevv;
        }else{

            ll prevv = getabssDiff(i,i-1) + getabssDiff(i,i-1)
                        + getabssDiff(j,j-1)+getabssDiff(j,j+1);
            ll neww = getabssDiff(j,i-1)+getabssDiff(j,i+1)
                        +getabssDiff(i,j-1)+getabssDiff(i,j+1);
            return neww - prevv;
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //▬▬ι═══════>
    ll n;cin>>n;
    ll i,j,k;
    fo(i,n)cin>>arr[i];
    ll disorder = getDisorder(n);
    for(i = 0;i < n;i++){
        ll minn = disorder;
        for(j = 0;j < n;j++){
            if(j!=i){
                ll a = ifChanged(i,j,n);
                ll b =0;// ifChanged(j,i,n);
                minn = min(minn,disorder+a+b);
            }
        }
        cout<<minn<<endl;
    }

    //▬▬ι═══════>
    return 0;
}

string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
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
string findDiff(string str1, string str2)
{
    //DEBUGGGG
    //
    swap(str1,str2);
    //
    //
    // Before proceeding further, make sure str1
    // is not smaller
    if (isSmaller(str1, str2))
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n2-1; i>=0; i--)
    {
        // Do school mathematics, compute difference of
        // current digits and carry
        int sub = ((str1[i+diff]-'0') -
                   (str2[i]-'0') -
                   carry);
        if (sub < 0)
        {
            sub = sub+10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of str1[]
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

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
