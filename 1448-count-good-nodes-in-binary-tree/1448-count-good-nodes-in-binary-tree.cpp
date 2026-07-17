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
    int dfs(TreeNode* root,int mx){
        if(root==NULL){
            return 0;
        }
        int ans=0;
        if(root->val>=mx){
            ans= 1;
        }
        
        mx=max(root->val,mx);
        ans+=dfs(root->left,mx);
        ans+=dfs(root->right,mx);

        return ans;


    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};