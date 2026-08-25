class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> size(n, 1);

        int mx = 1;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < i; j++) {

                if(nums[j] < nums[i]) {

                    // Found a longer LIS ending at i
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        size[i] = size[j];
                    }

                    // Found another LIS of same maximum length
                    else if(dp[j] + 1 == dp[i]) {
                        size[i] += size[j];
                    }
                }
            }

            mx = max(mx, dp[i]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == mx) {
                ans += size[i];
            }
        }

        return ans;
    }
};