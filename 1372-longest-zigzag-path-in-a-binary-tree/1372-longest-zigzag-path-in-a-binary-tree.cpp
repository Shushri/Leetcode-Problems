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
    
    void zigzag(TreeNode* root, int val,int length,int &ans){
        if(root==NULL) return ;
        ans=max(length,ans);
        if(val==0){
            zigzag(root->right,1,length+1,ans);
            zigzag(root->left,0,1,ans);
        }
        else{
            zigzag(root->left,0,length+1,ans);
            zigzag(root->right,1,1,ans);
        }
        


    }
    

    int longestZigZag(TreeNode* root) {
        int ans=0;
        zigzag(root,0,0,ans);
        zigzag(root,1,0,ans);
        return ans;
    }
};