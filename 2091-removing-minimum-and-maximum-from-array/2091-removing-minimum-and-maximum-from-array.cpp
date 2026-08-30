class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        int mn=INT_MAX;
        int mxind=-1;
        int mnind=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                mx=nums[i];
                mxind=i;
            }
            if(nums[i]<mn){
                mn=nums[i];
                mnind=i;
            }
        }
        int ans=max(mxind+1,mnind+1);
        int p=max(n-mxind,n-mnind);
        ans=min(ans,p);
        p=mxind+1+n-mnind;
        ans=min(p,ans);
        p=mnind+1+n-mxind;
        ans=min(p,ans);
        return ans;
    }
};