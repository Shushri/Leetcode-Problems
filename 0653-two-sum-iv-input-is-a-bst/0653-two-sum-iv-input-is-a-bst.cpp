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
    vector<int> arr;
    void inorder(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k)
         {
            inorder(root);
        int n=arr.size();
        int l=0;int h=n-1;
        
        while(l<h){
            int sm=arr[l]+arr[h];
            if(sm==k){
                return true;
            }
            else if(k<sm){
                h--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};