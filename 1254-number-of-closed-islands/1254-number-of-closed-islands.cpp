class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<int> &dr,vector<int> &dc){
        grid[i][j]=1;
        for(int p=0;p<4;p++){
            int rw=i+dr[p];
            int cl=j+dc[p];
            if(rw>=0 && rw<grid.size() && cl>=0 && cl<grid[0].size() && grid[rw][cl]==0){
                dfs(rw,cl,grid,dr,dc);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dc={0,1,0,-1};
        vector<int> dr={1,0,-1,0};
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                dfs(i,0,grid,dr,dc);
            }
        }

        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0){
                dfs(i,m-1,grid,dr,dc);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                dfs(0,i,grid,dr,dc);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]==0){
                dfs(n-1,i,grid,dr,dc);
            }
        }

        int ans=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(i,j,grid,dr,dc);
                }
            }
        }
        return ans;
    }
};