class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int sm=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            
            if(mpp[sm-goal]){
                ans+=mpp[sm-goal];
            }
            mpp[sm]++;
        }
        return ans;
    }
};