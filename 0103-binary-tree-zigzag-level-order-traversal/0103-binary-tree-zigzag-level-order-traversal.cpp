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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue <TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int f=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp(n);
            for(int i=0;i<n;i++){
                TreeNode* nd=q.front();
                int v=nd->val;
                q.pop();
                if(f==0){
                    temp[i]=v;
                }
                else{
                    temp[n-i-1]=v;
                }
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }
            f=f==0?1:0;
            ans.push_back(temp);
        }
        return ans;
    }
};