class Solution {
public:
    int f(int ind,int buy,vector<int>& p,vector<vector<int>> &dp){
        //base case
        if(ind>=p.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        int prft=0;
        if(buy==1){
            prft=max(-p[ind]+f(ind+1,0,p,dp),0+f(ind+1,1,p,dp));
        }
        else{
            prft=max(p[ind]+f(ind+2,1,p,dp),0+f(ind+1,0,p,dp));
        }
        return dp[ind][buy]=prft;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,p,dp);

    }
};