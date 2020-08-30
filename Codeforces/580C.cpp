/*****************************************************************************  
  1   / __| __ _ _  _ _ _ __ ___ __ | |/ / |_  __ _(_)_ _ _ _  __ _ _ _             
  2  | (_ -/ _` | || | '_/ _` \ V / | ' <| ' \/ _` | | '_| ' \/ _` | '_|            
  3   \___|\__,_|\_,_|_| \__,_|\_/  |_|\_\_||_\__,_|_|_| |_||_\__,_|_|              
  4   ******************************************************************************
  5 © GAURAV KHAIRNAR 2019                                             
  6                                                                                 
  7 @ Website    : gaurav1620.rf.gd                                                 
  8 @ Github     : gaurav1620                                                       
  9 @ Insta      : may_be_gaurav                                                    
 10 @ Gmail      : gauravak007@gmail.com                                            
 11 @ CodeForces : gaurav1620                                                       
 12                                                                                 
 13 # Dont compare yourself with anyone in this world.If you do so, you are insulting youreself .
 14 */

#include<bits/stdc++.h>
#define fo(i,n) for(i = 0;i < n;i++)
using namespace std;

class nod{
    public:
        int data = 0;
        int index = 0;
        nod* children = NULL;
        nod* nextSibling = NULL;
        
};

nod* initNod(int i,int dat){
    //cout<<"Initialized a node with index : "<<i<<" and cat : "<<dat<<endl;
    nod* n =  (nod*) malloc(sizeof(nod*));
    //n->children = NULL;
    //n->nextSibling = NULL;
    n->data = dat;
    n->index = i;
    return n;
}

nod* findNod(nod* root,int i);

void insertNod(nod* root,int pa,int ch,int dat){
    if(!root) return;
    if(root->index == pa){
        //cout<<"\t 1 Found the parent : "<<pa<<endl;
        if(root->children){
            //cout<<"\t\t 2 Appending to children : "<<ch<<endl;
            nod* tmp = initNod(ch,dat);
            tmp->nextSibling = root->children;
            root->children = tmp;
        }else{
            //cout<<"\t\t 3 Adding the only child : "<<ch<<endl;
            nod* tmp = initNod(ch,dat);
            root->children = tmp;
        }
    }else{
        //cout<<"\t 4 Parent not found !"<<endl;
        nod* tmp1 = findNod(root,pa);
        //cout<<"\t 5 Parent found !"<<tmp1->index<<endl;
        if(tmp1->children){
            //cout<<"\t\t 6 Appending to children : "<<ch<<endl;
            nod* tmp = initNod(ch,dat);
            tmp->nextSibling = tmp1->children;
            tmp1->children = tmp;
        }else{
            //cout<<"\t\t 7 Adding the only child : "<<ch<<endl;
            nod* tmp = initNod(ch,dat);
            tmp1->children = tmp;
        }
    }
}



nod* findNod(nod* root,int i){
    //cout<<"Find nod called for : "<<i<<endl;
    if(root){
        if(root->index == i)return root;
        nod* fC = findNod(root->children,i);
        nod* fNS = findNod(root->nextSibling,i);
        if(fC)return fC;
        if(fNS) return fNS;
        return NULL;
    }
    return NULL;
}

int staticAns = 0;


void getAns(nod* root,int consecIndex,int maxOk){
    //cout<<"GetANs called for ind : "<<root->index<<" , consecInd : "<<consecIndex<<endl;
    if(!root)return;
    if(consecIndex > maxOk)return;
    if(root->data == 1 && consecIndex == maxOk){
        if(root->nextSibling)getAns(root->nextSibling,consecIndex,maxOk);
        return;
    }

    if(root->children){
        if(root->data == 1){
            getAns(root->children,consecIndex+1,maxOk);
        }else{
            getAns(root->children,0,maxOk);
        }
    }else{
        if(root->data == 1){
            if(consecIndex < maxOk){
                staticAns++;
            }
        }else{
            staticAns++;
        }
    }

    if(root->nextSibling){
        getAns(root->nextSibling,consecIndex,maxOk);
    }

}
void printTree(nod* root){
    if(!root)return;
    cout<<root->index<<" ";
    printTree(root->children);
    printTree(root->nextSibling);
}

int main(){
	//START
	int n,m,i;
    cin>>n>>m;
    int cat[n];
    fo(i,n)cin>>cat[i];
    nod* root = initNod(1,cat[0]);
    fo(i,n-1){
        int f,g;
        cin>>f>>g;
        insertNod(root,f,g,cat[i+1]);
       // cout<<"TREE : ";printTree(root);cout<<endl;
    }
    //cout<<root->children->nextSibling->index<<endl;
    getAns(root,0,m);
    cout<<staticAns<<endl;
    //cout<<"Answer : "<<staticAns<<endl;
    //END
	return 0;
}

/*
  1 ⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠞⠉⢉⣭⣿⣿⠿⣳⣤⠴⠖⠛⣛⣿⣿⡷⠖⣶⣤⡀⠀⠀⠀
  2 ⠀⠀⠀⠀⠀⠀⠀⣼⠁⢀⣶⢻⡟⠿⠋⣴⠿⢻⣧⡴⠟⠋⠿⠛⠠⠾⢛⣵⣿⠀⠀⠀⠀
  3 ⣼⣿⡿⢶⣄⠀⢀⡇⢀⡿⠁⠈⠀⠀⣀⣉⣀⠘⣿⠀⠀⣀⣀⠀⠀⠀⠛⡹⠋⠀⠀⠀⠀
  4 ⣭⣤⡈⢑⣼⣻⣿⣧⡌⠁⠀⢀⣴⠟⠋⠉⠉⠛⣿⣴⠟⠋⠙⠻⣦⡰⣞⠁⢀⣤⣦⣤⠀
  5 ⠀⠀⣰⢫⣾⠋⣽⠟⠑⠛⢠⡟⠁⠀⠀⠀⠀⠀⠈⢻⡄⠀⠀⠀⠘⣷⡈⠻⣍⠤⢤⣌⣀
  6 ⢀⡞⣡⡌⠁⠀⠀⠀⠀⢀⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢿⡀⠀⠀⠀⠸⣇⠀⢾⣷⢤⣬⣉
  7 ⡞⣼⣿⣤⣄⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠸⣿⣇⠈⠻
  8 ⢰⣿⡿⢹⠃⠀⣠⠤⠶⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⣿⠛⡄⠀
  9 ⠈⠉⠁⠀⠀⠀⡟⡀⠀⠈⡗⠲⠶⠦⢤⣤⣤⣄⣀⣀⣸⣧⣤⣤⠤⠤⣿⣀⡀⠉⣼⡇⠀
 10 ⣿⣴⣴⡆⠀⠀⠻⣄⠀⠀⠡⠀⠀⠀⠈⠛⠋⠀⠀⠀⡈⠀⠻⠟⠀⢀⠋⠉⠙⢷⡿⡇⠀
 11 ⣻⡿⠏⠁⠀⠀⢠⡟⠀⠀⠀⠣⡀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⢀⠈⠀⢀⣀⡾⣴⠃⠀
 12 ⢿⠛⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠈⠢⠄⣀⠠⠼⣁⠀⡱⠤⠤⠐⠁⠀⠀⣸⠋⢻⡟⠀⠀
 13 ⠈⢧⣀⣤⣶⡄⠘⣆⠀⠀⠀⠀⠀⠀⠀⢀⣤⠖⠛⠻⣄⠀⠀⠀⢀⣠⡾⠋⢀⡞⠀⠀⠀
 14 ⠀⠀⠻⣿⣿⡇⠀⠈⠓⢦⣤⣤⣤⡤⠞⠉⠀⠀⠀⠀⠈⠛⠒⠚⢩⡅⣠⡴⠋⠀⠀⠀⠀
 15 ⠀⠀⠀⠈⠻⢧⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣻⠿⠋⠀⠀⠀⠀⠀⠀
 16 ⠀⠀⠀⠀⠀⠀⠉⠓⠶⣤⣄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣠⡴⠖⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀
 17 */
