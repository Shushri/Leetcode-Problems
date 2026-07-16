class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;int j=n-1;
        int ans=0;
        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                ans++;
            }
            else if(nums[i]+nums[j]<k){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};