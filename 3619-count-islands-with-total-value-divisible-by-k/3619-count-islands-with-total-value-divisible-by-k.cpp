class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>& grid,vector<int> &dr,vector<int> &dc, vector<vector<int>>& vis, long long &sum){
        vis[i][j]=1;
        sum+=grid[i][j];
        for(int p=0;p<4;p++){
            int rw=i+dr[p];
            int cl=j+dc[p];
            if(rw>=0 && rw<grid.size() && cl>=0 && cl<grid[0].size() && grid[rw][cl]!=0 && vis[rw][cl]==0){
                dfs(rw,cl,grid,dr,dc,vis,sum);
            }
        }
    }
  
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> dc={0,1,0,-1};
        vector<int> dr={1,0,-1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long sum=0;
                    dfs(i,j,grid,dr,dc,vis,sum);
                    if(sum%k==0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};