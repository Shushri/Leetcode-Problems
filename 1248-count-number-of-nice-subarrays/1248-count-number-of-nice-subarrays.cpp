class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0]=1;
        int ans=0;
        int sm=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                sm++;
            }
            if(mpp[sm-k]){
                ans+=mpp[sm-k];
            }
            mpp[sm]++;
        }
        return ans;
    }
};