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
    TreeNode* findRight(TreeNode* root){
        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }
        return temp;
    }
    TreeNode* f1(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        else{
            TreeNode* nd=findRight(root->left);
            nd->right=root->right;
        }
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            return f1(root);
        }
       
            if(root->val>key){
                root->left= deleteNode(root->left,key);
            }
            else{
                root->right= deleteNode(root->right,key);
            }
        
        return root;
    }
};