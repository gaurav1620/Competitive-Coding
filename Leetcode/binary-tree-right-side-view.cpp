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
class Solution {
public:
    vector<int > v;
    //level will start from 1 at root;
    void gg(TreeNode* root,int level){
        if(root == NULL) return;
        
        if(v.size() >= level){
            
            gg(root->right,level+1);
            gg(root->left,level+1);
            return;
        }else {
            v.push_back(root->val);
            gg(root->right,level+1);
            gg(root->left,level+1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        gg(root,1);
        return v;
    }
};
