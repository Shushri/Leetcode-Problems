class Solution {
public:

    
    int count(int n, int c,vector<int>&dp){
        if(c>n) return 0;
        if(c==n){
            return 1;
        }
        if(dp[c]!=-1){
            return dp[c];
        }
        dp[c]=count(n,c+1,dp)+count(n,c+2,dp);
        return dp[c];
        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,0,dp);
        
    }
};