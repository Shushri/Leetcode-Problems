class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int z=0;
        int n=nums.size();
        int i=0;
        int j=0;
        int  ans=0;
        while(j<n){
            if(nums[j]==0){
                if(z==k){
                    if(nums[i]==0){
                        z--;
                        
                    }
                    i++;
                }
                else{
                    z++;
                    j++;
                }
            }
            else{
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};