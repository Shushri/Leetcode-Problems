class Solution {
public:
    static constexpr int MIN = -50000001;
    static inline string s[] = {"Bob", "Tie", "Alice"};

    int solve(int i, vector<int>& A, vector<int>& dp) {
        int n = A.size();

        if (i >= n) return 0;

        if (dp[i] != MIN) return dp[i];

        int a = A[i] - solve(i + 1, A, dp);
        int b = MIN, c = MIN;

        if (i + 1 < n)
            b = A[i] + A[i + 1] - solve(i + 2, A, dp);

        if (i + 2 < n)
            c = A[i] + A[i + 1] + A[i + 2] - solve(i + 3, A, dp);

        return dp[i] = max(a, max(b, c));
    }

    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, MIN);

        int d = solve(0, A, dp);

        return s[(d > 0) - (d < 0) + 1];
    }
};