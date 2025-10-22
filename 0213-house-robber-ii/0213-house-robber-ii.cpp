class Solution {
public:
    int f(int ind, vector<int>& nums, vector<int>& dp){
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind-2, nums, dp);
        int npick = f(ind-1, nums, dp);
        return dp[ind] = max(pick, npick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // edge case: only one house
        // Case 1: exclude last house
        vector<int> dp1(n, -1);
        int case1 = f(n-2, nums, dp1);
        // Case 2: exclude first house
        vector<int> dp2(n, -1);
        vector<int> nums2(nums.begin()+1, nums.end()); // new vector for 1..n-1
        int case2 = f(nums2.size()-1, nums2, dp2);

        return max(case1, case2);
    }
};
