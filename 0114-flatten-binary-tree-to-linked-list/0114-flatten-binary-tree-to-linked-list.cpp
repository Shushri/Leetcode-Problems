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
    TreeNode* ans;
    void preorder(TreeNode* root){
        if(root == nullptr){
            return ;
        }
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        TreeNode *temp=root;
        temp->left=nullptr;
        ans->right=temp;
        ans=ans->right;
        preorder(l);
        preorder(r);

    }
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return ;
        }
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        TreeNode *temp=root;
        temp->left=nullptr;
        ans=temp;
        preorder(l);
        preorder(r);

    }
};