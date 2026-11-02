class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        int sm=0;
        sort(nums.begin(),nums.end());
        int md=nums[n/2];
        for(int i=0;i<n/2;i++){
            sm+=(md-nums[i]);
        }
        for(int i=n/2+1;i<n;i++){
            sm+=(nums[i]-md);
        }
        return sm;
    }
};