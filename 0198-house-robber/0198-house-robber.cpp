class Solution {
public:


    int rob(vector<int>& nums) {
        //converting to tabulation form
        //space optimization
        int n=nums.size();
        
        int prev2=nums[0];
        int prev1=nums[0];
        int curr=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1){
                pick+=prev2;
            } 
            int npick=0+prev1;
            curr=max(pick,npick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
    }
};