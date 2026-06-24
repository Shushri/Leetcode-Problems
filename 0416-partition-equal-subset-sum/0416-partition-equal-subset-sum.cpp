class Solution {
public:
    bool f(int ind, int t,vector<int>& nums, int tot, vector<vector<int>> &dp){
        if(t==0){
            return true;
        }
        if(ind == 0) {
            return nums[0]==t;
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
        bool nttaken=f(ind-1,t,nums,tot,dp);
        bool taken=false;
        if(nums[ind]<=t){
            taken=f(ind-1,t-nums[ind],nums,tot,dp);
        }
        return dp[ind][t]=nttaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot&1) return false; 
        int sm=tot/2;
        vector<vector<int>> dp(n,vector<int>(tot+1,-1));
        return f(n-1,sm,nums,tot,dp);

    }
};

//sm+nums[0]==tot-sm-nums[0]