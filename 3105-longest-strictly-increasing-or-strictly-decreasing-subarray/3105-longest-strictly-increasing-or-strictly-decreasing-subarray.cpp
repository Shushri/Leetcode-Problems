class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                cnt++;
            }
            else{
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
            else{
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        return mx;
    }
};