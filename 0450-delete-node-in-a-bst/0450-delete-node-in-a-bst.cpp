class Solution {
public:
    TreeNode* findRight(TreeNode* root){
        while(root->right)
            root=root->right;
        return root;
    }

    TreeNode* f1(TreeNode* root){
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        TreeNode* nd=findRight(root->left);
        nd->right=root->right;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key)
            return f1(root);

        if(key<root->val)
            root->left=deleteNode(root->left,key);
        else
            root->right=deleteNode(root->right,key);

        return root;
    }
};