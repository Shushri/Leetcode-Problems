class Solution {
public:
    int MODD=1e9+7;
    int f(int i,int j,int n,int m,int prev, vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){

        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i==n){
            return 0;
        }
        if(j==m){
            return 0;
        }
        if(dp[i][j][prev]!=-1) return dp[i][j][prev];
        int l=0;
        int r=0;
        if(grid[i][j]==1){
            if(prev==1){
                l=f(i,j+1,n,m,2,grid,dp);
            }
            else if(prev==2){
                r=f(i+1,j,n,m,1,grid,dp);
            }
            else{
                l=f(i,j+1,n,m,2,grid,dp);
                r=f(i+1,j,n,m,1,grid,dp);
            }
        }
        else{
            l=f(i,j+1,n,m,2,grid,dp);
            r=f(i+1,j,n,m,1,grid,dp);
        }

        return dp[i][j][prev]=(l+r)%MODD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
        return f(0,0,n,m,0,grid,dp);
    }
};