class Solution {
public:
    int ans=0;
    void start(TreeNode* root, long long t) {
        if (!root) return ;

        
        if (root->val == t) ans++;

        start(root->left, t - root->val);
        start(root->right, t - root->val);

        
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        start(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};