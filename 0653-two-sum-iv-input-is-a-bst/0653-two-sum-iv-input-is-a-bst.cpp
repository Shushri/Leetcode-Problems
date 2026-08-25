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
class BSTiterator{
    private:
        stack<TreeNode*> st;
        bool reverse;
    public:
        BSTiterator(TreeNode* root,bool rev){
            reverse=rev;
            pushAll(root);
            
        }
        bool hasNext(TreeNode* root){
            return !st.empty();
        }
        int next(){
            TreeNode* x=st.top();
            st.pop();
            if(reverse) pushAll(x->left);
            else pushAll(x->right);
            return x->val;
        }
    private:
        void pushAll(TreeNode* root){
            while(root!=NULL){
                st.push(root);
                if(reverse){
                    
                    root=root->right;
                }
                else{
                    
                    root=root->left;

                }
            }
        }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k){
          BSTiterator l(root,false);
          BSTiterator r(root,true);
            int i=l.next();
            int j=r.next();
          while(i<j){
            int sm=i+j;
            if(sm==k) return true;
            else if(sm<k){
                i=l.next();
            }
            else{
                j=r.next();
            }
          }
          return false;
    }
};