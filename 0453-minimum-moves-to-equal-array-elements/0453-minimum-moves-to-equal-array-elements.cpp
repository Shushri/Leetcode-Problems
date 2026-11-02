class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mn=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]-mn);
        }
        return ans;
    }
};