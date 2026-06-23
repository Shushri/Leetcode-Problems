class Solution {
public:
   
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[i][j]=1;
                }
                else{
                    int right=0;
                    int down=0;
                    if(i<m-1) right=dp[i+1][j];
                    if(j<n-1) down=dp[i][j+1];
                    dp[i][j]=right+down;
                }
            }
        }
        return dp[0][0];
    }
};