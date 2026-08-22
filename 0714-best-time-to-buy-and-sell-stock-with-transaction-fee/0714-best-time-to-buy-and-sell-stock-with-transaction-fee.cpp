class Solution {
public:
    
    int maxProfit(vector<int>& p, int fee) {
        int n=p.size();
        vector<vector<int>> dp(p.size()+1,vector<int>(2,0));
        int buy=1;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j){
                    dp[i][j]=max(-p[i]+dp[i+1][0],0+dp[i+1][1]);
                }
                else{
                    dp[i][j]=max(p[i]+dp[i+1][1]-fee,0+dp[i+1][0]);
                }
            }
        }

        return dp[0][1];
    }
};