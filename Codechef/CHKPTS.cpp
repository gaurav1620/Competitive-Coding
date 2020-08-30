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
                    p++;
                }
                mp[{arr[i][0]+p*c , arr[i][1]+p*c}].push_back({arr[i][0],arr[i][1]});
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
                if(v.size() & 1){
                    //odd
                    int mid = v.size()/2;
                    for(int ind = 0;ind < v.size();ind++){
                        if(ind != mid){
                            int dist = (v[mid].first - v[ind].first);
                            dist = dist < 0 ? dist*-1 : dist;
                            tot += dist/c;
                        }
                    }
                }else{
                    int mid1 = v.size()/2;
                    int mid2 = mid1-1;
                    int tot1 = 0;
                    int tot2 = 0;
                    for(int ind = 0;ind < v.size();ind++){
                        if(ind != mid1){
                            int dist = (v[mid1].first - v[ind].first);
                            dist = dist < 0 ? dist*-1 : dist;
                            tot1 += dist/c;
                        }
                    }
                    for(int ind = 0;ind < v.size();ind++){
                        if(ind != mid2){
                            int dist = (v[mid2].first - v[ind].first);
                            dist = dist < 0 ? dist*-1 : dist;
                            tot2 += dist/c;
                        }
                    }
                    tot += tot1 > tot2 ? tot2:tot1;
                }
            }
        }
        cout<<mp.size()<<" "<<tot<<endl;
    }
    return 0;
}
