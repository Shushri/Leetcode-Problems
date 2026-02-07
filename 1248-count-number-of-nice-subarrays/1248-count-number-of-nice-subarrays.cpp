class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mpp;
        mpp[0]=1;
        int ans=0;
        int od=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                od++;    
            }
            
            if(mpp[od-k]){
                ans+=mpp[od-k];
            }
            mpp[od]++;
        }
        return ans;
    }
};

