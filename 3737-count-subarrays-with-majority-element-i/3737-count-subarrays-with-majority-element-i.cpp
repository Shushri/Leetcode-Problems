class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=i;j<n;j++){
                if(nums[j]==t){
                    c++;
                }
                if(c*2>(j-i+1)){
                    ans++;
                }
            }
        }
        return ans;
    }
};