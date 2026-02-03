class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int b=0;
        int i=0;
        for(i;i<n;i++){
            if(i+1<n && nums[i]<nums[i+1]){
                b=1;
            }
            else{
                break;
            }
        }
        if(b==0){
            return false;
        }
        b=0;
        for(i;i<n;i++){
            if(i+1<n && nums[i]>nums[i+1]){
                b=1;
            }
            else{
                break;
            }
        }
        if(b==0){
            return false;
        }
        b=0;
        for(i;i<n;i++){
            if(i+1<n && nums[i]<nums[i+1]){
                b=1;
            }
            else{
                break;
            }
        }
        if(b==0){
            return false;
        }
        if(i<n-1){
            return false;
        }
        return true;
    }
};