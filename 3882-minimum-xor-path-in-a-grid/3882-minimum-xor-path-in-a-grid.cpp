class Solution {
public:
    int f(int i,int j, vector<vector<int>>& grid,int xr,vector<vector<vector<int>>> &dp){
        xr=xr^grid[i][j];
        if(i==0 && j==0){
            return xr;
        }
        if(dp[i][j][xr]!=-1) return dp[i][j][xr];
        int l=INT_MAX;
        int r=INT_MAX; 
        if(i-1>=0) l=f(i-1,j,grid,xr,dp);
        if(j-1>=0) r=f(i,j-1,grid,xr,dp);
        return dp[i][j][xr]=min(l,r);
        
    }
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mn=INT_MAX;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(1024,-1)));
        return f(n-1,m-1,grid,0,dp);
        
    }
};