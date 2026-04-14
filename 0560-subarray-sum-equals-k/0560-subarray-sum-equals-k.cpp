class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int presm=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            presm+=nums[i];
            ans+=mpp[presm-k];
            mpp[presm]++;
           

        }
        
        return ans;
    }
};