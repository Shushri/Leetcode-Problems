class Solution {
public:
    const int M = 1e9 + 7;

    int dp[1002][1002];
    int prefixDp[1002][1002];

    int mod(int a) {
        return (a % M + M) % M;
    }

    int add(int a, int b) {
        return (1LL * a + b) % M;
    }

    int multiply(int a, int b) {
        return 1LL * a * b % M;
    }

    // Returns sum of ways for 1...n points
    int prefixWays(int n, int k) {
        if (n <= 0)
            return 0;

        if (prefixDp[n][k] != -1)
            return prefixDp[n][k];

        return prefixDp[n][k] =
            add(prefixWays(n - 1, k), countWays(n, k));
    }

    // Returns number of ways to make k segments using n points
    int countWays(int n, int k) {

        if (k == 0)
            return 1;

        if (n <= 1 || n - 1 < k)
            return 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        // Only one segment
        if (k == 1)
            return dp[n][k] = 1LL * n * (n - 1) / 2 % M;

        int total = 0;

        // Don't use the last point
        total = add(total, countWays(n - 1, k));

        // Make a segment ending at the last point
        total = add(total, prefixWays(n - 1, k - 1));

        return dp[n][k] = total;
    }

    int numberOfSets(int n, int k) {
        memset(dp, -1, sizeof(dp));
        memset(prefixDp, -1, sizeof(prefixDp));

        return countWays(n, k);
    }
};