class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==n || j==m){
            return INT_MAX;
        }
        if(i==n-1 && j==m-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=grid[i][j]+min(f(i+1,j,n,m,grid,dp),f(i,j+1,n,m,grid,dp));
        
   }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,n,m,grid,dp);

    }
};