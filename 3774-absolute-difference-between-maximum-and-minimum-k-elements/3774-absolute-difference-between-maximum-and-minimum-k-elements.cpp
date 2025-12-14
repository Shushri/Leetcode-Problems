class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long smf=0;
        long long sml=0;
        for(int i=0;i<k;i++){
            smf+=nums[i];
            sml+=nums[nums.size()-1-i];
        }
        return (int)sml-smf;
    }
};