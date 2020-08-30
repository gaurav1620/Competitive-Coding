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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first < b.first;
}


class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        ll s1 = (n1.second - n1.first);
        ll s2 = (n2.second - n2.first);
        //if s1 has more prio than s2;
        if(s1 < s2){
            return true;
        }else if(s1 > s2){
            return false;
        }
        return n1.first > n2.first;
    }
};

int main(){
    Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>, CompareDist> q;
        q.push({0,n-1});
        ll i,j,k;
        ll num = 1;

        ll arr[n];
        fo(i,n)arr[i] = -1;
        while(q.size() != 0){

           // priority_queue<pair<ll,ll> ,vector<pair<ll,ll>>, CompareDist> qq;
            
            //cout<<"NUM : "<<num<<endl;

            //while(q.size()){
           //     cout<<q.top().first<<" : "<<q.top().second<<endl;
           //     qq.push(q.top());
           //     q.pop();
           // }
           // q = qq;


            ll a = q.top().first;
            ll b = q.top().second;
            q.pop();
            arr[(a+b)/2] = num++;
            if(a == b-1){
                q.push({b,b});
            }else if(a != b){
                if((b-a)%2 == 0){
                    q.push({a, (a+b)/2-1});
                    q.push({(a+b)/2+1,b});
                }else{
                    q.push({(a+b)/2+1,b});
                    q.push({a, (a+b)/2-1});
                }
            }
        }
        fo(i,n)cout<<arr[i]<<" ";
        cout<<endl;

    }
    //▬▬ι═══════>
    return 0;
}

