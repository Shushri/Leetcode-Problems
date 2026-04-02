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
    int lefth(TreeNode* r){
        int ans=0;
        TreeNode* root=r;
        while(root){
            ans++;
            root=root->left;
        }
        return ans;
    }
    int righth(TreeNode* r){
        int ans=0;
        TreeNode* root=r;
        while(root){
            ans++;
            root=root->right;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int lh=lefth(root);
        int rh=righth(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return countNodes(root->left)+countNodes(root->right)+1;
    }
};