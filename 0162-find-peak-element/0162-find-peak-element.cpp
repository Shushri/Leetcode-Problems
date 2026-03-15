class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        int l=1;
        int h=n-2;
        while(l<=h){
            int md=l+(h-l)/2;
            
            if(nums[md]>nums[md-1] && nums[md]>nums[md+1]){
                return md;
            }
            else if(nums[md]>=nums[md-1] ){
                l=md+1;
            }
            else{
                h=md-1;
            }
        }
        return -1;
    }
};