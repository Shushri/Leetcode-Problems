class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                
            }
        }
        vector<int> dr={0,1,0,-1};
        vector<int> dc={1,0,-1,0};

        
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            vis[r][c]=1;
            q.pop();
            for(int i=0;i<4;i++){
                int rw=r+dr[i];
                int cl=c+dc[i];
                if(rw>=0 && rw<n && cl>=0 && cl<m && board[rw][cl]=='O' && !vis[rw][cl]){
                    q.push({rw,cl});
                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }

    }
};