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
    TreeNode* invert(TreeNode* root){
        if(root==nullptr){
            return NULL;
        }
        TreeNode* l=invert(root->left);
        TreeNode* r=invert(root->right);
        root->right=l;
        root->left=r;
        return root;


    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        invert(root);
        return root;
    }
};