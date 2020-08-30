#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
# Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
*/

#define Ninja ios::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,n)   for(i = 0;i < n;i++)
#define ll long long
#define watch(x) cout << (#x) << " is : " << (x) << endl
using namespace std;
ll max(ll a,ll b){return a > b?a:b;}
ll min(ll a,ll b){return a < b?a:b;}

string getS(ll x){
    string s;
    while(x){
        char c = x%2 == 0 ? '0':'1';
        s = c+s;
        x/=2;
    }
    while(s.length() < 25){
        s = "0"+s;
    }
    return s;
}

ll findAnsUtil(ll x,ll y,ll left,ll right){
    if(x == 0 || y == 0){return left;}
    
    ll maxprod = (left & x)*(left & y);
    ll ind = left;
    ll ans = left;

    while(ind++ < right){
        if((ind & x)*(ind & y) > maxprod){
            maxprod = (ind & x)*(ind & y);
            ans = ind;
        }
    }
    return ans;

}


ll findAnsFinal(ll x,ll y,ll left,ll right){
    ll breakCycles = 4;

    if(x == 0 || y == 0){return left;}
    ll best = (x|y);
    
    if(left <= best && best <= right){return best;}

    ll minn = 0;
    ll ind1 = (ffs(x)-1);
    ll ind2 = (ffs(y)-1);
    
    if(ind1 > ind2){
        if(y & 1LL << ind1){
            minn |= 1LL << ind1;
        } else{
            minn |= 1LL << ind1;
            minn |= 1LL << ind2;
        }
    }else if(ind1 < ind2){
        if(x & 1LL << ind2){
            minn |= 1LL << ind2;
        } else{
            minn |= 1LL << ind1;
            minn |= 1LL << ind2;
        }
    }else{
        minn |= 1LL << ind1;
    }

    if(right < minn){return left;}
    if(right == minn){return right;}

    //Useful
    minn = minn;
    best = best;
    ll globalBest = -1;

    
    if(best < left){

        ll ans = left;
        ll ind = log2(left);
        
        ll bestPro = (left & x)*(left & y);
        ll bestAns = left;
        

        while(ind >= 0){
            if((best & 1LL<<ind ) && !(left &1LL << ind)){
                ll newAns = left;

                newAns &= ~((ll)pow(2,ind+1)-1);
                newAns |= ((ll)pow(2,ind+1)-1 & best);

                if(newAns  > right){
                    
                    //make all ones zero and the bits to rightas newans 
                    //start from left to right
                    ll simpInd = log2(right);
                    ll mcPro = (right & x)*(right & y);
                    ll mcAns = right;

                    while(simpInd >= 0){
                        if(right & 1LL << simpInd){
                            ll fuckedAns = right;
                            fuckedAns &= ~((ll)pow(2,simpInd+1)-1);
                            fuckedAns |= (((ll)pow(2,simpInd)-1) & newAns);
                            
                            ll fuckedPro = (fuckedAns & x) * (fuckedAns & y);
                            if(fuckedPro > mcPro || (fuckedPro == mcPro && fuckedAns<mcAns)){
                                if(fuckedAns <= right && fuckedAns >= left){
                                    mcPro = fuckedPro;
                                    mcAns = fuckedAns;
                                }
                            }
                        }
                        simpInd--;
                    }
                    newAns = mcAns;
                
                }
                ll newPro = (newAns & x)*(newAns & y);
                if(((newPro > bestPro) ||(newPro == bestPro && newAns < bestAns)) && 
                        (newAns <= right && newAns >= left)){
                    bestPro = newPro;
                    bestAns = newAns;
                }

                //break;
            }
            ind--;
        }
        return bestAns;

        /*
        ll ans = left;
        ll ind = log2(left);
        
        ll bestPro = (left & x)*(left & y);
        ll bestAns = left;



        while(ind >= 0){
            //best's bit is set and left's not !
            ans = left;
            if((best & 1LL << ind) && !(left & 1LL << ind)){
                ans |= 1LL << ind;
                ans &= ~((ll)(pow(2,ind)-1));
                ans |= (best & (ll)(pow(2,ind)-1));
                //return ans;
                if(ans <= right){
                    ll locpro = (ans & x)*(ans & y);
                    if(locpro > bestPro || (locpro == bestPro && bestAns > ans)){
                        if(ans >= left && ans <= right){
                            bestAns = ans;
                            bestPro = locpro;
                        
                        }
                    }
                }
                else {

                    cout<<"HORRIBLE \n";
                    watch(ans);
                    watch(getS(ans));
                    ll locAns = ans;
                    ll locInd = log2(right);
                    while(locInd >= 0){
                        if(!(ans & 1LL <<ind) && (right & 1LL << ind)){
                            break;
                        }
                        locAns &= ~(1LL << ind);
                        locAns |= (1LL << ind & right);
                        locInd--;
                    }
                    


                    ans = locAns;
                    ll locpro = (ans & x)*(ans & y);
                    if((locpro > bestPro || (locpro == bestPro && bestAns > ans)) && (ans <= right && ans  >= left)){
                        bestAns = ans;
                        bestPro = locpro;
                    }
                    //return locAns;
                    //if(locAns <= right && locAns >= left)return locAns;
                }
            }
            ind--;
            */
        //}
        //if(bestPro == 0){return left;}
        //return bestAns;

    }
    if(best > right){
        greatLABEL:

        ll minAns = right;
        ll maxPro = (right & x) * (right & y);
        ll ans = right;
        if(globalBest != -1){
            best = globalBest;
        }
        ll ind = log2(ans);
        while(ind >= 0){
            if(right & 1LL << ind){
                ll localAnswer = ans;
                //make all to right zero
                localAnswer &= ~(ll)(pow(2,ind+1)-1);
                localAnswer |= (best & (ll)(pow(2,ind)-1));
                
                ll locpro = (localAnswer & x)*(localAnswer & y);

                if(localAnswer < left)cout<<"MISSED : \n";
                if(localAnswer < left)watch(localAnswer);
                if(localAnswer < left)watch(getS(localAnswer));
                
                if(localAnswer < left){
                    ll lmaoInd = log2(left);
                    while(lmaoInd >= 0){
                        if(left & 1LL << lmaoInd){
                            localAnswer |= 1LL << lmaoInd;
                        }else if(localAnswer & 1LL << lmaoInd){
                            break;
                        }
                        lmaoInd--;
                    }
                }
                
                if((localAnswer >= left&& localAnswer <= right && locpro > maxPro) 
                        || ((locpro == maxPro) &&
                                localAnswer < minAns 
                                && localAnswer >= left)){
                    maxPro = locpro;
                    minAns = localAnswer;
                }
            }
            ind--;
        }
        //return minAns;
        if(maxPro == 0){return left;}
        if(minAns >= left)return minAns;
        else{
            return minAns;
            //return -1;

        }
    }
}



int main(){
    ll num = 20;
    while(num){
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        srand((time_t)ts.tv_nsec);
        
        
        ll x,y,left,right;
        left  = rand()%1000;
        x     = rand()%1000;
        y     = rand()%1000;
        right = rand()%1000;
        if(left > right){swap(left,right);}
        ll noneff  = findAnsUtil(x,y,left,right);
        ll fina = findAnsFinal(x,y,left,right);  

        
        if(fina == -69){
            cout<<"\n*************  Test : "<<num<<"  *******************\n";
            
            watch(x);
            watch(y);
            watch(left);
            watch(right);
            watch(x|y);
            cout<<noneff<<" : "<<fina<<endl;
            cout<<"X     :"<<getS(x)<<endl;
            cout<<"Y     :"<<getS(y)<<endl;
            cout<<"Left  :"<<getS(left)<<endl;
            cout<<"Right :"<<getS(right)<<endl;
            cout<<"X|Y   :"<<getS(x|y)<<endl;
            cout<<"crt   :"<<getS(noneff)<<endl;
            cout<<"wa    :"<<getS(fina)<<endl;
            break;
        }
        if(noneff != fina){
            cout<<"\n*************  Test : "<<num<<"  *******************\n";
            
            watch(x);
            watch(y);
            watch(left);
            watch(right);
            watch(x|y);
            cout<<noneff<<" : "<<fina<<endl;
            cout<<"X     :"<<getS(x)<<endl;
            cout<<"Y     :"<<getS(y)<<endl;
            cout<<"Left  :"<<getS(left)<<endl;
            cout<<"Right :"<<getS(right)<<endl;
            cout<<"X|Y   :"<<getS(x|y)<<endl;
            cout<<"crt   :"<<getS(noneff)<<endl;
            cout<<"wa    :"<<getS(fina)<<endl;
            //break;
            if((x|y) > right){
            cout<<"ERROR FOR : BEST > RIGHT\n";
            }
            else{ 
            cout<<"ERROR FOR : BEST < LEFT\n";
            break;
            //num--;
            }
        }else{
            cout << "OK \n";
            //if((x|y) > right)cout<<" : BEST > RIGHT\n";
            //else cout<<" : BEST < LEFT\n";
        }
    }
    return 0;

    //Ninja
    //▬▬ι═══════>
    ll t;cin>>t;
    while(t--){
        ll x,y,left,right,i,j,k;cin>>x>>y>>left>>right;
        
    }   
    //▬▬ι═══════>
    return 0;
}


/*
                     .                          
                     M                          
                    dM                          
                    MMr                         
                   4MMML                  .     
                   MMMMM.                xf     
   .              "MMMMM               .MM-     
    Mh..          +MMMMMM            .MMMM      
    .MMM.         .MMMMML.          MMMMMh      
     )MMMh.        MMMMMM         MMMMMMM       
      3MMMMx.     'MMMMMMf      xnMMMMMM"       
      '*MMMMM      MMMMMM.     nMMMMMMP"        
        *MMMMMx    "MMMMM\    .MMMMMMM=         
         *MMMMMh   "MMMMM"   JMMMMMMP           
           MMMMMM   3MMMM.  dMMMMMM            .
            MMMMMM  "MMMM  .MMMMM(        .nnMP"
=..          *MMMMx  MMM"  dMMMM"    .nnMMMMM*  
  "MMn...     'MMMMr 'MM   MMM"   .nMMMMMMM*"   
   "4MMMMnn..   *MMM  MM  MMP"  .dMMMMMMM""     
     ^MMMMMMMMx.  *ML "M .M*  .MMMMMM**"        
        *PMMMMMMhn. *x > M  .MMMM**""           
           ""**MMMMhx/.h/ .=*"                  
                    .3P"%....                   
                  nP"     "*MMnx       GaUrAv..
*/

