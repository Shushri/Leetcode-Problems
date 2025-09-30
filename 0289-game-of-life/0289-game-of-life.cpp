class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Directions for 8 neighbors
        vector<vector<int>> dirs = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},          {0,1},
            {1,-1}, {1,0}, {1,1}
        };

        // First pass: compute next state
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live = 0;
                for(auto &d : dirs){
                    int ni = i + d[0], nj = j + d[1];
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        live += board[ni][nj] & 1; // take only old state
                    }
                }

                // Apply rules, store next state in 2nd bit
                if(board[i][j] == 1 && (live == 2 || live == 3)){
                    board[i][j] |= 2;  // set 2nd bit to 1
                }
                if(board[i][j] == 0 && live == 3){
                    board[i][j] |= 2;
                }
            }
        }

        // Second pass: update board to next state
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] >>= 1; // take next state from 2nd bit
            }
        }
    }
};
