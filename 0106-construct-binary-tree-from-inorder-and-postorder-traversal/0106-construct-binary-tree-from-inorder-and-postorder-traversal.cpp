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
    TreeNode* build(vector<int>& ino,int is,int ie, vector<int>& poso,int ps,int pe,unordered_map<int,int>& mpp ){
        if(is>ie || ps>pe){
            return nullptr;
        }
        TreeNode* nd=new TreeNode(poso[pe]);
        int ind=mpp[poso[pe]];
        int lft=ind-is;
        nd->left=build(ino,is,ind-1,poso,ps,ps+lft-1,mpp);
        nd->right=build(ino,ind+1,ie,poso,ps+lft,pe-1,mpp);
        return nd;
    }
    TreeNode* buildTree(vector<int>& ino, vector<int>& poso) {
        if(ino.size()==0 || poso.size()==0){
            return nullptr;
        }
        unordered_map<int,int> mpp;
        for(int i=0;i<ino.size();i++){
            mpp[ino[i]]=i;
        }
        return build(ino,0,ino.size()-1,poso,0,poso.size()-1,mpp);


    }
};