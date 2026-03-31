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
    int height(TreeNode* root,int &vl){
        if(root==nullptr){
            return 0;
        }
        int l=max(0,height(root->left,vl));
        int r=max(0,height(root->right,vl));

        vl=max(vl,l+r+root->val);

        return max(l,r)+root->val;
    } 

    int maxPathSum(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int vl=INT_MIN;
        height(root,vl);
        return vl;


    }
};