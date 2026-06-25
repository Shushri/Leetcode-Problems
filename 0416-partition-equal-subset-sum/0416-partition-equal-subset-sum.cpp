class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //tabulation method
        int n=nums.size();

        int tot=accumulate(nums.begin(),nums.end(),0);
        //odd
        if(tot&1) return false;
        int t=tot/2;
        
        vector<vector<bool>> dp(n,vector<bool>(t+1,false));
        //target=0 is always possible
        for(int i=0;i<n;i++){
            dp[i][0]=true;
            
        }
        //the first element of array check (base cond in recursive approach) if it is less than the target then its possible to take it otherwise false
        if(nums[0]<=t){
            dp[0][nums[0]]=true;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int sm=1;sm<=t;sm++){
                
                bool take=false;
                if(sm>=nums[ind]) take=dp[ind-1][sm-nums[ind]];
                bool nttake=dp[ind-1][sm];
                
                dp[ind][sm]=take || nttake;
            }
        }
        return dp[n-1][t];
    }
};