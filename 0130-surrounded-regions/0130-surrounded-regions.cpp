class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        if(r-1>=0 && board[r-1][c]=='O' && !vis[r-1][c]){
            vis[r-1][c]=1;
            dfs(r-1,c,board,vis);
        }
        if(c-1>=0 && board[r][c-1]=='O' && !vis[r][c-1]){
            vis[r][c-1]=1;
            dfs(r,c-1,board,vis);
        }
        if(r+1<n && board[r+1][c]=='O' && !vis[r+1][c]){
            vis[r+1][c]=1;
            dfs(r+1,c,board,vis);
        }
        if(c+1<m && board[r][c+1]=='O' && !vis[r][c+1]){
            vis[r][c+1]=1;
            dfs(r,c+1,board,vis);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis);
            }

            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,board,vis);
            }

        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis);
            }

            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis);
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};