class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int ind,vector<int> ds,vector<int>& nums,int n){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        backtrack(ind+1,ds,nums,n);

        ds.pop_back();
        backtrack(ind+1,ds,nums,n);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,{},nums,nums.size());
        return ans;
    }
};