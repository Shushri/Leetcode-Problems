class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
         for(int i = x; i < x + k/2; i++){
            for(int j = y; j < y + k; j++){
                int pos = x + k - 1 - (i - x);

                swap(grid[i][j], grid[pos][j]);
            }
        }

        return grid;
    }
};