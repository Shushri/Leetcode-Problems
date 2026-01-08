class Solution {
public:
    int findFinalValue(vector<int>& nums, int o) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==o){
                o=o*2;
            }
        }
        return o;
    }
};