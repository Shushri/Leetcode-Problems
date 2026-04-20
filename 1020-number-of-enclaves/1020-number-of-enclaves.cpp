class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<int> &rr,vector<int> &cc){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int r1=r+rr[i];
            int c1=c+cc[i];
            if(r1<n && r1>=0 && c1<m && c1>=0 && !vis[r1][c1] && grid[r1][c1]==1){
                vis[r1][c1]=1;
                dfs(r1,c1,grid,vis,rr,cc);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> rr={0,-1,0,1};
        vector<int> cc={-1,0,1,0};
        for(int i=0;i<m;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i,grid,vis,rr,cc);
            }
            if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1,i,grid,vis,rr,cc);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,grid,vis,rr,cc);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis,rr,cc);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};