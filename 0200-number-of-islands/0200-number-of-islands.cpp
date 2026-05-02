class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid,vector<int> dir ,vector<int> dic  ){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int rw=r+dir[i];
            int cl=c+dic[i];
            if(rw>=0 && rw<n && cl>=0 && cl<m && grid[rw][cl]=='1' && !vis[rw][cl]){
                dfs(rw,cl,vis,grid,dir,dic);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dir = {0,1,0,-1};
        vector<int> dic = {1,0,-1,0};
        vector<vector<int>> vis(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,vis,grid,dir,dic);
                }
            }
        }
        return ans;
    }
};