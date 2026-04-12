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
    int ans = 0;

    struct NodeInfo {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };

    NodeInfo solve(TreeNode* root) {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        auto left = solve(root->left);
        auto right = solve(root->right);
      if (left.isBST && right.isBST &&
            root->val > left.maxVal &&
            root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                currSum,
                min(root->val, left.minVal),
                max(root->val, right.maxVal)
            };
        }

        return {false, 0, INT_MIN, INT_MAX};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};