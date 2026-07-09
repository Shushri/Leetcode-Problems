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
    int maxDepth(TreeNode* root) {
        
        if(root==NULL ) return 0;
        if( root->left==NULL && root->right==NULL) return 1;
        int h=0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* nd=q.front();
                q.pop();
                if(nd->left!=NULL) q.push(nd->left);
                if(nd->right!=NULL) {q.push(nd->right);}

            }
            h++;
        }
        return h;
    }
};