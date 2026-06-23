class Solution {
public:
    int f(int ind,int mx,vector<int>& nums,vector<int>& dp){
        if(ind>mx){
            return 0;
        }
        if(ind==mx){
            return nums[ind];
        }
        if(dp[ind]!=-1) return dp[ind];
        int taken=nums[ind]+f(ind+2,mx,nums,dp);
        int nttaken=0+f(ind+1,mx,nums,dp);

        return dp[ind]=max(taken,nttaken);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> dp1(n+1,-1);
        int case1=f(0,n-2,nums,dp1);
        vector<int> dp2(n+1,-1);
        int case2=f(1,n-1,nums,dp2);
        return max(case1,case2);
    }
};