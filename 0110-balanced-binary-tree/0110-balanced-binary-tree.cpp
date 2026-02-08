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
    int geth(TreeNode* r){
        if(r==nullptr){
            return 0;
        }
        int llh=geth(r->left);
        int rrh=geth(r->right);
        return 1+max(llh,rrh);
    }

    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }    
        int lh=geth(root->left);
        int rh=geth(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
            return true;
        }
        return false;
    }
};