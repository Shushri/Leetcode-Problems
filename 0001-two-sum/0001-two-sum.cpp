class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++){
            int comp=t-nums[i];
            if(mpp.count(comp)!=0){
                return {i,mpp[comp]};
            }

            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};