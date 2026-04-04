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
    TreeNode* build(vector<int>& pre,int ps,int pe,vector<int>& ino,int is,int ie,unordered_map<int,int>& mpp){
        if(ps>pe || is>ie){
            return nullptr;
        }
        TreeNode* nd=new TreeNode(pre[ps]);
        int pos=mpp[pre[ps]];
        int diff=pos-is;
        nd->left=build(pre,ps+1,ps+diff,ino,is,pos-1,mpp);
        nd->right=build(pre,ps+1+diff,pe,ino,pos+1,ie,mpp);
        return nd;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int m=preorder.size();
        if(n!=m){
            return nullptr;
        }
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};