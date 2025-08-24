class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        for (int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }
            else{
                zero++;
            }
        }
        if(one==n){
            return n-1;
        }
        if(zero==n){
            return 0;
        }
        int ans=0;
        int z=0;
        int prev=0;
        int mx=0;
        nums.push_back(0);
        for (int i=0;i<=n;i++){
            if(nums[i]==1){
                ans++;
            }
            else{
                if(z==0){
                    z++;
                    mx=max(mx,ans+prev);
                    prev=ans;
                    ans=0;
                }
                else if(z==1){
                    mx=max(mx,(ans+prev));
                    prev=ans;
                    ans=0;
                    z=0;
                }
            }
        }
        return mx;
    }
};