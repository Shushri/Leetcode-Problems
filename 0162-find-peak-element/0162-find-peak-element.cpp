class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid==0){
                if(nums[1]<nums[0]){
                    return 0;
                }
                l=mid+1;
            }
            else if(mid==n-1){
                if(nums[n-1]>nums[n-2]){
                    return n-1;
                }
                h=mid-1;
            }
            else if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                h=mid-1;
            }

        }
        return -1;
    }
};