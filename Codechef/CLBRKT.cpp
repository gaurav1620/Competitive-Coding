#include<bits/stdc++.h>
/*  author     : Gaurav Khairnar
    codechef   : gaurav_1620
    codeforces : gaurav1620
    email      : gauravak007@gmail.com
    Linkedin    : https://www.linkedin.com/in/gaurav-khairnar-393100171/
    Github     : www.github.com/gaurav1620

    $ Dont compare yourself with anyone in this world.
      If you do so, you are insulting youreself.
*/

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
int main(){
    Ninja
    //▬▬ι═══════>
    
    testCases = 1;
    cin>>testCases; 
    while(testCases--){
        //roll
        ll n;
        string s;cin>>s;
        n = s.length();

        ll i,j,k;
        ll dp[n+2];
        ll oc,cc;
        oc = cc = 0;
        
        memset(dp,-1,sizeof(dp));
       
        ll ind = n-1;
        stack<ll> st;

        while(ind >= 0 && s[ind] == '('){
            dp[ind--] = -1;
        }
        
        // now were at (
        ll ne = -1;
        while(ind >= 0){
            if(s[ind] == ')'){
                dp[ind] = ne;
                st.push(ind);
                ind--;
            }else{
                ne = i;
                if(st.size()){
                    dp[ind] = st.top();
                    ne = st.top();
                    st.pop();
                    ind--;
                }else{
                    dp[ind--] = -1;
                }
            }
        }
        //fo(i,n)cout<<dp[i]<<" ";
        //cout<<endl;
        ll q;
        cin>>q;
        while(q--){
            ll x;cin>>x;
            if(dp[x-1] == -1)cout<<-1<<endl;
            else cout<<dp[x-1]+1<<endl;
        }
        ////OOOOOOOOOOOOOOO
/*
        stack<ll> oind;
        ll pts = 0;
        
        ll nexC[n];
        ll ind = n-1;
        
        while(ind >= 0 && s[ind] == ')' ){
            nexC[ind] = -1;
            ind--;
        }   
        ll cunexInd = ind;
        
        memset(nexC,-1,sizeof(nexC));

        while(ind >= 0){
            if(s[ind] == ')'){
                nexC[ind] = cunexInd;
            }else{
                cunexInd = ind;
            }
            ind--;
        } 

        for(i = 0;i < n;i++){
            pts++;

            oc += s[i] == '(';
            cc += s[i] == ')';

            if(s[i] == ')'){
                dp[i] = -1;
                if(oind.size()){
                    ll hh = oind.top();
                    dp[hh] = i;
                    //
                    hh--;
                    while(hh >= 0 && s[hh] == ')'){
                        pts++;
                        dp[hh--] = i;
                    }
                    //
                    oind.pop();
                }
            }else{
                oind.push(i);
            }
        }
        

        ll q;
        cin>>q;
        
        while(q--){
            ll x;
            cin>>x;
            if(s[x-1] == ')'){
                x = nexC[x-1];
                if(dp[x] != -1)cout<<dp[x]+1<<endl;
                else cout<<-1<<endl;

            }else{
                if(dp[x-1] != -1)cout<<dp[x-1]+1<<endl;
                else cout<<-1<<endl;
            }
        }
        //
        fo(i,n)cout<<dp[i]<<" ";
        cout<<endl;
        fo(i,n)cout<<nexC[i]<<" ";
        cout<<endl;

        cout<<pts<<endl;
        //
        */
    }
    
    //▬▬ι═══════>
    return 0;
}

/*
  ____   ___  ____     __  __     __     _____   _     ____ __    ___
 |  _ \ / _ \|  _ \   |  \/  |   /  \   |  _  \ | |   |  __\  \  /  /
 | |_) | | | | |_) |  | \  / |  / ^  \  | |_)  || |   | |_  \  \/  /
 |  _ <| | | |  _ <   | |\/| | / /_\  \ |     / | |   |  _|  \    /
 | |_) | `-' | |_) |  | |  | |/ _____  \| |\  '-| `---| |___  |  |
 |____/ \___/|____/   |_|  |_|_/     \__|_| `.__|_____|_____| |__|
    ,         |                                     |            '
    |         .                                     ;            |
    ;          \                                   .            ;
     ;          .                                 /            /
      \          \    .-""-._           _.--""-. /            /
       \          ','`       r'-.  _.-'\        t           .'
        `.        '          \__/`| |__/                  .'
          '.                _..._7\    _,_             .'
            `'Y          ,'`     `/`"'`   `.         ,'
             /          /                   ;        L
            ;           |                   |         |mx
            |           ;                  ;          ;
             ; _ __      \                /     _ .- /
              \  \ \ `.   `.            .'    / ' / /
               '._\ `. \    `.        .'    .' / /-'
                   `._\ `.    `.    .' .-..'_.'-`
                       `-'`. /`.`. /  /  /
                            `\ _> )|  \_/
                             `'-'  `--' 
*/
