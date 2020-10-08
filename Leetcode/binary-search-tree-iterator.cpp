/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    int arr[10000];
    int siz = 0;
    int rig = -1;
    
    void gg(TreeNode* root){
        if(root == NULL)return;
        gg(root->left);
        arr[++rig] = root->val;
        siz++;
        
        gg(root->right);
    }
    BSTIterator(TreeNode* root) {
        gg(root);
    }
    
    /** @return the next smallest number */
    int next() {
        //siz--;
        return arr[rig - (siz--)+1];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return siz> 0;  
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
