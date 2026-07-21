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
    
    bool f(TreeNode* root, int t){
        if(root==NULL ){
            return false;
        }
        if(!root->left && !root->right) {
            if(t-root->val==0){
                return true;
            }
        }

        t=t-root->val;
        int l=f(root->left,t);
        
        int r=f(root->right,t);

        

        return l || r;
    }
    bool hasPathSum(TreeNode* root, int t) {
        return f(root,t);
    }
};