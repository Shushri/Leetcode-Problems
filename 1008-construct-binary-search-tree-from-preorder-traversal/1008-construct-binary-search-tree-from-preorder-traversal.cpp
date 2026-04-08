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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        TreeNode* temp=root;
        stack<TreeNode*> st;
        st.push(root);
        for(int i=1;i<preorder.size();i++){
            TreeNode* nd=new TreeNode(preorder[i]);
            if(preorder[i]<st.top()->val){
                
                st.top()->left=nd;
                
            }
            else{
                TreeNode* parent=NULL;
                while(!st.empty() && preorder[i]>st.top()->val){
                    parent=st.top();
                    st.pop();
                }
                
                parent->right=nd;
                
            }
            st.push(nd);
        }
        return root;
    }
};