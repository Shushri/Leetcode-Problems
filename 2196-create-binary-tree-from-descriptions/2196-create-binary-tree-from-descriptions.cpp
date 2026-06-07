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
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        int n=des.size();
        unordered_map<int,pair<TreeNode*,int>> mpp;//{val,{add,child or not}}
        for(int i=0;i<n;i++){
            TreeNode* pr;
            TreeNode* ch;
            if(mpp.count(des[i][0])==0){
                pr=new TreeNode(des[i][0]);
                mpp[des[i][0]]={pr,0};
            }
            else{
                pr=mpp[des[i][0]].first;
            }
            if(mpp.count(des[i][1])==0){
                ch=new TreeNode(des[i][1]);
                mpp[des[i][1]]={ch,1};
            }
            else{
                ch=mpp[des[i][1]].first;
                mpp[des[i][1]].second=1;
            }
            if(des[i][2]==1){
                pr->left=ch;

            }
            else{
                pr->right=ch;
            }
            


        }
        for(auto ele:mpp){
            if(ele.second.second==0){
                return ele.second.first;
            }
        }
        return NULL;
    }
};