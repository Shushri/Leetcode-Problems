class Solution {
public:
    int f(int ind,int t,vector<int>& nums,vector<vector<int>> &dp,int sm){
        if(abs(t)>sm){
            return 0;
        }
        if(ind==0){
            if(nums[0]==0 && t==0){
                return 2;
            }
            if(nums[0]+t==0 || nums[0]-t==0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][t+sm]!=-1) return dp[ind][t+sm];
        int plus=f(ind-1,t-nums[ind],nums,dp,sm);
        int minus=f(ind-1,t+nums[ind],nums,dp,sm);
        return dp[ind][t+sm]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int t) {
        int n=nums.size();
        int sm=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(2*sm+1,-1));
        return f(n-1,t,nums,dp,sm);
    }
};