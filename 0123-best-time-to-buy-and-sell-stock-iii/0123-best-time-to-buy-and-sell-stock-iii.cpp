class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>& p,vector<vector<vector<int>>> &dp){
        if(ind==p.size()) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy==1){
            profit=max(-p[ind]+f(ind+1,0,cap,p,dp),0+f(ind+1,1,cap,p,dp));
        }
        else{
            profit=max(p[ind]+f(ind+1,1,cap-1,p,dp),0+f(ind+1,0,cap,p,dp));
        }
        return dp[ind][buy][cap]= profit;

    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,p,dp);
    }
};