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

using namespace std;

ll testCases;
#define Yess cout<<"YES\n";
#define Noo cout<<"NO\n";
#define yess cout<<"Yes\n";
#define noo cout<<"No\n";
#define setpreccc std::cout << std::fixed;cout <<setprecision(0)
int main(){
    testCases = 1;
    cin>>testCases; 

    while(testCases--){
        float price[2];
        price[0] = price[1] = -1;

        ll inventory[2];
        ll cart[2];
        inventory[0] = inventory[1] = 0;
        cart[0] = cart[1] = 0;

        string s;
        
        while(1){
            cin>>s;
            if(s == "END")break;
            if(s == "CMD"){
                cin>>s;
                if(s == "SM"){
                    cin>>s;
                    string item;
                    cin>>item;
                    float temp;
                    ll ind = item == "SHOE";

                    if(s == "ADD"){
                        cin>>temp;
                        if(inventory[ind] != 0 || temp == 0){
                            cout<<-1<<endl;
                        }else{
                            inventory[ind] += (ll)temp;
                            cout<<(ll)temp<<endl;
                        }
                    }else if(s == "REMOVE"){
                        if(inventory[ind] == 0){
                            cout<<-1<<endl;
                        }else{
                            cout<<1<<endl;
                            inventory[ind] = 0;
                        }
                    }else if(s == "GET_QTY"){
                        cout<<inventory[ind]<<endl;
                    }else if(s == "INCR"){
                        cin>>temp;
                        if(inventory[ind] == 0 || temp == 0){
                            cout<<-1<<endl;
                        }else{
                            cout<<(ll)temp<<endl;
                            inventory[ind] += (ll) temp;
                        }
                    }else if(s == "DCR"){   
                        cin>>temp;
                        if(inventory[ind] == 0 || temp == 0
                                ||inventory[ind] - (ll)temp < 0){
                            cout<<-1<<endl;
                        }else{
                            inventory[ind] -= (ll)temp;
                            //cout<<inventory[ind]<<endl;
                            cout<<(ll) temp<<endl;
                        }
                    }else if(s == "SET_COST"){
                        cin>>temp;
                        price[ind] = temp;
                        printf("%.1f\n",temp);
                    }
                }else if(s == "S"){
                    cin>>s;
                    if(s == "GET_ORDER_AMOUNT"){
                        if((price[0] == -1 && cart[0] > 0)|| (price[1] == -1 && cart[1] > 0)){
                            cout<<-1<<endl;
                        }else 
                        printf("%.2f\n",((float)cart[0]*price[0]+(float)cart[1]*(float)price[1]));
                        continue;
                    }
                    string x;cin>>x;
                    ll ind = x == "SHOE";
                    float temp;

                    if(s == "ADD"){
                        cin>>temp;
                        if(cart[ind] != 0 || temp == 0
                                || temp > inventory[ind]
                                ){
                            cout<<-1<<endl;
                        }else{
                            cout<<(ll)temp<<endl;
                            cart[ind] = (ll)temp;
                        }
                    }else if(s == "REMOVE"){
                        if(cart[ind] != 0){
                            cart[ind] = 0;
                            cout<<1<<endl;
                        }else{
                            cout<<-1<<endl;
                        }
                    }else if(s == "INCR"){
                        cin>>temp;
                        if(cart[ind] == 0  || temp == 0
                                || temp + cart[ind] > inventory[ind]
                                ){
                            cout<<-1<<endl;
                        }else{
                            cart[ind] += (ll)temp;
                            cout<<(ll)temp<<endl;
                        }
                    }else if(s == "DCR"){
                        cin>>temp;
                        if(cart[ind] < (ll)temp || temp == 0){
                            cout<<-1<<endl;
                        }else{
                            cart[ind] -= (ll) temp;
                            cout<<(ll) temp<<endl;
                            //cout<<cart[ind]<<endl;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
