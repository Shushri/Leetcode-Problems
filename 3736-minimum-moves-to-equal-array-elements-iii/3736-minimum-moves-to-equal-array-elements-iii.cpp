class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        int sm=accumulate(nums.begin(),nums.end(),0);
        int ans=mx*(n-1)-(sm-mx);
        return ans;
    }
};