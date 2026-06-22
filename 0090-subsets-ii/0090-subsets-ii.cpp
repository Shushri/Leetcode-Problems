class Solution {
public:
    void f(int ind,vector<int>& nums,vector<vector<int>> &ans,vector<int> &arr){
            ans.push_back(arr);
        
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]){
                continue;
            }
            arr.push_back(nums[i]);
            f(i+1,nums,ans,arr);
            arr.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> arr;
        f(0,nums,ans,arr);
        return ans;
    }
};