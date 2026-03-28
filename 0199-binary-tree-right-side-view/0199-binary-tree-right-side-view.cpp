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
        if(root==nullptr) return {};
        map<int,int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* nd=q.front().first;
                int lvl=q.front().second;
                q.pop();
                if(mpp.find(lvl)==mpp.end()){
                    mpp[lvl]=nd->val;
                }
                if(nd->right) q.push({nd->right,lvl+1});
                if(nd->left) q.push({nd->left,lvl+1});

            }
            
        }
        vector<int> ans;
        for(auto ele:mpp){
            ans.push_back(ele.second);
        }
        return ans;

    
    }
};