class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    void f(int ind,int n,int k,vector<int>& nums){
        if(ind==nums.size()){
            if(n==0 && k==0){
                ans.push_back(arr);
            }
            return;
        }

        if(n>=nums[ind]){
            arr.push_back(nums[ind]);
            f(ind+1,n-nums[ind],k-1,nums);
            arr.pop_back();
        }
        f(ind+1,n,k,nums);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        f(0,n,k,nums);
        return ans;
    }
};