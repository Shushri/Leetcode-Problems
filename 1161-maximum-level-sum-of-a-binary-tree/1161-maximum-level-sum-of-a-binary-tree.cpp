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
    
    vector<TreeNode*> f(vector<TreeNode*>& arr){
        vector<TreeNode*> ans;
        
        for (auto ele:arr){
            if(ele->left){
                
                ans.push_back((ele->left));
            }
            if(ele->right){
                
                ans.push_back((ele->right));
            }
        }
        return ans;

    }
    int maxLevelSum(TreeNode* root) {
        
        vector<TreeNode*> arr;
        arr.push_back(root);
        int sum=root->val;
        int c=2;
        int level=1;
        while(arr.size()>0){
            arr=f(arr);
            if(arr.size()==0){
                break;
            }
            int sm=0;
            for(int i=0;i<arr.size();i++){
                sm+=(arr[i]->val);
            }
            if(sm>sum){
                sum=sm;
                level=c;
            }
            c++;
        }
        return level;
    }
};