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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return check(root);
        }
        TreeNode* temp=root;
        while(temp){
            if(key<temp->val){
                if(temp->left && temp->left->val==key){
                    temp->left=check(temp->left);
                    break;
                }
                else{
                    temp=temp->left;
                }
                
            }
            else if(key>temp->val){
                if(temp->right && temp->right->val==key){
                    temp->right=check(temp->right);
                    break;
                }
                else{
                    temp=temp->right;
                }
            }

        }
        return root;
    }
    TreeNode* check(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        if(!root->right){
            return root->left;
        }
        
        TreeNode* x=findrightmost(root->left);
        x->right=root->right;
        return root->left; 
        

    }

    TreeNode* findrightmost(TreeNode* root){
        TreeNode* temp=root;
        while(temp->right){
            temp=temp->right;
        }
        return temp;
    }
};