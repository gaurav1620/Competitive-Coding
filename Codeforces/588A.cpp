#include<bits/stdc++.h>
using namespace std;

class nod{
    public:
        int data;
        int index;
        node* chilren;
        node* nextSibling;
        
};

nod* initNod(int i,int dat){
    nod* n =  (nod*) malloc(sizeof(nod*));
    n->chilren = NULL;
    n->nextSibling = NULL;
    n->data = dat;
    n->index = i;
    return n;
}
void insertNod(nod* root,int pa,int ch,int dat){
    if(root->index == pa){
        if(root->chilren){
            nod* tmp = initNod(ch,dat);
            tmp->nextSibling = root->chilren;
            root->chilren = tmp;
        }else{
            nod* tmp = initNod(ca,dat);
            root->chilren = tmp;
        }
    }else{
        nod* tmp = findNod(root,pa);
        if(root->chilren){
            nod* tmp = initNod(ch,dat);
            tmp->nextSibling = root->chilren;
            root->chilren = tmp;
        }else{
            nod* tmp = initNod(ch,dat);
            root->chilren = tmp;
        }
    }
}



nod* findNod(nod* root,int i){
    if(root){
        if(root->index == i)return root;
        nod* fC = find(root->chilren);
        nod* fNS = find(root->nextSibling);
        if(fC)return fC;
        if(fNS) return fNS;
        return NULL;
    }
    return NULL;
}

int getAns(nod* root,int consecIndex,int maxOk,int currentAns){
    if(root->data == 1){
        //Break condition cannot move forward
        if(consecIndex+1 > maxOk)return currentAns;
        
        //Can move forward
        else{
            if(root->nextSibling){
                if(root->chilren){
                    currentAns+=(getAns(root->nextSibling, consecIndex+1, maxOk, currentAns)
                                + getAns(root->chilren, consecIndex+1, maxOk, currentAns));
                    return currentAns;
                }else{
                    currentAns += getAns(root->nextSibling, consecIndex+1, maxOk, currentAns);
                    return currentAns;
                }
            }else{
                if(root->chilren){
                    currentAns+= getAns(root->chilren, consecIndex+1, maxOk, currentAns);
                    return currentAns;
                }else{
                    return currentAns+1;
                }
            }
        }
    }else{
        if(root->nextSibling){
            if(root->chilren){
                currentAns += (getAns(root->nextSibling,0,maxOk,currentAns)+
                                 getAns(root->chilren,0,maxOk,currentAns));
                return currentAns;
            }else{
                currentAns += getAns(root>nextSibling,0,maxOk,currentAns);
                return currentAns;
            }
        }else{
            if(root->chilren){
                currentAns+=getAns(root->chilren,0,maxOk,currentAns);
                return currentAns;
            }else{
                return currentAns+1;
            }
        }
    }

}

int main(){
	//START
	nod* root = initNod(1,)

	//END
	return 0;
}
