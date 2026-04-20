class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis,vector<int> &rr,vector<int> &cc){
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<4;i++){
            int r1=r+rr[i];
            int c1=c+cc[i];
            if(r1>=0 && r1<n && c1>=0 && c1<m && board[r1][c1]=='O' && !vis[r1][c1]){
                vis[r1][c1]=1;
                dfs(r1,c1,board,vis,rr,cc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> rr={0,1,0,-1};
        vector<int> cc={1,0,-1,0};
        for(int i=0;i<m;i++){
            if(board[0][i]=='O' && !vis[0][i]){
                dfs(0,i,board,vis,rr,cc);
            }

            if(board[n-1][i]=='O' && !vis[n-1][i]){
                dfs(n-1,i,board,vis,rr,cc);
            }

        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,rr,cc);
            }

            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,rr,cc);
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