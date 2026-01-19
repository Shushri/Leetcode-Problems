class Solution {
public:
    int rsum(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;
        for (int j = 0; j < k; j++)
            target += grid[r][c + j];

        for (int i = r + 1; i < r + k; i++) {
            int sm = 0;
            for (int j = 0; j < k; j++)
                sm += grid[i][c + j];
            if (sm != target) return -1;
        }
        return target;
    }

    int csum(vector<vector<int>>& grid, int r, int c, int k) {
        int target = 0;
        for (int i = 0; i < k; i++)
            target += grid[r + i][c];

        for (int j = c + 1; j < c + k; j++) {
            int sm = 0;
            for (int i = 0; i < k; i++)
                sm += grid[r + i][j];
            if (sm != target) return -1;
        }
        return target;
    }

    int dsum(vector<vector<int>>& grid, int r, int c, int k) {
        int d1 = 0, d2 = 0;
        for (int i = 0; i < k; i++) {
            d1 += grid[r + i][c + i];
            d2 += grid[r + i][c + k - 1 - i];
        }
        return (d1 == d2) ? d1 : -1;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int k = min(n, m); k >= 2; k--) {
            for (int r = 0; r + k <= n; r++) {
                for (int c = 0; c + k <= m; c++) {

                    int a = rsum(grid, r, c, k);
                    if (a == -1) continue;

                    int b = csum(grid, r, c, k);
                    if (b == -1 || a != b) continue;

                    int d = dsum(grid, r, c, k);
                    if (d == -1 || d != a) continue;

                    return k;
                }
            }
        }
        return 1;
    }
};
