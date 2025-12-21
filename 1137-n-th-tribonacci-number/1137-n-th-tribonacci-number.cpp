class Solution {
public:
    int f(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        else if(n<=2){
            return 1;
        }
        if(dp[n]!=-1) return dp[n];
        int a=f(n-1,dp);
        int b=f(n-2,dp);
        int c=f(n-3,dp);
        return dp[n]=a+b+c;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};