class Solution {
public:
    void f(int ind,int k,int n,vector<int> &nums,vector<int> &arr,vector<vector<int>> &ans){
        if(ind==nums.size()){
            if(k==0 && n==0){
                ans.push_back(arr);
            }
            return; 
        }

        if(nums[ind]<=n){
            arr.push_back(nums[ind]);
            f(ind+1,k-1,n-nums[ind],nums,arr,ans);
            arr.pop_back();
        }
        f(ind+1,k,n,nums,arr,ans);


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> arr;
        f(0,k,n,nums,arr,ans);
        return ans;
    }
};