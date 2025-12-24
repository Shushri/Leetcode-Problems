class Solution {
public:
    int n;
    vector<int> dp;

    int f(int i, vector<int>& cost) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(f(i + 1, cost), f(i + 2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n, -1);
        return min(f(0, cost), f(1, cost));
    }
};
