class Solution {
public:
    int f(int ind,int buy,vector<int>& p, int &fee,vector<vector<int>> &dp){
        if(ind==p.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]=max(-p[ind]+f(ind+1,0,p,fee,dp),0+f(ind+1,1,p,fee,dp));

        }
        else{
            return dp[ind][buy]=max(p[ind]+f(ind+1,1,p,fee,dp)-fee,0+f(ind+1,0,p,fee,dp));
        }
    }
    int maxProfit(vector<int>& p, int fee) {
        vector<vector<int>> dp(p.size()+1,vector<int>(2,-1));
        return f(0,1,p,fee,dp);
    }
};