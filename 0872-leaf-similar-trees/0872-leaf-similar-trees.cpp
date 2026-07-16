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
    void f(TreeNode* r,vector<int> &ans){
        
        if(r->left==NULL && r->right==NULL){
            ans.push_back(r->val);
            return;
        }
        if(r->left) f(r->left,ans);
        if(r->right) f(r->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        f(root1,ans1);
        vector<int> ans2;
        f(root2,ans2);
        return ans1==ans2;
    }
};