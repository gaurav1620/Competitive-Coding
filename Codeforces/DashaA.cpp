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

int main(){
	//START
    int n;
    cin>>n;
    int arr[n],i;
    fo(i,n)cin>>arr[i];
    int tmo = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+tmo);
    int ans = 0;
    fo(i,n){
        int el = arr[i];
        if(el != -1){
            ans++;
            for(int j = i;j < n;j++){
                if(arr[j]%el == 0 && arr[j]!= -1)arr[j] = -1;
            }
        }
    }    
    cout<<ans<<endl;
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
