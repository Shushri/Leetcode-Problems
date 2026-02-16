class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(l==h){
                return l;
            }
            if(mid-1>=0 && mid+1<n && nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]){
                return mid;
            }
            else{
                if(nums[mid]<nums[mid+1]){
                    l=l+1;
                }
                else{
                    h=h-1;
                }
            }

        }
        return l;
    }
};