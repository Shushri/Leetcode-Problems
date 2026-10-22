class Solution {
public:
    int f(int ind,vector<int>& cost,vector<int> &dp){
        
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int x1=cost[ind]+f(ind+1,cost,dp);
        int x2=cost[ind]+f(ind+2,cost,dp);

        return dp[ind]=min(x1,x2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        int ind0=f(0,cost,dp);
        int ind1=f(1,cost,dp);
        return min(ind0,ind1);
    }
};