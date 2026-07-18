class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int ind=2;ind<cost.size();ind++){
            int a=dp[ind-1];
            int b=dp[ind-2];
            dp[ind]=cost[ind]+min(a,b);
        }
        return min(dp[cost.size()-1],dp[cost.size()-2]);
    }
};