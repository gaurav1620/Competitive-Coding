/*****************************************************************************

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⠙⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢯⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⠛⢿⣿⣿⣿⣿⣿
⣿⣿⣿⢧⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡕⠂⠈⢻⣿⣿⣿⣿
⣿⣿⡅⣻⡿⢿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠿⢿⣿⡇⠀⠀⠈⣿⣿⣿⣿
⣿⣿⠀⠀⠀⠘⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⠀⣹⣿⣿⣿
⣿⣿⠀⠀⠀⠀⣿⣿⡿⠿⠛⠻⣿⣿⣿⣿⡿⠟⠁⠈⠀⠉⠻⡆⠀⠀⠀⣿⣿⣿
⣿⣯⠄⠂⠀⠀⣿⡋⠀⢀⠀⠀⠀⠉⣿⣿⡀⠀⠀⠘⠓⣠⣶⣿⡀⠀⠀⠘⣿⣿
⣿⣫⡆⠀⠀⢀⣿⣷⣶⣄⠀⢀⣤⣴⣿⣿⣿⣶⣄⠀⣴⣿⣿⣿⠁⠀⠀⠀⠘⣿
⣿⣿⠁⠀⠀⡤⠙⢿⣿⣿⣷⣾⣿⡿⣿⣿⢿⠿⣿⣧⣿⣿⡿⢣⠀⠀⠀⠀⢠⣿
⣷⣌⠈⠀⠀⠀⠀⣆⠈⡉⢹⣿⣿⣆⡀⠀⠀⢠⣿⣿⣿⡿⢃⣼⠀⠀⠀⠀⣸⣿
⣿⣿⡇⠀⠀⠀⠀⠙⢿⣿⣆⠈⠛⠛⠛⠀⠀⠈⠉⠁⠀⢠⣿⠇⠀⠀⠀⠹⢿⡇
⣿⡫⠀⠀⠁⠀⠀⠀⠈⠻⣿⢢⣄⠀⠀⠀⠀⠀⣀⣠⣾⡾⠋⠀⠀⠀⠀⢀⠴⠋
⣿⣁⠄⠀⠀⠀⣀⠀⠀⠀⠈⠛⠿⣿⣿⣿⣿⣿⠿⡿⠋⠀⠀⠀⠀⠀⣀⠬⠆⢀
⣿⣿⣧⣄⠀⠀⠉⠀⠀⠀⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠠⠙
  ******************************************************************************
© GAURAV KHAIRNAR 2019

@ Website    : gaurav1620.rf.gd
@ Github     : gaurav1620
@ Insta      : may_be_gaurav
@ Gmail      : gauravak007@gmail.com
@ CodeForces : gaurav1620 


To them, you're just a freak, like me! They need you right now, but when they
don't, they'll cast you out, like a leper! You see, their morals, their code,
it's a bad joke. Dropped at the first sign of trouble. They're only as good as
the world allows them to be. I'll show you. When the chips are down, these...
these civilized people, they'll eat each other. See, I'm not a monster.
I'm just ahead of the curve.
*/


#include<bits/stdc++.h>
#define fo(i,n)   for(i = 0;i < n;i++)
#define Fo(i,k,n) for(i = k;i < n;i++)
#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
using namespace std;

int getState(char x){
    return x == '1'?1:0;
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int findlcm(int arr[], int n){
    int ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));
    return ans;
}

int toggle(int a){
    return a==1?0:1;
}

int disp(int arr[],int h){
    int i;
    fo(i,h)cout<<arr[i]<<" ";
    cout<<endl;
}

int getStateSum(int arr[],int n){
    int i;
    int ct  = 0;
    fo(i,n){
        if(arr[i] == 1)ct++;
    }
    return ct;
}

int main(){
	//START
    int n;
    cin>>n;
    char init[n+1];
    cin>>init;
    int stateArr[n],o;
    fo(o,n)stateArr[o] = getState(init[o]);
    int arr[n][2],i;
    int lcM[n];
    int maxB= 0;
    fo(i,n){
        int a,b;
        
        cin>>a>>b;
        if(b > maxB)maxB = b;
        arr[i][0] = a;
        arr[i][1] = b;
        lcM[i] = a;
    }
    int fLcm = findlcm(lcM,n);

    int tim = 0;
    int maxx = 0;
    fo(i,1000){
        //disp(stateArr,n);
        if(i==0){
            if(getStateSum(stateArr,n) > maxx)maxx = getStateSum(stateArr,n);
        }
        int j;
        fo(j,n){
            if(tim == arr[j][1])stateArr[j] = toggle(stateArr[j]);
            else if(tim > arr[j][1] && (tim-arr[j][1])%arr[j][0] == 0){
                stateArr[j] = toggle(stateArr[j]);
            }
                    
        }
        if(getStateSum(stateArr,n)> maxx)maxx = getStateSum(stateArr,n);
        tim++;
    }
    cout<<maxx<<endl;
	//END
	return 0;
}

/* 
⣿⣿⣿⣿⣿⣿⠟⠋⠁⣀⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣿⣿
⣿⣿⣿⣿⠋⠁⠀⠀⠺⠿⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠻⣿
⣿⣿⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣤⣤⠀⠀⠀⠀⠀⣤⣦⣄⠀⠀
⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣿⠏⣿⣿⣿⣿⣿⣁⠀⠀⠀⠛⠙⠛⠋⠀⠀
⡿⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⣰⣿⣿⣿⣿⡄⠘⣿⣿⣿⣿⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀
⡇⠀⠀⠀⠀⠀⠀⠀⠸⠇⣼⣿⣿⣿⣿⣿⣷⣄⠘⢿⣿⣿⣿⣅⠀⠀⠀⠀⠀⠀⠀⠀
⠁⠀⠀⠀⣴⣿⠀⣐⣣⣸⣿⣿⣿⣿⣿⠟⠛⠛⠀⠌⠻⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣶⣮⣽⣰⣿⡿⢿⣿⣿⣿⣿⣿⡀⢿⣤⠄⢠⣄⢹⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣿⣿⣿⣿⣿⡘⣿⣿⣿⣿⣿⣿⠿⣶⣶⣾⣿⣿⡆⢻⣿⣿⠃⢠⠖⠛⣛⣷⠀
⠀⠀⢸⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣮⣝⡻⠿⠿⢃⣄⣭⡟⢀⡎⣰⡶⣪⣿⠀
⠀⠀⠘⣿⣿⣿⠟⣛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⡿⢁⣾⣿⢿⣿⣿⠏⠀
⠀⠀⠀⣻⣿⡟⠘⠿⠿⠎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣿⠧⣷⠟⠁⠀⠀
⡇⠀⠀⢹⣿⡧⠀⡀⠀⣀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠋⢰⣿⠀⠀⠀⠀
⡇⠀⠀⠀⢻⢰⣿⣶⣿⡿⠿⢂⣿⣿⣿⣿⣿⣿⣿⢿⣻⣿⣿⣿⡏⠀⠀⠁⠀⠀⠀⠀
⣷⠀⠀⠀⠀⠈⠿⠟⣁⣴⣾⣿⣿⠿⠿⣛⣋⣥⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀ ⣿⡀

*/
