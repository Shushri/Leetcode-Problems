class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        const int MOD = 1e9 + 7;
      vector<vector<pair<long long, long long>>> dp(r, vector<pair<long long, long long>>(c));

        dp[0][0] = {grid[0][0], grid[0][0]};

        for(int j = 1; j < c; j++){
            long long val = grid[0][j];
            dp[0][j].first = dp[0][j-1].first * val;
            dp[0][j].second = dp[0][j].first;
        }

        for(int i = 1; i < r; i++){
            long long val = grid[i][0];
            dp[i][0].first = dp[i-1][0].first * val;
            dp[i][0].second = dp[i][0].first;
        }

        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                long long val = grid[i][j];

                long long a = dp[i-1][j].first * val;
                long long b = dp[i-1][j].second * val;
                long long c1 = dp[i][j-1].first * val;
                long long d = dp[i][j-1].second * val;

                long long mn = min({a, b, c1, d});
                long long mx = max({a, b, c1, d});

                dp[i][j] = {mn, mx};
            }
        }

        long long ans = dp[r-1][c-1].second;

        if(ans < 0) return -1;
        return ans % MOD;
    }
};