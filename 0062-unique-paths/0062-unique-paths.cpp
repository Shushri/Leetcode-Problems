class Solution {
public:
    int f(int n,int m,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 1;
        }
        if(n<0 || m<0){
            return 0;
        }
        if(dp[n][m]!=-1) return dp[n][m];
        int left=f(n,m-1,dp);
        int up=f(n-1,m,dp);
        return dp[n][m]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,dp);
    }
};