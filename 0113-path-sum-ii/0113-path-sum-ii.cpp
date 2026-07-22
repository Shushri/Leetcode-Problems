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
    void f(TreeNode* root, int t, vector<vector<int>> &ans, vector<int> &arr){
        if(root==NULL){
            return;
        }
        arr.push_back(root->val);
        if(!root->left && !root->right){
            if(t-root->val==0){
                
                ans.push_back(arr);
            }
            
        }
        else{
            f(root->left,t-root->val,ans,arr);
            f(root->right,t-root->val,ans,arr);
        }

        arr.pop_back();


    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> arr;
        f(root,t,ans,arr);
        return ans;
    }
};