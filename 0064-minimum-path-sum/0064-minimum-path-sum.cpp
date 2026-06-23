class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,-1));
        dp[n-1][m-1]=grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) dp[i][j]=grid[n-1][m-1];
                else{
                    long long r=INT_MAX;
                    long long d=INT_MAX;
                    if(i<n-1) d=dp[i+1][j];
                    if(j<m-1) r=dp[i][j+1];
                    dp[i][j]=grid[i][j]+min(r,d);
                }
            }

        }
        return dp[0][0];

    }
};