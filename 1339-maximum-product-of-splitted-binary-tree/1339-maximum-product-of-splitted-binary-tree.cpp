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
    static const int MOD = 1e9 + 7;
    long long total;
    long long ans=0;
    long long ttl(TreeNode* root){
        if(!root){
            return 0;
        }
        long long l=ttl(root->left);
        long long r=ttl(root->right);
        long long ans=root->val+l+r;
        return ans;

    }
    long long dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        long long pp=root->val+dfs(root->left)+dfs(root->right);
        ans=max(ans,((total-pp)*pp));
        return pp;
    }
    int maxProduct(TreeNode* root) {
        total=ttl(root);
        dfs(root);
        return (int)(ans%MOD);
    }
};