class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int p = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    // top
                    if (i == 0 || grid[i-1][j] == 0) p++;
                    // bottom
                    if (i == r-1 || grid[i+1][j] == 0) p++;
                    // left
                    if (j == 0 || grid[i][j-1] == 0) p++;
                    // right
                    if (j == c-1 || grid[i][j+1] == 0) p++;
                }
            }
        }
        return p;
    }
};
