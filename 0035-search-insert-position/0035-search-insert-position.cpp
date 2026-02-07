class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        int ans=0;
        if(target>nums[h]){
            return h+1;
        }
        while(l<=h){
            int mid=l-(l-h)/2;
            if(nums[mid]>=target){
                ans=mid;
                h=h-1;
            }
            else{
                l=l+1;
            }
        }
        return ans;
    }
};