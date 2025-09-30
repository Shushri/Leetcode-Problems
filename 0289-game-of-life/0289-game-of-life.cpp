class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> copy = board; // keep a copy for neighbor counts

        for (int i = 0; i < n; i++) {         // ✅ loop rows correctly
            for (int j = 0; j < m; j++) {     // ✅ loop cols correctly
                int c1 = 0;

                // check 8 neighbors
                if (i - 1 >= 0 && j - 1 >= 0 && copy[i - 1][j - 1] == 1) c1++;
                if (i - 1 >= 0 && copy[i - 1][j] == 1) c1++;
                if (i - 1 >= 0 && j + 1 < m && copy[i - 1][j + 1] == 1) c1++;
                if (j + 1 < m && copy[i][j + 1] == 1) c1++;
                if (i + 1 < n && j + 1 < m && copy[i + 1][j + 1] == 1) c1++;
                if (i + 1 < n && copy[i + 1][j] == 1) c1++;
                if (i + 1 < n && j - 1 >= 0 && copy[i + 1][j - 1] == 1) c1++;
                if (j - 1 >= 0 && copy[i][j - 1] == 1) c1++;

                // apply rules
                if (copy[i][j] == 1) {
                    if (c1 < 2 || c1 > 3) board[i][j] = 0;
                    else board[i][j] = 1;
                } else {
                    if (c1 == 3) board[i][j] = 1;
                }
            }
        }
    }
};
