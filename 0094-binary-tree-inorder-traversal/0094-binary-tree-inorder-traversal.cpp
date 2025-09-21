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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int > ans;
        stack<TreeNode*> st;
        TreeNode* r=root;
        while(true){
            if(r!=NULL){
                st.push(r);
                r=r->left;
            }
            else{
                if(st.empty()) break;
                TreeNode* tp=st.top();
                st.pop();
                ans.push_back(tp->val);
                r=tp->right;
            }
        }
        return ans;
    }
};