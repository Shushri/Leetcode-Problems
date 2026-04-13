class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i=start;
        int j=start;
        int n=nums.size();
        if(nums[i]==target){
            return 0;
        }
        while(true){
            if(i<n){
               if(nums[i]==target){
                return abs(i-start);
               } 
               else{
                i++;
               }
            }
            if(j>=0){
               if(nums[j]==target){
                return abs(j-start);
               } 
               else{
                j--;
               }
            }
        }
        return -1;
    }
};