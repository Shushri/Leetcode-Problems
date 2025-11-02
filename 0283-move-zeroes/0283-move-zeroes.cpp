class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            
            if(j<nums.size() && nums[j]==0 && nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
            if(nums[j]!=0){
                j++;
            }
        }
    }
};