class Solution {
public:
    int MOD = 1000000007;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            reverse(dp.begin(), dp.end());
            int sum = 0;

            for (int i = 0; i < dp.size(); i++) {
                int old = dp[i];
                dp[i] = sum;
                sum = (sum + old) % MOD;
                }
        }

        return ((accumulate(dp.begin(), dp.end(), 0LL) % MOD) << 1) % MOD;
    }
};