class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int z=0;
        int mx=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0) z++;
            while(z>1){
                if(nums[left]==0) z--;
                left++;
                
            }
            
            mx=max(mx,right-left);
            
            
        }
        return mx;
    }
};