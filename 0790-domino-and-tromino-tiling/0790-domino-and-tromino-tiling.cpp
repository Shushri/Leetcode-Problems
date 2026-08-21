class Solution {
public:
    long long MOD=1e9 + 7;
    
    int numTilings(int n){

        vector<vector<long long>> dp(n+2,vector<long long>(2,0));
        dp[n][0]=1;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            dp[i][1]=(dp[i+1][0]+dp[i+1][1])%MOD;
            dp[i][0]=(dp[i+1][0]+dp[i+2][0]+2L*dp[i+2][1])%MOD;
        }
        

        return dp[0][0];
    }

};