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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        int lvl=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                pair<int,TreeNode*> nd=q.front();
                q.pop();
                int ind=nd.first;
                TreeNode* ndd=nd.second;
                int v=ndd->val;
                mpp[ind][lvl].insert(v);
                
                if(ndd->left){
                    q.push({ind-1,ndd->left});
                }
                if(ndd->right){
                    q.push({ind+1,ndd->right});
                }
            }
            lvl++;
        }
        vector<vector<int>> ans;
        for(auto ele:mpp){
            vector<int> temp;
            for(auto it:ele.second){
                for(auto vv:it.second){
                    temp.push_back(vv);
                }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};