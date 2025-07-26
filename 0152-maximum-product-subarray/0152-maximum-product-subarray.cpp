class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();int ans=INT_MIN;
            int p=1;
            int r=1;
            for (int i=0;i<n;i++){
                p*=nums[i];
                r*=nums[n-i-1];
                ans=max(ans, max(p,r));
                if(nums[i]==0 ){
                    p=1;
                }
                if(nums[n-i-1]==0 ){
                    r=1;
                }
                
            }
        return ans;
    }
};