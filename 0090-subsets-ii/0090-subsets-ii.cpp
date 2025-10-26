class Solution {
public:
    vector<vector<int>> ans;
   
    void f(int ind,vector<int>& nums,int n,vector<int>& arr){
        
        ans.push_back(arr);
        
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1] ) continue;
            arr.push_back(nums[i]);
            f(i+1,nums,n,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> arr;
        f(0,nums,nums.size(),arr);
        return ans;
    }
};