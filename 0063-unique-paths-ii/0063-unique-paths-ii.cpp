class Solution {
public:
    int f(int i,int j,int n,int m,vector<vector<int>>& og,vector<vector<int>> &dp){
        if(i==n  || j==m){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int r=0;
        int d=0;
        if(j+1<m && og[i][j+1]==0)  r=f(i,j+1,n,m,og,dp);
        if(i+1<n && og[i+1][j]==0)  d=f(i+1,j,n,m,og,dp);
        return dp[i][j]=r+d;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int n=og.size();
        int m=og[0].size();

        if(og[0][0]==1 || og[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,n,m,og,dp);
    }
};