class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h){
            int mid=l-(l-h)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target>nums[mid]){
                l=l+1;
            }
            if(target<nums[mid]){
                h=h-1;
            }
        }
        return -1;
    }
};