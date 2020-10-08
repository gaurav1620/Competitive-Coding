/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find(TreeNode* root,int dat){
        if(root->val == dat)return 1;
        else if(root->left != NULL && find(root->left,dat))return 1;
        else if(root->right != NULL && find(root->right,dat))return 1;
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val == p->val || root->val == q->val)return root;
        else if(root->left == NULL && root->right == NULL)return NULL;
        else if(root->left != NULL && root->right !=NULL){
            if(find(root->left,p->val) && find(root->right,q->val)){
                return root;
            }
            else if(find(root->left,q->val) && find(root->right,p->val)){
                return root;
            }else if(find(root->left,q->val)){
                return lowestCommonAncestor(root->left,p,q);
            }else{
                return lowestCommonAncestor(root->right,p,q);
            }
        }else if(root->left == NULL)return lowestCommonAncestor(root->right,p,q);
        return lowestCommonAncestor(root->left,p,q);
    }
};
