class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        int z=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xr=nums[i]^xr;
            if(nums[i]==0) z++;
        }
        if(z==n){
            return 0;
        }
        if(xr!=0){
            return n;
        }
        for(int i=0;i<n;i++){
            xr=nums[i]^xr;
        }
        return n-1;
    }
};