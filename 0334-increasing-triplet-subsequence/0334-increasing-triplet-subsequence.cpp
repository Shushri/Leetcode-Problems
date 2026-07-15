class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1=INT_MAX;
        int n2=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<=n1){
                n1=nums[i];
            }
            else if(nums[i]<=n2){
                n2=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};