#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;

        int arr[n][2];
        int i,j,k;
        for(i = 0;i < n;i++)cin>>arr[i][0]>>arr[i][1];

        map<pair<int,int>,vector<pair<int,int> >> mp;
        for(int i = 0;i < n;i++){
            if(arr[i][1] < 0){
                int p = arr[i][1]/c;
                //cout<<"ERR0\n";
                //cout<<arr[i][0] - p*c<<endl;
                //cout<<arr[i][1] - p*c<<endl;
                if(arr[i][1]%c != 0){
                    p--;
                }
                mp[{arr[i][0]-p*c , arr[i][1]-p*c}].push_back(
                        {arr[i][0],arr[i][1]});
            }else{
                int p = arr[i][1]/c;
                //cout<<"ERR1\n";
                //cout<<arr[i][0] - p*c<<endl;
                //cout<<arr[i][1] - p*c<<endl;
                mp[{arr[i][0] - p*c ,arr[i][1]-p*c}].push_back({arr[i][0],arr[i][1]});
            }
        }
        int tot = 0;
        for(auto it = mp.begin();it!= mp.end();it++){
            vector<pair<int,int>> v = it->second;
            sort(v.begin(),v.end());
            
            pair<int ,int > coor = it->first;

            if(v.size() > 1){
                long long gf = 0;
                for(int i = 0;i < v.size();i++)
                    gf += v[i].second;
                gf /= v.size();
                gf = (gf/c)*c;
                
                int gf2 = gf+c;
                int tot1 = 0;
                int tot2 = 0;
                cout<<"CHEKC : \n";
                cout<<gf<<" "<<gf2<<endl;
                for(int i = 0;i < v.size();i++){
                    if(i != gf){
                        int dist = gf-v[i].second; 
                        dist = dist < 0 ? dist*-1:dist;
                        tot1 += dist/c;
                    }
                    if(i != gf2){
                        int dist = gf2-v[i].second; 
                        dist = dist < 0 ? dist*-1:dist;
                        tot2 += dist/c;
                    }
                }

                tot += tot1 < tot2 ? tot1 : tot2;
            }
        }
        cout<<mp.size()<<" "<<tot<<endl;
    }
    return 0;
}
