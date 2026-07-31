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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL) return {};
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int sz=q.size();
            int vl;
            while(sz--){
                TreeNode* tp=q.front();
                q.pop();
                vl=tp->val;
                if(tp->left) q.push(tp->left);
                if(tp->right) q.push(tp->right); 
            }
            ans.push_back(vl);
        }
        return ans;

    }
};