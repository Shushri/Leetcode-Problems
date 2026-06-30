class Solution {
public:
    int f(int ind,int buy,vector<int> &p,vector<vector<int>> &dp){
        if(ind==p.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy==1){
            profit=max(-p[ind]+f(ind+1,0,p,dp),0+f(ind+1,1,p,dp));
        }
        else{
            profit=max(p[ind]+f(ind+1,1,p,dp),0+f(ind+1,0,p,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size(),vector<int>(2,-1));
        return f(0,1,p,dp);
    }
};