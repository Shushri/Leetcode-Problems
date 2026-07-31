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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int mx=INT_MIN;
        int ans=0;
        int lvl=1;
        while(!q.empty()){
            int sz=q.size();
            int sm=0;
            for(int i=0;i<sz;i++){
                  TreeNode* tp=q.front();
                  q.pop();
                  sm+=tp->val;
                  if(tp->left) q.push(tp->left);
                  if(tp->right) q.push(tp->right);
            }
            if(mx<sm){
                mx=sm;
                ans=lvl;
            }
            lvl++;
        }
        return ans;
    }
};