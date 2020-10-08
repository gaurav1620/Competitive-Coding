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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return true;
        }
        else if(root -> left == nullptr || root->right == nullptr){return false;}
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(q.size() > 0){
            vector<TreeNode*> v;
            int sizz = q.size();
            
            if(sizz%2 == 1){return false;}
            widthCur *=2;
            
            //Copy the level
            for(int i = 0;i < sizz;i++){
                v.push_back(q.front());
                q.pop();
            }
            
            //Check level
            for(int i = 0 ;i < v.size()/2;i++){
                if(v[i] == nullptr && v[v.size()-1-i] == nullptr)continue;
                else if(v[i] == nullptr || v[v.size()-1-i] == nullptr){return false;}
                else if(v[i]->val != v[v.size()-1-i]->val){return false;}
            }
            
            //add children
            for(int i = 0;i < v.size();i++){
                if(v[i] != nullptr){
                    q.push(v[i]->left);
                    q.push(v[i]->right);                        
                }

            }
        }
        return true;
    }
};
