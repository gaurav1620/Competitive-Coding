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

void printVector(vector<ll> v){ll i;fo(i,v.size())cout<<v[i]<<" ";cout<<endl;}
void printVector(ll v[],ll n){ll i;fo(i,n)cout<<v[i]<<" ";cout<<endl;}

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n,len;cin>>n>>len;
        string arr[n];
        ll i,j,k;
        fo(i,n){
            cin>>arr[i];
        }

        if(n == 1){
            cout<<arr[0]<<endl;
        }else{

            ll ind1 ,ind2;
            ll hasInd1 = false;
            ll hasInd2 = false;
            string s1,s2;


            bool done = false;
            for(i =0;i < len;i++){
                if(arr[0][i] != arr[1][i]){
                    if(hasInd1 == false){
                        hasInd1 = true;
                        ind1 = i;
                    }else if(hasInd2 == false){
                        hasInd2 = true;
                        ind2 = i;
                    }else{
                        done = true;
                        cout<<"-1"<<endl;
                        break;
                    }
                }    
            }
            if(!done){
                if(hasInd1 == )

                s1 = arr[1];
                s2 = arr[0];
                watch(ind1);
                watch(ind2);
                for( i = 0;i < len;i++){
                    if(i == ind1){
                        s1[i] = arr[1][i];
                        
                    }else if(i == ind2){
                        s2[i] = arr[0][i];
                    }
                }
                watch(s1);
                watch(s2);

                ll ans=0;
                bool has1 = true;
                bool has2 = false;

                for(i = 2;i < n;i++){
                    ll loc = 0;
                    for(j = 0 ; i < len;j++){
                        if(arr[i][j] != s1[j])loc++;
                    }
                    if(loc > 2){
                        has1 = false;
                        break;
                    }

                }

                for(i = 2;i < n;i++){
                    ll loc = 0;
                    for(j = 0 ; i < len;j++){
                        if(arr[i][j] != s2[j])loc++;
                    }
                    if(loc > 2){
                        has2 = false;
                        break;
                    }

                }
                if(has1)cout<<s1<<endl;
                else if(has2)cout<<s2<<endl;
                else cout<<"-1\n";
            }
        
        }



    }
    //▬▬ι═══════>
    return 0;
}

