class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int sum=nums[0];
        int mn=INT_MAX;
        while(i<n && j<n){
           
            if(sum>=target){
                mn=min(mn,(j-i+1));
                sum=sum-nums[i];
                i++;
            }
            else if(sum>target){
                sum=sum-nums[i];
                i++;
            }
            else{
                j++;
                if(j>=n){
                    break;
                }
                sum+=nums[j];
            }

        }
        if(mn==INT_MAX){
            return 0;
        }
        return mn;
    }
};