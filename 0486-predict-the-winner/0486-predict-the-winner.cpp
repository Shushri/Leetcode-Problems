class Solution {
public:
    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (i == j) return dp[i][j] = a[i];

        return dp[i][j] = max(
            a[i] - f(i + 1, j, a, dp),
            a[j] - f(i, j - 1, a, dp)
        );
    }

    bool predictTheWinner(vector<int>& a) {
        int n = a.size();

        if (!(n & 1)) return true;

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return f(0, n - 1, a, dp) >= 0;
    }
};