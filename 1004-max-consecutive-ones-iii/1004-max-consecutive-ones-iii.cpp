class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int z=k;
        int i=0;
        int j=0;
        int mx=0;
        
        while(j<n){
            if(nums[j]==1){
                
                j++;
            }
            else{
                if(z>0){
                    z--;
                    
                    j++;
                }
                else{
                    if(nums[i]==0 && z<k){
                        z++;
                    }
                    i++;
                    
                    

                }
            }
            mx=max(mx,j-i);
        }
        return mx;
    }
};