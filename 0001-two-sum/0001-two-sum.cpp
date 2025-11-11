class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int ,int> hash;


        for (int i=0;i<n;i++){
            int complement=target-nums[i];
            if(hash.count(complement)!=0 ){
                return {i,hash[complement]};
            }
            hash[nums[i]]=i;
        }
        return {};
        
    }
};