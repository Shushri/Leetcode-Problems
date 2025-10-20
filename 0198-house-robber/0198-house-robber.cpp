class Solution {
public:
    int f(int ind,vector<int>& nums,int n,vector<int>&dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];

        int pick=nums[ind]+f(ind-2,nums,n,dp);
        int npick=0+f(ind-1,nums,n,dp);

        return dp[ind]= max(pick,npick);
    }
    int rob(vector<int>& nums) {
        //this is a recurrence subsesquence problem with one extra constraint that the elements cant be take adjacent
        vector<int> dp(nums.size(),-1);
        return f(nums.size()-1,nums,nums.size(),dp);
        
    }
};