class Solution {
public:
    int f(int ind,vector<int> &cost,vector<int> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0 || ind==1){
            return cost[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int a=f(ind-1,cost,dp);
        int b=f(ind-2,cost,dp);

        return dp[ind]=cost[ind]+min(a,b);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(f(cost.size()-1,cost,dp),f(cost.size()-2,cost,dp));
    }
};