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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        queue<pair<long long,TreeNode*>> q;
        q.push({0,root}) ;
        long long ans=0;
        while(!q.empty()){
            long long n=q.size();
            long long mn=q.front().first;
            long long a=-1;
            long long b=-1;
            for(int i=0;i<n;i++){
                long long ind=q.front().first-mn;
                TreeNode* nd=q.front().second;
                q.pop();
                if(a==-1){
                    a=ind;
                }
                b=ind;
                if(nd->left) q.push({2*ind+1,nd->left});
                if(nd->right) q.push({2*ind+2,nd->right});
            }
            ans=max(ans,b-a+1);
        }
        return ans;
    }
};