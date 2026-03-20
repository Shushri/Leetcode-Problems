class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));

        for(int i = 0; i <= n - k; i++) {
            for(int j = 0; j <= m - k; j++) {

                set<int> st;

                for(int i1 = i; i1 < i + k; i1++) {
                    for(int j1 = j; j1 < j + k; j1++) {
                        st.insert(grid[i1][j1]);
                    }
                }

                if(st.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }

                vector<int> temp(st.begin(), st.end());

                int mn = INT_MAX;
                for(int i2 = 1; i2 < temp.size(); i2++) {
                    mn = min(mn, temp[i2] - temp[i2 - 1]);
                }

                ans[i][j] = mn;
            }
        }

        return ans;
    }
};