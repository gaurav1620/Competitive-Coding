#include<bits/stdc++.h>
using namespace std;

int main(){
	//START
	char arr[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
	char i;
	cin>>i;
	char inp[101];
	cin>>inp;
	if(i == 'R'){
		for(int i =0;i < strlen(inp);i++){
			for(int j = 0;j < 30;j++){
				if(inp[i] == arr[j]){
					cout<<arr[j-1];
					break;
				}
			}
		}
		cout<<endl;
	}else{
		for(int i =0;i < strlen(inp);i++){
                        for(int j = 0;j < 30;j++){
                                if(inp[i] == arr[j]){
                                        cout<<arr[j+1];
                                        break;
                                }
                        }
                }
		cout<<endl;
	}
	//END
	return 0;
}
