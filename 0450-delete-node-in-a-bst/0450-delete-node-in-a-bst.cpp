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
    TreeNode* nextconnection(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        else{
            TreeNode* r=rightmost(root->left);
            r->right=root->right;
        }
        return root->left;
    }

    TreeNode* rightmost(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val==key){
            return nextconnection(root);
        }
        TreeNode* temp=root;
        while(temp){
            if(key<temp->val){
                if(temp->left && temp->left->val==key){
                    temp->left=nextconnection(temp->left);
                }
                else{
                    temp=temp->left;
                }
            }
            else if(key>temp->val){
                if(temp->right && temp->right->val==key){
                    temp->right=nextconnection(temp->right);
                }
                else{
                    temp=temp->right;
                }
            }

        }
        return root;
    }
    
};