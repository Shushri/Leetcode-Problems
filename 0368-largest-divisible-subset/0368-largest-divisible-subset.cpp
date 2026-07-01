class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int maxi=1;
        int ind=0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                ind=i;    
            }
        }

        vector<int> ans;
        while(hash[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=hash[ind];
        }
        ans.push_back(nums[ind]);
        return ans;




    }
};