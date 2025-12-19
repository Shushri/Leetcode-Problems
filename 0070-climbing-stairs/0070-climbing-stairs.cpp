class Solution {
public:
    
    int count(int n, vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n]; 
        }
        int r=0;
        int l= count(n-1,dp);
        if(n>=2){
            r= count(n-2,dp);
        }
        return dp[n]=l+r;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return count(n,dp);
        
    }
};