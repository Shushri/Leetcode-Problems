class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> mn1(n);
        vector<int> mn2(n);
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,nums[i]);
            mn1[i]=mn;
        }
        mn=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mn=min(mn,nums[i]);
            mn2[i]=mn;
        }
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++){
            if(nums[i]>mn1[i] && nums[i]>mn2[i]){
                ans=min(ans,nums[i]+mn1[i]+mn2[i]);
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};