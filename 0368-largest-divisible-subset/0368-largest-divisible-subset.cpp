class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> prev_ind(n);
        int mx=INT_MIN;
        int ind=-1;
        for(int i=0;i<n;i++){
            prev_ind[i]=i;
            
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        prev_ind[i]=j;
                    }
                }
            }
            if(dp[i]>mx){
                mx=dp[i];
                ind=i;
            }
        }

        //backtracking
        vector<int > ans;
        int prev=-1;

        while(prev!=ind){
            ans.push_back(nums[ind]);
            prev=ind;
            ind=prev_ind[ind];
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};