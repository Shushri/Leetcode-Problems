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
    vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int n=arr.size();
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(arr[i]->val<arr[i-1]->val){
                ans.push_back(i);
            }
        }
        if(ans.size()==1){
            swap(arr[ans[0]]->val,arr[ans[0]-1]->val);
        }
        else if(ans.size()==2){
            swap(arr[ans[1]]->val,arr[ans[0]-1]->val);
        }
    }
};

//3 2 1

//1 3 2 4

//4 2 3 1

//1 5 3 4 2 6 