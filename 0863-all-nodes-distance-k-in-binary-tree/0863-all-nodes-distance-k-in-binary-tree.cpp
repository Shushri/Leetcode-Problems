/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mpp ){
        queue<TreeNode*> q;
        q.push(root);
        mpp[root]=nullptr;
        while(!q.empty()){
            TreeNode* tp=q.front();
            q.pop();
            if(tp->left){
                mpp[tp->left]=tp;
                q.push(tp->left);
            }
            if(tp->right){
                mpp[tp->right]=tp;
                q.push(tp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0){
            return {target->val};
        }
        unordered_map<TreeNode*,TreeNode*> mpp;
        parent(root,mpp);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int kc=0;
        while(!q.empty()){
            int nn=q.size();
            for(int i=0;i<nn;i++){
                TreeNode* tp=q.front();
                q.pop();
                if(tp->left && vis[tp->left]==false){
                    q.push(tp->left);
                    vis[tp->left]=true;
                }
                if(tp->right && vis[tp->right]==false){
                    q.push(tp->right);
                    vis[tp->right]=true;
                }
                if(mpp[tp]!=nullptr && vis[mpp[tp]]==false){
                    q.push(mpp[tp]);
                    vis[mpp[tp]]=true;
                }
            }
            kc++;
            if(kc==k){
                break;
            }
            
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};