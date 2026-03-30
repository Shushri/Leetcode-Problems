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
    int checkh(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int l=checkh(root->left);
        int r=checkh(root->right);

        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr){
            return true;
        }
        
        int l=checkh(root->left);
        int r=checkh(root->right);

        if(abs(l-r)>1){
            return false;
        }

        return (isBalanced(root->left) && isBalanced(root->right));

        
        

    }
};